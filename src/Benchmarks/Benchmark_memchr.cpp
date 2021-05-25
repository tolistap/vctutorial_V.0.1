#include "memFNS.h"
#include<iostream>
#include<chrono>


/*In the code bellow benchmarks for scalar and vectorized functions which implement the procedure of memory search are made.*/

void Benchmark_memchr(){
    std::cout<<std::endl << "memchr Function Vectorization: "<<std::endl;

    /* initialize random seed: */
    srand (time(NULL));
    
    /*Based on ASCII representation a random int from 65 to
    122 can describe the [ABC..xyz] chars and ([]\^_`) */
    register int c = 122;
    std::cout<<"Searcing for char: "<<(char)c<<std::endl;
    
    register int size =100;
    /*alocate memory for benchmars*/
    char *buf1 = (char *) malloc(size);
    if (buf1 == NULL) {
        std::cout<<"Failed to allocate memory 100 bytes";                   
        exit(1); // error!
    }
    
    /*clean the array allocated and put the char in a radnom possition*/
    vectorized_memset128i(buf1,'K',size); 
    register int rand_pos= rand() % size + 0;
    buf1[rand_pos]=c;
    
    /*scalar memchr function Benchmark*/
    intptr_t *isin; 
    auto start = std::chrono::steady_clock::now();
    isin = (intptr_t *) scalar_memchr(buf1,c,size);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    if (isin == NULL) {std::cout<<"The char is not in string";}
    else {std::cout<<"The char is in string in address: "<<isin;}
    std::cout <<" Scalar memchr function a few bytes (stringlen % 16 !=0) elapsed time:: " << elapsed_seconds.count() << "s\n";

    /*vectorized memchrw1 function Benchmark*/ 
    start = std::chrono::steady_clock::now();
    isin = (intptr_t *) vectorized_memchrw1(buf1,c,size);
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end-start;
    if (isin == NULL) {std::cout<<"The char is not in string";}
    else {std::cout<<"The char is in string in address: "<<isin;}
    std::cout << " Vectorized memchrw1 function a few bytes(stringlen % 16 !=0) elapsed time:: " << elapsed_seconds.count() << "s\n";
    
     
    /*vectorized memchrw2 function Benchmark*/
    start = std::chrono::steady_clock::now();
    isin = (intptr_t *) vectorized_memchrw2(buf1,c,size);
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end-start;
    if (isin == NULL) {std::cout<<"The char is not in string";}
    else {std::cout<<"The char is in string in address: "<<isin;}
    std::cout << " Vectorized memchrw2 function a few bytes(stringlen % 16 !=0) elapsed time: " << elapsed_seconds.count() << "s\n";
    

    /*vectorized memchr256 function Benchmark*/
    start = std::chrono::steady_clock::now();
    isin = (intptr_t *) vectorized_memchr256(buf1,c,size);
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end-start;
    if (isin == NULL) {std::cout<<"The char is not in string";}
    else {std::cout<<"The char is in string in address: "<<isin;}
    std::cout << " Vectorized memchr256 function a few bytes(stringlen % 16 !=0) elapsed time: " << elapsed_seconds.count() << "s\n";
    

    free(buf1);

    /*alocate memory for benchmars*/
    size = 160;
    char *buf2 = (char *) malloc(size);
    if (buf2 == NULL) {
        std::cout<<"Failed to allocate memory 160 bytes";                   
        exit(1); // error!
    }
    vectorized_memset128i(buf2,'A',size);
    buf2[rand_pos]=c;
    
    /*scalar memchr function Benchmark*/ 
    start = std::chrono::steady_clock::now();
    isin = (intptr_t *) scalar_memchr(buf2,c,size);
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end-start;
    if (isin == NULL) {std::cout<<"The char is not in string";}
    else {std::cout<<"The char is in string in address: "<<isin;}
    std::cout << " Scalar memchr function a few bytes (stringlen % 16 ==0) elapsed time:: " << elapsed_seconds.count() << "s\n";

    /*vectorized memchrw1 function Benchmark*/ 
    start = std::chrono::steady_clock::now();
    isin = (intptr_t *) vectorized_memchrw1(buf2,c,size);
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end-start;
    if (isin == NULL) {std::cout<<"The char is not in string";}
    else {std::cout<<"The char is in string in address: "<<isin;}
    std::cout << " Vectorized memchrw1 function a few bytes(stringlen % 16 ==0) elapsed time:: " << elapsed_seconds.count() << "s\n";
    
     
    /*vectorized memchrw2 function Benchmark*/
    start = std::chrono::steady_clock::now();
    isin = (intptr_t *) vectorized_memchrw2(buf2,c,size);
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end-start;
    if (isin == NULL) {std::cout<<"The char is not in string";}
    else {std::cout<<"The char is in string in address: "<<isin;}
    std::cout << " Vectorized memchrw2 function a few bytes(stringlen % 16 ==0) elapsed time: " << elapsed_seconds.count() << "s\n";
    
    /*vectorized memchr function Benchmark*/
    start = std::chrono::steady_clock::now();
    isin = (intptr_t *) vectorized_memchr256(buf2,c,size);
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end-start;
    if (isin == NULL) {std::cout<<"The char is not in string";}
    else {std::cout<<"The char is in string in address: "<<isin;}
    std::cout << " Vectorized memchr256 function a few bytes(stringlen % 16 ==0) elapsed time: " << elapsed_seconds.count() << "s\n";
    
    free(buf2);
    

    std::cout<<std::endl;
    size = 100000;
    /*alocate memory for benchmars*/
    char *buf3 = (char *) malloc(size);
    if (buf3 == NULL) {
        std::cout<<"Failed to allocate memory 100000 bytes -> 100kB";                   
        exit(1); // error!
    }
    vectorized_memset128i(buf3,'A',size);
    buf3[rand_pos]=c;
    
    /*scalar memchr function Benchmark*/ 
    start = std::chrono::steady_clock::now();
    isin = (intptr_t *) scalar_memchr(buf3,c,size);
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end-start;
    if (isin == NULL) {std::cout<<"The char is not in string";}
    else {std::cout<<"The char is in string in address: "<<isin;}
    std::cout << " Scalar memchr function a few kbytes (stringlen % 16 !=0) elapsed time:: " << elapsed_seconds.count() << "s\n";

    /*vectorized memchrw1 function Benchmark*/ 
    start = std::chrono::steady_clock::now();
    isin = (intptr_t *) vectorized_memchrw1(buf3,c,size);
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end-start;
    if (isin == NULL) {std::cout<<"The char is not in string";}
    else {std::cout<<"The char is in string in address: "<<isin;}
    std::cout << " Vectorized memchrw1 function a few kbytes(stringlen % 16 !=0) elapsed time:: " << elapsed_seconds.count() << "s\n";
    
     
    /*vectorized memchrw2 function Benchmark*/
    start = std::chrono::steady_clock::now();
    isin = (intptr_t *) vectorized_memchrw2(buf3,c,size);
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end-start;
    if (isin == NULL) {std::cout<<"The char is not in string";}
    else {std::cout<<"The char is in string in address: "<<isin;}
    std::cout << " Vectorized memchrw2 function a few kbytes(stringlen % 16 !=0) elapsed time: " << elapsed_seconds.count() << "s\n";
    
    /*vectorized memchr256 function Benchmark*/
    start = std::chrono::steady_clock::now();
    isin = (intptr_t *) vectorized_memchr256(buf3,c,size);
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end-start;
    if (isin == NULL) {std::cout<<"The char is not in string";}
    else {std::cout<<"The char is in string in address: "<<isin;}
    std::cout << " Vectorized memchr256 function a few kbytes(stringlen % 16 !=0) elapsed time: " << elapsed_seconds.count() << "s\n";
    

    free(buf3);
    size = 160000;
    /*alocate memory for benchmars*/
    char *buf4 = (char *) malloc(size);
    if (buf4 == NULL) {
        std::cout<<"Failed to allocate memory 160000 bytes -> 160kB";                   
        exit(1); // error!
    }
    vectorized_memset128i(buf4,'A',size);
    buf4[rand_pos]=c;
    
    /*scalar memchr function Benchmark*/ 
    start = std::chrono::steady_clock::now();
    isin = (intptr_t *) scalar_memchr(buf4,c,size);
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end-start;
    if (isin == NULL) {std::cout<<"The char is not in string";}
    else {std::cout<<"The char is in string in address: "<<isin;}
    std::cout << " Scalar memchr function a few kbytes (stringlen % 16 ==0) elapsed time:: " << elapsed_seconds.count() << "s\n";

    /*vectorized memchrw1 function Benchmark*/ 
    start = std::chrono::steady_clock::now();
    isin = (intptr_t *) vectorized_memchrw1(buf4,c,size);
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end-start;
    if (isin == NULL) {std::cout<<"The char is not in string";}
    else {std::cout<<"The char is in string in address: "<<isin;}
    std::cout << " Vectorized memchrw1 function a few kbytes(stringlen % 16 ==0) elapsed time:: " << elapsed_seconds.count() << "s\n";
    
     
    /*vectorized memchrw2 function Benchmark*/
    start = std::chrono::steady_clock::now();
    isin = (intptr_t *) vectorized_memchrw2(buf4,c,size);
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end-start;
    if (isin == NULL) {std::cout<<"The char is not in string";}
    else {std::cout<<"The char is in string in address: "<<isin;}
    std::cout << " Vectorized memchrw2 function a few kbytes(stringlen % 16 ==0) elapsed time: " << elapsed_seconds.count() << "s\n";
    
    
    /*vectorized memchr function Benchmark*/
    start = std::chrono::steady_clock::now();
    isin = (intptr_t *) vectorized_memchr256(buf4,c,size);
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end-start;
    if (isin == NULL) {std::cout<<"The char is not in string";}
    else {std::cout<<"The char is in string in address: "<<isin;}
    std::cout << " Vectorized memchr256 function a few kbytes(stringlen % 16 ==0) elapsed time: " << elapsed_seconds.count() << "s\n";
    
    free(buf4);


    std::cout<<std::endl;
    size = 100000000;

    /*alocate memory for benchmars*/
    char *buf5 = (char *) malloc(size);
    if (buf5 == NULL) {
        std::cout<<"Failed to allocate memory 100000000 bytes -> 100MB";                   
        exit(1); // error!
    }
    vectorized_memset128i(buf5,'o',size);
    rand_pos= rand() % size + 0;
    buf5[rand_pos]=c;
    
    /*scalar memchr function Benchmark*/ 
    start = std::chrono::steady_clock::now();
    isin = (intptr_t *) scalar_memchr(buf5,c,size);
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end-start;
    if (isin == NULL) {std::cout<<"The char is not in string";}
    else {std::cout<<"The char is in string in address: "<<isin;}
    std::cout << " Scalar memchr function a few Mbytes (stringlen % 16 !=0) elapsed time:: " << elapsed_seconds.count() << "s\n";

    /*vectorized memchrw1 function Benchmark*/ 
    start = std::chrono::steady_clock::now();
    isin = (intptr_t *) vectorized_memchrw1(buf5,c,size);
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end-start;
    if (isin == NULL) {std::cout<<"The char is not in string";}
    else {std::cout<<"The char is in string in address: "<<isin;}
    std::cout << " Vectorized memchrw1 function a few Mbytes(stringlen % 16 !=0) elapsed time:: " << elapsed_seconds.count() << "s\n";
    
     
    /*vectorized memchrw2 function Benchmark*/
    start = std::chrono::steady_clock::now();
    isin = (intptr_t *) vectorized_memchrw2(buf5,c,size);
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end-start;
    if (isin == NULL) {std::cout<<"The char is not in string";}
    else {std::cout<<"The char is in string in address: "<<isin;}
    std::cout << " Vectorized memchrw2 function a few Mbytes(stringlen % 16 !=0) elapsed time: " << elapsed_seconds.count() << "s\n";
    
    /*vectorized memchr256 function Benchmark*/
    start = std::chrono::steady_clock::now();
    isin = (intptr_t *) vectorized_memchr256(buf5,c,size);
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end-start;
    if (isin == NULL) {std::cout<<"The char is not in string";}
    else {std::cout<<"The char is in string in address: "<<isin;}
    std::cout << " Vectorized memchr256 function a few Mbytes(stringlen % 16 !=0) elapsed time: " << elapsed_seconds.count() << "s\n";
    
    free(buf5);
    size = 160000000;
    /*alocate memory for benchmarks*/
    char *buf6 = (char *) malloc(size);
    if (buf6 == NULL) {
        std::cout<<"Failed to allocate memory 160000000 bytes -> 160MB";                   
        exit(1); // error!
    }
    vectorized_memset128i(buf6,'i',size);
    rand_pos= rand() % size + 0;
    buf6[rand_pos]=c;
    
    /*scalar memchr function Benchmark*/ 
    start = std::chrono::steady_clock::now();
    isin = (intptr_t *) scalar_memchr(buf6,c,size);
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end-start;
    if (isin == NULL) {std::cout<<"The char is not in string";}
    else {std::cout<<"The char is in string in address: "<<isin;}
    std::cout << " Scalar memchr function a few Mbytes (stringlen % 16 ==0) elapsed time:: " << elapsed_seconds.count() << "s\n";

    /*vectorized memchrw1 function Benchmark*/ 
    start = std::chrono::steady_clock::now();
    isin = (intptr_t *) vectorized_memchrw1(buf6,c,size);
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end-start;
    if (isin == NULL) {std::cout<<"The char is not in string";}
    else {std::cout<<"The char is in string in address: "<<isin;}
    std::cout << " Vectorized memchrw1 function a few Mbytes(stringlen % 16 ==0) elapsed time:: " << elapsed_seconds.count() << "s\n";
    
     
    /*vectorized memchrw2 function Benchmark*/
    start = std::chrono::steady_clock::now();
    isin = (intptr_t *) vectorized_memchrw2(buf6,c,size);
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end-start;
    if (isin == NULL) {std::cout<<"The char is not in string";}
    else {std::cout<<"The char is in string in address: "<<isin;}
    std::cout << " Vectorized memchrw2 function a few Mbytes(stringlen % 16 ==0) elapsed time: " << elapsed_seconds.count() << "s\n";
    
    /*vectorized memchr256 function Benchmark*/
    start = std::chrono::steady_clock::now();
    isin = (intptr_t *) vectorized_memchr256(buf6,c,size);
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end-start;
    if (isin == NULL) {std::cout<<"The char is not in string";}
    else {std::cout<<"The char is in string in address: "<<isin;}
    std::cout << " Vectorized memchr256 function a few Mbytes(stringlen % 16 ==0) elapsed time: " << elapsed_seconds.count() << "s\n";
    
    free(buf6);
}
