//
//  main.cpp
//  templates
//
//  Created by Emil Iliev on 4/13/18.
//  Copyright © 2018 Emil Iliev. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cstring>
#include "Group.hpp"
#include "Student.hpp"
#include "DynamicArray.hpp"

#include "LinkedList.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
//
//    Group students;
//
//
//    students.readFromFile("students.txt");
//    students.print();
////
//    for( int index = 0; index < students.getNumberOfStudents(); ++index) {
//        Student tempStudent = students.getStudent(index);
//        cout<<tempStudent.getFN()<<" "<<tempStudent.getName()<<endl;
//    }
//
//    cout<<"Enter student fn\n";
//    int newStudentFN;
//    cin>>newStudentFN;
//
//    cout<<"Enter student Name\n";
//    cin.ignore();
//    char buffer[MAX_BUFFER_SIZE];
//    cin.getline(buffer, MAX_BUFFER_SIZE);
//
//    Student newStudent(newStudentFN, buffer);
//    students.addStudent(newStudent);
//
    
//    Node<int>* sample;
    
    LinkedList<int> list;
    
    list.addItem(1);
    list.addItem(16);
    list.addItem(15);
    list.addItem(41);
    list.addItem(3);
    list.addItem(2);
    
    list.print();
     
    return 0;
}
