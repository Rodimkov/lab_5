#include <iostream>
#include "TList.h"
#include <time.h>

using namespace std;

int main()
{
	TList<int> a;
	int tmp;
	srand(time(NULL));
	for ( int i = 0 ; i < 30 ; i++ ) 
	{
		tmp = rand();
		a.Reset();
		while( !a.isEnd() && a.Getcurr() < tmp )
			a.GoNext();
		a.inscurr(tmp);
	}
		
	for(a.Reset();!a.isEnd();a.GoNext())
		cout << a.Getcurr() << "  ";

	system("pause");
	return 0;
}