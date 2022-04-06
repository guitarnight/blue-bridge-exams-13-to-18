#include <iostream>
using namespace std;

int main(){
    int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int y = 2014, m = 10, d = 9;
    //11月放置，数组下标为10
    for (int i=1; i<=1000; i++){
        if (y %400==0 || (y%4==0 && y%100!=0)){
            month[1] = 29;
        }else{
            month[1] = 28;
        }
        d++;
        if (d == month[m]+1){
            d = 1;
            m++;
        }
        if (m == 12){
            m = 0;
            y++;
        }
    }
    cout <<y <<"-"<<m+1<<"-"<<d<<endl;
    return 0;
}