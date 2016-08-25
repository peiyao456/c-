#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;


class A
{
public:
	A(int a = 0):m_a(a)
	{
		cout << "A()" << endl;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int m_a;
};
void my_new_delete()
{
	//int *p = new int[10];
	int i = 0;
	A *p = (A*)malloc(sizeof(A)*10+4);//���ٿռ�
	if (NULL == p)
	{
		cout << "out of memory" << endl;
		return;
	}
	*((int *)p ) = 10;//����count
	//���ù��캯����ʼ��
	for ( i = 0;i < 10;i++)
	{
		new(p + i+1 ) A(i);
	}
	//delete[] p;
	for (i = 0;i < 10;i++)
	{
		p[i + 1].~A();
	}
}
int main()
{
	my_new_delete();
	system("pause");
	return 0;
}