#include "memFNS.h"
#include<iostream>
#include<chrono>


/*In the code bellow benchmarks for scalar and vectorized functions which implement the procedure of memory set are made.*/

void Benchmark_memset() {
    std::cout<<std::endl << "memset Function Vectorization: "<<std::endl;
    
    /*alocate memory for benchmars*/
    int size = 1000000;
    char *buf1 = (char *) malloc(size);
    if (buf1 == NULL) {
        std::cout<<"Failed to allocate memory 1000000 bytes";                   
        exit(1); // error!
    }

    /*system memset function Benchmark*/
    auto start = std::chrono::steady_clock::now();
    memset(buf1,'$',size);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "System memset function elapsed time:: " << elapsed_seconds.count() << "s\n";

    /*scalar memset function Benchmark*/
    start = std::chrono::steady_clock::now();
    scalar_memset(buf1,'$',size);
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end-start;
    std::cout << "Scalar memset function elapsed time: " << elapsed_seconds.count() << "s\n";


    /*vectorized memset function Benchmark*/
    start = std::chrono::steady_clock::now();
    vectorized_memset128i(buf1,'$',size);
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end-start;
    std::cout << "Vectorized memset function elapsed time: " << elapsed_seconds.count() << "s\n";
    

    /*vectorized memset256i function Benchmark*/
    start = std::chrono::steady_clock::now();
    vectorized_memset256i(buf1,'$',size);
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end-start;
    std::cout << "Vectorized memset256 function elapsed time: " << elapsed_seconds.count() << "s\n";
    
    /*dealocate memory for benchmariking*/
    free(buf1);

} 
