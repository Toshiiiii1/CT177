# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>

/* define List */
#define Maxlength 100

typedef int ElementType;

typedef int Position;

typedef struct{
	ElementType Elements[Maxlength];

	Position Last;
}List;

/* function prototype */

void makenullList(List *pL);							// khoi tao 1 List rong
int emptyList(List L);									// kiem tra List co rong hay khong
int fullList(List L);									// kiem tra List full hay khong
Position first(List L);									// tra ve vi tri cua p.tu dau tien trong List
Position endList(List L);								// tra ve vi tri p.tu cuoi cung trong List
Position next(Position P, List L);						// tra ve p.tu sau p.tu tai vi tri P
Position previous(Position P, List L);					// tra ve p.tu truoc p.tu tai vi tri P
ElementType retrieve(Position P, List L);				// tra ve gia tri cua p.tu tai vi tri P
Position locate(ElementType x, List L);					// tra ve vi tri xuat hien dau tien cua p.tu X
void insertList(ElementType x, Position P, List *pL); 	// chen p.tu vao List
void deleteList(Position P, List *pL);					// xoa p.tu khoi List
int member(ElementType x, List list);					// kiem tra X co trong List hay khong
void insertSet(ElementType x, List *pL);				// chen p.tu vao cuoi List
void printList(List L);									// in tat ca cac p.tu trong List
void readList(List *pL);								// nhap List tu ban phim

/* function declaration */

void makenullList(List *pL){
	pL->Last = 0;
}

int emptyList(List L){
	return L.Last == 0;
}

int fullList(List L){
	return L.Last == Maxlength;
}

Position first(List L){
	return 1;
}

Position endList(List L){
	return L.Last+1;
}


Position next(Position P, List L){
	return P+1;
}

Position previous(Position P, List L){
	return P-1;
}

ElementType retrieve(Position P, List L){
	return L.Elements[P-1];
}

Position locate(ElementType x, List L){
	Position P;

	for (P=1; P<=L.Last; P++){
		if (L.Elements[P-1] == x){
			return P;
		}
	}
	
	return P+1;
}

void insertList(ElementType x, Position P, List *pL){
	if (pL->Last == Maxlength){
		printf("Full\n");
	}

	else if (P < 1 || P > pL->Last+1){
		printf("Out of range, bitch\n");
	}

	else{
		Position Q;

		for(Q = pL->Last; Q >= P; Q--)
			pL->Elements[Q] = pL->Elements[Q-1];

		pL->Elements[P-1] = x;

		pL->Last++;
	}
}

void deleteList(Position P, List *pL){
	if (pL->Last == 0){
		printf("Empty\n");
	}

	else if (P < 1 || P > pL->Last){
		printf("Out of range, bitch\n");
	}

	else {
		Position Q;
		for(Q = P; Q < pL->Last; Q++)
			pL->Elements[Q-1] = pL->Elements[Q];

		pL->Last--;
	}
}

int member(ElementType x, List L){
	Position P;
	for (P = 1; P <= L.Last; P++)
		if (x == L.Elements[P-1])
			return 1;
	return 0;
}

void insertSet(ElementType x, List *pL){
	pL->Elements[pL->Last] = x;
	pL->Last++;
}

void printList(List L){
	for (Position P=1; P<=L.Last; P++){
		printf("%d ", L.Elements[P-1]);
	}
	printf("\n");
}

void readList(List *pL){
	int n;
	scanf("%d", &n);
	for (Position P=1; P<=n; P++){
		scanf("%d", &pL->Elements[pL->Last]);
		pL->Last++;
	}
}

int main(){

	return 0;
}