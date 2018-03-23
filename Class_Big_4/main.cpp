//
//  main.cpp
//  dynamic_array
//
//  Created by Emil Iliev on 3/23/18.
//  Copyright © 2018 Emil Iliev. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cstring>

#define MAX_BUFFER_SIZE 1000

using namespace std;

class Student {
    
    int fn;
    char* name;
    
    void copyFrom(const Student& other) {
        setFN(other.fn);
        setName(other.name);
    }
    
public:
    
    Student(): fn(10), name(nullptr){
        cout<<"Default student created\n";
    }
    
    Student(int _fn, char* _name): name(nullptr){
        setFN(_fn);
        setName(_name);
    }
    
    Student(const Student& other): name(nullptr) {
        copyFrom(other);
    }
    
    Student& operator=(const Student& other) {
        if (this != &other){
            copyFrom(other);
        }
        
        return *this;
    }
    
    ~Student() {
        delete [] name;
    }
    
    void setFN( int _fn) {
        if (_fn > 0) {
            fn = _fn;
        } else {
            cout<<"Wrong FN\n";
        }
    }
    
    int getFN() const {
        return fn;
    }
    
    void setName(char* _studentName) {
        delete [] name;
        
        int length = strlen(_studentName) + 1;
        name = new char[length];
        strcpy(name, _studentName);
    }
    
    char* getName() const {
        return name;
    }
};

void removeFirstSymbol(char* text) {
    text++;
    cout<<text<<endl;
}



class Group {
    
    Student* students;
    int numStudents;
    int studentCapacity;
    
    void copyFrom(const Group& other) {
        students = new Student[other.studentCapacity];
        
        numStudents = other.numStudents;
        studentCapacity = other.studentCapacity;
        
        for (int index = 0; index < numStudents; ++index) {
            students[index] = other.students[index];
        }
    }
    
    void resize() {
        studentCapacity *= 2;
        Student* tempStudentGroup = new Student[studentCapacity];
        
        for(int index = 0; index < numStudents; ++index) {
            tempStudentGroup[index] = students[index];
        }
    
        delete [] students;
        students = tempStudentGroup;
    }
    
    void writeToFile(char* fileName, const Student& other) {
        ofstream output(fileName, ios::app);
        
        if (output) {
            output<<other.getFN()<<" "<<other.getName()<<endl;
        }
        
        output.close();
    }
    
    
public:
    
    Group(): numStudents(0), studentCapacity(1){
        students = new Student[studentCapacity];
    }
    
    Group(const Group& other) {
        copyFrom(other);
    }
    
    Group& operator=(const Group& other) {
        if (this != &other) {
            copyFrom(other);
        }
        return *this;
    }
    
    ~Group() {
        delete [] students;
    }
    
    Student getStudent(int index) {
        if (index < numStudents) {
            return students[index];
        }
        return Student();
    }
    
    void addStudent(const Student& student, bool shouldWriteToFile = true) {
        if (numStudents * 2 >= studentCapacity){
            resize();
        }
            students[numStudents] = student;
            numStudents += 1;
        
        // Write to file if neccessary
        if (shouldWriteToFile) {
            writeToFile("students.txt", student);
        }
    }
    
    int getNumberOfStudents() {
        return numStudents;
    }
    
    void readFromFile(char* fileName) {
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
   
};

int main(int argc, const char * argv[]) {

    Group students;
    
   
    students.readFromFile("students.txt");
    
    for( int index = 0; index < students.getNumberOfStudents(); ++index) {
        Student tempStudent = students.getStudent(index);
        cout<<tempStudent.getFN()<<" "<<tempStudent.getName()<<endl;
    }
    
    cout<<"Enter student fn\n";
    int newStudentFN;
    cin>>newStudentFN;
    
    cout<<"Enter student Name\n";
    cin.ignore();
    char buffer[MAX_BUFFER_SIZE];
    cin.getline(buffer, MAX_BUFFER_SIZE);
    
    Student newStudent(newStudentFN, buffer);
    students.addStudent(newStudent);
    
    return 0;
}
