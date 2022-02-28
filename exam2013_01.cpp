#include <iostream>
using namespace std;
class Date{
		public:
			int year;
			int mon;
			int day;
			int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
			Date():
			year(1777),
			mon(3),
			day(30){};
			void add(int num){
				for(int i=1; i<num; i++){				//出生算一天，计数少一天 
					if(year %4 == 0 && year%400 != 0){
						days[1] = 29;
					}else{
						days[1] = 28;
					}
					day++;
					if (day > days[mon]){
						day = 1;
						mon = (mon+1) % 12;
						if(mon == 0){
							year++;
						}
					}
				}
			}
			void reset(){
				year = 1777;
				mon = 3;
				day = 30;
			}
	};
int main(){
	Date tmp;
	tmp.add(5343);
	cout<<tmp.year<<" "<<tmp.mon+1<<" "<<tmp.day<<endl;
	tmp.reset();
	tmp.add(8113);
	cout<<tmp.year<<" "<<tmp.mon+1<<" "<<tmp.day<<endl;
	return 0;
}
