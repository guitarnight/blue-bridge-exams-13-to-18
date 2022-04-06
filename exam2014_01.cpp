#include <iostream>
using namespace std;

int main(){
    for(int i=1; i<=30; i++){
        for(int j=i+1; j<=30; j++){
            if (j-i<=8 && j*i == 6*(j+i)){
                cout<<i<<endl;
            }
        }
    }
    return 0;
}