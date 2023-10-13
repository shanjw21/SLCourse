/*
    三个车站窗口卖票程序
*/
#include <iostream>
#include <thread>
#include <list>
#include <mutex>

std::mutex mtx;
int tickets = 100;
void sellTicket(int idx){ 
    while(tickets > 0){
        // mtx.lock(); // 临界区代码段
        {
            std::lock_guard<std::mutex>lck(mtx); // 类似于scopped_ptr，出作用域就自动释放锁了，不会发生死锁。
            if(tickets > 0){ // 锁+双重检验
                std::cout << "窗口:" << idx << " 卖第  " << tickets << " 张票。" << std::endl;
                tickets--;
            }
        }
        // mtx.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main(){
    std::list<std::thread>lst;
    for(int i = 1; i <= 3; i++) 
        lst.push_back(std::thread(sellTicket,i));
    for(auto &t:lst){
        t.join();
    }
    std::cout << "所有的票都卖完了！" << std::endl;
    return 0;
}