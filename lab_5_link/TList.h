#include <iostream>
template <class T>
struct TLink
{
	T value;
	TLink *pNext; 
};

template <class T>
class TList
{
public:
	int size,pos;
	TLink<T> *pFirst, *pNew, *pCurr, *pLast, *pStop , *pPrew;
public:
	TList();
	~TList();
	virtual void InsFirst(T el);
	void InsLast(T el);
	void InsCurr(T el);
	void Reset();
	virtual void GoNext();
	virtual	bool isEnd();
	virtual void Delfirst();
	void Delcurr();
	void Dellast();
	T Getcurr();
	void SetCurr(int k);
	void Del();
};


template <class T>
TList<T>::TList()
{
	pFirst = pNew = pLast = pCurr = pPrew = pStop = NULL;
	pos = -1;
	size = 0;
}

template <class T>
TList<T>::~TList()
{
	for (int i = 0; i < size;i++)
		Delfirst();
}

template <class T>
void TList<T>::Del()
{
	for (int i = 0; i < size;i++)
		Delfirst();
}


template <class T>
void TList<T>::InsFirst(T el)
{
	TLink<T> *tmp = new TLink<T>;
	tmp->value = el;
	tmp -> pNext = pFirst;
	if(pFirst == pStop || pFirst == NULL )
	{
		pLast = pFirst = tmp;
		pLast -> pNext = pStop;
		pos = 0;
	}
	else
	{
		pFirst = tmp;
		pos++;
	}
	size++;
}

template <class T>
void TList<T>::InsLast(T el)
{	
	TLink<T> *tmp = new TLink<T>;
	tmp->value = el;
	tmp->pNext = pStop;
	if(pFirst == pStop || pFirst == NULL )
	{
		pLast = pFirst = tmp;
		pLast -> pNext = pStop;
		pos = 0;
	}
	else
	{
		pLast->pNext = tmp;
		pLast = tmp;
		pos++;
	}
	size++;
}

template <class T>
void TList<T>::InsCurr(T el)
{
	if(pCurr == pFirst)
	{
		InsFirst(el);
		pCurr = pFirst;
		pos = 0;
	}
	else if(pCurr == pStop)
	{
		InsLast(el);
		pCurr = pLast;
		pos = size - 1 ;
	}
	else
	{
		TLink<T> *tmp = new TLink<T>;
		tmp->value = el;
		tmp -> pNext = pCurr;
		pPrew->pNext = tmp;
		pCurr = tmp;
		size++;
	}
}


template <class T>
void TList<T>::Delfirst()
{
	if(size == 1)
	{
		delete pFirst;
		pFirst = pNew = pLast = pCurr = pPrew = pStop;
	}
	else if (size > 1)
	{
		TLink<T> *tmp = pFirst;
		pFirst = pFirst -> pNext;
		delete tmp;
	}
	size--;
}

template <class T>
void TList<T>::Delcurr()
{
	if(size == 1)
	{
		delete pCurr;
		pFirst = pNew = pLast = pCurr = pPrew = pStop = NULL;
	}
	else if( pos == 0)
	{
		Delfirst();
		pPrew = pStop;
		pCurr = pFirst;
	}
	else
	{
		TLink<T> *tmp = pCurr;

		pPrew->pNext = pCurr;

		pCurr = pCurr->pNext;
		delete tmp;
	}
	size--;
}

template <class T>
void TList<T>::Dellast()
{
	TLink<T> *temp = pPrew;
	TLink<T> *tmp = pCurr;

	for(Reset();!isEnd;GoNext());
		Delcurr();

	pPrew = temp;
	pCurr = tmp;
}

template <class T>
T TList<T>::Getcurr()
{
	if(pCurr == pStop)
		throw -1;
	return pCurr->value;
}

template <class T>
void TList<T>::SetCurr(int k)
{
	for(Reset();pos < k; GoNext() );
}

template <class T>
void TList<T>::Reset()
{
	pCurr = pFirst;
	pPrew = pStop;
	pos = 0;
}

template <class T>
void TList<T>::GoNext()
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
}

template <class T>
bool TList<T>::isEnd()
{
	return (pCurr == pStop) || (pCurr == NULL);
}
