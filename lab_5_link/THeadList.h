#pragma once
#include "TList.h"

template <class T>
class THeadList : public TList<T>
{
protected:
	TLink<T> *pHead;
public:
	THeadList():TList()
	{
		pHead = new TLink<T>;
		pStop = pHead;
		pHead->pNext = pFirst;
	}
	~THeadList()
	{
		TList::~TList();
		delete pHead;
	}
	void insfirst(T a)
	{
		TList::insfirts(a);
		pHead->pNext = pFirst;
	}
	void Delfirst()
	{
		TList::Delfirst();
		pHead->pNext = pFirst;
	}
};