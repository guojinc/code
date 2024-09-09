/*************************************************************************
  > File Name: test.cpp
  > Author: dascard
  > Mail: dascard601@gmail.com 
  > Created Time: Sat Aug 24 20:36:16 2024
 ************************************************************************/

#include <iostream>


using namespace std;

int test();

/* class t{ */
/* 	public void func(int n) */
/* 	{ */
/* 		for (int i = 0; i < n; i++) */
/* 		{ */	
/* 			cout << i << endl; */
/* 		} */
/* 	} */
/* }; */

int main()
{
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

