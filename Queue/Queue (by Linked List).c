# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>

/* define Queue */
typedef int ElementType;

struct Node{
	ElementType Element;
	struct Node* Next;
};

typedef struct Node* Position;

typedef struct{
	Position Front, Rear;
}Queue;

/* function prototype */

void makenullQueue(Queue *pQ);					// khoi tao Queue rong
int emptyQueue(Queue Q);						// kiem tra Queue rong
ElementType front (Queue Q);					// tra ve gia tri cua p.tu tai dau Queue
void enQueue(ElementType x, Queue *pQ);			// them p.tu tai cuoi Queue
void deQueue(Queue *pQ);						// xoa p.tu tai dau Queue

/* function declaration */

void makenullQueue(Queue *pQ){
	Position Header;
	Header = (struct Node*)malloc(sizeof(struct Node));

	Header->Next = NULL;
	pQ->Front = Header;
	pQ->Rear = Header;
}

int emptyQueue(Queue Q){
	return (Q.Front==Q.Rear);
}

ElementType front (Queue Q){
	if (!emptyQueue(Q)){
		return Q.Front->Next->Element;
	}
	else printf("Loi : Hang rong");
}

void enQueue(ElementType x, Queue *pQ){
	pQ->Rear->Next = (struct Node*)malloc(sizeof(struct Node));
	pQ->Rear = pQ->Rear->Next;
	pQ->Rear->Element = x;
	pQ->Rear->Next = NULL;
}

void deQueue(Queue *pQ){
	if (!emptyQueue(*pQ)){
		Position Tempt;
		Tempt = pQ->Front;
		pQ->Front = pQ->Front->Next;
		free(Tempt);
	}
	else printf("Loi : Hang rong");
}

int main(){

	return 0;
}