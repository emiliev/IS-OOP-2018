//
//  SProgrammer.cpp
//  inheritance
//
//  Created by Emil Iliev on 29.04.18.
//  Copyright © 2018 Emil Iliev. All rights reserved.
//

#include "SProgrammer.hpp"
SProgramer::SProgramer() {
    numBooks = 0;
}

SProgramer::SProgramer(char* name, double salary, char* newLanguage,WorkingTime _wTime, int readBooks): JProgrammer(name,salary,newLanguage, _wTime){
    
    setBooks(readBooks);
}

void SProgramer::setBooks(int numOfBooks) {
    if (numOfBooks > 0) {
        numBooks = numOfBooks;
    } else {
        numBooks = 1;
    }
}

int SProgramer::getBooks() {
    return numBooks;
}

void SProgramer::represent() {
    JProgrammer::represent();
    std::cout<<"num books:"<<numBooks<<std::endl;
}

