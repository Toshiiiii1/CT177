# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>

/* define Dictionary */

#define B 100 // so p.tu toi da cua Dic
#define Deleted -1000 // gia tri cua o da bi xoa
#define Empty 1000 // gia tri cua o rong

typedef int ElementType;
// khoi tao Dic bang Array
typedef ElementType Dictionary[B];

/* function prototype */

void makenullDic(Dictionary D);
int emptyDic(Dictionary D);
int fullDic(Dictionary D);
int hashFunction(ElementType x);
int isMember(ElementType x, Dictionary D);
void insertDic(ElementType x, Dictionary D);
void deleteDic(ElementType x, Dictionary D);

/* function declaration */

void makenullDic(Dictionary D){
	for (int i=0; i<B; i++){
		D[i] = Empty;
	}
}

int emptyDic(Dictionary D){
	for (int i=0; i<B; i++){
		if (D[i] != Empty && D[i] != Deleted)
			return 0;
	}

	return 1;
}

int fullDic(Dictionary D){
	for (int i=0; i<B; i++){
		if (D[i] == Empty || D[i] == Deleted)
			return 0;
	}

	return 1;
}

int hashFunction(ElementType x){
	return x%B;
}

int isMember(ElementType x, Dictionary D){
	int i, init = hashFunction(x);

	for (i=0; i<B; i++){
		if (D[(i+init)%B] == x)
			return 1;
	}
	return 0;
}

void insertDic(ElementType x, Dictionary D){
	int i, init;

	if (fullDic(D))
		printf("Full\n");

	else if (!isMember(x, D)){
		init = hashFunction(x);

		for (i=0; i<B; i++){
			if (D[(i+init)%B] == Empty || D[(i+init)%B] == Deleted){
				D[(i+init)%B] = x;
			}
		}
	}

	else
		printf("element already exists\n");
}

void deleteDic(ElementType x, Dictionary D){
	int i, init;

	if (emptyDic(D))
		printf("Empty\n");

	else{
		for (i=0; i<B; i++){
			if (D[(i+init)%B] == x){
				D[(i+init)%B] = Deleted;
			}
		}
	}
}

int main(){
	
	return 0;
}