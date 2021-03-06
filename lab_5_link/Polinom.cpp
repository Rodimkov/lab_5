#include "Polinom.h"

bool operator==(const TMonom &t1,const TMonom &t2)
{

	 if((t1.x*100 + t1.y*10 + t1.z) == (t2.x*100 + t2.y*10 + t2.z))
	 return true;
	else return false;
}

bool operator>(const TMonom &t1,const TMonom &t2)
{
	 if(t1.x*100 + t1.y*10 + t1.z > t2.x*100 + t2.y*10 + t2.z)
	 return true;
	 else return false;
}

bool operator<(const TMonom &t1,const TMonom &t2)
{
	 if((t1.x*100 + t1.y*10 + t1.z) < (t2.x*100 + t2.y*10 + t2.z))
	 return true;
	 else return false;
}


Polinom::Polinom(void):THeadList()
{
	pHead->value.coeff = 0;
	pHead->value.x=-1;
	pHead->value.y=-1;
	pHead->value.z=-1;
}

Polinom::Polinom(TMonom *tmp,int size):THeadList()
{
	pHead->value.coeff = 0;
	pHead->value.x=-1;
	pHead->value.y=-1;
	pHead->value.z=-1;
	for (int i = 0; i < size ; i++)
	{
		Insbyorder(tmp[i]);
	}
}

Polinom::Polinom(Polinom &tmp):THeadList()
{
	pHead->value.coeff = 0;
	pHead->value.x=-1;
	pHead->value.y=-1;
	pHead->value.z=-1;
	for(tmp.Reset();!tmp.isEnd(); tmp.GoNext() )
	{
		InsCurr(tmp.Getcurr());
		GoNext();
	}
}

Polinom::~Polinom(void)
{

}

void Polinom::Insbyorder(const TMonom &tmp)
{
	for(Reset();!isEnd();GoNext())
	{
		if(pCurr->value == tmp)
		{
			pCurr->value.coeff += tmp.coeff;
			if (pCurr->value.coeff == 0)
			{
				Delcurr();
				return;
			}
		return;
		}
		if(pCurr->value < tmp)
		{
			InsCurr(tmp);
			return;
		}

	}
	InsLast(tmp);
}

Polinom& Polinom::operator=(Polinom &tmp)
{
	if(&tmp == this)
		return *this;
	else
	{
		for(Reset();!isEnd();)
		{
			Delfirst();
		}

		Reset();
		for(tmp.Reset();!tmp.isEnd();tmp.GoNext())
		{
			InsCurr(tmp.pCurr->value);
			GoNext();
		}
	}
	return *this;
}

Polinom Polinom::operator+(Polinom &tmp)
{
	Polinom res;
	Reset();
	tmp.Reset();
	while ((!isEnd()) || (!tmp.isEnd()))
	{
		if(pCurr->value == tmp.pCurr->value)
		{
 			res.InsCurr(pCurr->value);
			res.pCurr->value.coeff += tmp.pCurr->value.coeff;
			if(res.pCurr->value.coeff == 0)
			{
				res.Delcurr();
				tmp.GoNext();
				GoNext();
			}else
			{
				res.GoNext();
				GoNext();
				tmp.GoNext();
			}
		}
		else if(pCurr->value > tmp.pCurr->value)
			{
				/*res.GoNext();
				res.InsCurr(tmp.pCurr->value);
				tmp.GoNext();
				res.GoNext();
				//res.GoNext();*/
				res.InsCurr(pCurr->value);
				GoNext();
				res.GoNext();
				//res.GoNext();
			}
		else
		{
				/*res.GoNext();
				res.InsCurr(pCurr->value);
				GoNext();
				res.GoNext();
				//res.GoNext();*/
				res.InsCurr(tmp.pCurr->value);
				tmp.GoNext();
				res.GoNext();
				//res.GoNext();
		}
	}
	return res;
}


Polinom Polinom::operator*(TMonom & tmp)
{
	Polinom res;
	Reset();
	while ((!isEnd()))
	{
			res.InsCurr(pCurr->value);
			res.pCurr->value.coeff *= tmp.coeff;
			res.pCurr->value.x += tmp.x;
			res.pCurr->value.y += tmp.y;
			res.pCurr->value.z += tmp.z;
			if(res.pCurr->value.coeff == 0)
			{
				res.Delcurr();
			}
			else
			{
				res.GoNext();
				GoNext();
			}
	}
	return res;
}

Polinom Polinom::operator*(Polinom &tmp)
{
	Polinom res;
	Reset();
	tmp.Reset();
	while ((!isEnd()) || (!tmp.isEnd()))
	{
		res = res + (*this)*tmp.pCurr->value;
		//GoNext();
		tmp.GoNext();
	}


	return res;
}

std::ostream& operator<<(std::ostream& os,Polinom &tmp)
{
	for(tmp.Reset();!tmp.isEnd();)
	{
		os << tmp.pCurr->value.coeff << '*' << "x^" << tmp.pCurr->value.x << '*' << "y^" << tmp.pCurr->value.y << '*' << "z^" << tmp.pCurr->value.z; 
		tmp.GoNext();
		if( !tmp.isEnd() ) 
			os << "+";
	}

	return os;
}

std::istream& operator>>(std::istream& is,Polinom &tmp)
{
	TMonom Temp;
	is >> Temp.coeff >> Temp.x >> Temp.y >> Temp.z;
	tmp.Insbyorder(Temp);
	return is;
}


Polinom Polinom::operator-(Polinom & tmp)
{
	TMonom M3 = {-1,0,0,0};
	Polinom temp(&M3,1);
	Polinom res;
	res = (*this) + (temp * tmp);
	return res;
}