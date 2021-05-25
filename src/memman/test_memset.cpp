#include<iostream>
#include<vector>
#include"PrintFNS.h"
#include"memFNS.h"
#include"gtest/gtest.h"

TEST(memsettest12810x10,memset){
    /*alocate memory*/
    int size = 100;
    char *buf1 = new char[size];
    char *buf2 = new char[size];
    if (buf1 == NULL) {
        std::cout<<"Failed to allocate memory 100bytes";                   
        exit(1); // error!
    }
    if (buf2 == NULL) {
        std::cout<<"Failed to allocate memory 100 bytes";                   
        exit(1); // error!
    }
    memset(buf1,'$',size);
    vectorized_memset128i(buf2,'$',size);
    for (int i=0;i<size;i++){ASSERT_EQ(buf1[i],buf2[i]);}
    
    /*dealocate memory*/
    delete[] buf1;
    delete[] buf2;
}

TEST(memsettest12810x1000,memset){
    /*alocate memory*/
    int size = 100000;
    char *buf1 = new char[size];
    char *buf2 = new char[size];

    if (buf1 == NULL) {
        std::cout<<"Failed to allocate memory 100000 bytes";                   
        exit(1); // error!
    }
    if (buf2 == NULL) {
        std::cout<<"Failed to allocate memory 100000 bytes";                   
        exit(1); // error!
    }
    memset(buf1,'$',size);
    vectorized_memset128i(buf2,'$',size);
    for (int i=0;i<size;i++){ASSERT_EQ(buf1[i],buf2[i]);}
    
    /*dealocate memory*/
    delete[] buf1;
    delete[] buf2;
}

TEST(memsettest12810x100000,memset){
    /*alocate memory*/
    int size = 10000000;
    char *buf1 = new char[size];
    char *buf2 = new char[size];
    if (buf1 == NULL) {
        std::cout<<"Failed to allocate memory 10000000 bytes";                   
        exit(1); // error!
    }
    if (buf2 == NULL) {
        std::cout<<"Failed to allocate memory 10000000 bytes";                   
        exit(1); // error!
    }
    memset(buf1,'$',size);
    vectorized_memset128i(buf2,'$',size);
    for (int i=0;i<size;i++){ASSERT_EQ(buf1[i],buf2[i]);}
    
    /*dealocate memory*/
    delete[] buf1;
    delete[] buf2;
}



TEST(memsettest25610x10,memset){
    /*alocate memory*/
    int size = 100;
    char *buf1 = new char[size];
    char *buf2 = new char[size];
    if (buf1 == NULL) {
        std::cout<<"Failed to allocate memory 100bytes";                   
        exit(1); // error!
    }
    if (buf2 == NULL) {
        std::cout<<"Failed to allocate memory 100 bytes";                   
        exit(1); // error!
    }
    memset(buf1,'$',size);
    vectorized_memset256i(buf2,'$',size);
    for (int i=0;i<size;i++){ASSERT_EQ(buf1[i],buf2[i]);}
    
    /*dealocate memory*/
    delete[] buf1;
    delete[] buf2;
}

TEST(memsettest25610x1000,memset){
    /*alocate memory*/
    int size = 100000;
    char *buf1 = new char[size];
    char *buf2 = new char[size];
    if (buf1 == NULL) {
        std::cout<<"Failed to allocate memory 100000 bytes";                   
        exit(1); // error!
    }
    if (buf2 == NULL) {
        std::cout<<"Failed to allocate memory 100000 bytes";                   
        exit(1); // error!
    }
    memset(buf1,'$',size);
    vectorized_memset256i(buf2,'$',size);
    for (int i=0;i<size;i++){ASSERT_EQ(buf1[i],buf2[i]);}
    
    /*dealocate memory*/
    delete[] buf1;
    delete[] buf2;
}

TEST(memsettest25610x100000,memset){
    /*alocate memory*/
    int size = 10000000;
    char *buf1 = new char[size];
    char *buf2 = new char[size];
    if (buf1 == NULL) {
        std::cout<<"Failed to allocate memory 10000000 bytes";                   
        exit(1); // error!
    }
    if (buf2 == NULL) {
        std::cout<<"Failed to allocate memory 10000000 bytes";                   
        exit(1); // error!
    }
    memset(buf1,'$',size);
    vectorized_memset256i(buf2,'$',size);
    for (int i=0;i<size;i++){ASSERT_EQ(buf1[i],buf2[i]);}
    
    /*dealocate memory*/
    delete[] buf1;
    delete[] buf2;
}



int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
  /*
  std::vector<char> *buf1 = new std::vector<char>(1000);
  scalar_memsetcpp(buf1,'$',1000);
  //std::cout<<buf1<< std::endl;
  delete buf1;
  */

}
