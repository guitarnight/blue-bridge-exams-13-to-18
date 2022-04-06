#include <iostream>
#include <stdlib.h>
using namespace std;
int main(){
    int n = 0;
    cin >> n;
    int* arr = (int*) malloc(n*sizeof(int));
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    //两个蚂蚁相遇可以视为不掉头，从同一点继续分两向走
    //这样，同向蚂蚁不相遇
    int ans = 1;
    if (arr[0]>0){
        int flag = 0;
        for (int i=1; i<n; i++){
            if (abs(arr[i]) > abs(arr[0]) && arr[i]<0){
                ans++;
                flag = 1;
            }
        }
        if (flag = 1){
            for(int i=1; i<n; i++){
                if (abs(arr[i]) < abs(arr[0]) && arr[i]>0){
                    ans++;
                }
            }
        }
    }else{
        int flag = 0;
        for (int i=1; i<n; i++){
            if (abs(arr[i]) < abs(arr[0]) && arr[i]>0){
                ans++;
                flag = 1;
            }
        }
        if (flag = 1){
            for(int i=1; i<n; i++){
                if (abs(arr[i]) > abs(arr[0]) && arr[i]<0){
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}