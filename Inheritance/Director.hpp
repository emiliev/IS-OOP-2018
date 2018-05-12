//
//  Director.hpp
//  inheritance
//
//  Created by Emil Iliev on 29.04.18.
//  Copyright © 2018 Emil Iliev. All rights reserved.
//

#ifndef Director_hpp
#define Director_hpp

#include <stdio.h>
#include "Worker.hpp"
#include "DynamicArray.hpp"
#include "Secretary.hpp"
#include "JProgrammer.hpp"
#include "SProgrammer.hpp"
#include "TeamLeader.hpp"

class Director: public Worker {
    
    DynamicArray<Worker*> workers;
    
    void createSecretaries(int num);
    void createTLs(int num);
public:
    
    Director();
    ~Director();
    void createCompany();
};



#endif /* Director_hpp */
