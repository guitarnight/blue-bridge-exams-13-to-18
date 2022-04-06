#include <iostream>
using namespace std;
int m, n ,k;
//全局变量少传参，写起来快
long long ans = 0;

void func(int **arr, int x, int y, int max, int count){
    //不合规统一终结
	if (x==n || y==m || count > k){
		return ;
	}
	if (x==n-1 && y==m-1){
		if (count == k){
			ans++;
            if (ans >= 1000000007){
                ans = ans % 1000000007;
            }
		}else if (count == k-1 && arr[y][x]>max){
			ans++;
            if (ans >= 1000000007){
                ans = ans % 1000000007;
            }
		}
	}
    //可以不合规,进入非法层统一终结
	if (arr[y][x] > max){
		func(arr, x+1, y, arr[y][x], count+1);
		func(arr, x, y+1, arr[y][x], count+1);
	}
	func(arr, x+1, y, max, count);
	func(arr, x, y+1, max, count);
}

int main(){
	cin >> m >> n >> k;
	int **arr = new int*[m];
	for(int i=0; i<m; i++){
		arr[i] = new int[n];
	}
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cin >> arr[i][j];
		}
	}
	
	func(arr,0,0,-1,0);
	cout << ans<< endl;
	return 0;
}