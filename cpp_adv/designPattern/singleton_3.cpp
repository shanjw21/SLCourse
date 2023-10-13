#include <iostream>
#include <mutex>

using namespace std;
/*
    使用静态局部变量的初始化来实现线程安全的懒汉单例。
*/

class Singleton{
private:
    Singleton(){

    }
    Singleton(const Singleton&)=delete;
    Singleton& operator=(const Singleton&)=delete;
public:
    static Singleton* getInstacne(){
        // 函数静态局部变量的初始化，在汇编指令上就自动添加线程互斥了
        static Singleton instance;
        return &instance;
    }
};