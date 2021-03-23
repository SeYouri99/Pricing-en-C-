//
//  Option.cpp
//  Projet
//
//  Created by Youri Semaan on 25/11/2020.
//  Copyright © 2020 Youri Semaan. All rights reserved.
//

#include "Option.hpp"


// Constructors

Option::Option(char type_, float k, float t)
{
    type = type_;
    K = k;
    T = t;

}

Option::Option(const Option& source)
{
    type = source.type;
    K = source.K;
    T = source.T;
}
