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
using namespace std;


int main(int argc, const char * argv[]) {
    
    SProgramer sPesho("Pesho", 5000, "C++", fullTime, 1);
    SProgramer sGosho;
    
    char* spokenLanguages[] = {"Bulgarian", "English", "Deutsch"};
    
    Secretary penka("Penka", 1000, spokenLanguages, 3, fullTime);
    cout<<penka.getLanguageAt(2);
    
    sGosho = sPesho;
    cout<<sGosho.getBooks()<<" "
        <<sGosho.getLanguage()<<" "
        <<sGosho.getSalary()<<" "
        <<sGosho.getName()<<endl;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}
