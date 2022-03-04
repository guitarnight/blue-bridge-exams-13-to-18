#include <iostream>
using namespace std;
int num = 0;
int ans[8] = {0,1,2,3,4,5,6,7};
int match(int *a, int *b){
	for(int i=0; i<8; i++){
		if (a[i] != b[i]){
			return 0;
		}
	}
	return 1;
} 
//  通过添加step限制，才能使递归有所终止
void func(int (*map)[5], int x, int y, int step, int* line){
    //可以进入所有的异常情况，然后统一return视作一起处理，比分类讨论要不要进入省事
	if (x < 0 || x >3 || y<0 || y>4 || step>7){
		return;
	}
	line[step] = map[x][y];
	//cout<<step<<line[step]<<endl;             出问题时加cout调试
    if(step==7 && x==3 && y==4 && match(line, ans)==1){
		num++;
    }
    func(map, x+1, y, step+1, line);
    func(map, x-1, y, step+1, line);
    func(map, x, y+1, step+1, line);
    func(map, x, y-1, step+1, line);
}
int main(){
    int map[4][5] = {{0,1,2,3,4},
                    {1,2,3,4,5},
                    {2,3,4,5,6},
                    {3,4,5,6,7}};
    int arr[8] = {0,0,0,0,0,0,0,0};     //注意一定要数据初始化
    func(map, 0, 0, 0, arr);
    cout<<num<<endl;
    return 0;
}