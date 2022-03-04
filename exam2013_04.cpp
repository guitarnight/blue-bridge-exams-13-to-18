#include <iostream>
using namespace std;
//0     1 25 69 8
//3 4 7
//
int func(int num){
    int tmp = num;
    int sum = 0;
    while(tmp>0){
        sum *= 10;
        //按规则反转
        if(tmp%10 == 0 || tmp%10 == 1 || tmp%10 == 8){
            sum += tmp%10;
        }else if(tmp%10 == 2){
            sum += 5;
        }else if(tmp%10 == 5){
            sum += 2;
        }else if(tmp%10 == 6){
            sum += 9;
        }else if(tmp%10 == 9){
            sum += 6;
        }else if(tmp%10 == 3 || tmp%10 == 4 || tmp%10 == 7){
            return 0;       //-200多 和 +800多  中间正好没有0，返回0不影响结果采纳
        }
        tmp /= 10;
    }
    return sum-num;
}
int main(){
    int a = 0, b =0;
    for (int a=1000; a<=9999; a++){
        for(int b=1000; b<=9999; b++){
            //事先排除错误情况，从根本剪枝
            if(a%10==0 || b%10==0){
                continue;
            }
            //注意所谓的亏损200多是-300 ~ -200  盈利800多是+800 ~ +900
            if (func(a)<-200 && func(a)>-300 && func(b)>800 && func(b)<900 && func(a)+func(b)==558){
                cout<<a<<" "<<b<<endl;
            }
        }
    }
    return 0;
}