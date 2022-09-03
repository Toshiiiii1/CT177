# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>

/* define Tree */
typedef int KeyType;

struct Node{
	KeyType Key;
	struct Node *Left, *Right;
};

typedef struct Node *Tree;

/* function prototype */

void preOrder(Tree T); 								// duyet tien tu
void inOrder(Tree T); 								// duyet trung tu
void postOrder(Tree T); 							// duyet hau tu
Tree search(KeyType x, Tree Root); 					// tim kiem Node co gia tri x trong cay
void insertNode(KeyType x, Tree *pRoot);			// them Node vao cay
void deleteNode(KeyType x, Tree *pRoot);			// xoa Node khoi cay

/* function declaration */

void preOrder(Tree T){
	if (T != NULL){
		printf("%d ", T->Key);
		preOrder(T->Left);
		preOrder(T->Right);
	}
}

void inOrder(Tree T){
	if (T != NULL){
		inOrder(T->Left);
		printf("%d ", T->Key);
		inOrder(T->Right);
	}
}

void postOrder(Tree T){
	if (T != NULL){
		postOrder(T->Left);
		postOrder(T->Right);
		printf("%d ", T->Key);
	}
}
	
Tree search(KeyType x, Tree T){
	if (T == NULL)
		return NULL;

	else if (T->Key < x)
		return search(x, T->Right);
	
	else if (T->Key > x)
		return search(x, T->Left);
	
	return T;
}

void insertNode(KeyType x, Tree *pRoot){
	if ((*pRoot) == NULL){
		(*pRoot) = (Tree)malloc(sizeof(struct Node));
		(*pRoot)->Key = x;
		(*pRoot)->Left = NULL;
		(*pRoot)->Right = NULL;
	}

	else if (x < (*pRoot)->Key)
		insertNode(x, &((*pRoot)->Left));

	else if (x > (*pRoot)->Key)
		insertNode(x, &((*pRoot)->Right));
	
}

/* ham di kem voi ham deleteNode */
KeyType deleteMin(Tree *pRoot){
	KeyType k;

	if((*pRoot)->Left == NULL){
		k = (*pRoot)->Key;
		(*pRoot) = (*pRoot)->Right;
		return k;
	}
	
	else
		return deleteMin(&((*pRoot)->Left));
}

void deleteNode(KeyType x, Tree *pRoot){
	if ((*pRoot) != NULL){
		if (x < (*pRoot)->Key)
			deleteNode(x, &(*pRoot)->Left);

		else if (x > (*pRoot)->Key)
			deleteNode(x, &(*pRoot)->Right);

		else{
			if (((*pRoot)->Left == NULL) && ((*pRoot)->Right == NULL))
				(*pRoot) = NULL;

			else if ((*pRoot)->Left == NULL)
				(*pRoot) = (*pRoot)->Right;

			else if ((*pRoot)->Right == NULL)
				(*pRoot) = (*pRoot)->Left;

			else
				(*pRoot)->Key = deleteMin(&(*pRoot)->Right);

		}
	}
}

int main(){
	
	return 0;
}