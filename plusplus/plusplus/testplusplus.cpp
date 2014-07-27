#include "testplusplus.h"
#include <iostream>

using namespace std;
void main()

{
	int sum=0;
	for(int i=0;i<10 ;i++)
	{
		sum=sum++;
	}
	cout << sum << endl;

}