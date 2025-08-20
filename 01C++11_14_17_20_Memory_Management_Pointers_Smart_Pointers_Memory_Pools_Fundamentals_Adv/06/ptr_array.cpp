#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

class XData {
 public:
  int x = 0;
  int y = 0;
};

int main(int argc, char* argv[]) {
  cout << "ptr_array!" << endl;

  // 栈空间数组示例
  int arr1[10];                   // 未初始化数组，内容不确定
  memset(arr1, 0, sizeof(arr1));  // 通过memset显式清零（手动初始化）
  int arr2[5] = {1, 2, 3, 4, 5};  // 完全初始化数组，显式指定所有元素
  int arr3[32] = {1, 2, 3};       // 部分初始化，剩余元素自动补零（C++默认行为）
  int arr4[1024] = {0};           // 全部初始化为0，适用于大数组初始化
  int arr5[] = {1, 2, 3,
                4};  // 自动推导数组大小（4个元素），编译器根据初始化列表推断
  char str1[] =
      "hello world";  // 字符数组自动包含终止符\0，字符串字面量隐式添加

  // 输出数组大小
  // 注意：sizeof返回数组总字节数，int通常为4字节，char为1字节
  cout << "sizeof(arr5)=" << sizeof(arr5) << endl;  // 4*4=16字节（int[4]）
  cout << "sizeof(str1)=" << sizeof(str1) << endl;  // 12字节（包含11字符+1\0）

  // 范围for循环遍历字符数组
  // 使用auto自动推导类型，适用于数组和容器
  for (auto s : str1) {  // 仅适用于原生数组和容器
    cout << s << "-" << flush;
  }
  cout << endl;

  // 指针算术演示
  // 数组名arr2本质是int*类型指针，指向首元素
  cout << "&arr2[0] = " << &arr2[0] << endl;  // 数组首地址
  cout << "&arr2[1] = " << &arr2[1]
       << endl;  // 第二个元素地址（步长为sizeof(int)）
  cout << "arr2+2 = " << arr2 + 2 << endl;  // 指针加法：地址+步长*偏移量

  // 使用标准算法
  // 查找arr5中值为3的元素，返回指向该元素的迭代器
  std::find(std::begin(arr5), std::end(arr5), 3);  // 查找元素3的位置

  // 堆空间分配示例
  int* parr1 = new int[1024];  // 分配1024个int，未初始化
  int psize = 2048;
  auto* parr2 = new unsigned char[psize];  // 分配指定大小的字节数组
  // int tmp[psize]; // 错误：VLA非标准C++特性（变长数组不被支持）
  memset(parr2, 0, psize);  // 正确初始化字节数组，每个字节置0
  auto* parr3 = new int[psize];
  // 注意：memset需要计算实际字节大小
  // sizeof(int)*psize确保完整初始化int数组
  memset(parr3, 0, psize * sizeof(int));  // sizeof(parr3)仅返回指针大小
  int* parr4 = new int[3]{1, 2, 3};       // 列表初始化堆数组（C++11特性）

  // 指针访问方式演示
  // 两种等效的元素访问方式：下标和指针算术
  cout << "parr4[2] = " << parr4[2] << endl;
  cout << "*(parr4+2) = " << *(parr4 + 2) << endl;
  cout << "&parr4[0] = " << &parr4[0] << endl;
  cout << "&parr4[1] = " << &parr4[1] << endl;
  cout << "parr4+2 = " << parr4 + 2 << endl;

  // 释放堆内存（必须使用delete[]）
  // 避免内存泄漏和未定义行为
  delete[] parr1;
  parr1 = nullptr;  // 避免悬空指针（防止后续误用）
  delete[] parr2;
  parr2 = nullptr;
  delete[] parr3;
  parr3 = nullptr;
  delete[] parr4;
  parr4 = nullptr;
  XData* datas = new XData[1024];  // 自定义类型数组分配
  delete[] datas;
  datas = nullptr;

  return 0;
}