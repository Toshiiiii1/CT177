# include <stdio.h>
# include <string.h>

/* define List */
#define MaxLength 40

struct SinhVien{
	char MSSV[10], HoTen[50];
	float DiemLT, DiemTH1, DiemTH2;
};

typedef struct SinhVien ElementType;

typedef struct{
	ElementType A[MaxLength];
	int n;
}DanhSach;

/* function prototype */
void chenCuoi(struct SinhVien sinhVien, DanhSach *pL);
DanhSach dsRong();
void hienthi(DanhSach L);
int ktRong(DanhSach L);
void nhap(DanhSach *pL);
int tim(char *MSSV, DanhSach L);
void xoaTai(int p, DanhSach *pL);

/* function declaration */

void chenCuoi(struct SinhVien sinhVien, DanhSach *pL){
	if (pL->n >= 40){
		printf("Loi! Danh sach day!");
		return;
	}
	pL->A[pL->n] = sinhVien;
	pL->n++;
}

DanhSach dsRong(){
	DanhSach L;
	L.n = 0;
	return L;
}

void hienthi(DanhSach L){
	for (int i=0; i<L.n; i++){
		printf("%s - ", L.A[i].MSSV);
		printf("%s - ", L.A[i].HoTen);
		printf("%.2f - ", L.A[i].DiemLT);
		printf("%.2f - ", L.A[i].DiemTH1);
		printf("%.2f - \n", L.A[i].DiemTH2);
	}
}

int ktRong(DanhSach L){
	return L.n == 0;
}

void nhap(DanhSach *pL){
	scanf("%d", &pL->n);
	getchar();

	for (int i=0; i < pL->n; i++){
		fgets(pL->A[i].MSSV, 10, stdin);
		if (pL->A[i].MSSV[strlen(pL->A[i].MSSV)-1] == '\n'){
			pL->A[i].MSSV[strlen(pL->A[i].MSSV)-1] = '\0';
		}

		fgets(pL->A[i].HoTen, 50, stdin);
		if (pL->A[i].HoTen[strlen(pL->A[i].HoTen)-1] == '\n'){
			pL->A[i].HoTen[strlen(pL->A[i].HoTen)-1] = '\0';
		}

		scanf("%f %f %f", &pL->A[i].DiemLT, &pL->A[i].DiemTH1, &pL->A[i].DiemTH2);
		getchar();
	}
}

int tim(char *MSSV, DanhSach L){
	int i;
	for (i = 0; i < L.n; i++)
		if (strcmp(MSSV, L.A[i].MSSV) == 0)
			return i + 1;
	return i + 1;
}

void xoaTai(int p, DanhSach *pL){
	for (int i = p - 1; i < pL->n; i++)
		pL->A[i] = pL->A[i + 1];

	pL->n--;
}