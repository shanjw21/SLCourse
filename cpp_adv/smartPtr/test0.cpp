/*
    手写智能指针：
    智能指针保证可以做到资源的自动释放。
    利用栈上的对象出作用域自动析构的特征，来做到资源的自动释放。
    注意：不能将智能指针new到堆上。p是一个裸指针。
    CSmartPtr<int>*p = new CSmartPtr<int>(new int); delete p;
*/

#include <iostream>

using namespace std;

template<typename T>
class CSmartPtr{
public:
    //构造函数
    CSmartPtr(T* ptr = nullptr):mptr(ptr){}
    // 析构函数
    ~CSmartPtr(){delete mptr;}

    // 重载*运算符:要更改内存中的内容，所以返回类型是引用
    // T operator*(){return *mptr;} 左操作数必须为左值。
    T& operator*(){return *mptr;}
    // 重载->运算符，直接提供底层指针。
    T* operator->(){return mptr;}
    // T* operator->(){return & this->operator*();} this->operator*()返回*mptr,所以重载->时返回的是地址&

private:
    T* mptr;
};

class Test{
public:
    void test(){
        cout << "call Test::test()" << endl;
    }
};

int main(){
    // 调用构造函数创建对象p，指向int类型.
    CSmartPtr<int> ptr1(new int);
    *ptr1 = 20;

    CSmartPtr<Test>ptr2(new Test());

    // (ptr2.operator->())->test();
    ptr2->test();
    // (*ptr2).test();

    return 0;
}