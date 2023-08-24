//
// Created by 少迟 on 2023/8/24.
//

#include <iostream>

#ifndef INC_408DS_TREENODE_H
#define INC_408DS_TREENODE_H

#endif //INC_408DS_TREENODE_H


/***
 * 二叉树节点的实现
 * 二叉树具有左右孩子节点，二叉树节点需要对左右孩子节点进行访问与处理
 */

class TreeNode{
private:
    int value;
    TreeNode* leftChild;
    TreeNode* rightChild;
    int degree;//该根节点的平衡度，右子树减去左子树的深度，平衡度为-1，0，1时该节点平衡

public:
    TreeNode(int _value):value(_value),leftChild(nullptr),rightChild(nullptr){};
    TreeNode():value(NAN),leftChild(nullptr),rightChild(nullptr){};
    int GetValue() const{
        return value;
    }
    void SetValue(int _value){
        this->value = _value;
    }

    TreeNode* GetLeftNode(){
        return this->leftChild;
    }

    TreeNode* GetRightNode(){
        return this->rightChild;
    }

    void SetLeftChild(TreeNode* _node){
        this->leftChild = _node;
    }
    void SetRightChild(TreeNode* _node){
        this->rightChild = _node;
    }
    //递归进行插入操作
    void InsertNode(int _value){
        if (_value==NAN)
            this->value = _value;
        else {
            if(this->value>=_value)
                this->leftChild== nullptr?this->SetLeftChild(new TreeNode(_value)):this->leftChild->InsertNode(_value);
            else
                this->rightChild== nullptr?this->SetRightChild(new TreeNode(_value)):this->rightChild->InsertNode(_value);
        }
    }

    //递归进行删除操作


    //计算每个节点的深度信息，递归实现
    //记录左右子树的深度信息，对该子树根节点的平衡度进行计算
    void CalcDegree(){
        int rightDepth = 0;
        int leftDepth = 0;
        this->degree = rightDepth - leftDepth;
    }


    friend std::ostream &operator<<(std::ostream &os, const TreeNode &node) {
        os << "value: " << node.value << " leftChild: " << node.leftChild << " rightChild: " << node.rightChild
           << " degree: " << node.degree;
        return os;
    }
};