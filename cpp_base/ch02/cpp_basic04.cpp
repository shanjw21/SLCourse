/*
    const 的用法：
    const的初始理解：const修饰的变量，不能再作为左值，初始化完成后，值不能被修改。
    C语言中： const修饰的量不叫常量，叫做常变量，可以不用初始化。c中，const只是从语法上说明a是左值，不能再被修改
    实际上可以通过指针对其内存进行修改。
    c++中： const修饰的变量必须被初始化，叫做常量。
    如果const int a = b;时，此时退化成常变量(与C语言一致)，初始值不是立即数，是一个变量。
    总结：
        const在c和c++中的编译方式不同，c中，const就是被当作一个变量来编译生成指令的，c++中所有出现const常量
        名字的地方，都被常量的初始化替换了。
*/
#include <iostream>
#include <typeinfo>
int main(){
    // const int a; error: uninitialized ‘const a’ const修饰的变量必须被初始化。

    // const int a = 20;
    // int array[a] = {};

    // int* p = (int*)&a;
    // *p = 30;

    // // 20 30 20
    // printf("%d %d %d \n", a, *p, *(&a));

    int b = 20;
    const int a = b; // a退化成常变量了，不是常数了，所以不能定义数组了，与c语言中一样。
    //int array[a] = {};
    return 0;
}