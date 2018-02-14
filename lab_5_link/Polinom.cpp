#include "Polinom.h"


Polinom::Polinom(void):THeadList()
{
	pHead->value.coeff = 0;
	pHead->value.z=-1;
}

Polinom::Polinom(TMonom *tmp,int size):THeadList()
{
	pHead->value.coeff = 0;
	pHead->value.z=-1;
	for (int i =0;i<size; i++)
	{
		InsLast(tmp[i]);
	}
}

Polinom::~Polinom(void)
{
}

void Polinom::Insbyorder(const TMonom &tmp)
{
	for(Reset();!isEnd();GoNext())
	{
		if(pCurr->value ==tmp)
		{
			pCurr->value.coeff +=tmp.coeff;
			if (pCurr->value.coeff == 0)
			{
				Delcurr();
				return;
			}
		}
		if(pCurr->value < tmp)
		{
			InsCurr(tmp);
			return;
		}
		InsLast(tmp);
	}
}

Polinom& Polinom::operator=(Polinom &tmp)
{
	if(&tmp == this)
		return *this;
	else
	{
		Reset();
		for(tmp.Reset();!tmp.isEnd();tmp.GoNext())
		{
			InsCurr(tmp.pCurr->value);
		}
	}
}

Polinom Polinom::operator+(Polinom &tmp)
{
	Polinom res;
	Reset();
	tmp.Reset();
	while (!isEnd() || tmp.isEnd())
	{
		if(pCurr->value == tmp.pCurr->value)
		{
			res.pCurr->value.coeff = pCurr->value.coeff + tmp.pCurr->value.coeff;
			if(res.pCurr->value.coeff == 0)
			{
				Delcurr();
			
				tmp.GoNext();
			}else
			{
				GoNext();
				tmp.GoNext();
			}
		}else if(pCurr->value < tmp.pCurr->value)
		{
			InsCurr(tmp.pCurr->value);
			tmp.GoNext();
		}else
			GoNext();
	}
	return res;
}

std::ostream& operator<<(std::ostream& os,Polinom &tmp)
{
	for(tmp.Reset();!tmp.isEnd();tmp.GoNext())
	os << tmp.pCurr->value.coeff << '*' << "x^" << tmp.pCurr->value.x << "y^"  << tmp.pCurr->value.y << "z^" << tmp.pCurr->value.z;  
	return os;
}
