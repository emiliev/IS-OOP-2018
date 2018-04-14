//
//  Student.hpp
//  templates
//
//  Created by Emil Iliev on 4/13/18.
//  Copyright © 2018 Emil Iliev. All rights reserved.
//

#ifndef Student_hpp
#define Student_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
#define MAX_BUFFER_SIZE 1000
class Student {
    
    int fn;
    char* name;
    
    void copyFrom(const Student& other);

    public:
    
    Student();
    Student(int _fn, char* _name);
    Student(const Student& other);
    Student& operator=(const Student& other);
    ~Student();
    void setFN(int _fn);
    int getFN() const ;
    void setName(char* _studentName);
    char* getName() const;
};

#endif /* Student_hpp */
