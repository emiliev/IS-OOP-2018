//
//  JProgrammer.cpp
//  inheritance
//
//  Created by Emil Iliev on 29.04.18.
//  Copyright © 2018 Emil Iliev. All rights reserved.
//

#include "JProgrammer.hpp"
JProgrammer::JProgrammer(): pLanguage(nullptr) {}

JProgrammer::JProgrammer(char* _name, double newSalary, char* _lang, WorkingTime _wTime): Worker(_name, newSalary, _wTime), pLanguage(nullptr)
{
    setLanguage(_lang);
}

JProgrammer::JProgrammer(const JProgrammer& other): Worker(other), pLanguage(nullptr) {
    copyFrom(other);
}

JProgrammer& JProgrammer::operator=(const JProgrammer& other)
{
    if (this != &other) {
        Worker::operator=(other);
        erase();
        copyFrom(other);
    }
    return *this;
}

JProgrammer::~JProgrammer() {
    erase();
}

void JProgrammer::setLanguage(char* newLang) {
    
    delete [] pLanguage;
    size_t length = strlen(newLang) + 1;
    pLanguage = new char[length];
    strcpy(pLanguage, newLang);
}

const char* JProgrammer::getLanguage() const {
    return pLanguage;
}

void JProgrammer::represent() {
    Worker::represent();
    std::cout<<"Prog language: "<<pLanguage<<"\n";
}

