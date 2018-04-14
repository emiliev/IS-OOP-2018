//
//  LinkedList.hpp
//  templates
//
//  Created by Emil Iliev on 4/13/18.
//  Copyright © 2018 Emil Iliev. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>
#include <iostream>
#endif /* LinkedList_hpp */

using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T>* pNext;
    
    Node(T _data, Node<T>* nextP = nullptr) {
        this->data = _data;
        pNext = nextP;
    }
};

template <typename T>
class LinkedList {

    Node<T>* head;
    Node<T>* tail;
    
    size_t size;
    
    void erase() {
        
        Node<T>* tempNode = head;
        Node<T>* oldNode = head;
        
        while(tempNode) {
            oldNode = tempNode;
            tempNode = tempNode->pNext;
            cout<<"Deleting node with data: "<<oldNode->data<<endl;
            delete [] oldNode;
        }
    
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    
    void copyFrom(const LinkedList& other) {
        Node<T>* temp = other.head;
        
        while (temp) {
            addItem(temp->data);
            temp = temp->pNext;
        }
    }
    
public:
    LinkedList(){
        head = 0;
        tail = 0;
        size = 0;
    }
    
    LinkedList(const LinkedList& other) {
        copyFrom(other);
    }
    
    LinkedList& operator=(const LinkedList& other) {
        if (this != &other) {
            erase();
            copyFrom(other);
        }
        
        return *this;
    }
    
    ~LinkedList() {
        erase();
    }
    
    void addItem(T data) {
        Node<T>* temp = new Node<T>(data);
        
        if (head == nullptr) {
            head = temp;
        } else {
            tail->pNext = temp;
        }
        
        tail = temp;
        
        size++;
    }
    
    int getSize() {
        return size;
    }
    
    void print() {
        Node<T>* temp = head;
        while(temp) {
            cout<<temp->data<<endl;
            temp = temp->pNext;
        }
    }
};













