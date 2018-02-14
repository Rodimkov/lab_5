#pragma once
#include <iostream>
#include "THeadList.h"

struct TMonom
{
	double coeff;
	int x,y,z;
};

bool operator==(const TMonom &t1,const TMonom &t2)
{
	 if(t1.x*100 + t1.y*10 + t1.z == t2.x*100 + t2.y*10 + t2.z)
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
	 if(t1.x*100 + t1.y*10 + t1.z < t2.x*100 + t2.y*10 + t2.z)
	 return true;
	 else return false;
}


class Polinom : public THeadList<TMonom> 
{
public:
	Polinom(void);
	Polinom(TMonom *tmp,int size);
	~Polinom(void);
	Polinom& operator=(Polinom &tmp);
	Polinom operator+(Polinom &tmp);
	void Insbyorder(const TMonom &tmp);
	friend std::ostream& operator<<(std::ostream& os,const Polinom &tmp);
};

