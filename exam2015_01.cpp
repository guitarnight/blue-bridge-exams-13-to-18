#include <iostream>
using namespace std;

int main(){
	for (int i=1; i<40; i++){
		for (int j=1; j<40; j++){
			for (int k=1; k<40; k++){
				//三数排序去重 
				if (k > j && j>i && i*i + j*j + k*k == 1000){
					cout <<i<<" "<< j<<" "<< k<< endl;
				}
			}
		}
	}
	return 0;
}