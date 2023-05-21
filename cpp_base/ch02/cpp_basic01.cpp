/*
    一、形参带默认值的函数
        1.给默认值时，从右向左转给，因为压栈就是从右向左压的。
        2.调用效率问题 
        3.定义处可以给形参默认值，声明处也可以给形参默认值
        4.形参给默认值的时候，不管是定义处给，还是声明处给，形参默认值只能出现一次。 
*/
#include <iostream>
using namespace std;

int sum(int a = 10, int b = 20){
    return a + b;
}

int main(){
    int a = 10;
    int b = 20;
    int ret = sum(a,b);
    /*
        mov eax,dword ptr[ebp-8]
        push eax
        mov ecx,dword ptr[ebp-4]
        push ecx
        call sum
    */
    cout << "ret: " << ret << endl;

    ret = sum(a);
    /*
        push 14H
        mov ecx,dword ptr[ebp-4]
        push ecx
        call sum
    */

    ret = sum();// 等价于sum(20,30)
    /*
        push 14H
        push 0Ah
        call sum
    */
}