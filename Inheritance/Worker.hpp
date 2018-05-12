//
//  Worker.hpp
//  inheritance
//
//  Created by Emil Iliev on 29.04.18.
//  Copyright © 2018 Emil Iliev. All rights reserved.
//

#ifndef Worker_hpp
#define Worker_hpp

#include <stdio.h>
#include <string.h>
#include <iostream>

enum WorkingTime {
    fixed,
    flexible,
    partTime,
    fullTime,
    
};

class Worker {
    
    char* name;
    double salary;
    WorkingTime workingTime;
    
    void erase() {
        delete [] name;
        name = nullptr;
    }
    
    void copyFrom(const Worker& other) {
        setName(other.name);
        setSalary(other.salary);
        workingTime = other.workingTime;
    }
    
public:
    
    Worker();
    Worker(char* newName, double newSalary, WorkingTime _wTime);
    Worker(const Worker& other);
    Worker& operator=(const Worker& other);
    virtual ~Worker();
    
    void setName(char* newName);
    void setSalary(double newSalary);
    double getSalary() const ;
    const char* getName() const ;
    WorkingTime getWorkingTime() const ;

    virtual void represent();
};


#endif /* Worker_hpp */
