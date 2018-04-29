//
//  SProgrammer.hpp
//  inheritance
//
//  Created by Emil Iliev on 29.04.18.
//  Copyright © 2018 Emil Iliev. All rights reserved.
//

#ifndef SProgrammer_hpp
#define SProgrammer_hpp

#include <stdio.h>
#include "JProgrammer.hpp"

class SProgramer: public JProgrammer {
    int numBooks;
    
public:
    SProgramer();
    SProgramer(char* name, double salary, char* newLanguage,WorkingTime _wTime, int readBooks);
    
    void setBooks(int numOfBooks);
    int getBooks();
};


#endif /* SProgrammer_hpp */
