
template <class T>
struct TLink
{
	T value;
	TLink *pNext; 
};

template <class T>
class TList
{
private:
	int size,pos;
	TLink<T> *pFirst, *pNew, *pCurr, *pLast, *pStop , *pPrew;
public:
	TList();
	~TList();
	void insfirst(T el);
	void inslast(T el);
	void inscurr(T el);
	void Reset();
	void GoNext();
	bool isEnd();
	void Delfirst();
	void Delcurr();
	T Getcurr();
};


template <class T>
TList<T>::TList()
{
	pFirst = pNew = pLast = pStop = pCurr = pPrew = NULL;
	pos = -1;
	size = 0;
}

template <class T>
TList<T>::~TList()
{
	for(Reset();!isEnd();GoNext())
		Delfirst();
}

template <class T>
void TList<T>::insfirst(T el)
{
	TLink<T> *tmp = new TLink<T>;
	tmp->value = el;
	tmp -> pNext = pFirst;
	if(pFirst == pStop)
	{
		pLast = pFirst = tmp;
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
void TList<T>::inslast(T el)
{	
	TLink<T> *tmp = new TLink<T>;
	tmp->value = el;
	tmp -> pNext = pStop;
	if(pFirst == pStop)
	{
		pLast = pFirst = tmp;
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
void TList<T>::inscurr(T el)
{
	if(pCurr == pFirst )
		insfirst(el);
	else if(pCurr == pStop)
		inslast(el);
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
void TList<T>::Reset()
{
	pCurr = pFirst;
	pPrew = pStop;
	pos = 0;
}

template <class T>
void TList<T>::GoNext()
{
	pPrew = pCurr;
	pCurr = pCurr->pNext;
	pos++;
}

template <class T>
bool TList<T>::isEnd()
{
	return pCurr == pStop;
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
		pos--;
	}
	size--;
}

template <class T>
void TList<T>::Delcurr()
{
	if(pos == 1)
	{
		delete pCurr;
		pFirst = pNew = pLast = pCurr = pPrew = pStop;
	}
	else if( pos > 1)
	{
		TLink *tmp = pCurr;
		pCurr = pCurr->pNext;
		pPrew -> pNext = pCurr;
		delete tmp;
		pos--;
	}
	size--;
}

template <class T>
T TList<T>::Getcurr()
{
	if(pCurr == pStop)
		throw -1;
	return pCurr->value;
}
