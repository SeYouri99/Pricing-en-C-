//
//  main.cpp
//  Projet
//
//  Created by Youri Semaan on 30/10/2020.
//  Copyright © 2020 Youri Semaan. All rights reserved.
//

#include <iostream>
// Projet C++.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Option.hpp"
#include "Pricing.hpp"

int main()
{

    char type1;
    float K1, T1, S1, r1, sigma1;

    std::cout << "Enter the type of the option (Call = C, Put = P)" << std::endl;
    std::cin >> type1;
    std::cout << "Enter the Stike Price" << std::endl;
    std::cin >> K1;
    std::cout << "Enter the Expiry Date" << std::endl;
    std::cin >> T1;
    
    Option option1 = Option(type1, K1, T1);
                            
    std::cout << "Enter the Underlaying Price" << std::endl;
    std::cin >> S1;
    std::cout << "Enter the Interest rate" << std::endl;
    std::cin >> r1;
    std::cout << "Enter the Volatility" << std::endl;
    std::cin >> sigma1;
    
    Pricing pricing1 = Pricing(S1,r1,sigma1);
    
    
    double call = pricing1.call_price(option1, S1, r1, sigma1);
    double put = pricing1.put_price(option1, S1, r1, sigma1);

    // Finally we output the parameters and prices
    std::cout << "Underlying:      " << S1 << std::endl;
    std::cout << "Strike:          " << K1 << std::endl;
    std::cout << "Risk-Free Rate:  " << r1 << std::endl;
    std::cout << "Volatility:      " << sigma1 << std::endl;
    std::cout << "Maturity:        " << T1 << std::endl;

    std::cout << "Call Price:      " << call << std::endl;
    std::cout << "Put Price:       " << put << std::endl;

    return 0;
    

    /*
    // Exercice 2: EVO CRR

    char type2;
    int N;
    float K2, S0, r2, sigma2;

    std::cout << "Enter the type of the option (Call = C, Put = P)" << std::endl;
    std::cin >> type2;
    std::cout << "Enter the Stike Price" << std::endl;
    std::cin >> K2;
    std::cout << "Enter the Expiry Date" << std::endl;
    std::cin >> N;
    std::cout << "Enter the Underlaying Price" << std::endl;
    std::cin >> S0;
    std::cout << "Enter the Interest rate" << std::endl;
    std::cin >> r2;
    std::cout << "Enter the Volatility" << std::endl;
    std::cin >> sigma2;

    EOCRR option2 = EOCRR(type2, K2, N, S0, r2, sigma2);
    float** matrix = option2.CalculPriceIterative();
     */
}
