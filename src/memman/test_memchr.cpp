#include<iostream>
#include<time.h>
#include<vector>
#include"memFNS.h"
#include"gtest/gtest.h"

TEST(memchrtest12810x10w1,memchr){
    intptr_t *isin1;
    intptr_t *isin2;
    /*alocate memory*/
    int size = 100;
    char *buf1 = new char[size];
    if (buf1 == NULL) {
        std::cout<<"Failed to allocate memory 100bytes";                   
        exit(1); // error!
    }
    
    vectorized_memset256i(buf1,'$',size);

    /* initialize random seed: */
    srand (time(NULL));
    register int pos = rand() % size + 0;
    buf1[pos] = 'a';

    isin1 = (intptr_t *) memchr(buf1,'a',size);
    isin2 = (intptr_t *) vectorized_memchrw1(buf1,'a',size); 
    
    ASSERT_EQ(isin1,isin2);

    /*dealocate memory*/
    delete[] buf1;
}

TEST(memchrtest12810x10w2,memchr){
    intptr_t *isin1;
    intptr_t *isin2;

    /*alocate memory*/
    int size = 100;
    char *buf1 = new char[size];
    if (buf1 == NULL) {
        std::cout<<"Failed to allocate memory 100bytes";                   
        exit(1); // error!
    }
    
    vectorized_memset256i(buf1,'$',size);

    /* initialize random seed: */
    srand (time(NULL));
    register int pos = rand() % size + 0;
    buf1[pos] = 'a';

    isin1 = (intptr_t *) memchr(buf1,'a',size);
    isin2 = (intptr_t *) vectorized_memchrw2(buf1,'a',size); 
    
    ASSERT_EQ(isin1,isin2);

    /*dealocate memory*/
    delete[] buf1;
}


TEST(memchrtest12810x100w1,memchr){
    intptr_t *isin1;
    intptr_t *isin2;
    /*alocate memory*/
    int size = 1000;
    char *buf1 = new char[size];
    if (buf1 == NULL) {
        std::cout<<"Failed to allocate memory 1000 bytes";                   
        exit(1); // error!
    }
    
    vectorized_memset256i(buf1,'$',size);

    /* initialize random seed: */
    srand (time(NULL));
    register int pos = rand() % size + 0;
    buf1[pos] = 'a';

    isin1 = (intptr_t *) memchr(buf1,'a',size);
    isin2 = (intptr_t *) vectorized_memchrw1(buf1,'a',size); 
    
    ASSERT_EQ(isin1,isin2);

    /*dealocate memory*/
    delete[] buf1;
}

TEST(memchrtest12810x100w2,memchr){
    intptr_t *isin1;
    intptr_t *isin2;
    
    /*alocate memory*/
    int size = 1000;
    char *buf1 = new char[size];
    if (buf1 == NULL) {
        std::cout<<"Failed to allocate memory 1000bytes";                   
        exit(1); // error!
    }
    
    vectorized_memset256i(buf1,'$',size);

    /* initialize random seed: */
    srand (time(NULL));
    register int pos = rand() % size + 0;
    buf1[pos] = 'a';

    isin1 = (intptr_t *) memchr(buf1,'a',size);
    isin2 = (intptr_t *) vectorized_memchrw2(buf1,'a',size); 
    
    ASSERT_EQ(isin1,isin2);

    /*dealocate memory*/
    delete[] buf1;
}

TEST(memchrtest12810x10000w1,memchr){
    intptr_t *isin1;
    intptr_t *isin2;
    /*alocate memory*/
    int size = 1000000;
    char *buf1 = new char[size];
    if (buf1 == NULL) {
        std::cout<<"Failed to allocate memory 100bytes";                   
        exit(1); // error!
    }
    
    vectorized_memset256i(buf1,'$',size);

    /* initialize random seed: */
    srand (time(NULL));
    register int pos = rand() % size + 0;
    buf1[pos] = 'a';

    isin1 = (intptr_t *) memchr(buf1,'a',size);
    isin2 = (intptr_t *) vectorized_memchrw1(buf1,'a',size); 
    
    ASSERT_EQ(isin1,isin2);

    /*dealocate memory*/
    delete[] buf1;
}

TEST(memchrtest12810x100000w2,memchr){
    intptr_t *isin1;
    intptr_t *isin2;
    
    /*alocate memory*/
    int size = 1000000;
    char *buf1 = new char[size];
    if (buf1 == NULL) {
        std::cout<<"Failed to allocate memory 100bytes";                   
        exit(1); // error!
    }
    
    vectorized_memset256i(buf1,'$',size);

    /* initialize random seed: */
    srand (time(NULL));
    register int pos = rand() % size + 0;
    buf1[pos] = 'a';

    isin1 = (intptr_t *) memchr(buf1,'a',size);
    isin2 = (intptr_t *) vectorized_memchrw2(buf1,'a',size); 
    
    ASSERT_EQ(isin1,isin2);

    /*dealocate memory*/
    delete[] buf1;
}

TEST(memchrtest25610x10,memchr){
    intptr_t *isin1;
    intptr_t *isin2;
    
    /*alocate memory*/
    int size = 100;
    char *buf1 = new char[size];
    if (buf1 == NULL) {
        std::cout<<"Failed to allocate memory 100bytes";                   
        exit(1); // error!
    }
    
    vectorized_memset256i(buf1,'$',size);

    /* initialize random seed: */
    srand (time(NULL));
    register int pos = rand() % size + 0;
    buf1[pos] = 'a';

    isin1 = (intptr_t *) memchr(buf1,'a',size);
    isin2 = (intptr_t *) vectorized_memchr256(buf1,'a',size); 
    
    ASSERT_EQ(isin1,isin2);

    /*dealocate memory*/
    delete[] buf1;
}

TEST(memchrtest25610x1000,memchr){
    intptr_t *isin1;
    intptr_t *isin2;
    
    /*alocate memory*/
    int size = 10000;
    char *buf1 = new char[size];
    if (buf1 == NULL) {
        std::cout<<"Failed to allocate memory 10000bytes";                   
        exit(1); // error!
    }
    
    vectorized_memset256i(buf1,'$',size);

    /* initialize random seed: */
    srand (time(NULL));
    register int pos = rand() % size + 0;
    buf1[pos] = 'a';

    isin1 = (intptr_t *) memchr(buf1,'a',size);
    isin2 = (intptr_t *) vectorized_memchr256(buf1,'a',size); 
    
    ASSERT_EQ(isin1,isin2);

    /*dealocate memory*/
    delete[] buf1;
}

TEST(memchrtest25610x100000,memchr){
    intptr_t *isin1;
    intptr_t *isin2;
    
    /*alocate memory*/
    int size = 1000000;
    char *buf1 = new char[size];
    if (buf1 == NULL) {
        std::cout<<"Failed to allocate memory 1000000bytes";                   
        exit(1); // error!
    }
    
    vectorized_memset256i(buf1,'$',size);

    /* initialize random seed: */
    srand (time(NULL));
    register int pos = rand() % size + 0;
    buf1[pos] = 'a';

    isin1 = (intptr_t *) memchr(buf1,'a',size);
    isin2 = (intptr_t *) vectorized_memchr256(buf1,'a',size); 
    
    ASSERT_EQ(isin1,isin2);

    /*dealocate memory*/
    delete[] buf1;

}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
