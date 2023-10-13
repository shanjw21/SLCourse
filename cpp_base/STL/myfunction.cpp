/*
    Created by shanjw on 2023/07/02
    function实现原理:实现自己的function
*/

#include <iostream>
#include <functional>
using namespace std;

// 函数类型 void(string)
void hello(string s){cout << s << endl;}
// 函数类型int(int,int)
int sum(int a, int b){return a + b;}

// 普通类模版
template<typename T>
class myfunction{};

/*
// 类型为R(A)的部分特例化类模版
template<typename R, typename A>
class myfunction<R(A)>{
public:
    //定义函数指针类型 pFunc为R(*)(A)用于接收R(A)类型函数
    using pFunc = R(*)(A);
    myfunction(pFunc pfunc):_pFunc(pfunc){}

    // 重载operator()运算符
    R operator()(A arg){
        return _pFunc(arg); // hello(arg)
    }
private:
    pFunc _pFunc;
};

// 类型为R(A)的部分特例化类模版
template<typename R, typename A1,typename A2>
class myfunction<R(A1,A2)>{
public:
    //定义函数指针类型 pFunc为R(*)(A)用于接收R(A)类型函数
    using pFunc = R(*)(A1,A2);
    myfunction(pFunc pfunc):_pFunc(pfunc){}

    // 重载operator()运算符
    R operator()(A1 arg1,A2 arg2){
        return _pFunc(arg1,arg2); // hello(arg)
    }
private:
    pFunc _pFunc;
};
*/

// 可变参数模版
template <typename R, typename... A>
class myfunction<R(A...)>{
public:
    using pFunc = R(*)(A...);
    myfunction(pFunc pfunc):_pFunc(pfunc){}
    R operator()(A... arg){
        return _pFunc(arg...);
    }
private:
    pFunc _pFunc;
};

int main(int argc, char** argv){
    // 使用函数类型void(string)实例化func模版
    // function<void(string)> func(hello);
    function<void(string)> func = hello;
    func("hello function!");

    myfunction<void(string)> myfunc(hello);
    myfunc("hello myfunction!");

    myfunction<int(int,int)> myfunc1(sum);
    std::cout << myfunc1(10,20) << std::endl;
    return 0;
}
