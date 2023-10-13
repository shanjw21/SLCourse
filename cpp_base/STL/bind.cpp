#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>
#include <ctime>
using namespace std;

// 遍历容器内元素。
template<typename Container>
void showContainer(Container &con){
    auto it = con.begin();
    for(;it != con.end();it++){
        cout << *it << " ";
    }
    cout << endl;
}

// 实现my_find_if泛型算法
template<typename Iterator,typename Compare>
Iterator my_find_if(Iterator first, Iterator last, Compare comp){
    for(;first != last; ++first){
        if(comp(*first)){ // 需要一元函数对象，从容器中拿一个元素与其比较。
            return first; // comp.operator()(*first);调用小括号运算符
        }
    }
    return last;
}

// 模版类，实现operator()运算符
template<typename Compare, typename T>
class _mybind1st{
public:
    // 构造函数
    _mybind1st(Compare comp, T val)
    : m_comp(comp),m_val(val){}

    //重载operator()运算符，使得_mybind1st对象成为一个函数对象.
    bool operator()(const T& second){
        return m_comp(m_val,second);
    }
private:
    Compare m_comp;
    T m_val;
};

/*
    实现绑定器bind1st:接收一个二元函数对象和一个固定值，返回一个函数对象。
*/
template<typename Compare, typename T>
_mybind1st<Compare,T> mybind1st(Compare com, T& val){
    // 使用函数模版，可以直接使用模版参数推演
    return _mybind1st<Compare,T>(com,val);
}


int main(){
    vector<int> vec;
    srand(time(nullptr));
    for(int i = 0; i < 20; ++i){
        vec.push_back(rand()%100+1);
    }
    showContainer(vec);
    sort(vec.begin(),vec.end()); // 默认小到大排序
    showContainer(vec);

    // greater二元函数对象，从大到小排序
    sort(vec.begin(),vec.end(),greater<int>());
    showContainer(vec);
    /*
        将70插入到vec容器中，：找到第一个小于70的数字
        operator() (const T&val)
        greater a > b
        less a < b
        绑定器 + 二元函数对象 --> 一元函数对象
        bind1st: + greater --> 小于70的数字
        bind2nd: + less --> 小于70的数字
    */
    auto it = my_find_if(vec.begin(),vec.end(),_mybind1st(greater<int>(),70));
    // auto it = my_find_if(vec.begin(),vec.end(),bind2nd(less<int>(),70));
    if(it != vec.end()){
        vec.insert(it,70);
    }
    showContainer(vec);
    return 0;
}