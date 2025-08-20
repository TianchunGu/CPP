#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
  cout << "ptr_array!" << endl;
  
  // 栈空间数组示例
  int arr1[10]; // 未初始化数组，内容不确定
  memset(arr1, 0, sizeof(arr1));  // 通过memset显式清零
  int arr2[5] = {1, 2, 3, 4, 5}; // 完全初始化数组
  int arr3[32] = {1, 2, 3};      // 部分初始化，剩余元素自动补零
  int arr4[1024] = {0};          // 全部初始化为0
  int arr5[] = {1, 2, 3, 4};     // 自动推导数组大小（4个元素）
  char str1[] = "hello world";   // 字符数组自动包含终止符\0

  // 输出数组大小
  cout << "sizeof(arr5)=" << sizeof(arr5) << endl;   // 4*4=16字节（int[4]）
  cout << "sizeof(str1)=" << sizeof(str1) << endl;   // 12字节（包含11字符+1\0）

  // 范围for循环遍历字符数组
  for (auto s : str1) {  // 仅适用于原生数组和容器
    cout << s << "-" << flush;
  }
  cout << endl;

  // 指针算术演示
  cout << "&arr2[0] = " << &arr2[0] << endl; // 数组首地址
  cout << "&arr2[1] = " << &arr2[1] << endl; // 第二个元素地址
  cout << "arr2+2 = " << arr2 + 2 << endl;  // 指针加法（步长为sizeof(int)）

  // 使用标准算法
  std::find(std::begin(arr5), std::end(arr5), 3); // 查找元素3的位置

  // 堆空间分配示例
  int* parr1 = new int[1024]; // 分配1024个int
  int psize = 2048;
  auto* parr2 = new unsigned char[psize]; // 分配指定大小的字节数组
  // int tmp[psize]; // 错误：VLA非标准C++特性
  memset(parr2, 0, psize); // 正确初始化字节数组
  auto* parr3 = new int[psize];
  // 注意：memset需要计算实际字节大小
  memset(parr3, 0, psize * sizeof(int));  // sizeof(parr3)仅返回指针大小
  int* parr4 = new int[3]{1, 2, 3}; // 列表初始化堆数组

  // 指针访问方式演示
  cout << "parr4[2] = " << parr4[2] << endl;
  cout << "*(parr4+2) = " << *(parr4 + 2) << endl;
  cout << "&parr4[0] = " << &parr4[0] << endl;
  cout << "&parr4[1] = " << &parr4[1] << endl;
  cout << "parr4+2 = " << parr4 + 2 << endl;

  // 释放堆内存（必须使用delete[]）
  delete[] parr1;
  parr1 = nullptr;  // 避免悬空指针
  delete[] parr2;
  parr2 = nullptr;
  delete[] parr3;
  parr3 = nullptr;
  delete[] parr4;
  parr4 = nullptr;

  return 0;
}