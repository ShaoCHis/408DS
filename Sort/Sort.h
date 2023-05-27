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
    int size = 20;
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
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size-i-1; j++) {
                if (this->array[j]>this->array[j+1])
                    SwapItem(this->array[j],this->array[j+1]);
            }
        }
    }

    /// \comment 归并排序实现
    void MergeSort(int left,int right){
        if(left>=right)
            return;
        int mid = left+(int)(right-left)/2;
        MergeSort(left,mid);
        MergeSort(mid+1,right);
        Merge(left,right,mid);
    }

    /// \comment 归并排序的归并方法，两个有序序列，在原有内存空间上合并成一个有序序列，即O(1)的空间复杂度
    /// \details 利用额外的O(1)空间即temp，我们有两个有序序列，左序列L1，右序列L2，需要利用temp将左右两个有序序列合并成一个完整的序列
    /// \n 左序列索引设置为i，右序列索引设置为j，对L1和L2中的第一个元素进行比较，保证较小的元素在L1序列中，同时对L1中元素值交换到L2中的元素值进行更新，保证L2一直为有序状态
    void Merge(int left,int right,int mid){
        for (int i = left; i <= mid; i++) {
            if(this->array[i]> this->array[mid+1]){
                SwapItem(this->array[i],this->array[mid+1]);
                UpdateL2(mid,right);
            }
        }
    }

    /// \comment 对序列2进行更新操作，保证L2一直有序
    void UpdateL2(int mid,int right){
        for (int i = mid+1; i < right; i++) {
            if(this->array[i]>this->array[i+1])
                SwapItem(this->array[i],this->array[i+1]);
            else
                break;
        }
    }

    void SwapItem(int& a,int& b){
        int temp = a;
        a = b;
        b =temp;
    }

    int GetLength(){
        return size;
    }
};


#endif //INC_408DS_SORT_H
