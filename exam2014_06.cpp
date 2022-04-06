#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
bool check1(string &s){
    for (int i=0; i<s.length(); i++){
        if (s[i] == 'A'){
            if (s[i+2] != 'A' && s[i-2]!='A'){
                return 0;
            }
        }
        if (s[i] == '2'){
            if (s[i+3] != '2' && s[i-3]!='2'){
                return 0;
            }
        }
        if (s[i] == '3'){
            if (s[i+4] != '3' && s[i-4]!='3'){
                return 0;
            }
        }
        if (s[i] == '4'){
            if (s[i+5] != '4' && s[i-5]!='4'){
                return 0;
            }
        }
    }
    return 1;
}
bool check2(string &s){
	if (
		//s.rfind()从右向左找	s.find()从左向右找 
		s.rfind('A') - s.find('A') == 2 &&
		s.rfind('2') - s.find('2') == 3 &&
		s.rfind('3') - s.find('3') == 4 &&
		s.rfind('4') - s.find('4') == 5 &&
		){
		return 1;
	}else{
		return 0;
	}
}
int main(){
    string s = "223344AA";
    while(next_permutation(s.begin(), s.end())){
        //字符串字典序由小到大枚举函数,到最大return 1 
    	if(check2(s)){
    		cout <<s << endl;
		}  
    }
    return 0;
}