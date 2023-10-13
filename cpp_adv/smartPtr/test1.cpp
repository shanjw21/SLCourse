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
#include <memory>
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

#if 0
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
    auto_ptr:
    不推荐使用auto_ptr。 特别是在容器中例如：vector<auto_ptr<int>> vec1; vec2(vec1)
    在容器拷贝时，容器内元素会大量拷贝，vec1中底层指针全部被置为nullptr,所以不能使用auto_ptr

    scoped_ptr:
    scoped_ptr(const scoped_ptr<T>&) = delete;
    scoped_ptr<T>& operator=(const scoped_ptr<T>&) = delete;
    将拷贝构造和拷贝赋值设为delete的，当调用scoped_ptr进行拷贝，编译器报错。

    推荐使用unique_ptr:
    unique_ptr(const unique_ptr<T>&) = delete;
    unique_ptr<T>& operator=(const unique_ptr<T>&) = delete;
    unique_ptr提供了带右值引用的移动构造函数和移动赋值运算符。
    unique_ptr(unique_ptr<T>&&src);
    unique_prt<T>& operator=(unique_ptr<T>&& src);

    template<typename T>
    unique_ptr<T>getSmartPtr(){
        unique_ptr<T>ptr(new T());
        return ptr;
    }
    // 栈上创建的临时对象，不用保存其资源，调用的是移动构造函数
    unique_ptr<int>ptr1 = getSmartPtr<int>();
    // 临时对象，调用的是移动赋值运算符。
    ptr1 = getSmartPtr<int>();
*/

#if 0
int main1(){

    // 永远让最后一个智能指针管理资源，前面的智能指针置为nullptr，
    // 拷贝构造中调用release()。release()将ptr1的值赋予ptr2,然后将ptr1置空。
    auto_ptr<int>ptr1(new int);
    auto_ptr<int>ptr2(ptr1);
    // 此时ptr1已经被置为空指针。
    *ptr1 = 20;

    // Segmentation fault (core dumped)
    cout << "ptr1指向的内存值为: " << *ptr1 << endl;

    *ptr2 = 30; 
    cout << "ptr2指向的内存值为: " << *ptr2 << endl;
    cout << "ptr1指向的内存值为: " << *ptr1 << endl;
}
#endif

#if 0
int main(){
    unique_ptr<int>ptr1(new int);
    // unique_ptr<int>ptr2(ptr1); use of deleted function
    // std::move 右值引用，std::move得到当前变量的右值类型。
    unique_ptr<int>ptr2(std::move(ptr1)); // 可以编译通过，但是运行访问ptr1报错。
    *ptr1 = 20;// Segmentation fault (core dumped)，ptr1管理的资源已经移动了，不能再访问。

    // Segmentation fault (core dumped)
    cout << "ptr1指向的内存值为: " << *ptr1 << endl;

    *ptr2 = 30; 
    cout << "ptr2指向的内存值为: " << *ptr2 << endl;
    cout << "ptr1指向的内存值为: " << *ptr1 << endl;
}
#endif 

int main(){
    shared_ptr<int>ptr1(new int);
    shared_ptr<int>ptr2(ptr1); 
    *ptr1 = 20;
    cout << "ptr1指向的内存值为: " << *ptr1 << endl;

    *ptr2 = 30; 
    cout << "ptr2指向的内存值为: " << *ptr2 << endl;
    cout << "ptr1指向的内存值为: " << *ptr1 << endl;
}