#include<iostream>
#include<vector>
#include<chrono>
#include"LinearAlgebraFNS.h"
#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;


/*In the code bellow benchmarks for scalar and vectorized functions which implement the procedure of matrix transposure are made.*/

void Benchmark_Transpose_matrix4x4(){
    std::vector<double> x;

    //std::vector<std::vector<int>> vec1(4, std::vector<int> (4, 0));
    std::vector<std::vector<int>> tr(4, std::vector<int> (4, 0));
    std::vector<std::vector<int>> tr1(4, std::vector<int> (4, 0));
    //for(int i=0; i<4; i++){
    //    for (int j=0; j<4; j++){vec1[i][j]=i+1;}
    //}
    std::vector<std::vector<int>> vec1 {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};


    /*Scala 4x4 matrix trasnposure Benchmark*/
    auto start = std::chrono::steady_clock::now();
    for (int i=0; i<100000; i++){tr = scalar_transposeint(vec1);}
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "Scalar Transposure matrixes4x4 Function elapsed time: " << elapsed_seconds.count() << "s\n";
    x.push_back(elapsed_seconds.count());
    
    /*Vectrorized 4x4 matrix trasnposure Benchmark*/
    start = std::chrono::steady_clock::now();
    for (int i=0; i<100000; i++){tr1 = vectorized128i_transpose_mat4x4(vec1);}
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end-start;
    std::cout << "Vectrorized Transposure matrixes4x4 Function elapsed time: " << elapsed_seconds.count() << "s\n";
    x.push_back(elapsed_seconds.count());

    /*Crate barplot for benchmarks*/
    plt::figure();
    plt::bar(x);
    plt::title("Transose Matrix Functions Benchmarks");
    plt::show();

}