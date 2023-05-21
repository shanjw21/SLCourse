/*
    函数重载详解：
    1.c++为什么支持函数重载，c语言不支持函数重载
        函数重载：一组函数，其中函数名相同，参数列表的个数或者类型不同，则这组函数称为函数重载。
        （1）c++代码产生函数符号的时候，由函数名 + 参数列表类型组成的；c代码产生函数符号的时候，由函数名来决定。
        （2）一组函数要称得上重载，一定先是处在同一个作用域当中的。
         (3)一组函数，函数名相同，参数列表也相同，仅仅是返回值不同，不叫重载。
         函数重载又可以看成是静态（编译时期）的多态
    2.函数重载需要注意什么
    3.c++和c语言代码之间如何相互调用。
    c++调用c代码：无法直接调用，原因是编译时c++和c对函数符号的命名格式不一样导致在连接时找不到相应的符号，从而导致链接错误。
    “无法解析的外部符号”。
    解决方法： 使用 extern "C"{c代码函数} 告诉c++编译器按照c语言方式编译。
*/
#include <iostream>
#include <string.h>
using namespace std;

// c++编译器内置了 __cplusplus这个宏名
// 如果在c++中贴了这段代码则编译时会在 int sum(int a, int b)上加上相应extern "C"，那么函数的符号生成按c生成。
// 不管是c代码还是cpp代码，里面的函数都是按照c的方式编译生成的。
#ifdef __cplusplus
extern "C"{
#endif
    int sum(int a, int b){
        return a + b;
    }
#ifdef __cplusplus
}
#endif

bool compare(int a, int b){
    cout << "compare_int_int" << endl;
    return a > b;
}

bool compare(double a, double b){
    cout << "compare_double_double" << endl;
    return a > b;
}

bool compare(const char* a, const char* b){
    cout << "compare_char*_char*" << endl;
    return strcmp(a,b) > 0;
}

int main(){
    // bool compare(int a, int b); 函数声明,作用域使得下面两个函数之间调用compare_int_int函数了。

    compare(10,20);
    compare(10.0,20.0); // warning:精度丢失
    compare("aaa","bbb"); // error:无法将const char* 转化到 int 

    return 0;
}