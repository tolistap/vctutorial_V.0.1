#include"memFNS.h"
#include<iostream>
#include<vector>
#include<chrono>
#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;


/*In the code bellow benchmarks for scalar and vectorized functions which implement the procedure of memory copy are made.*/

void Benchmark_memcpy(){
    std::vector<double> x;

    std::cout<<std::endl << "memcpy Function Vectorization: "<<std::endl<<std::endl;

    /* initialize random seed: */
    srand (time(NULL));
    
    /*Benchmark a few bytes*/
    register int size =100;
    /*alocate memory for benchmars*/
    char *src1 = (char *) malloc(size);
    char *dest1 = (char *) malloc(size);
    
    if (src1 == NULL) {
        std::cout<<"src Failed to allocate memory 100 bytes";                   
        exit(1); // error!
    }

    if (dest1 == NULL) {
        std::cout<<"dest Failed to allocate memory 100 bytes";                   
        exit(1); // error!
    }

    /*clean the array allocated and put the char in*/
    vectorized_memset128i(src1,'A',size);
    vectorized_memset128i(dest1,'0',size);

    auto start = std::chrono::steady_clock::now();
    scalar_memcpy(dest1,src1,size);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout <<"Scalar memcpy function a few bytes elapsed time: " << elapsed_seconds.count() << "s\n";
    x.push_back(elapsed_seconds.count());

    vectorized_memset128i(dest1,'0',size);
    start = std::chrono::steady_clock::now();
    vectorized_memcpy128i(dest1,src1,size);
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end-start;
    std::cout <<"Vectorized memcpy function a few bytes elapsed time: " << elapsed_seconds.count() << "s\n";
    x.push_back(elapsed_seconds.count());

    free(src1);
    free(dest1);




    /*Benchmark a few bytes*/
    size =160;
    /*alocate memory for benchmariking*/
    char *src2 = (char *) malloc(size);
    char *dest2 = (char *) malloc(size);
    
    if (src2 == NULL) {
        std::cout<<"src Failed to allocate memory 160 bytes";                   
        exit(1); // error!
    }

    if (dest2 == NULL) {
        std::cout<<"dest Failed to allocate memory 160 bytes";                   
        exit(1); // error!
    }

    /*clean the array allocated and put the char in*/
    vectorized_memset128i(src2,'A',size);
    vectorized_memset128i(dest2,'0',size);

    start = std::chrono::steady_clock::now();
    scalar_memcpy(dest2,src2,size);
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end-start;
    std::cout <<"Scalar memcpy function a few bytes elapsed time: " << elapsed_seconds.count() << "s\n";
    x.push_back(elapsed_seconds.count());

    vectorized_memset128i(dest2,'0',size);
    start = std::chrono::steady_clock::now();
    vectorized_memcpy128i(dest2,src2,size);
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end-start;
    std::cout <<"Vectorized memcpy function a few bytes elapsed time: " << elapsed_seconds.count() << "s\n";
    x.push_back(elapsed_seconds.count());

    free(src2);
    free(dest2);




    /*Benchmark about 1Kbyte*/
    size =1000000;
    /*alocate memory for benchmariking*/
    char *src3 = (char *) malloc(size);
    char *dest3 = (char *) malloc(size);
    
    if (src3 == NULL) {
        std::cout<<"src Failed to allocate memory 1Kbytes";                   
        exit(1); // error!
    }

    if (dest3 == NULL) {
        std::cout<<"dest Failed to allocate memory 1Kbytes";                   
        exit(1); // error!
    }

    /*clean the array allocated and put the char in */
    vectorized_memset128i(src3,'A',size);
    vectorized_memset128i(dest3,'0',size);

    start = std::chrono::steady_clock::now();
    scalar_memcpy(dest3,src3,size);
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end-start;
    std::cout <<"Scalar memcpy function about 1Κbyte elapsed time: " << elapsed_seconds.count() << "s\n";
    x.push_back(elapsed_seconds.count());

    vectorized_memset128i(dest3,'0',size);
    start = std::chrono::steady_clock::now();
    vectorized_memcpy128i(dest3,src3,size);
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end-start;
    std::cout <<"Vectorized memcpy function about 1Kbyte elapsed time: " << elapsed_seconds.count() << "s\n";
    x.push_back(elapsed_seconds.count());

    free(src3);
    free(dest3);

    
    /*Benchmark a 1Kbyte*/
    size =1000000;
    /*alocate memory for benchmariking*/
    char *src4 = (char *) malloc(size);
    char *dest4 = (char *) malloc(size);
    
    if (src4 == NULL) {
        std::cout<<"src Failed to allocate memory 1Kbytes";                   
        exit(1); // error!
    }

    if (dest4 == NULL) {
        std::cout<<"dest Failed to allocate memory 1Kbytes";                   
        exit(1); // error!
    }

    /*clean the array allocated and put the char in*/
    vectorized_memset128i(src4,'A',size);
    vectorized_memset128i(dest4,'0',size);

    start = std::chrono::steady_clock::now();
    scalar_memcpy(dest4,src4,size);
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end-start;
    std::cout <<"Scalar memcpy function 1Κbyte elapsed time: " << elapsed_seconds.count() << "s\n";
    x.push_back(elapsed_seconds.count());

    vectorized_memset128i(dest4,'0',size);
    start = std::chrono::steady_clock::now();
    vectorized_memcpy128i(dest4,src4,size);
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end-start;
    std::cout <<"Vectorized memcpy function 1Kbyte elapsed time: " << elapsed_seconds.count() << "s\n";
    x.push_back(elapsed_seconds.count());

    free(src4);
    free(dest4);


    /*Benchmark  about 1Mbyte*/
    size =100000000;
    /*alocate memory for benchmariking*/
    char *src5 = (char *) malloc(size);
    char *dest5 = (char *) malloc(size);
    
    if (src5 == NULL) {
        std::cout<<"src Failed to allocate memory 1Mbytes";                   
        exit(1); // error!
    }

    if (dest5 == NULL) {
        std::cout<<"dest Failed to allocate memory 1Mbytes";                   
        exit(1); // error!
    }

    /*clean the array allocated and put the char in*/
    vectorized_memset128i(src5,'A',size);
    vectorized_memset128i(dest5,'0',size);

    start = std::chrono::steady_clock::now();
    scalar_memcpy(dest5,src5,size);
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end-start;
    std::cout <<"Scalar memcpy function about 1Mbyte elapsed time: " << elapsed_seconds.count() << "s\n";
    x.push_back(elapsed_seconds.count());

    vectorized_memset128i(dest5,'0',size);
    start = std::chrono::steady_clock::now();
    vectorized_memcpy128i(dest5,src5,size);
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end-start;
    std::cout <<"Vectorized memcpy function about 1Mbyte elapsed time: " << elapsed_seconds.count() << "s\n";
    x.push_back(elapsed_seconds.count());

    free(src5);
    free(dest5);
    
    //for (int i=0; i<x.size(); i++){x[i] = std::log10(x[i]) *(-1) ;}

    /*Crate memcpy for benchmarks*/
    plt::figure(); 
    plt::bar(x);
    plt::title("memcpy Functions Benchmarks");
    plt::show();
}