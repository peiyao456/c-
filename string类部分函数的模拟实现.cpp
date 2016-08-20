#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

class String
{
	friend ostream &operator<<(ostream &os, String & s)
	{
		os << s.m_str;
		return os;
	}
public:
	String(char *str = "")
		:m_sz(strlen(str))
		, m_capacity(m_sz + 1)
		, m_str(new char[m_capacity])
	{
		cout << "String()" << endl;
		strcpy(m_str, str);
	}
	String(const String &s)
	{
		m_str = new char[strlen(s.m_str) + 1];
		strcpy(m_str, s.m_str);
		m_sz = strlen(s.m_str);
		m_capacity = m_sz + 1;
	}
	~String()
	{
		cout << "~String()" << endl;
		if (NULL != m_str)
		{
			delete[] m_str;
			m_str = nullptr;
			m_sz = 0;
			m_capacity = 0;
		}
	}
	//String& operator=(const String &s)
	//{
	//	cout << "operator=(String &s)" << endl;
	//	//�����жϲ���ȵĴ��Ÿ�ֵ
	//	if (this != &s)
	//	{
	//		delete[] m_str;
	//		m_str = new char[strlen(s.m_str) + 1];
	//		strcpy(m_str,s.m_str);
	//	}
	//	return *this;
	//}
	//����=���ִ��İ취
	String& operator=(String s)//��������������
	{
		std::swap(m_str, s.m_str);
		std::swap(m_sz, s.m_sz);
		std::swap(m_capacity, s.m_capacity);
		return *this;
	}
	//β�������ַ���
	void PushBack(char * str)
	{
		CheckCapacity(strlen(str));
		strcpy(m_str + m_sz, str);
		m_sz += strlen(str);
		//m_str[m_sz] = '\0';
	}
	//β�������ַ�
	void PushBack(char c)
	{
		CheckCapacity(1);
		m_str[m_sz++] = c;
		m_str[m_sz] = '\0';
	}
	//����[]��ȡ�ַ����е������ַ�
	char& operator[](unsigned int index)
	{
		return m_str[index];//Ҫ�ǲ����޸��ַ��������ݣ�����д�ɳ���Ա���������س�����
	}
	//���ö���ת����c���͵��ַ���
	const char* c_str() const
	{
		return m_str;
	}
	//�����ַ�����posλ�ÿ�ʼ��n���ַ�
	String& erase(size_t pos, size_t n)
	{
		unsigned int i = 0;
		c_str();
		if ((pos >= 0) && (pos <= m_sz) && (n >= 0) && (n <= m_sz))
		{
			for (i = pos + n; i < m_sz + 1;i++)
			{
				m_str[i - n] = m_str[i];
			}
		}
		m_sz -= n;
		return *this;
	}
	//��string�����е�pos1��λ�ò������str(Ҫ�ж��Ƿ���Ҫ����)
	String& insert(size_t pos1,const String& str)
	{
		if (pos1 <= strlen(m_str))
		{ 
			CheckCapacity(strlen(str.m_str));
			unsigned int i = 0;
			for (i = strlen(m_str);i >= strlen(m_str)-strlen(str.m_str)+1;i--)
			{
				m_str[i + strlen(str.m_str)] = m_str[i];
			}
			strncpy(m_str + pos1, str.m_str,strlen(str.m_str));
			m_sz += strlen(str.m_str);
		}
		return *this;
	}
	//��pos1λ�ò���str��pos2λ�ÿ�ʼ��n���ַ�
	String& insert(size_t pos1, const String& str, size_t pos2, size_t n)
	{
		if ((pos2 >= 0) && (pos2 <= strlen(str.m_str)) && (n <= strlen(str.m_str)))
		{ 
			CheckCapacity(n);
			unsigned int i = 0;
			//�����ƶ����ڵ��õ�insert������ʵ��
			for (i = 0;(i < n)&&str.m_str[pos2 + i];i++)
			{
				this->insert(pos1+i, str.m_str[pos2 + i]);
			}
		}
		return *this;
	}
	//��pos1λ�ò����ַ���s��ǰn���ַ�
	String& insert(size_t pos1, const char* s, size_t n)
	{
		if ((pos1 <= strlen(m_str)) && n <= strlen(s))
		{
			CheckCapacity(n);
			unsigned int i = 0;
			for (i = 0;(i < n) && s[i];i++)
			{
				this->insert(pos1 + i, s[i]);
			}
		}
		return *this;
	}
	//��pos1λ�ò����ַ���s
	String& insert(size_t pos1, const char* s)
	{
		if ((pos1 <= strlen(m_str)))
		{
			CheckCapacity(strlen(s));
			unsigned int i = 0;
			for (i = 0;(i < strlen(s)) && s[i];i++)
			{
				this->insert(pos1 + i, s[i]);
			}
		}
		return *this;
	}
	//��pos1λ�ò���n���ַ�c
	String& insert(size_t pos1, size_t n, char c)
	{
		if ((pos1 <= strlen(m_str)))
		{
			CheckCapacity(n);
			unsigned int i = 0;
			for (i = 0;i < n ;i++)
			{
				this->insert(pos1 + i, c);
			}
		}
		return *this;
	}
	String& operator+= (const String& str)
	{
		this->insert( strlen(str.m_str), str);
		return *this;
	}
	String& operator+= (const char* s)
	{
		this->insert(strlen(m_str), s);
		return *this;
	}
	String& operator+= (char c)
	{
		CheckCapacity(1);
		this->insert(strlen(m_str), c);
		return *this;
	}
	
private:
	void CheckCapacity(int count)
	{
		if (m_capacity <= m_sz + count)//��Ҫ����ռ�
		{
			int NewCapacity = 2 * m_capacity > (m_capacity + count+1)
				? 2 * m_capacity : (m_sz + count+1);
			char *tmp = new char[NewCapacity];
			//��ԭ���ռ�����ݿ�������
			strcpy(tmp,m_str);
			delete[] m_str;
			m_str = tmp;
			m_capacity = NewCapacity;
		}
	}
	//��pos1λ�ò����ַ�c
	String& insert(size_t pos1, char c)
	{
		unsigned int i = 0;
		for (i = strlen(m_str);i >= pos1;i--)
		{
			m_str[i + 1] = m_str[i];
		}
		m_str[pos1] = c;
		m_sz++;
		return *this;
	}
private:
	unsigned int m_sz;
	unsigned int m_capacity;
	char *m_str;
};
int main()
{
	{
		const char * str = "hello";
		char c = 'y';
		String str1("abcdef");
		str1.PushBack(" love");
		str1.erase(3,5);
		cout << str1 << endl;
		String str2;
		str2 = str1;
		cout << str2 << endl;
		//str2.insert(3, str1);
		//str2.insert(3,str1,2,3);
		//str2.insert(3,str,3);
		//str2.insert(3, str);
		str2.insert(3,10,c);
		cout << str2 << endl;
		String str3("hello");
		cout << str3 << endl;
		String str4("world");
		//str4 += str3;
		//str4 += str;
		//str4 += c;
		cout << str4 << endl;
	}
	system("pause");
	return 0;
}