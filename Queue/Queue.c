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
void printQueue(Queue *pQ);					// in tat ca p.tu cua Queue
void readQueue(Queue *pQ);					// nhap Queue tu ban phim

/* function declaration */

void makenullQueue(Queue *pQ){
	pQ->Front = -1;
	pQ->Rear = -1;
}

int emptyQueue(Queue Q){
	return Q.Front == -1;
}

int fullQueue(Queue Q){
	return (Q.Rear - Q.Front + 1) == MaxLength;
}

ElementType front(Queue Q){
	// if (emptyQueue(Q))
	// 	printf ("Hang rong");
	// else
	return Q.Elements[Q.Front];
}

void deQueue(Queue *pQ){
	if (!emptyQueue(*pQ)){
		if (pQ->Front == pQ->Rear)
			makenullQueue(pQ);
		else pQ->Front = pQ->Front+1;
	}
	else printf("Loi: Hang rong!");
}

void enQueue(ElementType x,Queue *pQ){
	if (!fullQueue(*pQ)){

		// neu Queue rong
		if (emptyQueue(*pQ)) pQ->Front=0;

		/* neu Queue bi tran, di chuyen tat ca cac
		p.tu tren dau hang, roi them X vao vi tri cuoi cung cua Queue*/
		if (pQ->Rear == MaxLength-1){
			for(int i = pQ->Front; i <= pQ->Rear; i++)
				pQ->Elements[i - pQ->Front] = pQ->Elements[i];

			pQ->Rear = MaxLength - 1 - pQ->Front;
			pQ->Front = 0;
		}

		pQ->Rear = pQ->Rear+1;
		pQ->Elements[pQ->Rear] = x;
	}
	else printf("Loi: Hang day!");
}

void printQueue(Queue *pQ){
	if (!emptyQueue(*pQ)){
		for (int i = pQ->Front; i <= pQ->Rear; i++){
			printf("%d ", pQ->Elements[i]);
			deQueue(pQ);
		}
	}
	else printf("Loi: Hang rong!");

	printf("\n");
}

void readQueue(Queue *pQ){
	makenullQueue(pQ);

	int n;
	scanf("%d", &n);

	ElementType x;
	for (int i=1; i<=n; i++){
		scanf("%d", &x);
		enQueue(x, pQ);
	}
}

int main(){
	
	return 0;
}