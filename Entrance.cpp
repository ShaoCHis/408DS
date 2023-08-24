//
// Created by 少迟 on 2023/5/27.
//

#include "Sort/Sort.h"
#include "Queue/Queue.h"
#include "Tree/BinarySearchTree.h"

using namespace std;

int main(){
    Sort sort = Sort();
    sort.ViewArray();
    sort.BucketSort();
    sort.ViewArray();
    BinarySearchTree* b = new BinarySearchTree();
    for (int i = 0; i < 20; i++) {
        b->InsertNode(rand()%100);
    }
    b->Show(b->GetRoot());
    int num = 0;
    std::cout<<std::endl<<"请输入需要查找的值：";
    std::cin>>num;
    std::cout<<*b->Search(num)<<std::endl;
    std::cout<<"请输入要删除的值：";
    std::cin>>num;
    std::cout<<num<<std::endl;
    b->DeleteItem(num);
    b->Show(b->GetRoot());
    return 0;
}

