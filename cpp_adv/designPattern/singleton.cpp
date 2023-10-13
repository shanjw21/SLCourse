#include <iostream>
using namespace std;

/*
    饿汉式单例模式：还没有获取实例对象，实例对象就已经产生了。
    懒汉式单例模式：唯一的实例对象，直到第一次获取他的时候，才产生。
*/
class Singleton{
private:
    static Singleton instance;
    // 构造函数设为私有的
    Singleton(){

    }
    // 拷贝赋值与拷贝构造函数定义为delete
    Singleton(const Singleton&)=delete;
    Singleton& operator=(const Singleton&)=delete;
public:
    // 这个如果不返回指针会用到拷贝构造有错误
    static Singleton* getInstance(){
        return &instance;
    }
};
Singleton Singleton::instance;

int main(){
    Singleton* p1 = Singleton::getInstance();
    return 0; 
}