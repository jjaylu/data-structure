void union(List &La, List Lb)
{//�����������Ա�Lb�е�����La�е�����Ԫ�ز��뵽La��
	La_len = ListLength(La);
	Lb_len = ListLength(Lb);
	for (i = 1; i <= Lb; i++)
	{
		GetElem(Lb, i, e);
		if (!LocateElem(La, e, equal))
			ListInsert(La, ++La_len, e);
	}
}