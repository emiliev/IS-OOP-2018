//
//  main.cpp
//  inheritance
//
//  Created by Emil Iliev on 27.04.18.
//  Copyright © 2018 Emil Iliev. All rights reserved.
//

#include <iostream>
#include "SProgrammer.hpp"
#include "Director.hpp"
#include "Secretary.hpp"
#include "TeamLeader.hpp"


using namespace std;


class Task {
    
public:
    Task() {
        cout<<id<<endl;
        Task::id += 1;
    }
    
    ~Task() {
        Task::id -= 1;
    }
    static unsigned int id;
};


class BTask: public Task {
    
    
};
unsigned int Task::id = 0;

int main(int argc, const char * argv[]) {
    
//    SProgramer sPesho("Pesho", 5000, "C++", fullTime, 1);
//    SProgramer sGosho;
//
//    char* spokenLanguages[] = {"Bulgarian", "English", "Deutsch"};
//
//    Secretary penka("Penka", 1000, spokenLanguages, 3, fullTime);
//    cout<<penka.getLanguageAt(2);
    
//    sGosho = sPesho;
//    cout<<sGosho.getBooks()<<" "
//    <<sGosho.getLanguage()<<" "
//    <<sGosho.getSalary()<<" "
//    <<sGosho.getName()<<endl;
////
//
    Task t1;
    Task t4;
    BTask t2;

    cout<<Task::id<<endl;
////    TeamLeader emo;
//    emo.addProgramer('z');
//    emo.addProgramer('S');
//    emo.printWorkers();
//
//    cout<<"*******************\n";
//    emo.printSeniors();
//    emo.printSalaries();
    
//    Director dir;
//    dir.createCompany();
    
    
    return 0;
}
