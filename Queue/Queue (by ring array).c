# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>

/* define Queue */
#define MaxLength 100

typedef int ElementType;

typedef struct {
	ElementType Elements[MaxLength];
	int Front, Rear;
}Queue;

/* function prototype */

void makenullQueue(Queue *pQ);				// khoi tao Queue rong
int emptyQueue(Queue Q);					// kiem tra Queue rong
int fullQueue(Queue Q);						// kiem tra Queue day
ElementType front(Queue Q);					// gia tri cua p.tu tai dau Queue
void deQueue(Queue *pQ);					// xoa p.tu tai dau Queue
void enQueue(ElementType x,Queue *pQ);  	// them p.tu tai cuoi Queue

/* function declaration */

void makenullQueue(Queue *pQ){
	pQ->Front = -1;
	pQ->Rear = -1;
}

int emptyQueue(Queue Q){
	return Q.Front == -1;
}

int fullQueue(Queue Q){
	return (Q.Rear - Q.Front + 1) % MaxLength == 0;
}

ElementType front(Queue Q){
	if (emptyQueue(Q))
		printf ("Hang rong");
	else 
		return Q.Elements[Q.Front];
}

void deQueue(Queue *pQ){
	if (!emptyQueue(*pQ)){
		if (pQ->Front == pQ->Rear)
			makenullQueue(pQ);
		else pQ->Front = pQ->Front+1 % MaxLength;
	}
	else printf("Loi: Hang rong!");
}

void enQueue(ElementType x,Queue *pQ){
	if (!fullQueue(*pQ)){
		if (emptyQueue(*pQ))
			pQ->Front = 0;

		pQ->Rear = (pQ->Rear+1) % MaxLength;
		pQ->Elements[pQ->Rear] = x;
	}
	else printf("Loi: Hang day!");
}

void printQueue(Queue Q){
	if (!emptyQueue(Q)){
		for (int i = Q.Front; i <= Q.Rear; i++){
			printf("%d ", Q.Elements[i]);
		}
	}
	else printf("Loi: Hang rong!");
}

void readQueue(Queue *pQ){
	makenullQueue(pQ);

	int n;
	scanf("%d", &n);

	pQ->Front = 0, pQ->Rear = 0;
	for (int i=0; i<n; i++){
		scanf("%d", &pQ->Elements[i]);
		pQ->Rear++;
	}
}

int main(){

	return 0;
}