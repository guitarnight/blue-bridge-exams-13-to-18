#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
using namespace std;

bool check(int a, int b){
    stringstream ss;				//头文件sstream 
    stringstream ss1;				//字符流不可重复使用 
    string aa, bb;
    ss << a;
    ss >> aa;
    ss1 << b;
    ss1 >> bb;
    sort(aa.begin(),aa.end());		//利用字符串排序比较出现的字符是否一致 
    sort(bb.begin(),bb.end());		//sorr字符串只要首尾地址 
    return aa==bb;
}
int func4(int a, int b, int c, int d){
    return a*1000+ b*100 + c*10 +d;
}
int func3(int a, int b, int c){
    return a*100+ b*10 + c;
}
int func2(int a, int b){
    return a*10 + b;
}
int main(){
    int ans= 0;
    for (int i=1; i<=9; i++){
        for (int j=0; j<=9; j++){
            for(int m=0; m<=9; m++){
                for (int n=1; n<=9; n++){
                    if (i!=j && i!=m && i!=n && j!=m && j!=n && m!=n){ 
                        if (check(func3(i,j,m)*n, func4(i,j,m,n))){
                        	cout << func3(i,j,m) <<"*"<<n << "==" << func3(i,j,m)*n << endl;
                            ans++;
                        }
						//千 * 个 必然没有重复 
                        if (check(func2(i,j)*func2(n,m), func4(i,j,m,n)) && func2(i,j)<func2(n,m)){
                        	cout << func2(i,j) <<"*"<<func2(n,m) << "==" << func2(i,j)*func2(n,m) << endl;
                            ans++;
                        }
                        //十 * 十 必然有重复，利用前面的十 大于或小于后面的十去重 
                    }
                }
            }
        }
    }
    cout <<ans << endl;
    return 0;
}