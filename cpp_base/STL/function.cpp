#include <functional>
#include <string>
#include <iostream>
/*
    function模版实例化：使用函数类型来实例化function模版
    函数类型:返回值类型 + 参数列表
*/
using namespace std;

void hello(){
    cout << "hello world" << endl;
}

// 全局函数调用可以使用函数指针: void(*pfunc)(string);
void hello1(string str){
    cout << str << endl;
}

int sum(int a, int b){
    return a + b;
}

class Test{
public:
    // 类内的成员函数使用函数指针指向时的类型是:void(Test::*pfunc)(string);
    // 类内成员函数调用必须依赖一个对象。
    void hello(string str){
        cout << str << endl;
    }
};

int main(){
    // hello函数类型为void()
    // function<void()>func1 = hello;与下式子等价
    function<void()>func1(hello);
    func1(); // 调用func1.operator() 等价于调用hello()

    // hello1函数类型为: void(string)
    function<void(string)> func2 = hello1;
    func2("hello hello1"); // 调用func2.operator(string)等价于调用 hello1(string)

    function<int(int,int)> func3 = sum;
    cout << func3(20,30) << endl;

    // function还可以保留函数对象类型，使用函数对象类型实例化function模版。
    function<int(int,int)> func4 = [](int a, int b)->int {return a + b;};
    cout << func4(100,200) << endl; // 等价于调用operator(int,int);

    // 类成员函数经编译后，形参列表中会有一个类指针，这里是Test*类型指针。
    function<void(Test*,string)> func5 = &Test::hello;
    // 类成员函数调用需要一个对象,这里可以传入一个临时对象(taking address of rvalue [-fpermissive])
    // 这里使用临时对象报错了，所以老实使用局部对象。
    Test t = Test();
    func5(&t,"call Test::hello!");
    return 0;
}