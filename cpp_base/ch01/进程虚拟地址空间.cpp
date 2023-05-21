#include <iostream>

using namespace std;
// 定义三个全局变量，分别是初始化为0，初始化非0，默认初始化的变量
int gdata1 = 10;
int gdata2 = 0;
int gdata3;

// 定义三个静态全局变量
static int gdata4 = 11;
static int gdata5 = 0;
static int gdata6; 
/*
    gdata1 ~ gdata6在编译之后都是数据，gdata1,gdata4初始化不为0，放在.data段， 
    其他几个未初始化或初始化为0的都放在.bss段。
*/


int main(int argc, char** argv){

    // 局部变量在编译后产生的是指令。指令存放在.text中存放。 
    int a = 12;
    int b = 0;
    int c;

    // 静态变量也是数据，在运行时进行初始化
    static int e = 13; // 初始化不为0，放在.data段，剩下两个放在.bss段
    static int f = 0;
    static int g; // 打印出来一定是0，因为存在.bss段，os会将其变为0

    return 0;
}