#include <iostream>
using namespace std;
char* prefix(char *haystack, char* needstack){
    char *a = haystack;         //长串
    char *b = needstack;        //短串
    while(*a && *b){
        if (*(a++) != *(b++)){
            return NULL;
        }
    }
    if(*b){						//串末尾是 0 
        return NULL;
    }
    return haystack;
}
int main(){
    char *a = "abcde";
    char *b = "abc";
    char *c = "";
    char *d = "not";
    //cout<<prefix("abcd","d")<<endl;	停止所有输出 
    //cout<<NULL<<endl;					输出0 
	cout<<prefix(a, b)<<endl;
    cout<<prefix(a, c)<<endl;
    cout<<prefix(a, d)<<endl;
    return 0;
}