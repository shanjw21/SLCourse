#include <iostream>
#include <thread>

void callback(int t){
    std::cout << "a new thread " << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(t));
}
int main(){
    std::thread t1(callback,3);
    t1.join();
    std::cout << "子线程结束。" << std::endl;
    return 0;
}