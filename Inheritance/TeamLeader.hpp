//
//  TeamLeader.hpp
//  inheritance
//
//  Created by Emil Iliev on 29.04.18.
//  Copyright © 2018 Emil Iliev. All rights reserved.
//

#ifndef TeamLeader_hpp
#define TeamLeader_hpp

#include <stdio.h>
#include "SProgrammer.hpp"
#include "LinkedList.hpp"

class TeamLeader: public SProgramer {
    LinkedList<JProgrammer*> list;
    
    JProgrammer* createWorker(char type);
    
public:
    TeamLeader();
    TeamLeader(char* name, double salaray, char* pLang, WorkingTime wTime, int numBooks);
    ~TeamLeader();
    
    void addProgramer(char type);
    
    void printWorkers();
    void printSeniors();
    void printSalaries();
    virtual void represent();
    
    JProgrammer* getWorkerAt(int index);
};

#endif /* TeamLeader_hpp */












