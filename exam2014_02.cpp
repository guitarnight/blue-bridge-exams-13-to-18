#include <iostream>
#include <cmath>
using namespace std;

int main(){
	//2 ^ n	
	cout << pow(2,10) + 1 << endl;
	//2 * 2 ^ (n-1)
	cout << ((2<<(10-1))+ 1) << endl;
	//1 * 2 ^ n
	cout << ((1 << 10) + 1) << endl;
	// << 左右移动运算符优先级低于 + - * / 
    return 0;
}