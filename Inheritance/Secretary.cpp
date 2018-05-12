
//  Secretary.cpp
//  inheritance
//
//  Created by Emil Iliev on 29.04.18.
//  Copyright © 2018 Emil Iliev. All rights reserved.
//

#include "Secretary.hpp"

Secretary::Secretary(): languages(nullptr) {
    numLanguages = 0;
}

Secretary::Secretary(char* _name, double _salary, char** spokenLanguages, int numOfLanguages, WorkingTime _wTime):
    Worker(_name,_salary, _wTime),
    languages(nullptr)
{
    setLanguages(spokenLanguages, numOfLanguages);
}

Secretary::Secretary(const Secretary& other): Worker(other), languages(nullptr) {
    setLanguages(other.languages, other.numLanguages);
}

Secretary& Secretary::operator=(const Secretary& other) {
    if (this != &other) {
        Worker::operator=(other);
        // no need to call erase, it's being called in the setter
        setLanguages(other.languages, other.numLanguages);
    }
    
    return *this;
}

Secretary::~Secretary() {
    erase();
}

void Secretary::setLanguages(char** _languages, int _numLanguages) {
    erase();
    numLanguages = _numLanguages;
    languages = new char*[numLanguages];
    for(int index = 0; index < numLanguages; ++index) {
        size_t languageLength = strlen(_languages[index]) + 1;
        languages[index] = new char[languageLength];
        strcpy(languages[index], _languages[index]);
    }
}

const char*  Secretary::getLanguageAt(int index) const {
    assert(index >= 0 && index < numLanguages);
    return languages[index];
}

int Secretary::getNumberOfLanguages() const {
    return numLanguages;
    }

void Secretary::represent() {
    Worker::represent();
}
