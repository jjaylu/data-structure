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
{//构造三元组T，元素e1,e2,e3分别被赋以参数v1,v2,v3
	T = (ElemType *)malloc(3 * sizeof(ElemType));
	if (!T)
		exit(OVERFLOW);
	T[0] = v1;
	T[1] = v2;
	T[2] = v3;

	return true;
}

bool DestroyTriplet(Triplet &T)
{//销毁三元组T
	free(T);
	T = NULL;
	return true;
}

bool Get(Triplet T, int i, ElemType &e)
{//1<=i<=3,用e返回T的第i元的值
	if (i < 1 || i>3) 
		return false;
	e = T[i-1];
	return true;
}

bool Put(Triplet &T, int i, ElemType e)
{//1<=i<=3,置T的第i元为e
	if (i < 1 || i>3)
		return false;
	T[i - 1] = e;
	return true;
}

int IsAscending(Triplet T)
{//如果T的3个元素按升序排列，则返回1，否则返回0；
	return (T[0] <= T[1]) && (T[1] <= T[2]);
}

int IsDescending(Triplet T)
{//如果T的3个元素按降序排列，则返回1，否则返回0；
	return (T[0] >= T[1]) && (T[1] >= T[2]);
}

bool Max(Triplet T, ElemType &e)
{//用e返回指向T的最大元素的值
	e = (T[0 > T[1]]) ? ((T[0] > T[2]) ? T[0] : T[2]) : ((T[1] > T[2]) ? T[1] : T[2]); //我真服了严奶奶了，这种操作。。。
	return true;
}

bool Min(Triplet T, ElemType &e)
{//用e返回指向T的最小元素的值
	e = (T[0 < T[1]]) ? ((T[0] < T[2]) ? T[0] : T[2]) : ((T[1] < T[2]) ? T[1] : T[2]);
	return true;
}