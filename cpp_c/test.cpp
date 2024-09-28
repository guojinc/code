/*************************************************************************
  > File Name: test.cpp
  > Author: dascard
  > Mail: dascard601@gmail.com 
  > Created Time: Sat Aug 24 20:36:16 2024
 ************************************************************************/

#include <ios>
#include <iostream>


using namespace std;

int test();

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n = 4;
	for (int i = 0; i < n; i++)	
	{
		cout << i ;
	}
	cout << test() << endl;
	return 0;
}

int test()
{
	cout << "sss" << endl;
	return 0;
}

