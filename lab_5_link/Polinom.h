#pragma once
#include "THeadList.h"

struct TMonom
{
	double coeff;
	int x,y,z;
};


class Polinom : public THeadList<TMonom> 
{
public:
	Polinom(void);
	~Polinom(void);
};

