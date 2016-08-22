#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#include<iostream>
#include<cassert>
using namespace std;
typedef int DataType ;
class SeqList
{
	friend ostream& operator<<(ostream& os,const SeqList &l);
public:
	SeqList(DataType* data,int sz);
	~SeqList();
	SeqList(const SeqList& l);
	SeqList& operator=(const SeqList& l);
	void PushBack(DataType x);
	void PopBack();
	void PushFront(DataType x);
	void PopFront();
	void erase(int index);
	void Remove(DataType x);
	void RemoveAll(DataType x);
	void bottleSort();
	void selectSort();
	void insertSort();
private:
	void CheckCapacity(int count);
private:
	int m_sz;
	int m_capacity;
	DataType* m_data;
};
#endif//__SEQLIST_H__