//
//  Group.cpp
//  templates
//
//  Created by Emil Iliev on 4/13/18.
//  Copyright © 2018 Emil Iliev. All rights reserved.
//

#include "Group.hpp"

Student& Group::getStudentAt(int index) {
    return students.getItemAt(index);
}

int Group::numStudents() {
    return students.numberOfItems();
}

int Group::studentCap() {
    return students.size();
}

void Group::readFromFile(char* fileName) {
    ifstream input(fileName);
    
    while (!input.eof())
    {
        
        int tempFN;
        char buffer[MAX_BUFFER_SIZE];
        
        input>>tempFN;
        input>>buffer;
        if (input.good()) {
            Student student(tempFN, buffer);
            
            addStudent(student, false);
        }
    }
    
    input.close();
}

void Group::addStudent(const Student& student, bool shouldWriteToFile) {
    students.addItem(student);
    
    // Write to file if neccessary
    if (shouldWriteToFile) {
        writeToFile("students.txt", student);
    }
    
}

void Group::writeToFile(char* fileName, const Student& other) {
    ofstream output(fileName, ios::app);
    
    if (output) {
        output<<other.getFN()<<" "<<other.getName()<<endl;
    }
    
    output.close();
}

void Group::print() {
    for(int index = 0; index < students.numberOfItems(); ++index) {
        Student student = students.getItemAt(index);
        cout<<student.getName()<<" "<<student.getFN()<<endl;
    }
}
