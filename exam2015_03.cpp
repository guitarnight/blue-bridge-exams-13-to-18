#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <set>
using namespace std;
//法一:permutation
bool check1(int a, int b){
    stringstream ss, ss1;
    string s1, s2;
    ss << a;
    ss >> s1;
    ss1 << b;
    ss1 >> s2;
    
    string tmp = s1 + s2;
    //prev_permutation(tmp.begin(), tmp.end());降序 
    while(next_permutation(tmp.begin(), tmp.end())){
    	//调用一次重排列一次，全升序return false; 
	}
    return tmp == "0123456789";
}
//法二:set<char>
bool check2(int a, int b){
	stringstream ss, ss1;
    string s1, s2;
    ss << a;
    ss >> s1;
    ss1 << b;
    ss1 >> s2;
    
    string tmp = s1 + s2;
    
    set<char> st;
	for (int i=0; i<tmp.length(); i++){
		st.insert(tmp[i]);
	}
	//set 去重+限长 
	return tmp.length()==10 && st.size()==10;
} 
int main(){
    for(int i=1; i<=100; i++){
        if (check2(i*i, i*i*i)){\
            cout << i << endl;
            break;
        }
    }
    return 0;
}