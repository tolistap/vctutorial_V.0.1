#include"MathsFNS.hpp"
#include"gtest/gtest.h"

TEST(Lshift,Lshift0){
    uint8_t k[16];
    ASSERT_EQ(Lshift(k, 16),0); 
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}