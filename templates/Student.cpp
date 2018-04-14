//
//  Student.cpp
//  templates
//
//  Created by Emil Iliev on 4/13/18.
//  Copyright © 2018 Emil Iliev. All rights reserved.
//

#include "Student.hpp"

Student::Student(): fn(10), name(nullptr){}

Student::Student(int _fn, char* _name): name(nullptr){
    setFN(_fn);
    setName(_name);
}

Student::Student(const Student& other): name(nullptr) {
    copyFrom(other);
}

Student& Student::operator=(const Student& other) {
    if (this != &other){
        copyFrom(other);
    }
    
    return *this;
}

Student::~Student() {
    delete [] name;
}

void Student::setFN( int _fn) {
    if (_fn > 0) {
        fn = _fn;
    } else {
        cout<<"Wrong FN\n";
    }
}

int Student::getFN() const {
    return fn;
}

void Student::setName(char* _studentName) {
    delete [] name;
    
    int length = strlen(_studentName) + 1;
    name = new char[length];
    strcpy(name, _studentName);
}

char* Student::getName() const {
    return name;
}

void Student::copyFrom(const Student& other) {
    setFN(other.fn);
    setName(other.getName());
}

