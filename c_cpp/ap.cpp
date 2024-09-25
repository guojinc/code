/*************************************************************************
	> File Name: ap.cpp
	> Author: dascard
	> Mail: dascard601@gmail.com 
	> Created Time: Mon Sep 23 14:47:05 2024
 ************************************************************************/
#include <memory>
#include <iostream>

using namespace std;

template <class T>
class C{
	public:
		explicit C(T a){
			cout << a << endl;
		}
		~C(){
			cout << "Object is destroyed" << endl;
		}
};


int main(){
	// auto_ptr<C<int>> ptr(new C(5));
	shared_ptr<C<int>> ptr(new C(5));
	unique_ptr<C<int>> ptr1(new C(5));

}
