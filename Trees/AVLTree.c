# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>

/* define AVL Tree */

typedef int KeyType;

struct Node{
	KeyType Key;
	int Height;
	struct Node *Left, *Right;
};

typedef struct Node *AVLTree;

/* function prototype */

void preOrder(AVLTree T);                              // duyet tien tu
void inOrder(AVLTree T);                               // duyet trung tu
void postOrder(AVLTree T);                             // duyet hau tu
AVLTree search(KeyType x, AVLTree T);                  // tim kiem Node co gia tri x trong cay
int getHeight(AVLTree T);                              // tinh chieu cao cua cay
int getBalance(AVLTree T);                             // tinh he so can bang cua 1 Node
AVLTree leftRotate(AVLTree T); 						   // xoay trai
AVLTree rightRotate(AVLTree T);						   // xoay phai
AVLTree leftrightRotate(AVLTree T);					   // xoay kep trai - phai
AVLTree rightRotate(AVLTree T); 					   // xoay kep phai - trai
AVLTree insertNode(KeyType x, AVLTree T);              // them Node vao cay
AVLTree deleteNode(KeyType x, AVLTree T);              // xoa Node khoi cay

/* function decleration */

void preOrder(AVLTree T){
	if (T != NULL){
		printf("(%d - %d); ", T->Key, T->Height);
		preOrder(T->Left);
		preOrder(T->Right);
	}
}

void inOrder(AVLTree T){
	if (T != NULL){
		inOrder(T->Left);
		printf("(%d - %d); ", T->Key, T->Height);
		inOrder(T->Right);
	}
}

void postOrder(AVLTree T){
	if (T != NULL){
		postOrder(T->Left);
		postOrder(T->Right);
		printf("(%d - %d); ", T->Key, T->Height);
	}
}
	
AVLTree search(KeyType x, AVLTree T){
	if (T == NULL)
		return NULL;

	else if (T->Key < x)
		return search(x, T->Right);
	
	else if (T->Key > x)
		return search(x, T->Left);
	
	return T;
}

int getHeight(AVLTree T){
	if (T == NULL)
		return -1;

	else{
		int maxL = getHeight(T->Left);
		int maxR = getHeight(T->Right);

		return (maxL > maxR)? maxL+1 : maxR+1;
	}
}

int getBalance(AVLTree T){
	if (T == NULL)
		return 0;
	return getHeight(T->Left) - getHeight(T->Right);
}

AVLTree leftRotate(AVLTree T){
	AVLTree newRoot = T->Right;
	AVLTree temp = newRoot->Left;

	newRoot->Left = T;
	T->Right = temp;

	T->Height = getHeight(T);
	newRoot->Height = getHeight(newRoot);

	return newRoot;
}

AVLTree rightRotate(AVLTree T){
	AVLTree newRoot = T->Left;
	AVLTree temp = newRoot->Right;

	newRoot->Right = T;
	T->Left = temp;

	T->Height = getHeight(T);
	newRoot->Height = getHeight(newRoot);

	return newRoot;
}

AVLTree leftrightRotate(AVLTree T){
	T->Left =  leftRotate(T->Left);
	return rightRotate(T);
}

AVLTree rightleftRotate(AVLTree T){
	T->Right = rightRotate(T->Right);
	return leftRotate(T);
}

AVLTree insertNode(KeyType x, AVLTree T){
	int balance;
	
	if (T == NULL){
		T = (AVLTree)malloc(sizeof(struct Node));
		T->Key = x;
		T->Left = NULL;
		T->Right = NULL;
		T->Height = getHeight(T);
		return T;
	}

	else if (x < T->Key)
		T->Left = insertNode(x, T->Left);

	else if (x > T->Key)
		T->Right = insertNode(x, T->Right);

	else
		return T;
	
	T->Height = getHeight(T);
	balance = getBalance(T);

	if (balance > 1 && x < T->Left->Key)
		return rightRotate(T);

	if (balance < -1 && x > T->Right->Key)
		return leftRotate(T);

	if (balance > 1 && x > T->Left->Key){
		return leftrightRotate(T);
	}

	if (balance < -1 && x < T->Right->Key){
		return rightleftRotate(T);
	}

	return T;
}

/* ham di kem voi ham deleteNode */
AVLTree deleteMin(AVLTree T){
	AVLTree temp;

	if(T->Left == NULL){
		temp = T;
		T = T->Right;
		return temp;
	}
	
	else
		return deleteMin(T->Left);
}

AVLTree deleteNode(KeyType x, AVLTree T){
	if (T != NULL){
		if (x < T->Key)
			T->Left = deleteNode(x, T->Left);

		else if (x > T->Key)
			T->Right = deleteNode(x, T->Right);

		else{
			if (T->Left == NULL && T->Right == NULL)
				T = NULL;

			else if (T->Left == NULL)
				T = T->Right;

			else if (T->Right == NULL)
				T = T->Left;

			else
				T = deleteMin(T->Right);

			return T;
		}

		T->Height = getHeight(T);
		int balance = getBalance(T);

		if (balance > 1 && getBalance(T->Left) >= 0)
			return rightRotate(T);

		if (balance > -1 && getBalance(T->Left) <= 0)
			return leftRotate(T);

		if (balance > 1 && getBalance(T->Left) < 0){
        	T->Left =  leftRotate(T->Left);
        	return rightRotate(T);
    	}

    	if (balance < -1 && getBalance(T->Right) > 0){
    		T->Right = rightRotate(T->Right);
        	return leftRotate(T);
    	}
	}

	return T;
}

int main(){
	
	return 0;
}