/*

void MergeList(List La, List Lb, List &Lc)
{
//��֪���Ա�La��Lb�е�����Ԫ�ذ�ֵ�ǵݼ�����
//�鲢La��Lb�õ��µ����Ա�Lc��Lc������Ԫ��Ҳ��ֵ�ǵݼ����У�

InitList(Lc);
i = j = 1;
k = 0;
La_len = ListLength(La);
Lb_len = ListLength(Lb);

while((i<=La_len)&&(j<=Lb_len))
{
GetElem(La,i,ai);
GetElem(Lb,j,bj);
if(ai<=bj)
{
ListInsert(Lc,++k,ai);
++i;
}
else
{
ListInsert(Lc,++k,bj);
++j;
}
}

while(i<=La_len)
{
GetElem(La,i,ai);
ListInsert(Lc,++k,ai);
++i;
}

while(j<=Lb_len)
{
GetElem(Lb,j,bj);
ListInsert(Lc,++k,bj);
++j;
}


}



*/