#include <iostream>
using namespace std;

int main(int argc, char** argv) {
  // 输出程序标题
  cout << "101 pointer" << endl;

  // 在堆(heap)上动态分配int类型内存，返回指向该内存的指针
  int* p1 = new int;
  // 通过解引用操作符*给堆内存赋值
  *p1 = 101;

  // 栈(stack)上创建的局部变量i
  int i = 10;
  cout << "i=" << i << endl;

  // 获取i的地址并赋值给指针p2（指向栈内存的指针）
  int* p2 = &i;
  // 通过指针修改栈内存中的值
  *p2 = 102;

  // 展示指针访问修改后的值
  cout << "i=" << i << endl;
  cout << "p1=" << *p1 << endl;

  // 指针变量本身的大小（通常为8字节，64位系统）
  cout << "sizeof(p1)=" << sizeof(p1) << endl;
  // 指针指向的数据类型大小（int通常为4字节）
  cout << "sizeof(*p1)=" << sizeof(*p1) << endl;

  // 释放堆内存，避免内存泄漏
  delete p1;
  // 已释放内存的访问（不安全操作！此处仅作演示）
  cout << "after delete p1=" << *p1 << endl;

  // 检查指针有效性（此时p1为悬空指针）
  if (p1) {
    cout << "p1 is not null" << endl;
  }

  // 将指针置为nullptr（C++11空指针常量）
  p1 = nullptr;
  // 安全的空指针删除操作
  delete p1;

  // 空指针检查
  if (!p1) {
    cout << "p1 is null" << endl;
  }
  return 0;
}