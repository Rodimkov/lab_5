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
	void Reset();
	//void GoNext();
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
/*
template <class T>
void THeadList<T>::GoNext()
{
	if(pCurr == pStop)
		pPrew = pStop;
	else
	if( pCurr == pLast)
	{
		pPrew = pCurr;
		pCurr = pStop;
	}else
	{
		pPrew = pCurr;
		pCurr = pCurr->pNext;
	}
	pos++;
}*/
template <class T>
void THeadList<T>::Reset()
{
	if(pFirst == NULL)
	{
		pCurr = pStop;
		pPrew = pLast;
		pos = -1;
	}
	else
	{
	pCurr = pFirst;
	pPrew = pStop;
	pos = 0;
	}
}