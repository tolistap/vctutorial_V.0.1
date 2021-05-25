#include<iostream>
#include"BenchmarksFNS.h"

/*In the following benchmarks 2^19 selected for arrays length because the some of the functions was vectorized
  based the assumptions that the array's len will be given as input will be multiples of power of 2 (i.e.2^19). 
  Thus, the code bellow illustrates benchmarks for all functions was written in this project. 
*/

int main(){
    std::cout<<"Start Benchmarks..."<<std::endl;
    Benchmark_memcpy();
    //Benchmark_memset();
    //Benchmark_memchr();
    //Benchmark_Comparisons(200000);
    //Benchmark_Dotproduct(524288); 
    //Benchmark_minmax(20000);
    //Benchmark_add_matrixes(1024,4096);
    //Benchmark_mul_matrixesnx4();
    //Benchmark_Transpose_matrix4x4();
}

