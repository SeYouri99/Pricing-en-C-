////
////  RandomWalkGenerator.cpp
////  Projet
////
////  Created by Youri Semaan on 30/10/2020.
////  Copyright © 2020 Youri Semaan. All rights reserved.
////
//
//#include <iostream>
//#include "RandomWalkGenerator.hpp"
//#include <random>
//using namespace std;
//
///* ONE CONSTRUCTOR */
///*
//RandomWalkGenerator::RandomWalkGenerator()
//{
//    std::random_device rd;                     // Allowing random
//    std::mt19937 generator(rd());
//    enum distribution {normal_distribution,bernoulli_distribution};
//
//    std::cout << std::endl << "We have created the only instance of the singleton class !" << std::endl << std::endl;
//}
//*/
///*
//RandomWalkGenerator& RandomWalkGenerator::generate()  // Returns a reference, a pointer on RandomWalkGenerator
//{
//    static std::unique_ptr<RandomWalkGenerator> instance(new RandomWalkGenerator());    // Create the unique instance of the class (unique pointer)
//    
//    return *instance;                                                                // Returns the pointer on the instance, the reference of the instance
//}
//*/
//
//
//
//
//
//RandomWalkGenerator::RandomWalkGenerator() : n(10),walk(n,0),limit(5.0)
//{
//    
//}
//
//
//RandomWalkGenerator& RandomWalkGenerator::generate(int n,float limit)
//{
//    vector<int> walk;
//    random_device rd;                     // Allowing random
//    mt19937 gen(rd());
//    //enum Distribution { uniform_real_distribution<> dis(-limit, limit),bernoulli_distribution dis(0.5)};
//    uniform_real_distribution<> dis(-limit, limit);
//    
//    int i = 0;
//    while (i < n)
//    {
//        walk[i+1]=walk[i]+dis(gen);
//        i++;
//    }
//    
//    return *walk;
//}
//
