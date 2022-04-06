#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(){
    string s = "aaabbbbccccc";
    int ans = 1;
    vector<string> vec;

    string tmp = s+s;
    vec.push_back(tmp);
    reverse(tmp.begin(),tmp.end());
    vec.push_back(tmp);

    while(next_permutation(s.begin(),s.end())){
    	int i = 0;
    	for (i=0; i<vec.size(); i++){
    		if (vec[i].find(s) != string::npos){
    			//找到了就提前退出 
    			break;
			}
		} 
		//没找到就收录，算一种新的 
		if (i == vec.size()){
			ans++;
    		tmp = s+s;
    		vec.push_back(tmp);
    		reverse(tmp.begin(),tmp.end());
    		vec.push_back(tmp);
		}
    }
    
    cout <<ans<<endl;
    return 0;
}