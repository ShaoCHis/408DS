//
// Created by 少迟 on 2023/5/26.
//

#ifndef INC_408DS_SORT_H
#define INC_408DS_SORT_H

#include<math.h>
#include<iostream>

class Sort {
private:
    int *array;
    int size = 10;
public:
    Sort() {
        this->array = new int[size];
        for (int i = 0; i < size; i++) {
            this->array[i] = rand() % 100;
        }
    }

    void ViewArray() {
        for (int i = 0; i < size - 1; i++) {
            std::cout << this->array[i] << "->";
        }
        std::cout << this->array[size - 1] << std::endl;
    }

    /// \comment 快排递归实现（默认以左起点的值作为分界值，对序列进行升序排序）
    /// \param left 子区间的左起点
    /// \param right 子区间的右终点
    void QuickSort(int left, int right) {
        if (left >= right)
            return;
        int temp = this->array[left];
        int i = left, j = right;
        //在内部循环满足左索引小于右索引，最终结束循环的终结条件正好为i==j，即temp值在数组中对应位置
        while (i < j) {
            //注意在循环内进行执行时，满足左索引小于右索引值，以免出现死循环
            while (this->array[j] >= temp && j > i)
                j--;
            this->array[i] = this->array[j];
            while (this->array[i] <= temp && i < j)
                i++;
            this->array[j] = this->array[i];
        }
        this->array[i] = temp;
        QuickSort(left, i - 1);
        QuickSort(i + 1, right);
    }

    /// \comment 插排实现，默认左侧为有序序列，对序列进行升序排序
    void InsertSort(){
        for (int i = 1; i < size; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (this->array[j]>this->array[j+1]){
                    SwapItem(this->array[j],this->array[j+1]);
                }
            }
        }
    }

    /// \comment 选择排序实现，对序列进行升序排序
    void SelectSort(){
        for (int i = 0; i < size; i++) {
            for (int j = i; j < size; j++) {
                if (this->array[i]>this->array[j]){
                    SwapItem(this->array[i],this->array[j]);
                }
            }
        }
    }

    /// \comment 冒泡排序实现，对序列进行升序排序
    void BubbleSort(){

    }

    void SwapItem(int& a,int& b){
        int temp = a;
        a = b;
        b =temp;
    }
};


#endif //INC_408DS_SORT_H
