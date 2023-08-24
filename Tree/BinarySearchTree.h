//
// Created by 少迟 on 2023/8/24.
//

#ifndef INC_408DS_BINARYSEARCHTREE_H
#define INC_408DS_BINARYSEARCHTREE_H


#include "TreeNode.h"

/***
 * 平衡二叉树的实现，首先实现树节点的定义与各种方法定义
 *
 * 平衡二叉树的前提为搜索二叉树，左节点<=根节点<=右节点
 *
 * 需要通过一系列操作保证平衡二叉树
 */

class BinarySearchTree {
private:
    //平衡二叉树的根节点信息，通过根节点对后续所有节点进行访问以及进行插入和删除操作
    TreeNode *root;

public:
    BinarySearchTree() : root(nullptr) {};

    TreeNode *GetRoot() {
        return root;
    }

    void InsertNode(int _value) {
        if (root == nullptr) {
            root = new TreeNode(_value);
        } else {
            root->InsertNode(_value);
        }
    }

    //对二叉搜索树进行查找，查找特定值的树节点
    TreeNode *Search(int _value) {
        TreeNode *node = root;
        while (node != nullptr) {
            if (node->GetValue() == _value)
                break;
            node = node->GetValue() > _value ? node->GetLeftNode() : node->GetRightNode();
        }
        return node;
    }

    //利用中序遍历对二叉搜索树进行遍历得到有序序列
    void Show(TreeNode* node) const {
        if (node == nullptr)
            return;
        if (node->GetLeftNode() != nullptr)
            Show(node->GetLeftNode());
        std::cout << "->" << node->GetValue();
        if (node->GetRightNode() != nullptr)
            Show(node->GetRightNode());
    }

    /***
     * 为了避免双指针的使用，即父子互相指向，这里采用父层节点对子层节点的使用访问判断
     * @param _value
     */
    void DeleteItem(int _value) {
        //需要找到删除节点的父节点进行删除操作，避免内存访问异常
        TreeNode *parent = root;
        if (parent->GetValue() != _value) {
            while (parent != nullptr) {
                if ((parent->GetLeftNode() != nullptr && parent->GetLeftNode()->GetValue() == _value) ||
                    (parent->GetRightNode() != nullptr && parent->GetRightNode()->GetValue() == _value))
                    break;
                parent = parent->GetValue() > _value ? parent->GetLeftNode() : parent->GetRightNode();
            }
        }
        if (parent == nullptr)
            std::cout << "树中不存在该值节点" << std::endl;
            //node不为空的话，那么其左右孩子其中一个为我们需要删除的节点
        else {
            //删除该子树的根节点后，需要拿取左子树的右子树节点或者右子树的左子树节点来进行节点的替换
            TreeNode* target = parent->GetValue()>_value?parent->GetLeftNode():parent->GetRightNode();
            /**
             * 拿取左子树的右子树节点
             */
            if (target->GetLeftNode() != nullptr) {
                //左子树不具有右孩子，那么该节点即为左子树的最大值，进行替换和删除
                if(target->GetLeftNode()->GetRightNode()== nullptr){
                    //左子树的根节点为需要进行值替换的节点
                    SwapAndDelete(target,target,target->GetLeftNode(),0,0);
                }
                    //左子树有右孩子节点
                else{
                    parent = target->GetLeftNode();
                    while(parent->GetRightNode()->GetRightNode()!= nullptr)
                        parent = parent->GetRightNode();
                    SwapAndDelete(target,parent,parent->GetRightNode(),0,1);
                }
            }
                //拿取右子树的左孩子节点
            else if(target->GetRightNode()!= nullptr){
                //右子树不具有左孩子，那么该节点即为右子树的最小值，进行替换和删除
                if (target->GetRightNode()->GetLeftNode()== nullptr){
                    //右子树根节点为需要进行替换的节点
                    SwapAndDelete(target,target,target->GetRightNode(),1,0);
                }
                    //右子树有左孩子节点
                else{
                    parent = target->GetRightNode();
                    while(parent->GetLeftNode()->GetLeftNode()!= nullptr)
                        parent = parent->GetLeftNode();
                    SwapAndDelete(target,parent,parent->GetLeftNode(),1,1);
                }
            }
                //删除节点为叶子节点
            else {
                parent->GetValue()>_value?parent->SetLeftChild(nullptr):parent->SetRightChild(nullptr);
                delete target;
            }
        }
    }

    //当需要删除的目标节点不是叶子节点时，那么需要将目标节点的value进行更新，并删除查找到的叶子节点
    /***
     *
     * @param target 查找的的需要删除的目标节点，需要进行值替换
     * @param parent 需要删除的叶子节点的父节点
     * @param end 需要删除的叶子节点
     * @param direction 通过两位来表示四种不同的情况，其中第一位0表示左孩子，1表示右孩子，
     * 第二位表示其左右孩子是否有后续的相同方向的孩子节点进行不同的后续处理，其中0表示没有后续相同的方向的孩子节点，1表示后续有相同方向的孩子节点
     */
    static void SwapAndDelete(TreeNode* _target,TreeNode* _parent,TreeNode* _end,int _1_direction,int _2_direction){
        switch (_1_direction) {
            case 0:
                switch (_2_direction) {
                    case 0:
                        _target->SetValue(_end->GetValue());
                        _parent->SetLeftChild(_end->GetLeftNode());
                        delete _end;
                        break;
                    case 1:
                        _target->SetValue(_end->GetValue());
                        _parent->SetRightChild(_end->GetLeftNode());
                        delete _end;
                        break;
                    default:
                        break;
                }
            case 1:
                switch (_2_direction) {
                    case 0:
                        _target->SetValue(_end->GetValue());
                        _parent->SetRightChild(_end->GetRightNode());
                        delete _end;
                        break;
                    case 1:
                        _target->SetValue(_end->GetValue());
                        _parent->SetLeftChild(_end->GetRightNode());
                        delete _end;
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
    }

    //递归删除节点，进行数据结构的完全析构
    //搭配析构函数进行使用，在程序退出时，进行调用，对所有的节点进行删除
    void deleteComplete(TreeNode *node) {
        if (node == nullptr)
            return;
        if (node->GetLeftNode() != nullptr)
            deleteComplete(node->GetLeftNode());
        if (node->GetRightNode() != nullptr)
            deleteComplete(node->GetRightNode());
        delete node;
    }

    ~BinarySearchTree() {
        deleteComplete(root);
    }
};

#endif //INC_408DS_BINARYSEARCHTREE_H
