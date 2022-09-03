# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>

/* define Dictionary */

#define B 100

typedef int ElementType;

struct Node{
	ElementType Data;
	struct Node *Next;
};

typedef struct Node *Position;
typedef Position Dictionary[B];

/* function prototype */

void makenullDic(Dictionary *D);
int hashFunction(ElementType x);
int isMember(ElementType x, Dictionary D);
void insertDic(ElementType x,Dictionary *D);
void deleteDic(ElementType x,Dictionary *D);

/* function decleration */

void makenullDic(Dictionary *D){
	for (int i=0; i<B; i++){
		(*D)[i] = NULL;
	}
}

int hashFunction(ElementType x){
	return x%B;
}

int isMember(ElementType x, Dictionary D){
	Position P;
	P = D[hashFunction(x)];

	while (P != NULL){
		if (P->Data == x)
			return 1;
		P = P->Next;
	}

	return 0;
}

void insertDic(ElementType x,Dictionary *D){
	Position P;

	if (!isMember(x, *D)){
		P = D[hashFunction(x)];
		D[hashFunction(x)] = (struct Node*)malloc(sizeof(struct Node));
		D[hashFunction(x)]->Data = x;
		D[hashFunction(x)]->Next = P;
	}
}

void deleteDic(ElementType x,Dictionary *D){
	Position P, Q;

	if ((*D)[hashFunction(x)] != NULL){
		if ((*D)[hashFunction(x)]->Data == x){
			Q = (*D)[hashFunction(x)];
			(*D)[hashFunction(x)] = (*D)[hashFunction(x)]->Next;
			free(Q);
		}

		else{
			P = (*D)[hashFunction(x)];
			while (P->Next != NULL){
				if (P->Next->Data == x){
					Q = P->Next;
					P->Next = Q->Next;
					free(Q);
				}
				P = P->Next;
			}
		}
	}
}

int main(){
	
	return 0;
}