#include <iostream>
using namespace std;

// 全局变量演示
int g1;                // 未初始化的全局变量 - 存储在BSS段
int g2 = 0;            // 显式初始化为0的全局变量 - 通常也位于BSS段
int g3 = 1;            // 已初始化全局变量 - 存储在数据段
int g4 = 2;            // 另一个已初始化全局变量
static int sg1 = 3;    // 静态全局变量 - 作用域仅限本文件，存储在数据段

int main(int argc, char const* argv[]) {
  // 输出程序标题
  cout << "memory address!";
  
  // 代码区演示（.text段）
  cout << "代码区 main = " << main << endl;  // 函数指针地址表示代码段位置
  
  // 全局变量地址演示
  cout << "未初始化 g1 = " << &g1 << endl;    // BSS段地址
  cout << "初始化为0 g2 = " << &g2 << endl;    // BSS段地址
  cout << "初始化为1 g3 = " << &g3 << endl;    // 数据段地址
  cout << "初始化为1 g4 = " << &g4 << endl;    // 数据段地址
  cout << "静态全局初始化为3 sg1 = " << &sg1 << endl;  // 静态变量地址

  // 堆内存演示（动态分配区）
  int* p1 = new int;    // 在堆上分配int大小的内存
  int* p2 = new int;    // 再次分配
  cout << "堆空间地址 p1 = " << p1 << endl;    // 显示堆内存地址
  cout << "堆空间地址 p2 = " << p2 << endl;    // 通常高于栈地址

  // 指针变量本身存储在栈上
  cout << "指针变量的栈空间地址&p1 = " << &p1 << endl;  // 指针变量的栈地址
  cout << "指针变量的栈空间地址&p2 = " << &p2 << endl;

  // 栈内存演示（局部变量）
  int i1 = 100;        // 栈变量
  int i2 = 101;        // 另一个栈变量
  cout << "栈空间地址 i1 = " << &i1 << endl;    // 栈地址通常向下增长
  cout << "栈空间地址 i2 = " << &i2 << endl;    // 相邻变量地址相近

  return 0;
}