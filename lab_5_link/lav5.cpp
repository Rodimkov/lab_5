#pragma once
#include <iostream>
#include <time.h>
#include "Polinom.h"
using namespace std;

volatile int mas[10000];

int main()
{
	TMonom M1[] = {	{5,7,5,15},
					{3,4,8,9},
					{4,7,8,1},
					{7,5,3,6},
					};
	TMonom M2[] = {	{4,4,8,1},
					{3,4,1,1},
					{4,2,8,1},
					{1,5,8,6},
					};

	Polinom qw(M1,4);
	Polinom aw(M2,4);

	//Polinom q1(aw);
	//Polinom q2(q1);
	//Polinom q3(q2);


	//cout << aw << endl << q1 << endl << q2 << endl << q3 << endl ;

	Polinom zw = qw * aw;
	cout << endl << zw;



	



	system("pause");
	return 0;
}