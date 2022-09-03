# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>
# include "PListLib.c"

/* define Stack */
typedef List Stack;

/* function prototype */
void makenullStack(Stack *pS); 					// khoi tao Stack rong
int emptyStack(Stack S); 						// kiem tra Stack rong
ElementType top(Stack S); 						// tra ve p.tu o dinh Stack
void pop(Stack *pS); 							// xoa p.tu tai dinh Stack
void push(ElementType x, Stack *pS); 			// them p.tu vao dinh Stack
void printStack(Stack S); 						// in cac p.tu trong Stack
void readStack(Stack *pS); 						// nhap Stack tu ban phim

/* function declaration */

void makenullStack(Stack *pS){
	makenullList(pS);
}

int emptyStack(Stack S){
	return emptyList(S);
}

ElementType top(Stack S){
	return retrieve(first(S), S);
}

void pop(Stack *pS){
	deleteList(first(*pS), pS);
}

void push(ElementType x, Stack *pS){
	insertList(x, first(*pS), pS);
}

void printStack(Stack S){
	printList(S);
}

void readStack(Stack *pS){
	readList(pS);
}

void chuyenHauto(char trungto[], char hautp[]){
	Stack S;
	makenullStack(&S);

	int i, j = 0;
	//char temp;

	for (i=0; i < strlen(trungto); i++){
		if ((trungto[i] >= 0 && trungto[i] <= 9) || (trungto[i] >= 'a' && trungto[i] <= 'z')){
			hautp[j++] = trungto[i];
		}
		else if (trungto[i] == '('){
			push(trungto[i], &S);
		}
		else if (trungto[i] == ')'){
			while (top(S) != '('){
				hautp[j++] = top(S);
				pop(&S);
			}

			pop(&S);
		}
		else if (trungto[i] >= 42 && trungto[i] <= 47){
			while (!emptyStack(S) && top(S) != '('){
				hautp[j++] = top(S);
				pop(&S);
			}

			push(trungto[i], &S);
		}
	}
}

int main(){
	
	return 0;
}