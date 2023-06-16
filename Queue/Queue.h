//
// Created by 少迟 on 2023/6/7.
//

#ifndef INC_408DS_QUEUE_H
#define INC_408DS_QUEUE_H

class Node{
private:
    int value;
    Node* next;
public:
    Node(int _value,Node* _ptr):value(_value),next(_ptr){};
    Node(){};
    Node* GetNext(){
        return this->next;
    }
    void SetNext(Node* node){
        this->next= node;
    }
    int GetValue() const{
        return this->value;
    }
};

/// \comment 队列实现，链式队列，采用带头尾指针的队列实现
class Queue{
private:
    Node* head;
    Node* tail;;
public:
    void push(int _value){
        if(head->GetNext()== nullptr){
            Node* node = new Node(_value, nullptr);
            tail = node;
            head->SetNext(node);
        }else{
            Node* node = new Node(_value, nullptr);
            tail->SetNext(node);
            tail = node;
        }
    }

    int pop(){
        int value;
        Node* node;
        if(head->GetNext()==tail){
            value = head->GetNext()->GetValue();
            node = head->GetNext();
            head->SetNext(nullptr);
            tail = new Node(0, nullptr);
        }else{
            node = head->GetNext();
            value =node->GetValue();
            head->SetNext(node->GetNext());
        }
        delete node;
        return value;
    }

    bool isEmpty(){
        if (head->GetNext()== nullptr)
            return true;
        else
            return false;
    }

    Queue(): head(new Node(0, nullptr)), tail(new Node(0, nullptr)){}
};

#endif //INC_408DS_QUEUE_H
