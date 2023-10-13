/*
    Created by shanjw on 2023/07/03
    c++ 11中 bind 绑定器 => 返回的结果也是一个函数对象。
    bind存在的问题，bind绑定对象出了语句无法再使用
    解决方法：使用function将bind绑定的函数对象保存起来复用
*/

#include <iostream>
#include <functional>
#include <string>
using namespace std;

/*
    muduo库实现的小型线程池 Thread类与ThreadPool类
*/
int main(){

    
    return 0;
}

#if 0
void hello(string str){cout << str << endl;}
int sum(int a, int b){return a + b;}

class Test{
public:
    void hello(string str){cout << str << endl;}
};

int main(int argc, char** argv){
    // bind将函数hello与参数"hello bind""绑定，返回一个函数对象，调用operator()调用函数
    bind(hello,"hello bind!")();
    // bind是一个函数模版，可以自动推到参数类型
    cout << bind(sum,10,20)() << endl;
    // 类的成员方法需要加上&符号，同时绑定需要一个类对象。
    bind(&Test::hello,Test(),"hello Test::hello")();

    // placeholder是占位符，绑定器绑定占位符等函数调用时再传入参数。
    bind(hello,placeholders::_1)("hello bind placeholder");
    cout << bind(sum,placeholders::_1,placeholders::_2)(200,300) << endl;

    // 使用function将bind绑定的函数对象保存起来复用
    function<void(string)>func = bind(hello,placeholders::_1);
    func("hello china!");
    func("hello JiLin");
    func("hello ChangChun");
    return 0;
}
#endif