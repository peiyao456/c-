#include"seqlist.h"

void SeqList:: CheckCapacity(int count)
{
	if (m_sz + count > m_capacity)//À©ÈÝ
	{
		int newCapacity = 0;
		do
		{
			newCapacity = m_capacity + 10;
		} while (newCapacity < m_sz + count);
		int *tmp = new int[newCapacity];
		memcpy(tmp,m_data,m_sz*sizeof(DataType));
		delete[] m_data;
		m_data = tmp;
		m_capacity = newCapacity;
	}
}

ostream& operator<<(ostream& os, const SeqList &l)
{
	int i = 0;
	for (i = 0;i < l.m_sz;i++)
	{
		os << *(l.m_data + i)<<" ";
	}
	return os;
}

SeqList::SeqList(DataType* data = nullptr,int sz = 0)
	:m_sz(sz)
	,m_capacity(0)
{
	m_data = new int[m_sz];
	memcpy(m_data,data,m_sz*sizeof(DataType));
	m_capacity = m_sz;
}

SeqList::~SeqList()
{
	if (m_data != nullptr)
	{
		delete[] m_data;
		m_data = nullptr;
	}
}

SeqList::SeqList(const SeqList& l)
	:m_data(new int[l.m_sz])
{
	//m_data = new int[l.m_sz];
	memcpy(m_data,l.m_data,l.m_sz*sizeof(DataType));
	m_sz = l.m_sz;
	m_capacity = l.m_capacity;
}

SeqList& SeqList:: operator=(const SeqList& l)
{
	delete[] m_data;
	m_data = new int[l.m_sz];
	memcpy(m_data, l.m_data, m_sz*sizeof(DataType));
	m_sz = l.m_sz;
	m_capacity = l.m_capacity;
	return *this;
}

void SeqList::PushBack(DataType x)
{
	CheckCapacity(1);
	m_data[m_sz] = x;
	m_sz++;
}

void SeqList::PopBack()
{
	if (m_sz != 0)
	{
		m_sz--;
	}
}

void SeqList:: PushFront(DataType x)
{
	CheckCapacity(1);
	int i = 0;
	for (i = m_sz;i >= 0;i--)
	{
		m_data[i + 1] = m_data[i];
	}
	m_data[0] = x;
	m_sz++;
}

void SeqList::PopFront()
{
	if (m_sz != 0)
	{
		int i = 0;
		for (i = 1;i < m_sz;i++)
		{
			m_data[i - 1] = m_data[i];
		}
		m_sz--;
	}
}

void SeqList::erase(int index)
{
	assert(index >= 0);
	assert(index <= m_sz);
	int i = 0;
	if (m_sz != 0)
	{
		for (i = index + 1;i < m_sz;i++)
		{
			m_data[i - 1] = m_data[i];
		}
		m_sz--;
	}
}

void SeqList::Remove(DataType x)
{
	if (m_sz != 0)
	{
		int i = 0;
		for (i = 0;i < m_sz;i++)
		{
			if (m_data[i] == x)
			{
				for (i = i + 1;i < m_sz;i++)
				{
					m_data[i - 1] = m_data[i];
				}
				break;
			}
		}
		m_sz--;
	}
}

void SeqList::RemoveAll(DataType x)
{
	if (m_sz != 0)
	{
		int i = 0;
		for (i = 0;i < m_sz;i++)
		{
			if (m_data[i] == x)
			{
				Remove(x);
				m_sz--;
			}
		}
	}
}

void SeqList::bottleSort()
{
	if (m_sz != 0)
	{
		int i = 0;
		int j = 0;
		int flag = 0;
		for (i = 0;i < m_sz;i++)
		{
			flag = 1;
			for (j = 0;j < m_sz - i - 1;j++)
			{
				if (m_data[j] > m_data[j + 1])
				{
					DataType tmp = m_data[j];
					m_data[j] = m_data[j+1];
					m_data[j + 1] = tmp;
					flag = 0;
				}
			}
			if (flag == 1)
				break;
		}
	}
}

void SeqList::selectSort()
{
	if (m_sz != 0)
	{
		int i = 0;
		int j = 0;
		int min = 0;
		int k = 0;
		for (i = 0;i < m_sz-1;i++)
		{
		    k = i;
			for (j = i ;j < m_sz;j++)
			{
				min = i;
				if (m_data[j ] < m_data[min])
				{
					min = j;
				}
			}
			if (m_data[min] != m_data[k])
			{
				int tmp = m_data[min];
				m_data[min] = m_data[k];
				m_data[k] = tmp;
			}
		}
	}
}

void SeqList::insertSort()
{
	if (m_sz != 0)
	{
		int i = 0;
		int j = 0;
		for (i = 1;i < m_sz;i++)
		{
			int tmp = m_data[i];
			for (j = i - 1;(j >= 0) && (m_data[j] > tmp);j--)
			{
				m_data[j + 1] = m_data[j];
			}
			m_data[j + 1] = tmp;
		}
	}
}