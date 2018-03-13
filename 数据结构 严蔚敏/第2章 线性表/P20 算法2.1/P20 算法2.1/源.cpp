void union(List &La, List Lb)
{//将所有在线性表Lb中但不在La中的数据元素插入到La中
	La_len = ListLength(La);
	Lb_len = ListLength(Lb);
	for (i = 1; i <= Lb; i++)
	{
		GetElem(Lb, i, e);
		if (!LocateElem(La, e, equal))
			ListInsert(La, ++La_len, e);
	}
}