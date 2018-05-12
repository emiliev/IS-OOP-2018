//
//  TeamLeader.cpp
//  inheritance
//
//  Created by Emil Iliev on 29.04.18.
//  Copyright © 2018 Emil Iliev. All rights reserved.
//

#include "TeamLeader.hpp"


TeamLeader::TeamLeader(): SProgramer("Foo", 1235, "Go", fullTime, 101) { }

TeamLeader::TeamLeader(char* name, double salary, char* pLang, WorkingTime wTime, int number):
SProgramer(name,salary,pLang,wTime, number) {}

void TeamLeader::represent() {
    SProgramer::represent();
}

void TeamLeader::addProgramer(char type) {
    JProgrammer* newProgrammer = createWorker(type);
    list.addItem(newProgrammer);
}

JProgrammer* TeamLeader::createWorker(char type) {
    char nameBuffer[256];
    char pLanguageBuffer[256];
    double tempSalary;
    
    cout<<"Enter name: ";
    cin.getline(nameBuffer, 256);
    cout<<"Enter prog language: ";
    cin.getline(pLanguageBuffer, 256);
    cout<<"Enter salary: ";
    cin>>tempSalary;
    cin.ignore();

    switch (type) {
        case 'S':
            int numBooks;
            cout<<"Enter num books: ";
            cin>> numBooks;
            cin.ignore();
            return new SProgramer(nameBuffer, tempSalary, pLanguageBuffer, fullTime,numBooks);
        default:
            return new JProgrammer(nameBuffer,
                                   tempSalary,
                                   pLanguageBuffer,
                                   fullTime);
    }
}

void TeamLeader::printSalaries() {
    list.map( [] (JProgrammer* programmer) { std::cout<<programmer->getSalary()<<"\n"; });
}


void TeamLeader::printSeniors() {
    list.map( [] (JProgrammer* programmer) {
            SProgramer* tempSenior = dynamic_cast<SProgramer*>(programmer);
            if(tempSenior)  {
                tempSenior->represent();
            }
        });
}

void TeamLeader::printWorkers() {
     list.map( [] (JProgrammer* programmer) { programmer->represent(); }
              );
}

TeamLeader::~TeamLeader() {
    for(int index = 0; index < list.getSize(); ++index) {
        delete list.getAt(index);
    }
}
    
 JProgrammer* TeamLeader::getWorkerAt(int index) {
    return list.getAt(index);
}
    
    
    
    
    
    
    
    
    
