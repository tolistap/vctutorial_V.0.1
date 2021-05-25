#include<iostream>
#include<chrono>
#include <time.h>
#include "MathsFNS.h"


/*In the code bellow benchmarks for scalar and vectorized functions which implement the procedure of dot product calculation are made.*/

void Benchmark_Dotproduct(const int n){
    std::cout<<std::endl << "Dotproduct Vectorization: "<<std::endl;
    
    /* initialize random seed: */
    srand (time(NULL));

    float vec[n];
    int test[n];
    for (int i=0;i<n;i++){vec[i]= rand() % 1000 + 1;}
    for (int i=0;i<n;i++){test[i]= rand() % 10 + 1;}

     /*Dot Product int Scalar Benchmark*/
    auto start = std::chrono::steady_clock::now();
    std::cout<<"output: " <<scalar_dot_int_product(test,n);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << " || Scalar int Dot product elapsed time: " << elapsed_seconds.count() << "s\n";


    /*Dot Product Vectorized w1 Benchmark*/
    start = std::chrono::steady_clock::now();
    std::cout<<"output: " <<dot_product_vectorized128w1(test,n);
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end-start;
    std::cout << " || Vectrorized Dot product128w1 int (with hadd) elapsed time: " << elapsed_seconds.count() << "s\n";

    /*Dot Product Vectorized w2 Benchmark*/
    start = std::chrono::steady_clock::now();
    std::cout<<"output: " <<dot_product_vectorized128w2(test,n);
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end-start;
    std::cout << " || Vectrorized Dot product128w2 int (without hadd) elapsed time: " << elapsed_seconds.count() << "s\n";

    /*Dot Product Vectorized 256 Benchmark*/
    start = std::chrono::steady_clock::now();
    std::cout<<"output: " <<dot_product_vectorized256iw1(test,n);
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end-start;
    std::cout << " || Vectrorized Dot product256w1 int (without hadd) elapsed time: " << elapsed_seconds.count() << "s\n";
    
    /*Dot Product Vectorized 256 Benchmark*/
    start = std::chrono::steady_clock::now();
    std::cout<<"output: " <<dot_product_vectorized256iw2(test,n);
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end-start;
    std::cout << " || Vectrorized Dot product256w2 int (without hadd) elapsed time: " << elapsed_seconds.count() << "s\n";
 

    /*Dot Product float Scalar Benchmark*/
    start = std::chrono::steady_clock::now();
    scalar_dot_f_product(vec,n);
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end-start;
    std::cout << "Scalar float Dot product elapsed time: " << elapsed_seconds.count() << "s\n";
    
    /*Dot Product float Vectorized Benchmark*/
    start = std::chrono::steady_clock::now();
    dot_product_vectorized128w3(vec,n);
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end-start;
    std::cout << "Vectrorized Dot product float with _mm_dp_ps elapsed time: " << elapsed_seconds.count() << "s\n";

 }   