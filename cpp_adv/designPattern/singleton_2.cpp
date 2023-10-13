#include <iostream>
#include <thread>
#include <mutex>
/*
    线程安全的懒汉单例模式：通过互斥锁+双重检验实现，使用 volatile 来直接指向内存中的instance而不是线程复制在
    内存中的instance
*/

using namespace std;
std::mutex mtx;
class Singleton{
private:
    static Singleton* volatile instance;
    // 构造函数私有化
    Singleton(){

    }
    Singleton(const Singleton&)=delete;
    Singleton& operator=(const Singleton&)=delete;
public:
    static Singleton* getInstance(){
        // 锁+双重检验来保证线程安全
        if(instance == nullptr){
            lock_guard<std::mutex>guard(mtx);
            if(instance == nullptr){
                instance = new Singleton();
            }
        }
        return instance;
    }
};
Singleton* volatile Singleton::instance = nullptr;