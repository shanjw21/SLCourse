/*
    Created by shanjw on 2023/06/23
    set：集合存储key
    底层数据结构：链式哈希表，增删查：O(1)
    常用增删查方法：
    1.增加:insert(val)
    2.遍历:iterator,自己搜索，调用find成员方法，iterator=set.find(key)
    3.删除:erase(key),erase(it) 
*/

#include <iostream>
#include <set>

int main(int argc, char** argv){
    std::set<int>s; // 不会存储key值重复的元素
    for(int i = 0; i < 50; ++i){
        s.insert(rand() % 20 + 1);
    }
    std::cout << "the size of set: " << s.size() << std::endl; // 18
    for(auto it = s.begin(); it != s.end();++it){ // 打印集合中的元素
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    auto it = s.begin(); // 遍历集合
    while(it != s.end()){
        if(*it == 20){
            it = s.erase(it); // 删除元素20
        }
        else{
            ++it;
        }
    }

    for(auto val:s){
        std::cout << val << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
