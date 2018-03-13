#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef int ElemType;
typedef int* Triplet;

bool InitTriplet(Triplet &T, ElemType v1, ElemType v2, ElemType v3);
bool DestroyTriplet(Triplet &T);
bool Get(Triplet T, int i, ElemType &e);
bool Put(Triplet &T, int i, ElemType e);
int IsAscending(Triplet T);
int IsDescending(Triplet T);
bool Max(Triplet T, ElemType &e);
bool Min(Triplet T, ElemType &e);

int main(void)
{
	Triplet T;
	ElemType v1 = 1, v2 = 2, v3 = 3;
	ElemType e, f, i;
	InitTriplet(T, v1, v2, v3);
	for (i = 0; i < 3; i++)
		printf("%d ", T[i]);
	printf("\n");

	printf("IsAscending? %d\n", IsAscending(T));
	printf("IsDescending? %d\n", IsDescending(T));

	Get(T, 3, e);
	printf("T[2]:%d\n", e);

	Put(T, 3, 2);
	for (i = 0; i < 3; i++)
		printf("%d ", T[i]);

	printf("IsAscending? %d\n", IsAscending(T));

	Max(T, e);
	printf("MAX:%d\n", e);

	Min(T, e);
	printf("MIN:%d\n", e);

	DestroyTriplet(T);
	system("pause");
	return 0;
}

bool InitTriplet(Triplet &T, ElemType v1, ElemType v2, ElemType v3)
{//������Ԫ��T��Ԫ��e1,e2,e3�ֱ𱻸��Բ���v1,v2,v3
	T = (ElemType *)malloc(3 * sizeof(ElemType));
	if (!T)
		exit(OVERFLOW);
	T[0] = v1;
	T[1] = v2;
	T[2] = v3;

	return true;
}

bool DestroyTriplet(Triplet &T)
{//������Ԫ��T
	free(T);
	T = NULL;
	return true;
}

bool Get(Triplet T, int i, ElemType &e)
{//1<=i<=3,��e����T�ĵ�iԪ��ֵ
	if (i < 1 || i>3) 
		return false;
	e = T[i-1];
	return true;
}

bool Put(Triplet &T, int i, ElemType e)
{//1<=i<=3,��T�ĵ�iԪΪe
	if (i < 1 || i>3)
		return false;
	T[i - 1] = e;
	return true;
}

int IsAscending(Triplet T)
{//���T��3��Ԫ�ذ��������У��򷵻�1�����򷵻�0��
	return (T[0] <= T[1]) && (T[1] <= T[2]);
}

int IsDescending(Triplet T)
{//���T��3��Ԫ�ذ��������У��򷵻�1�����򷵻�0��
	return (T[0] >= T[1]) && (T[1] >= T[2]);
}

bool Max(Triplet T, ElemType &e)
{//��e����ָ��T�����Ԫ�ص�ֵ
	e = (T[0 > T[1]]) ? ((T[0] > T[2]) ? T[0] : T[2]) : ((T[1] > T[2]) ? T[1] : T[2]); //��������������ˣ����ֲ���������
	return true;
}

bool Min(Triplet T, ElemType &e)
{//��e����ָ��T����СԪ�ص�ֵ
	e = (T[0 < T[1]]) ? ((T[0] < T[2]) ? T[0] : T[2]) : ((T[1] < T[2]) ? T[1] : T[2]);
	return true;
}