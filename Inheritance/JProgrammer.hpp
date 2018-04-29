//
//  JProgrammer.hpp
//  inheritance
//
//  Created by Emil Iliev on 29.04.18.
//  Copyright © 2018 Emil Iliev. All rights reserved.
//

#ifndef JProgrammer_hpp
#define JProgrammer_hpp

#include <stdio.h>
#include "Worker.hpp"

class JProgrammer: public Worker {
    
    
    char* pLanguage;
    void erase() {
        delete [] pLanguage;
        pLanguage = nullptr;
    }
    
    void copyFrom(const JProgrammer& other) {
        setLanguage(other.pLanguage);
    }
    
public:
    
    JProgrammer();
    JProgrammer(char* _name, double newSalary, char* _lang, WorkingTime _wTime);
    JProgrammer(const JProgrammer& other);
    JProgrammer& operator=(const JProgrammer& other);
    ~JProgrammer();
    
    void setLanguage(char* newLang);
    const char* getLanguage() const;
};

#endif /* JProgrammer_hpp */
