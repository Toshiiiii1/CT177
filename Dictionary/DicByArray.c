# include <stdio.h>

/* define Dictionary */
#define Maxlength 100

typedef int ElementType;

typedef int Position;

typedef struct{
	ElementType Elements[Maxlength];

	Position Last;
}Dictionary;

/* function prototype */

void makenullDictionary(Dictionary *pD);								// khoi tao 1 Dictionary rong
ElementType retrieve(Position P, Dictionary D);							// tra ve gia tri cua p.tu tai vi tri P
int member(ElementType x, Dictionary Dictionary);						// kiem tra X co trong Dictionary hay khong
void deleteDictionary(Position P, Dictionary *pD);						// xoa p.tu khoi Dictionary
void insertDictionary(ElementType x, Dictionary *pD);					// chen p.tu vao cuoi Dictionary
void printDictionary(Dictionary D);										// in tat ca cac p.tu trong Dictionary
void readDictionary(Dictionary *pD, int n);								// nhap Dictionary tu ban phim

/* function declaration */

void makenullDictionary(Dictionary *pD){
	pD->Last = 0;
}

ElementType retrieve(Position P, Dictionary D){
	return D.Elements[P-1];
}

int member(ElementType x, Dictionary D){
	Position P;
	for (P = 1; P <= D.Last; P++)
		if (x == D.Elements[P-1])
			return 1;
	return 0;
}

void deleteDictionary(ElementType x, Dictionary *pD){
	if (pD->Last == 0)
		printf("Empty\n");

	else{
		Position Q;
		for(Q = 1; Q <= pD->Last; Q++){
			if (pD->Elements[Q-1] == x)
				pD->Elements[Q-1] = pD->Elements[Q];
		}
		pD->Last--;
	}
}

void insertDictionary(ElementType x, Dictionary *pD){
	if (pD->Last == Maxlength)
		printf("Full\n");

	else if (member(x, *pD))
		printf("Element already exists\n");

	else{
		pD->Elements[pD->Last] = x;
		pD->Last++;
	}
}

void printDictionary(Dictionary D){
	for (Position P=1; P<=D.Last; P++){
		printf("%d ", D.Elements[P-1]);
	}
	printf("\n");
}

void readDictionary(Dictionary *pD){
	int n;
	ElementType temp;
	scanf("%d", &n);
	for (Position P=1; P<=n; P++){
		scanf("%d", &temp);
		if (!member(temp, *pD))
			insertDictionary(temp, pD);
	}
}

int main(){

	return 0;
}