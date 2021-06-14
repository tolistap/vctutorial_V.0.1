#include<vector>
#include<iostream>
#include<chrono>
#include"LinearAlgebraFNS.hpp"


/*In the code bellow benchmarks for scalar and vectorized functions which implement the procedure of matrix addition are made.*/

void Benchmark_add_matrixes(const int row, const int col){
    std::cout <<"\x1B[35m Matrix Addition Vectorization: \x1B[0m"<<std::endl;
    
    /* Declaring 3 2D vectors containing "n" elements each having the value "vector<float> (col, <fnumber>)".
    "vector<float> (col, <fnumber>)" means a vector having "m" elements each of value of any float number.
    Here these elements are vectors.
    */
    std::vector<std::vector<float>> vec1(row, std::vector<float> (col, 3.14));
    std::vector<std::vector<float>> vec2(row, std::vector<float> (col, 0.86));
    std::vector<std::vector<float>> vec3(row, std::vector<float> (col, 0));
    /*

    /*Benchmark Scalar Method*/
    auto start = std::chrono::steady_clock::now();
    scalar_add_matrixes(vec3,vec2,vec1);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "Scalar add matrixes Function elapsed time: " << elapsed_seconds.count() << "s\n";

    /*Benchmark Vectorized Method*/
    start = std::chrono::steady_clock::now();
    vectorized_add_matcpp(vec3,vec2,vec1,row,col);
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end-start;
    std::cout << "Vectorized 128 add matrixes Function elapsed time: " << elapsed_seconds.count() << "s\n";
    
    start = std::chrono::steady_clock::now();
    vectorized256_add_matcpp(vec3,vec2,vec1,row,col);
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end-start;
    std::cout << "Vectorized 256 add matrixes Function elapsed time: " << elapsed_seconds.count() << "s\n";

}