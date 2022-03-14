#include <iostream>
#include <sstream>          //istringstream分割类型 stringstream输入输出类型 头文件
#include <string.h>         //memset(begin,val,size)函数头文件
#include <algorithm>        //sort(begin,end,compare)函数头文件
#include <string>           //getline(i（string）stream,string,（parting）)函数头文件
using namespace std;
void s2i(string &s, int &num){
    stringstream ss;                //stringstream搭配>> <<用于类型转换
    ss << s;
    ss >> num;
}
int main(){
    int arr[10000] = {0};
    memset(arr,0,sizeof(arr));
    int idx = 0;

    int n = 0;
    cin >> n;
    getchar();
    for(int i=0; i<n; i++){
        string s1;
        getline(cin, s1);
        istringstream s2(s1);       //istringstream搭配while(getline(istringstream, string, parting))用于分割字符串
        string tmp = "";
        while(getline(s2,tmp,' ')){
            s2i(tmp,arr[idx++]);
        }
    }
    sort(arr, arr+idx);
    int a = 0, b = 0;
    for(int i=0; i<idx; i++){
        if (arr[i]+2 == arr[i+1]){
            a = arr[i]+1;
        }
        if (arr[i] == arr[i+1]){
            b = arr[i];
        }
    }
    cout << a<< " "<< b <<endl;
    return 0;
}