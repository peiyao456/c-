//以下代码只是用来探索各种继承下的对象模型

#include<iostream>
using namespace std;

//单继承下的对象模型
class B
{
public:
	B()
		:_b(1)
	{}
	virtual void fun1()
	{
		cout << "B::fun1()" << endl;
	}
	virtual void fun2()
	{
		cout << "B::fun2()" << endl;
	}
protected:
	int _b;
};
class D :public B
{
public:
	D()
		:_d(2)
	{}
	virtual void fun1()
	{
		cout << "D::fun1()" << endl;
	}
	virtual void fun3()
	{
		cout << "D::fun3()" << endl;
	}
protected:
	int _d;
};
typedef void(*pfun)();
void printVptr(pfun * pf)
{
	int i = 0;
	for (i = 0;pf[i] != NULL;i++)
	{
		pf[i]();
	}
}
void test()
{
	D d;
	printVptr((pfun *)*(int *)&d);
}
int main()
{
	test();
	system("pause");
	return 0;
}

//多继承下的对象模型
class B1
{
public:
	B1()
		:_b1(1)
		,_cb1('a')
	{}
	virtual void fun1()
	{
		cout << "B1::fun1()" << endl;
	}
	virtual void fun2()
	{
		cout << "B1::fun2()" << endl;
	}
protected:
	int _b1;
	char _cb1;
};
class B2
{
public:
	B2()
		:_b2(2)
		,_cb2('b')
	{}
	virtual void fun1()
	{
		cout << "B2::fun1()" << endl;
	}
	virtual void fun2()
	{
		cout << "B2::fun2()" << endl;
	}
protected:
	int _b2;
	char _cb2;
};

class D :public B1, public B2
{
public:
	D()
		:_d(3)
	{}
	virtual void fun1()
	{
		cout << "D::fun1()" << endl;
	}
	virtual void fun3()
	{
		cout << "D::fun3()" << endl;
	}
protected :
	int _d;
};

typedef void(*pfun)();

void printVptr(pfun* pf)
{
	int i = 0;
	for (i = 0;pf[i] != 0;i++)
	{
		pf[i]();
	}
}
void test()
{
	D d;
	printVptr((pfun *)*(int *)&d);
	printVptr((pfun *)*((int *)&d+3));
}
int main()
{
	test();
	system("pause");
	return 0;
}

//菱形继承下的对象模型
class  B
{
public:
	B()
		:_b(1)
	{}
	virtual void f()
	{ 
		cout << "B::f()" << endl; 
	}
	virtual void Bf()
	{
		cout << "B::Bf()" << endl; 
	}
protected:
	int _b;
};
class  B1:public B
{
public:
	B1()
		:_b1(2)
	{}
	virtual void f()
	{
		cout << "B1::f()" << endl; 
	}
	virtual void f1() 
	{
		cout << "B1::f1()" << endl; 
	}
	virtual void Bf1()
	{
		cout << "B1::Bf1()" << endl; 
	}
protected:
	int _b1;
};
class  B2 :public B
{
public:
	B2()
		:_b2(3)
	{}
	virtual void f() 
	{ 
		cout << "B2::f()" << endl;
	}
	virtual void f2() 
	{ 
		cout << "B2::f2()" << endl;
	}
	virtual void Bf2() 
	{ 
		cout << "B2::Bf2()" << endl;
	}
protected:
	int _b2;
};
class D :public B1, public B2
{
public:
	D()
		:_d(4)
	{}
	virtual void f() 
	{ 
		cout << "D::f()" << endl;
	}
	virtual void f1()
	{ 
		cout << "D::f1()" << endl; 
	}
	virtual void f2() 
	{ 
		cout << "D::f2()" << endl;
	}
	virtual void Df() 
	{ 
		cout << "D::Df()" << endl; 
	}
protected:
	int _d;
};
typedef void (*pfun)();
void printVptr(pfun * pf)
{
	int i = 0;
	for (i = 0;pf[i] != 0;i++)
	{
		pf[i]();
	}
}
void test()
{
	D d;
	printVptr((pfun *)*(int *)&d);
	cout << "---------------------" << endl;
	printVptr((pfun *)*((int *)&d + 3));
}
int main()
{
	test();
	system("pause");
	return 0;
}
//菱形虚继承下的对象模型
class  B
{
public:
	B()
		:_b(1)
	{}
	virtual void f()
	{
		cout << "B::f()" << endl;
	}
	virtual void Bf()
	{
		cout << "B::Bf()" << endl;
	}
protected:
	int _b;
};
class  B1 : virtual public B
{
public:
	B1()
		:_b1(2)
	{}
	virtual void f()
	{
		cout << "B1::f()" << endl;
	}
	virtual void f1()
	{
		cout << "B1::f1()" << endl;
	}
	virtual void Bf1()
	{
		cout << "B1::Bf1()" << endl;
	}
protected:
	int _b1;
};
class  B2 :virtual public B
{
public:
	B2()
		:_b2(3)
	{}
	virtual void f()
	{
		cout << "B2::f()" << endl;
	}
	virtual void f2()
	{
		cout << "B2::f2()" << endl;
	}
	virtual void Bf2()
	{
		cout << "B2::Bf2()" << endl;
	}
protected:
	int _b2;
};
class D :public B1, public B2
{
public:
	D()
		:_d(4)
	{}
	virtual void f()
	{
		cout << "D::f()" << endl;
	}
	virtual void f1()
	{
		cout << "D::f1()" << endl;
	}
	virtual void f2()
	{
		cout << "D::f2()" << endl;
	}
	virtual void Df()
	{
		cout << "D::Df()" << endl;
	}
protected:
	int _d;
};
typedef void(*pfun)();
void printVptr(pfun * pf)
{
	int i = 0;
	for (i = 0;pf[i] != 0;i++)
	{
		pf[i]();
	}
}
void test()
{
	D d;
	printVptr((pfun *)*(int *)&d);
	cout << "---------------------" << endl;
	printVptr((pfun *)*((int *)&d + 3));
	cout << "---------------------" << endl;
	printVptr((pfun *)*((int *)&d + 8));
}
int main()
{
	test();
	system("pause");
	return 0;
}