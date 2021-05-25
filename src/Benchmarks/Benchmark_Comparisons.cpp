#include<iostream>
#include<chrono>
#include <time.h>
#include "MathsFNS.h"

/*In the code bellow benchmarks for scalar and vectorized functions which implement the procedure of comparison are made.*/

void Benchmark_Comparisons(const int n){
    std::cout<<std::endl << "Comparisons Vectorization: "<<std::endl;
    
    /* initialize random seed: */
    srand (time(NULL));

    /*Initalize Data*/ 
    float vec[n],vec2[n];
    for (int i=0;i<n;i++){vec[i]= rand() % 1000 + 1;}
    for (int i=0;i<n;i++){vec2[i]= rand() % 1000 + 1;}

    /*Classic Comparison Benchmark*/
    auto start = std::chrono::steady_clock::now();
    classic_comparison(vec,vec2,n);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "Classic Comparison Equality Function elapsed time: " << elapsed_seconds.count() << "s\n";

    /*Vectorized128 Comparison Benchmark*/
    start = std::chrono::steady_clock::now();
    comparison_vectorized128(vec,vec2,n);
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end-start;
    std::cout << "Vectorized128 Comparison Equality Function elapsed time: " << elapsed_seconds.count() << "s\n";

    /*Vectorized256 Comparison Benchmark*/
    start = std::chrono::steady_clock::now();
    comparison_vectorized256(vec,vec2,n);
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end-start;
    std::cout << "Vectorized256 Comparison Equality Function elapsed time: " << elapsed_seconds.count() << "s\n";
}