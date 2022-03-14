#include <iostream>
using namespace std;
//使用结构体的变量n记录已经走过的字符串下标，节省了递归函数的参数
struct EV{
    int result;         //最终结果
    int n;              //已经运算了的字符
};
//简单递归 5+2   ->   +52
//题目递归3+5*(2+6)-1   ->   -+3*5+261

//原本的逆波兰：两个数字出栈，与符号栈栈顶符号运算得出的结果入栈。《本题就是在找每次运算的结果》
struct EV evaluate(char* x){
    struct EV ev = {0,0};
    struct EV v1;               //栈中数字a
    struct EV v2;               //栈中数字b
    if (*x == 0){               //逆波兰表达式是空则不需要继续
        return ev;
    }
    if (x[0] >= '0' && x[0] <= '9'){    //起初x[0]若是运算符，下面在找运算符的数字对象v1.result 和 v2.result
        ev.n = 1;                       //起初x[0]若是数字，则说明没有运算符，仅此一个数字
        ev.result = x[0] - '0';
        return ev;
    }
    v1 = evaluate(x+1);         //找数字a的值
    v2 = evaluate(x + v1.n + 1);//找数字b的值
                                
    if (x[0] == '+'){           //x[0]若不是数字，则需要返回栈中数字a b的运算结果
        ev.result = v1.result + v2.result;
    }else if (x[0] == '*'){
        ev.result = v1.result * v2.result;
    }else if (x[0] == '-'){
        ev.result = v1.result - v2.result;
    }
    ev.n = 1 + v1.n + v2.n;     //在x中查找数字时，已经被查找过的x
    return ev;
}

int main(){
    char *arr = "-+3*5+261";
    cout<<evaluate(arr).result<<endl;
    return 0;
}