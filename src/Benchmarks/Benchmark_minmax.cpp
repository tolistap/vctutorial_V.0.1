#include<iostream>
#include<chrono>
#include <time.h>   
#include <cstring>
#include "MathsFNS.h"


/*In the code bellow benchmarks for scalar and vectorized functions which implement the procedure of min max calculation are made.*/

void Benchmark_minmax(const int n){
    std::cout << "Min Max Vectorization: "<<std::endl;
    /* initialize random seed: */
    srand (time(NULL));

    /*Initalize Data*/ 
    float vec[n];     
    for (int i=0;i<n;i++){vec[i]= rand() % 1000 + 1;}
    
    /*Scalar max Benchmark*/
    auto start = std::chrono::steady_clock::now();
    scalar_max(vec,n);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "Scalar max Function elapsed time: " << elapsed_seconds.count() << "s\n";

    /*Vectorized128 max Benchmark*/
    start = std::chrono::steady_clock::now();
    max_vectorized128(vec,n);
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end-start;
    std::cout << "Vectorized128 max Function elapsed time: " << elapsed_seconds.count() << "s\n";

    /*Vectorized256 max Benchmark*/
    start = std::chrono::steady_clock::now();
    max_vectorized256(vec,n);
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end-start;
    std::cout << "Vectorized256 max Function elapsed time: " << elapsed_seconds.count() << "s\n";

    /*Classic min Benchmark*/
    start = std::chrono::steady_clock::now();
    scalar_min(vec,n);
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end-start;
    std::cout << "Scalar min Function elapsed time: " << elapsed_seconds.count() << "s\n";

    /*Vectorized128 min Benchmark*/
    start = std::chrono::steady_clock::now();
    min_vectorized128(vec,n);
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end-start;
    std::cout << "Vectorized128 min Function elapsed time: " << elapsed_seconds.count() << "s\n";

    /*Vectorized256 min Benchmark*/
    start = std::chrono::steady_clock::now();
    min_vectorized256(vec,n);
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end-start;
    std::cout << "Vectorized256 min Function elapsed time: " << elapsed_seconds.count() << "s\n";
         
}





