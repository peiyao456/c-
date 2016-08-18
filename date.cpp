#include<iostream>
#include<cstdio>
using namespace std;

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		:m_year(year)
		, m_month(month)
		, m_day(day)
	{
		if (IsCorrectDate())
		{
			m_year = 1900;
			m_month = 1;
			m_day = 1;
		}
	}
	void Display()const
	{
		cout << m_year << "-" << m_month << "-" << m_day << endl;
	}
public:
	bool IsCorrectDate()
	{
		if ((m_year < 1) || ((m_month < 1) || (m_month>12)) || (m_day<1) || (m_day>DaysOfMonth(*this)))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int DaysOfMonth(const Date &d)const
	{
		static int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (d.m_month == 2)
		{
			return arr[d.m_month] + IsLeap(d);
		}
		else
		{
			return  arr[d.m_month];
		}
	}
	int IsLeap(const Date &d)const
	{
		if (((d.m_year % 4 == 0) && (d.m_year % 100 != 0)) || (d.m_year % 400 == 0))
			return 1;
		else return 0;
	}
	bool operator==(const Date & d)
	{
		if ((m_year == d.m_year) && (m_month == d.m_month) && (m_day == d.m_day))
			return true;
		else
			return false;
	}
	Date operator+(int count)
	{
		Date tmp(*this);
		tmp.m_day += count;
		//校正日期
		ToCorrectDate(tmp);
		return tmp;
	}
	Date operator-(int count)
	{
		Date tmp(*this);
		tmp.m_day -=  count;
		//校正日期
		ToCorrectDate(tmp);
		return tmp;
	}

	void ToCorrectDate(Date &d)
	{
		if (d.m_day <= 0)
		{
			while (d.m_day <= 0)
			{
				d.m_month--;
				if (d.m_month < 1)
				{
					d.m_year--;
					d.m_month = 12;
				}
				d.m_day += DaysOfMonth(d);
			}
		}
		else 
		{
			while (d.m_day > DaysOfMonth(d))
			{
				(d.m_day) -= DaysOfMonth(d);
				d.m_month++;
				if (d.m_month > 12)
				{
					d.m_year++;
					d.m_month = 1;
				}
			}
		}
	}
	int operator-(Date d)
	{
		Date tmp;
		int count = 0;
		if (d > *this)
		{
			tmp = *this;
		}
		else
		{
			tmp = d;
			d = *this;//大日期在d中存储，小日期在tmp中
		}
		while (tmp  != d)
		{
			count++;
			tmp = tmp + 1;
		}
		return count;
	}
	bool operator>(Date& d)const
	{
		if (m_year > d.m_year)
		{
			return true;
		}
		else if (m_year == d.m_year)
		{
			if (m_month > d.m_month)
			{
				return true;
			}
			else if (m_month == d.m_month)
			{
				if (m_day > d.m_day)
				{
					return true;
				}
			}
		}
		else
			return false;
	}
	bool operator!=(Date &d)
	{
		return !(*this == d);
	}
	void showMonth()const
	{
		cout << "日 一 二 三 四 五 六 " << endl;
		int year = 0;
		int month = 0;
		//w = y + [y / 4] + [c / 4] - 2c + [26(m + 1) / 10] + d - 1
		if ((m_month == 1) || (m_month == 2))
		{
			year = m_year - 1;
			month = m_month + 12;
		}
		else
		{
			year = m_year ;
			month = m_month ;
		}
		int w = year % 100 + (year % 100 / 4) + (year / 400) - 2 * (year / 100) + (26 * (month + 1) / 10) ;
		//cout << (w % 7) << endl;
		for (int i = 0; i < (w % 7);i++)
		{
			cout << "   ";
		}
		for (int i = 0; i < 7 - (w % 7);i++)//处理第一行
		{
			//cout << (i+1)<<" ";
			printf("%2d ",i+1);
		}
		cout << endl;
		for (int i = 7 - (w % 7);i < DaysOfMonth(*this);i++)
		{
			//cout << (i + 1) << " ";
			printf("%2d ", i + 1);
			if ((i + 1 + w % 7) % 7 == 0)
			{
				cout << endl;
			}
		}
		cout << endl;
	}
private:
	int m_year;
	int m_month;
	int m_day;
};
void menu()
{
	cout << "##################################" << endl;
	cout << "--------欢迎使用此万年历----------" << endl;
	cout << "-----------1.日期加天数-----------" << endl;
	cout << "-----------2.日期减天数-----------" << endl;
	cout << "-----------3.日期减日期-----------" << endl;
	cout << "-----------4.打印某月的日历-------" << endl;
	cout << "-----------0.退出-----------------" << endl;
	cout << "##################################" << endl;
}
int main()
{
	int choose = 1;
	int year = 0;
	int month = 0;
	int day = 0;
	int count = 0;
	while (choose)
	{
		menu();
		cout << "请选择>:";
		cin >> choose;
		switch (choose)
		{
		case 0:
			break;
		case 1:
		{
			cout << "请输入日期>:";
			cin >> year >> month >> day;
			Date d(year, month, day);
			cout << "请输入间隔天数>:";
			cin >> count;
			d = d + count;
			d.Display();
			break;
		}
		case 2:
		{
			cout << "请输入日期>:";
			cin >> year >> month >> day;
			Date d(year, month, day);
			cout << "请输入间隔天数>:";
			cin >> count;
			d = d - count;
			d.Display();
			break;
		}
		case 3:
		{
			cout << "请输入第一个日期>:";
			cin >> year >> month >> day;
			Date d1(year, month, day);
			cout << "请输入第二个日期>:";
			cin >> year >> month >> day;
			Date d2(year, month, day);
			int count = d1 - d2;
			cout << count << endl;
			break;
		}
		case 4:
		{
			cout << "请输入要打印的月份" << endl;
			cin >> year >> month;
			Date d(year, month);
			d.showMonth();
			break;
		}
		default:
		{
			cout << "选择错误" << endl;
			break;
		}
		}
	}
	system("pause");
	return 0;
}