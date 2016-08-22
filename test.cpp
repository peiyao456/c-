#include"seqlist.h"
void test1()
{
	DataType data[] = { 1,2,3,4,5,3 };
	SeqList s1(data,6);
	cout << s1 << endl;
	/*cout << s1 << endl;
	s1.PushBack(6);
	cout << s1 << endl;
	s1.PopBack();
	cout << s1 << endl;
	s1.PushFront(8);
	cout << s1 << endl;
	s1.PopFront();
	cout << s1 << endl;*/
	/*s1.erase(4);
	cout << s1 << endl;*/
	//s1.Remove(3);
	/*s1.RemoveAll(3);
	cout << s1 << endl;*/
	//s1.bottleSort();
	s1.selectSort();
	//s1.insertSort();
	cout << s1 << endl;
}
int main()
{
	test1();
	system("pause");
	return 0;
}
//测试构造，拷贝构造，重载=
//void test()
//{
//	int data[] = { 1,2,3,4,5 };
//	SeqList s1(data,5);
//	cout << s1 << endl;
//	SeqList s2(s1);
//	cout << s2 << endl;
//	//SeqList s3;
//	s2 = s1;
//	cout << s2 << endl;
//}
//int main()
//{
//	test();
//	system("pause");
//	return 0;
//}