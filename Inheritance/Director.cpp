//
//  Director.cpp
//  inheritance
//
//  Created by Emil Iliev on 29.04.18.
//  Copyright © 2018 Emil Iliev. All rights reserved.
//

#include "Director.hpp"

Director::Director(): Worker("Pesho", 10000, fullTime)  { }

void Director::createCompany() {
    int numSecretaries, numTL;
    cout<<"Enter number of secretaries: ";
    cin>>numSecretaries;
    
    cout<<"Enter number of TLs: ";
    cin>>numTL;
    
    createSecretaries(numSecretaries);
    createTLs(numTL);
    
}

void Director::createSecretaries(int num) {
    for (int index = 0; index < num; ++index) {
        char nameBuffer[256];
        char* spokenLanguages[256];
        double tempSalary;
        
        cout<<"Enter name: ";
        cin.getline(nameBuffer, 256);
        cout<<"Enter spoken language: ";
        cin.getline(spokenLanguages[0], 256);
        cout<<"Enter salary: ";
        cin>>tempSalary;
        cin.ignore();
        
        Secretary* newSec = new Secretary(nameBuffer, tempSalary, spokenLanguages, 1, fullTime);
        workers.addItem(newSec);
    }
}

void Director::createTLs(int num) {
    for (int index = 0; index < num; ++index) {
        char nameBuffer[256];
        char pLangauge[256];
        double tempSalary;
        int numBooks;
        cout<<"Enter name: ";
        cin.getline(nameBuffer, 256);
        cout<<"Enter pLanguage language: ";
        cin.getline(pLangauge, 256);
        cout<<"Enter salary: ";
        cin>>tempSalary;
        cout<<"Num books: ";
        cin>>numBooks;
        cin.ignore();
        
        TeamLeader* newTL = new TeamLeader(nameBuffer, tempSalary, pLangauge, fullTime, numBooks);
        workers.addItem(newTL);
    }
}

Director::~Director() {
    for(int index = 0; index < workers.size(); ++index) {
        delete workers.getItemAt(index);
    }
    cout<<"director deleted\n";
}










