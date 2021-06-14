#include<iostream>
#include<chrono>
#include<vector>
#include"LinearAlgebraFNS.hpp"


/*In the code bellow benchmarks for scalar and vectorized functions which implement the procedure of matrix meultiplication are made.*/

void Benchmark_mul_matrixesnx4(){
    std::cout <<"\x1B[35m Matrix Multiplication Vectorization: \x1B[0m"<<std::endl;
    /*4X4 benchmarks*/
    std::vector<std::vector<int>> M1 {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    std::vector<std::vector<int>> M2 {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    std::vector<std::vector<int>> M3 {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    std::vector<std::vector<int>> M4 {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    
    /*Scala 4x4 matrix multiplication Benchmark*/
    auto start = std::chrono::steady_clock::now();
    scalar_mul_matrixes(M3,M1,M2);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "Scalar Mul matrixes4x4 Function elapsed time: " << elapsed_seconds.count() << "s\n";
    
    /*vectorized 4x4 matrix multiplication Benchmark*/
    start = std::chrono::steady_clock::now();
    vectorized128_mul_matcpp(M3,M1,M2,4,4,4);
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end-start;
    std::cout << "Vectorized Mul matrixes4x4 Function elapsed time: " << elapsed_seconds.count() << "s\n";


    /*8X4 Benchmarks*/
    std::vector<std::vector<int>> M11 {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}, {17, 18, 19, 20}, {21, 22, 23, 24}, {25, 26, 27, 28}, {29, 30, 31, 32}};
    std::vector<std::vector<int>> M22 {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    std::vector<std::vector<int>> M33 {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    std::vector<std::vector<int>> M44 {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};

    /*Scala 8x4 matrix multiplication Benchmark*/
    start = std::chrono::steady_clock::now();
    scalar_mul_matrixes(M33,M11,M22);
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end-start;
    std::cout << "Scalar Mul matrixes8x4 Function elapsed time: " << elapsed_seconds.count() << "s\n";
    
    /*vectorized 8x4 matrix multiplication Benchmark*/
    start = std::chrono::steady_clock::now();
    vectorized128_mul_matcpp(M44,M11,M22,8,4,4);
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end-start;
    std::cout << "Vectorized Mul matrixes8x4 Function elapsed time: " << elapsed_seconds.count() << "s\n";

}