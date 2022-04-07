#include <iostream>
using namespace std;
int main(){
    int n = 0;
    cin >> n;
    int ans = n;
    while(n/3){
        int add = n/3;
        ans += add;
        n = n%3 + add;
    }
    cout << ans<< endl;
    return 0;
}