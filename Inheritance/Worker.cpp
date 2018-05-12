//
//  Worker.cpp
//  inheritance
//
//  Created by Emil Iliev on 29.04.18.
//  Copyright © 2018 Emil Iliev. All rights reserved.
//

#include "Worker.hpp"

Worker::Worker(): name(nullptr) {
    salary = 1;
    workingTime = fullTime;
}

Worker::Worker(char* newName, double newSalary, WorkingTime _wTime): name(nullptr) {
    setName(newName);
    setSalary(newSalary);
    workingTime = _wTime;
}

Worker::~Worker() {
    if (name) {
        std::cout<<"triesh rabotnik s ime: "<< name<<std::endl;
    }
    erase();
}

Worker& Worker::operator=(const Worker& other) {
    if (this != &other){
        erase();
        copyFrom(other);
    }
    return *this;
}

Worker::Worker(const Worker& other): name(nullptr) {
    copyFrom(other);
}

void Worker::setName(char* newName) {
    delete [] name;
    size_t length = strlen(newName) + 1;
    name = new char[length];
    strcpy(name, newName);
}

void Worker::setSalary(double newSalary) {
    if (newSalary > 0) {
        salary = newSalary;
    } else {
        salary = 1;
    }
}

double Worker::getSalary() const {
    return salary;
}

const char* Worker::getName() const {
    return name;
}

WorkingTime Worker::getWorkingTime() const {
    return workingTime;
}

void Worker::represent() {
    std::cout<<"My name is: "<<name<<" working time: "<<workingTime<<" Salary: "<< salary<<std::endl;
}

