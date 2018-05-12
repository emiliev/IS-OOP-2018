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

    T getAt(int index) {
        if (!correctIndex(index)) {
            return head->data;
        }
        
        Node<T>* temp = head;
        int tempCounter = 0;
        
        while(tempCounter < index) {
            temp = temp->pNext;
            tempCounter++;
        }
        
        return temp->data;
    }

    bool correctIndex(int index) {
        return index >= 0 && index < size;
    }

    void insertAfter(int index, T data) {
        if (!correctIndex(index)) {
            return;
        }
    
        int tempIndex = 0;
        Node<T>* temp = head;
        
        while(tempIndex < index) {
            temp = temp->pNext;
            tempIndex++;
        }
        
        Node<T>* newNode = new Node<T>(data, temp->pNext);
        temp->pNext = newNode;
        size++;
    }

    void insertBefore(int index, T data) {
        if (!correctIndex(index)) {
            return;
        }
        
        if (index == 0) {
            // insert new head
            insertHead(data);
            return;
        }
        
        int tempIndex = 0 ;
        Node<T>* temp = head;
        
        while(tempIndex < index - 1) {
            tempIndex++;
            temp = temp->pNext;
        }

        Node<T>* newNode = new Node<T>(data,temp->pNext);
        temp->pNext = newNode;
        size++;
    }

    void insertHead(T data) {
        Node<T>* newHead = new Node<T>(data, head);
        head = newHead;
        size++;
    }
    
    void removeAt(int index) {
        if(!correctIndex(index)) {
            return;
        }
        
        if (index == 0) {
            removeHead();
        } else if (index == size - 1) {
            removeTail();
        } else {
        
            int tempCounter = 0;
            Node<T>* temp = head;
            
            while(tempCounter < index - 1) {
                tempCounter++;
                temp = temp->pNext;
            }
            
            Node<T>* removedNode = temp->pNext;
            temp->pNext = removedNode->pNext;
            delete removedNode;
            size--;
        }
    }

    void removeHead() {
        Node<T>* tempNode = head;
        head = head->pNext;
        delete tempNode;
        size--;
    }
    
    void removeTail() {
        Node<T>* temp = head;
        
        while(temp->pNext != tail) {
            temp = temp->pNext;
        }
        
        delete tail;
        tail = temp;
        tail->pNext = nullptr;
        size--;
    }
    
    void reverse() {
        Node<T>* prevNode = nullptr; // pointer to the previous node
        Node<T>* nextNode = nullptr; // pointer to the current node
        Node<T>* currentNode = head; // pointer to the next node
        
        tail = currentNode; // move the tail to the first node
        
        while(currentNode) {
            nextNode = currentNode->pNext; // move to the next node
            currentNode->pNext = prevNode; // "reversing" the pointer so that it points to the previous node (not the next)
            prevNode = currentNode; // move the previous pointer to the current node
            currentNode = nextNode; // moving to the next node
        }
        
        head = prevNode; // moveing the head to the
    }
    
    T findMid() {
        Node<T>* temp = head;
        Node<T>* fastTemp = head;
        
        while(fastTemp) {
            fastTemp = fastTemp->pNext;
            if (fastTemp) {
                fastTemp = fastTemp->pNext;
                temp = temp->pNext;
            }
        }
    
        return temp->data;
    }

    void findEven() {
        Node<T>* temp = head;
        
        while (temp) {
            if (temp->data % 2 == 0) {
                cout<<temp->data<<endl;
            }
            
            temp = temp->pNext;
        }
    }

    void map( void (*func) ( T ) )
    {
        for(int index = 0; index < size; ++index) {
            T tempElem = getAt(index);
            func(tempElem);
        }
    }
};
































