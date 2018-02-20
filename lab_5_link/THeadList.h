#pragma once
#include "TList.h"

template <class T>
class THeadList : public TList<T>
{
protected:
	TLink<T> *pHead;
public:
	THeadList();
	~THeadList();
	void InsFirst(T a);
	void Delfirst();
	//bool isEnd();
};

template <class T>
THeadList<T>::THeadList():TList()
{
	pHead = new TLink<T>;
	pStop = pHead;
	pHead->pNext = pFirst;
}

template <class T>
THeadList<T>::~THeadList()
{
	TList::~TList();	
	delete pHead;
}

template <class T>
void THeadList<T>::InsFirst(T a)
{
	TList::InsFirst(a);
	pHead->pNext = pFirst;
}

template <class T>
void THeadList<T>::Delfirst()
{
	TList::Delfirst();
	pHead->pNext = pFirst;
}
/*
template <class T>
bool THeadList<T>::isEnd()
{
	return pCurr == p;
}*/