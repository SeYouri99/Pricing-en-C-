//
//  Option.hpp
//  Projet
//
//  Created by Youri Semaan on 25/11/2020.
//  Copyright © 2020 Youri Semaan. All rights reserved.
//

#ifndef Option_hpp
#define Option_hpp


#include <stdio.h>
#pragma once
#include <iostream>

class Option
{
public:

    // Constructors
    
    Option(char, float, float);       //  Constructor
    Option(const Option&);                                    // Copy Constructor
    char type;            // Call or Put (C or P)
    float K;            // Strike price
    float T;            // Expiry Date

//private:
//    char type;            // Call or Put (C or P)
//    float K;            // Strike price
//    float T;            // Expiry Date
//

};
#endif /* Option_hpp */
