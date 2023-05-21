// 引用sum.cpp文件中的定义的全局变量以及函数。
extern int gdata;  // gdata *UND* 符号的引用而非定义的地方。
int sum(int,int);  // sum  *UND*
int data = 20;  // data  .text

int main(){     // main  .text
    int a = gdata;
    int b = data;
    int ret = sum(a,b);
    return 0;
}