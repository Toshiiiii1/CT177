# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>

/* define Tree */
typedef int DataType;

struct TNode{
	DataType Data;
	struct TNode *Left, *Right;
};

typedef struct TNode *Tree;

/* function prototype */

void makenullTree(Tree *pT); 						// khoi tao Tree rong
int emptyTree(Tree T);								// kiem tra Tree rong
Tree leftChild(Tree n); 							// tra ve con trai cua nut n trong Tree
Tree rightChild(Tree n); 							// tra ve con phai cua nut n trong Tree
int isLeaf(Tree n); 								// kiem tra 1 nut la
void preOrder(Tree T); 								// duyet tien tu
void inOrder(Tree T); 								// duyet trung tu
void postOrder(Tree T); 							// duyet hau tu
int nb_nodes(Tree T); 								// so nut trong Tree
int getLeaves(Tree T);								// so nut la trong Tree
Tree create2(DataType v, Tree l, Tree r); 			// tao Tree moi tu 2 Tree co san
Tree createTree(char pre[], char in[], int inStart, int inEnd); 		// tao Tree tu 2 chuoi duyet tien tu va chuoi duyet trung tu

/* function declaration */

void makenullTree(Tree *pT){
	(*pT) = NULL;
}

int emptyTree(Tree T){
	return T == NULL;
}

Tree leftChild(Tree n){
	return (emptyTree(n))? n->Left : NULL;
}

Tree rightChild(Tree n){
	return (emptyTree(n))? n->Right : NULL;
}

int isLeaf(Tree n){
	return (emptyTree(n))? (leftChild(n) == NULL) && (rightChild(n) == NULL) : 0;
}

void preOrder(Tree T){
	if (!emptyTree(T)){
		printf("%d ", T->Data);
		preOrder(leftChild(T));
		preOrder(rightChild(T));
	}
}

void inOrder(Tree T){
	if (!emptyTree(T)){
		inOrder(leftChild(T));
		printf("%d ", T->Data);
		inOrder(rightChild(T));
	}
}

void postOrder(Tree T){
	if (!emptyTree(T)){
		postOrder(leftChild(T));
		postOrder(rightChild(T)); 
		printf("%d ", T->Data);
	}
}

int nb_nodes(Tree T){
	return (emptyTree(T))? 0 : 1 + nb_nodes(leftChild(T)) + nb_nodes(rightChild(T));
}

int getLeaves(Tree T){
	if (T == NULL){
		return 0;
	}
	else if (T->Left == NULL && T->Right == NULL){
		return 1;
	}
	else{
		return getLeaves(T->Left) + getLeaves(T->Right);
	}
}

Tree create2(DataType v, Tree l, Tree r){
	Tree N;
	N = (struct TNode*)malloc(sizeof(struct TNode));
	N->Data = v;
	N->Left = l;
	N->Right = r;
	return N;
}

int findIndex(DataType x, char in[], int star, int end){
    int i = star;
    while (i <= end){
         if (x == in[i])
             return i;
         else
             i++;
   }
   return i;
}

int i = 0;

Tree createTree(char pre[], char in[], int inStart, int inEnd){
	int j;

	if (inStart > inEnd){
		Tree T = NULL;
		return T;
	}
	else if (inStart == inEnd){
		Tree T = (struct Node*)malloc(sizeof(struct TNode));
		T->Data = pre[i++];
		T->Left = NULL;
		T->Right = NULL;

		return T;
	}
	else{
		Tree T = (struct Node*)malloc(sizeof(struct TNode));
		T->Data = pre[i++];

		/* fineIndex(): tim vi tri cua 1 ki tu
		trong 1 chuoi bat dau tu inStart, ket thuc
		la inEnd*/
		j = findIndex(T->Data, in, inStart, inEnd);

		T->Left = createTree(pre, in, inStart, j-1);

		T->Right = createTree(pre, in, j+1, inEnd);

		return T;
	}
}

int main(){
	
	return 0;
}