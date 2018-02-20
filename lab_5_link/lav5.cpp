#pragma once
#include <iostream>
#include <time.h>
#include "Polinom.h"
using namespace std;

int main()
{
	TMonom q = {5,5,5,5};
	TMonom a = {10,10,10,10};

	Polinom qw(&q,1);
	Polinom aw(&a,1);

	qw.Del();
	Polinom zx =  qw + aw;
	cout << zx;




	system("pause");
	return 0;
}