//
//  DynamicArray.hpp
//  templates
//
//  Created by Emil Iliev on 4/13/18.
//  Copyright © 2018 Emil Iliev. All rights reserved.
//

#ifndef DynamicArray_hpp
#define DynamicArray_hpp

#include <stdio.h>
#include <assert.h>
#include <iostream>

using namespace std;

template <typename T>
class DynamicArray{
    
    T* items;
    int numItems;
    int capacity;
    
    void copyFrom(const DynamicArray& other) {
        numItems = other.numItems;
        capacity = other.capacity;
        
        items = new T[capacity];
        for(int index = 0; index < numItems; ++index) {
            items[index] = other.items[index];
        }
    }
    
    void erase() {
        delete [] items;
        numItems = 0;
        capacity = 0;
    }
    
    void resize() {
        capacity *= 2;
        T* itemsBuffer = new T[capacity];
        
        for(int index = 0; index < numItems; ++index ) {
            itemsBuffer[index] = items[index];
        }
    
        delete [] items;
        items = itemsBuffer;
    }
    
    public:
    
    DynamicArray() {
        cout<<"Default dynamic array created\n";
        numItems = 0;
        capacity = 2;
        items = new T[capacity];
    }
    
    DynamicArray(const DynamicArray& other)  {
        copyFrom(other);
    }
    
    DynamicArray& operator=(const DynamicArray& other) {
        
        if (this != &other) {
            erase();
            copyFrom(other);
        }
        return *this;
    }
    
    ~DynamicArray() {
        erase();
    }
    

    void addItem(const T& other) {
        if (numItems >= capacity) {
            resize();
        }
        items[numItems] = other;
        numItems++;
    }
    
    void addItemBefore(int index) {
        
    }
    
    void addItemAfter(int index) {
        
    }
    
    void removeItemAfter(int index){
        
    }
    
    void removeItemBefore(int index){
        
    }
    
//    ostream operator<<(const ostream& os){}
//    ifstream operator>>(const ifstream& ifs){}
    
    T& getItemAt(int index) {
        assert(index >= 0 && index < numItems);
        return items[index];
    }

    int numberOfItems() {
        return numItems;
    }
    
    int size() {
        return capacity;
    }
};

#endif /* DynamicArray_hpp */













