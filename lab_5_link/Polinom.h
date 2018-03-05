#pragma once
#include <iostream>
#include "THeadList.h"

struct TMonom
{
	double coeff;
	int x,y,z;
};

bool operator==(const TMonom &t1,const TMonom &t2);
bool operator>(const TMonom &t1,const TMonom &t2);
bool operator<(const TMonom &t1,const TMonom &t2);



class Polinom : public THeadList<TMonom> 
{
public:
	Polinom(void);
	Polinom(Polinom &tmp);
	Polinom(TMonom *tmp,int size);
	~Polinom(void);
	Polinom& operator=(Polinom &tmp);
	Polinom operator+(Polinom &tmp);
	Polinom operator-(Polinom &tmp);
	Polinom operator*(TMonom &tmp);
	Polinom operator*(Polinom &tmp);


	void Insbyorder(const TMonom &tmp);
	friend std::ostream& operator<<(std::ostream& os,Polinom &tmp);
	friend std::istream& operator>>(std::istream& is,Polinom &tmp);

};

