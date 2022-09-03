# include <stdio.h>
# include <stdlib.h>

/* define Linked List */
typedef int ElementType;

struct Node{
	ElementType Element;

	struct Node *Next;
};

typedef struct Node *Position;

typedef Position List;

/* Function prototype */
void makenullList(List *pL);							// create an empty list
int emptyList(List L);									// check the list is empty or not
Position first(List L);									// returns the first Node of the list
Position endList(List L);								// returns the last Node of the list
Position next(Position P, List L);						// returns the next Node of the Node at position P
Position previous(Position P, List L);					// returns the Node before the Node at position P
ElementType retrieve(Position P, List L);				// returns the value of the Node at position P
Position locate(ElementType x, List L);					// returns the positon of the Node containing value x
int member(ElementType x, List L);                      // check a number in List or not
void insertList(ElementType x, Position P, List *pL); 	// insert the Node into the list
void deleteList(Position P, List *pL);					// delete the Node from the list
void printList(List L);									// print all Node from the list
void readList(List *pL);								// read the list from keyboard

/* function declaration */

void makenullList(List *pL){
	(*pL) = (struct Node*) malloc(sizeof(struct Node));
	(*pL)->Next = NULL;
}

int emptyList(List L){
	return (L->Next == NULL);
}

Position first(List L){
	return L;
}

Position next(Position P, List L){
	return P->Next;
}

Position endList(List L){
	Position P = first(L);

	while (P->Next != NULL)
		P = next(P, L);
	return P;
}

Position previous(Position P, List L){
	Position Q = first(L);

	while(Q->Next != P)
		Q = next(Q, L);
	return Q;
}

ElementType retrieve(Position P, List L){
	if (P->Next != NULL)
		return P->Next->Element;
}

Position locate(ElementType x, List L){
	Position P = first(L), E = endList(L);

	while (P != E)
		if (retrieve(P, L) == x)
			return P;
		else P = next(P, L);
	return P;
}

int member(ElementType x, List L){
	Position P = L;
	while (P->Next != NULL){
		if (P->Next->Element == x)
			return 1;
		P = P->Next;
	}
	return 0;
}

void insertList(ElementType x, Position P, List *pL){
	Position T;
	T = (struct Node*) malloc(sizeof(Node));
	T->Element = x;
	T->Next = P->Next;
	P->Next = T;
}

void deleteList(Position P, List *pL){
	Position Temp;

	if (P->Next != NULL){
		Temp = P->Next;
		P->Next = Temp->Next;
		free(Temp);
	}
}

void printList(List L){
	Position P = first(L), E = endList(L);
	while (P != E){
		printf("%d ",retrieve(P, L));
		P = next(P, L);
	}
	printf("\n");
}

void readList(List *pL) {
	int i,n;
	ElementType x;
	makenullList(pL);

	scanf("%d", &n);

	for(i=1; i<=n; i++) {
		scanf("%d", &x);
		insertList(x, endList(*pL), pL);
		//insertList(x, first(*pL), pL);
	} 
}

int main(){

	return 0;
}