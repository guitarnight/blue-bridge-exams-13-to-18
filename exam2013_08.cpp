#include <iostream>
#include <set>
using namespace std;

int main(){
    int x = 0, y = 0;
    cin>>x;
    cin>>y;
    //法一：数论    两数a,b组合 x*a + y*b = c
    //             当 c 是 gcd(a,b)倍数，x y有解且无穷多
    //             当 gcd(a,b) == 1时，任意整数c,x y有解且无穷多解
    //若要求解 x,y均 >= 0, 则最小的c = a*b -a -b
    //cout<< x*y-x-y<< endl;

    set<int> st;
    //法二：蒙      x*a + y*b = c , a,b>=0
    //             必然不能从1尝试到INT_MAX,那就尝试到a*b，找到1~a*b内满足有解的最大c
	for(int i=0; i*x<=x*y; i++){
        for(int j=0; i*x+j*y<=x*y; j++){
            st.insert(st.end(),i*x+j*y); 
        }
    }
    for(int i=x*y; i>=0; i-- ){
    	if (st.find(i) == st.end()){
    		cout<<i<<endl;
    		break;
		}
	}
    return 0;
}