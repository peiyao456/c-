#include<iostream>
using namespace std;
#include<string>
#include<cassert>
//版本一
class String
{
public:
	String(const char * str = "")
		:m_str(new char[strlen(str) + 1])
		,m_pcount(new int(1))
	{
		strcpy(m_str, str);
	}
	~String()
	{
		if (--*m_pcount == 0)
		{
			delete[] m_str;
			m_str = nullptr;
			delete m_pcount;
			m_pcount = 0;
		}
	}
	//拷贝构造
	String(String &s)
		:m_str(s.m_str)
		,m_pcount(s.m_pcount)
	{
		++*m_pcount ;
	}
	//
	String& operator=(String& s)
	{
		if (--*(s.m_pcount) == 0)
		{
			delete[] (s.m_str);
			s.m_str = nullptr;
			delete m_pcount;
		}
		++*m_pcount;
		s.m_str = m_str;
		return *this;
	}
private:
	char* m_str;
	int *m_pcount;
};
void test()
{
	String str1("asd");
	String str2(str1);
	String str3("fgh");
	str3 = str1;
}

int main()
{
	test();
	system("pause");
	return 0;
}
//版本二

class String
{
	friend ostream& operator<<(ostream &os, const String& s)
	{
		os << s.m_str;
		return os;
	}
public:
	String(const char* str = "")
		:m_str(new char[strlen(str)+5])
	{
		m_str += 4;
		//*(int *)m_str = 1;
		GetCount() = 1;
		strcpy(m_str,str);
	}
	~String()
	{
		if (--GetCount() == 0)
		{
			delete[](m_str-4);
			m_str = nullptr;
		}
	}
	//拷贝构造
	String(const String& s)
		:m_str(s.m_str)
	{
		GetCount()++;
	}
	String& operator=(String& s)
	{
		if (--s.GetCount() == 0)
		{
			delete[](s.m_str - 4);
			m_str = nullptr;
		}
		m_str = s.m_str;
		GetCount()++;
		return *this;
	}
	char& operator[](int index)
	{
		assert(index >= 0);
		assert(index <= strlen(m_str) );
		if (GetCount() > 1)
		{
			--GetCount();
			char *tmp = new char[strlen(m_str) + 5];
			strcpy(tmp+4,m_str);
			m_str = tmp + 4;
			GetCount() = 1;
		}
		return m_str[index];
	}
private:
	int& GetCount()
	{
		return *((int *)m_str - 1);
	}
private:
	char *m_str;
};
void test()
{
	String str1("asd");
	cout << str1 << endl;
	String str2(str1);
	cout << str2 << endl;
	String str3("fgh");
	cout << str3 << endl;
	str3 = str1;
	cout << str3 << endl;
	str3[2] = 'w';
	cout << str3 << endl;
}
	
int main()
{
	test();
	system("pause");
	return 0;
}