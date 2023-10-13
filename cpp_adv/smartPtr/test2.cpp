/*
    带引用计数的智能指针shared_ptr和weak_ptr
    
    带引用计数：多个智能指针可以管理同一个资源。给每一个对象资源匹配一个引用计数
    智能指针管理资源的时候，引用计数+1；
    智能指针不使用资源的时候，引用计数-1，如果引用计数 !=0，不释放内存，=0 则释放内存
    
    手写带引用计数的智能指针。
    引用计数对象负责管理引用计数的增加与减少。
    智能指针累CSmartptr中需要自定义拷贝构造函数与拷贝赋值运算符。
    重载成员访问运算符*和->
*/
#include <iostream>
using namespace std;

// 对引用资源进行引用计数的类
template<typename T>
class RefCnt{
public:
    RefCnt(T* ptr = nullptr):_ptr(ptr){
        if(_ptr != nullptr)
            _count = 1;
    }
    // 添加引用计数
    void addRef(){_count++;}
    int delRef(){return --_count;}
private:
    T* _ptr;
    int _count;
};

template<typename T>
class CSmartptr{
public:
    CSmartptr(T* ptr = nullptr):_ptr(ptr){
        _refcnt = new RefCnt<T>(_ptr);
    }
    // 析构函数
    ~CSmartptr(){
        if(_refcnt->delRef() == 0){
            delete _ptr;
            _ptr = nullptr;
        }
    }
    // 访问成员运算符*重载，返回对象的引用
    T& operator*() {return *_ptr;}
    // 访问成员运算符->重载
    T& operator->() {return & this->operator*();}
    // T* operator->(){return *_ptr;}

    // 拷贝构造函数
    CSmartptr(const CSmartptr<T>& rhs):_ptr(rhs._ptr),_refcnt(rhs._refcnt){
        if(_ptr != nullptr)
            _refcnt->addRef();
    }
    // 拷贝赋值运算符：rhs对应引用计数++，this对应的引用计数--，如果变为0了，负责回收资源。
    CSmartptr<T>& operator=(const CSmartptr<T>&rhs){
        if(_ptr == rhs._ptr)
            return *this;
        if(_refcnt->delRef() == 0){
            delete _ptr;
            _ptr = nullptr;
        }
        rhs._refcnt->addRef();
        _ptr = rhs._ptr;
        _refcnt = rhs._refcnt;
        return *this;
    }

private:
    T* _ptr; // 指向资源的指针
    RefCnt<T>* _refcnt; // 指向资源计数对象的指针
};

int main(){
    CSmartptr<int>ptr1(new int);
    CSmartptr<int>ptr2(ptr1);
    CSmartptr<int>ptr3 = ptr1;

    *ptr1 = 20;
    cout << *ptr2 << " " << *ptr3 << endl;

    *ptr2 = 30;
    cout << *ptr1 << " " << *ptr3 << endl;

    return 0;
}