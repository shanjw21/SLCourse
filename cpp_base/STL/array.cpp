#include <array>
#include <iostream>
/*
    1.定义array时，要指定元素类型和容器大小
    2.默认构造的array是非空的：包含与其大小一样多的元素，且元素被默认初始化。若对其进行列表初始化
    则初始值数目需要小于等于其大小。
    3.如果元素类型是类类型，则类必须有一个默认构造函数以进行值初始化。
*/

int main(){
    // 定义array时，要指定元素类型和容器大小
    std::array<int,42> a;
    std::cout << a.size() << std::endl;
    for(auto x : a){
        std::cout << x << " ";
    }
    std::cout << std::endl;
    return 0;
}