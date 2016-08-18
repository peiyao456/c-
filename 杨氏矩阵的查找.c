#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//���Ͻ������
int yang_search(int a[][3], int rows, int cols, int key)
{
	int row = 0;
	int col = cols - 1;
	while (row >= 0 && col >= 0)
	{
		if (a[row][col] == key)
			return 1;
		else if (a[row][col] < key)
			row++;
		else
			col--;
	}
	return 0;
}
//���½������
int yang_search(int a[][3], int rows, int cols, int key)
{
	int row = rows-1;
	int col = 0;
	while (row >= 0 && col >= 0)
	{
		if (a[row][col] == key)
			return 1;
		else if (a[row][col] < key)
			col++;
		else
			row--;
	}
	return 0;
}
int main()
{
	int a[][3] = {1,2,3,2,3,4,3,4,5};
	int ret = yang_search(a,3,3,9);
	if (ret == 1)
		printf("���ҵ���");
	else
		printf("û�в��ҵ�");
	system("pause");
	return 0;
}