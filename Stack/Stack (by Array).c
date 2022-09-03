# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>

/* define Stack */
#define MaxLength 100

typedef int ElementType;

typedef struct{
	ElementType Elements[MaxLength];

	int Top_idx;
}Stack;

/* function prototype */

void makenullStack(Stack *pS); 			// khoi tao Stack rong
int emptyStack(Stack S); 				// kiem tra Stack rong
int full(Stack S); 						// kiem tra Stack day
ElementType top(Stack S); 				// tra ve p.tu tai dinh Stack
void pop(Stack *pS); 					// xoa p.tu tai dinh Stack
void push(ElementType x, Stack *pS); 	// xoa p.tu tai dinh Stack
void printStack(Stack S); 				// in tat ca p.tu co trong Stack
void readStack(Stack *pS); 				// nhap Stack tu ban phim

/* function declaration */

void makenullStack(Stack *pS){
	pS->Top_idx = MaxLength;
}

int emptyStack(Stack S){
	return S.Top_idx == MaxLength;
}

int full(Stack S){
	return S.Top_idx == 0;
}

ElementType top(Stack S){
	// neu Stack rong -> loi
	if (emptyStack(S)){
		printf("Stack is empty bitch!\n");
	}
	else{
		return S.Elements[S.Top_idx];
	}
}

void pop(Stack *pS){
	// neu Stack rong -> loi
	if (emptyStack(*pS)){
		printf("Stack is empty bitch!\n");
	}
	else{
		pS->Top_idx++;
	}
}

void push(ElementType x, Stack *pS){
	// neu Stack day -> loi
	if (full(*pS)){
		printf("Stack is full bitch!\n");
	}
	else{
		pS->Elements[--pS->Top_idx] = x;
	}
}

void printStack(Stack S){
	if (emptyStack(S)){
		printf("Ngan xep rong\n");
	}
	else{
		while (S.Top_idx < MaxLength){
			printf("%d ", S.Elements[S.Top_idx]);
			pop(&S);
		}
	}
	printf("\n");
}

void readStack(Stack *pS){
	makenullStack(pS);

	int n, x;
	scanf("%d", &n);

	for (int i=1; i <= n; i++){
		scanf("%d", &x);
		push(x, pS);
	}
}

int main(){
	
	return 0;
}