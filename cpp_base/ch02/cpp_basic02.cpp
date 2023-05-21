/*
    二、inline内联函数和普通函数的区别？？
        1. inline内联函数：在编译过程中，就没有函数的调用开销了，在函数的调用点直接把函数的代码进行展开处理了。
        2. inline函数不再生成相应的函数符号
        3. inline只是建议编译器把这个函数处理成内联函数，不是所有的inline都会被编译器处理成内联函数 -递归
        4. debug版本中，inline是不起作用的；inline只有在release版本中才能出现
*/
#include <iostream>
using namespace std;

/*
    vscode调试显示汇编：
        -exec disassemble /m main
        -exec disassemble /m 
    显示寄存器的值：
        -exec info registers
*/

inline int sum(int a = 10, int b = 20){ // *.o sum_int_int .text
    return a + b;
}

int main(){
    int a = 10;
    int b = 20;
    int ret = sum(a,b);

    /*
        sum对应的汇编指令：
        0x0000555555555183 <+26>:	mov    edx,DWORD PTR [rbp-0x8]
        0x0000555555555186 <+29>:	mov    eax,DWORD PTR [rbp-0xc]
        0x0000555555555189 <+32>:	mov    esi,edx
        0x000055555555518b <+34>:	mov    edi,eax
        0x000055555555518d <+36>:	call   0x55555555520b <_Z3sumii>
        0x0000555555555192 <+41>:	mov    DWORD PTR [rbp-0x4],eax
    */
    // 此处有标准的函数调用过程 参数压栈，函数栈帧的开辟和回退过程
    // 有函数调用的开销
    // x+y mov add mov 

}