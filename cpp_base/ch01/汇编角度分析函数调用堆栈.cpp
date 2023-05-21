#include <iostream>

using namespace std;

/*
    问题一：main函数调用sum，sum执行完后，怎么知道回到那个函数
    问题二：sum函数执行完，回到main以后，怎么知道从哪一行指令继续运行的。
*/

int sum(int a, int b){
    int temp = 0;
    temp = a + b;
    return temp;
}

int main(int argc, char**agv){

    int a = 10;
    int b = 10;
    int ret = sum(a,b);
    cout << "ret = " << ret << endl;
    return 0;
}