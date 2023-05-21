int sum(int* a, int n);

int array[2] = {1,2}; // 全局变量 标识为.global
int main(){
    int val = sum(array,2);
    return val;
}