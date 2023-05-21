/*
    不带引用计数的智能指针：
        auto_ptr:C++库里面
        c++11新标准：
        scoped_ptr
        unique_ptr

    解决问题：默认拷贝构造函数引发的浅拷贝问题。
    1.不带引用计数的智能指针解决方法：
     

*/
#include <iostream>
using namespace std;

template<typename T>
class CSmartPtr{
public:
    CSmartPtr(T* ptr = nullptr):mptr(ptr){}

    /*
        自定义拷贝构造函数，进行深拷贝。
        存在问题：
        ptr1和ptr2分别指向不同的内存，用户认为ptr1,ptr2指向同一块内存，修改一个，另一个也会变化。
        但是深拷贝无法满足这点。

        ptr1指向的内存值为: 20
        ptr2指向的内存值为: 30
        ptr1指向的内存值为: 20
    */
    CSmartPtr(const CSmartPtr<T>& src){
        mptr = new T(*src.mptr);
    }

    ~CSmartPtr(){
        delete mptr;
    }
    // 重载*运算符
    T& operator*(){
        return *mptr;
    }
    // 重载->运算符
    T* operator->(){
        return mptr;
    }

private:
    T* mptr;
};

#ifdef 0
int main(){
    CSmartPtr<int>ptr1(new int);
    // 默认拷贝构造是浅拷贝，导致mptr指向的内存被释放了两次，产生野指针问题。free(): double free detected in tcache 2 Aborted (core dumped)
    CSmartPtr<int>ptr2(ptr1);
    *ptr1 = 20;

    cout << "ptr1指向的内存值为: " << *ptr1 << endl;

    *ptr2 = 30; 
    cout << "ptr2指向的内存值为: " << *ptr2 << endl;
    cout << "ptr1指向的内存值为: " << *ptr1 << endl;

    return 0;
}
#endif

/*
    看提供的智能指针如何解决上述问题。
*/

int main(){

}