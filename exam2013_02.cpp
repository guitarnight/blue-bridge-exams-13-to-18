#include <iostream>
using namespace std;
int func(long long a, long long b){
    int numa[10] = {0};
    for(int i=0; i<10; i++){
        numa[i] = 0;
    }	
    while(a>0){							//最高位肯定不是0所以>0
    	numa[a%10]++;
    	if (numa[a%10] == 2){			//好好审题，看好要求，确定每一步操作在已经满足条件下实施 
            return 0;
        }
    	a/=10;							 
	}
	while(b>0){
		if (numa[b%10] == 1){
            return 0;
        }
    	b /= 10;   
	}
    return 1;
}
int main(){
    long long num = 102345;             //最小不重复六位数开始算起
    for(num; num<=987654; num++){
        long long res = num*num; 
        if (func(num,res) == 1){
            cout<<num<<endl;
        }
    }
    return 0;
}