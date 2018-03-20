#pragma once
#include <iostream>
#include <time.h>
#include "Polinom.h"
#include <string>

using namespace std;

volatile int mas[10000];

int main()
{
	TMonom M1[] = {	
					{7,5,3,6},
					{3,4,8,9},
					};
	TMonom M2[] = {	{4,8,6,1},
					{3,4,1,1},
					{3,2,8,9},
					};

	TMonom M4[] = {
					{7,2,3,6},
					{3,4,8,9},
					};

	TMonom M3 = {4,4,8,1};


	Polinom qw(M1,2);
	Polinom aw(M4,2);

	//Polinom q1(aw);
	//Polinom q2(q1);
	//Polinom q3(q2);

	

	Polinom zw;
	zw = qw - aw;
	cout << endl << zw;



	//добавление по порядку первого с нулевым коэф



	system("pause");
	return 0;
}