/*
    Created by shanjw on 2023/06/29
    模版的完全特例化和非完全(部分)特例化
    模版的实参推演
    必须有原模版才能提供一个特例化
    实例化模版的优先级:完全特例化 > 部分特例化 > 普通模版类型
*/
#include <iostream>
#include <iostream>
#include <string.h>
#include <typeinfo>
using namespace std;

int sum(int a, int b){return a + b;}

// 定义一个函数模版，打印传入参数的类型
// 模版T中包含大类类型的信息
template<typename T>
void func(T a){
    cout << typeid(a).name() << endl;
}



int main(){
    func(10); // 模版自动推演出的类型是:i
    func("aaa"); // 模版推断出的类型是:PKc
    return 0;
}

#if 0
template<class T>
class Vector{
public:
    Vector(){
        cout << "call vector template init." << endl;
    }
};

// 针对char*类型的完全特例化
template<>
class Vector<char*>{
public:
    Vector(){
        cout << "call char* vector template init." << endl;
    }
};

// 针对T*类型的部分特例化
template<typename T>
class Vector<T*>{
public:
    Vector(){
        cout << "call Vector<T*> template init." << endl;
    }
};

//针对函数指针类型(int(*)(int,int))的部分实例化模版,如果没有这个部分特例化，则会调用T*类型的特例化模版
template<typename R, typename A1, typename A2>
class Vector<R(*)(A1,A2)>{
public:
    Vector(){
        cout << "call Vector<R(*)(A1,A2)> template init." << endl;
    }
};

// 针对函数类型int(int,int)实现部分实例化模版,如果没有这个部分特例化，调用普通函数模版
template<typename R, typename A1, typename A2>
class Vector<R(A1,A2)>{
public:
    Vector(){
        cout << "call Vector<R(A1,A2) template init." << endl;
    }
};

// 定义sum函数，其函数类型为int(int,int)
int sum(int a, int b){return a + b;}

int main(){
    // 模版参数推演，推断出是 int类型
    Vector<int>vec;
    // 如果需要处理const char* 类型的特例化代码
    Vector<char*>vec1;
    // 处理int*类型，配合模版部分特例化
    Vector<int*>vec2;
    // 处理函数指针(int(*)(int,int))类型，使用函数指针模版部分特例化
    Vector<int(*)(int,int)>vec3;
    // 处理函数类型int(int,int)，使用原始模版实例化,函数类型与函数指针类型不一样。
    Vector<int(int,int)>vec4;

    // typedef函数指针类型int(*)(int,int)别名为PFUNC
    typedef int (*PFUNC) (int,int);
    PFUNC pfunc = sum;
    cout << pfunc(10,20) << endl;

    // typedef函数类型int(int,int)别名为PFUNC2
    typedef int PFUNC2 (int,int);
    PFUNC2* pfunc2 = sum;
    cout << pfunc2(10,20) << endl;

    return 0;
}
/*
    main()实验结果：
    all vector template init.
    call char* vector template init.
    call Vector<T*> template init.
    callVector<R(*)(A1,A2)> template init.
    call vector template init.
*/

// 普通的模版比较函数
template<typename T>
bool compare(T a, T b){
    cout << "普通模版函数调用" << endl;
    return a > b;
}
// 模版完全特例化
template<>
bool compare<const char*>(const char* a, const char* b){
    cout << "const char* 类型的模版特例化" << endl;
    return strcmp(a,b) > 0;
}

int main(int argc, char** argv){
    compare(10,20);
    compare("aaa","bbb");
    
    return 0;
}
#endif