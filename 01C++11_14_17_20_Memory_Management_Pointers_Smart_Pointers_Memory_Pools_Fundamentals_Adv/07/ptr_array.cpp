#include <iostream>
using namespace std;

#define ARRSIZE 3
int main(int argc, char const* argv[]) {
  cout << "ptr_array!" << endl;
  // 栈二维数组初始化
  {
    // 2*3
    // 1 2 3
    // 4 5 6
    unsigned char arr1[2][ARRSIZE] = {{1, 2, 3}, {4, 5, 6}}; // 定义2行3列的二维数组并初始化
    unsigned char arr2[][ARRSIZE] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}; // 自动推导行数的二维数组
    cout << "arr1[2][3] sizeof(arr1) = " << sizeof(arr1) << endl; // 输出总字节数（2*3=6字节）
    cout << "arr2[][3] sizeof(arr2) = " << sizeof(arr2) << endl; // 输出总字节数（3*3=9字节）

    // 三维数组示例
    int arr3[2][3][4] = {{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}},
                         {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}}};

    // 自动推导维度的三维数组
    int arr4[][3][4] = {{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}},
                        {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}},
                        {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}}};
    
    // 范围for循环遍历二维数组
    for (auto arr : arr2) {
      for (int i = 0; i < ARRSIZE; i++) {
        cout << static_cast<int>(arr[i]) << " " << flush; // 打印数组元素
      }
      cout << endl;
    }
    cout << "-----------------------------------------" << endl;
    
    // 计算二维数组行列数
    int width = ARRSIZE;
    int hight = sizeof(arr2) / (ARRSIZE * sizeof(unsigned char)); // 计算行数
    for (int i = 0; i < hight; i++) {
      for (int j = 0; j < width; j++) {
        arr2[i][j]++;
        cout << static_cast<int>(arr2[i][j]) << " " << flush; // 修改并打印数组元素
      }
      cout << endl;
    }
    cout << "-----------------------------------------" << endl;
  }
  // 堆中二维数组的两种方式
  {
    // 连续空间分配
    int size = 4;
    // 分配4行3列的连续二维数组
    int (*arr5)[3] = new int[size][3]{{1, 2, 3}, {4, 5, 6}};
    cout << "堆中连续空间二维数组访问" << endl;
    for (int i = 0; i < size; i++) {
      // sizeof(arr5[i]) == 12（每行大小=3*4字节）
      for (auto a : arr5[i]) {
        cout << a << " " << flush;
      }
      cout << endl;
    }
    delete[] arr5; // 释放连续空间
    arr5 = nullptr;
    cout << "-----------------------------------------" << endl;
    
    // 指针数组方式
    int width = 4;
    int height = 3;
    int** arr6 = new int* [height] { 0 }; // 先分配行指针数组
    for (int i = 0; i < height; i++) {
      arr6[i] = new int[width]{0}; // 为每行分配列空间
    }
    arr6[1][1] = 99; // 修改特定元素
    cout << "堆中二维指针数组访问" << endl;
    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
        cout << arr6[i][j] << " " << flush;
      }
      cout << endl;
    }
    // 释放内存（先释放每行，再释放行指针数组）
    for (int i = 0; i < height; i++) {
      delete[] arr6[i];
    }
    delete[] arr6;
    arr6 = nullptr;
  }

  return 0;
}