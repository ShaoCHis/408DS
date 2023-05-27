//
// Created by 少迟 on 2023/5/26.
//

#include "Sort.h"

int main(){
    Sort sort = Sort();
    sort.ViewArray();
    sort.MergeSort(0,19);
    sort.ViewArray();
    return 0;
}