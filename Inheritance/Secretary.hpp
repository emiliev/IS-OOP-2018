//
//  Secretary.hpp
//  inheritance
//
//  Created by Emil Iliev on 29.04.18.
//  Copyright © 2018 Emil Iliev. All rights reserved.
//

#ifndef Secretary_hpp
#define Secretary_hpp

#include <assert.h>
#include "Worker.hpp"
#include <string.h>

class Secretary: public Worker {
    char** languages;
    int numLanguages;
    
    void erase() {
        for (int index = 0; index < numLanguages; ++index) {
            delete [] languages[index];
        }
        delete [] languages;
        languages = nullptr;
        numLanguages = 0;
    }
    
    
public:
    Secretary();
    Secretary(char* _name, double _salary, char** spokenLanguages, int numOfLanguages, WorkingTime _wTime);
    Secretary(const Secretary& other);
    Secretary& operator=(const Secretary& other);
    ~Secretary();
    
    void setLanguages(char** _languages, int _numLanguages);
    const char*  getLanguageAt(int index) const;
    int getNumberOfLanguages() const;
    
    virtual void represent();
};

#endif /* Secretary_hpp */
