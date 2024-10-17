/*************************************************************************
	> File Name: test2.cpp
	> Author: dascard
	> Mail: dascard601@gmail.com 
	> Created Time: Sat Aug 24 23:21:23 2024
 ************************************************************************/

#include<iostream>
#include <numeric>
#include <vector>
using namespace std;

int main()
{
		
	vector<int> v(10);
	iota(v.begin(), v.end(), 1);

	for (auto it : v)
	{
		cout << it << endl;
	}
	return 0;
}
