//
//  Group.hpp
//  templates
//
//  Created by Emil Iliev on 4/13/18.
//  Copyright © 2018 Emil Iliev. All rights reserved.
//

#ifndef Group_hpp
#define Group_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include "DynamicArray.hpp"
#include "Student.hpp"
using namespace std;

#define MAX_BUFFER_SIZE 1000

class Group {
    
    DynamicArray<Student> students;
    
public:
    Group(){}
    Student& getStudentAt(int index);
    int numStudents();
    int studentCap();
    void readFromFile(char* fileName);
    void addStudent(const Student& student, bool shouldWriteToFile = true);
    void writeToFile(char* fileName, const Student& other);
    void print();
};



#endif /* Group_hpp */
