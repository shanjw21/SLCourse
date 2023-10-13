#include <iostream>
using namespace std;

/*
    懒汉式单例模式：只有在第一次获取他的时候，才创建唯一实例。
*/
class Singleton{
private:
    // 声明一个指针实例。
    static Singleton* instance;
    // 1、构造函数私有化
    Singleton(){

    }
    // 拷贝构造函数与拷贝构造运算符设为delete
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&)=delete;
public:
    static Singleton* getInstance(){
        // 不是线程安全的单例模式。
        if(instance == nullptr){
            /*
                开辟内存
                构造对象
                给instance赋值
            */
            instance = new Singleton();
        }
        return instance;
    }
};
Singleton* Singleton::instance = nullptr;

