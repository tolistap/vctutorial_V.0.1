#include <iostream>
#include"memFNS.h"
#include"gtest/gtest.h"

/*Both dest and sourse alligned small size*/
TEST(BAmemcpytest65x16,memcpy){
    /*Define a dummy text with 65 characters*/
    register int n = 65;
    char vec[] __attribute__((aligned(16))) = "This is a dummy text with aim to test memcpy function by me tolis";
    char vec2[n] __attribute__((aligned(16)));
    char vec3[n] __attribute__((aligned(16)));
    for (int i=0; i<n; i++){vec2[i] = '0';}
    for (int i=0; i<n; i++){vec3[i] = '0';}
    scalar_memcpy(vec2,vec,n);     
    vectorized_memcpy128i(vec3,vec,n);
    for (int i=0;i<n;i++){ASSERT_EQ(vec2[i],vec3[i]);}
}

/*Both dest and sourse alligned midle size*/
TEST(BAmemcpytest128x16,memcpy){
    /*Define a dummy text with 128 characters*/
    register int n = 128;
    char vec[] __attribute__((aligned(16))) = "Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligula eget dolor. Aenean massa. Cum sociis natoque pen";
    char vec2[n] __attribute__((aligned(16)));
    char vec3[n] __attribute__((aligned(16)));
    for (int i=0; i<n; i++){vec2[i] = '0';}
    for (int i=0; i<n; i++){vec3[i] = '0';}
    scalar_memcpy(vec2,vec,n);     
    vectorized_memcpy128i(vec3,vec,n);
    for (int i=0;i<n;i++){ASSERT_EQ(vec2[i],vec3[i]);}
}

/*Both dest and sourse alligned large size*/
TEST(BAmemcpytest1024x16,memcpy){
    /*Define a dummy text with 1024 characters*/
    register int n = 1024;
    char vec[] __attribute__((aligned(16))) = "Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligula eget dolor. Aenean massa. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Donec quam felis, ultricies nec, pellentesque eu, pretium quis, sem. Nulla consequat massa quis enim. Donec pede justo, fringilla vel, aliquet nec, vulputate eget, arcu. In enim justo, rhoncus ut, imperdiet a, venenatis vitae, justo. Nullam dictum felis eu pede mollis pretium. Integer tincidunt. Cras dapibus. Vivamus elementum semper nisi. Aenean vulputate eleifend tellus. Aenean leo ligula, porttitor eu, consequat vitae, eleifend ac, enim. Aliquam lorem ante, dapibus in, viverra quis, feugiat a, tellus. Phasellus viverra nulla ut metus varius laoreet. Quisque rutrum. Aenean imperdiet. Etiam ultricies nisi vel augue. Curabitur ullamcorper ultricies nisi. Nam eget dui. Etiam rhoncus. Maecenas tempus, tellus eget condimentum rhoncus, sem quam semper libero, sit amet adipiscing sem neque sed ipsum. Nam quam nunc, blandit ve";
    char vec2[n] __attribute__((aligned(16)));
    char vec3[n] __attribute__((aligned(16)));
    for (int i=0; i<n; i++){vec2[i] = '0';}
    for (int i=0; i<n; i++){vec3[i] = '0';}
    scalar_memcpy(vec2,vec,n);     
    vectorized_memcpy128i(vec3,vec,n);
    for (int i=0;i<n;i++){ASSERT_EQ(vec2[i],vec3[i]);}
}


/*Alligned dest and sourse unalligned small size*/
TEST(DAmemcpytest65x16,memcpy){
    /*Define a dummy text with 65 characters*/
    register int n = 65;
    char vec[] = "This is a dummy text with aim to test memcpy function by me tolis";
    char vec2[n] __attribute__((aligned(16)));
    char vec3[n] __attribute__((aligned(16)));
    for (int i=0; i<n; i++){vec2[i] = '0';}
    for (int i=0; i<n; i++){vec3[i] = '0';}
    scalar_memcpy(vec2,vec,n);     
    vectorized_memcpy128i(vec3,vec,n);
    for (int i=0;i<n;i++){ASSERT_EQ(vec2[i],vec3[i]);}
}

/*Alligned dest and sourse unalligned small size*/
TEST(DAmemcpytest128x16,memcpy){
    /*Define a dummy text with 128 characters*/
    register int n = 128;
    char vec[] = "Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligula eget dolor. Aenean massa. Cum sociis natoque pen";
    char vec2[n] __attribute__((aligned(16)));
    char vec3[n] __attribute__((aligned(16)));
    for (int i=0; i<n; i++){vec2[i] = '0';}
    for (int i=0; i<n; i++){vec3[i] = '0';}
    scalar_memcpy(vec2,vec,n);     
    vectorized_memcpy128i(vec3,vec,n);
    for (int i=0;i<n;i++){ASSERT_EQ(vec2[i],vec3[i]);}
}

/*Alligned dest and sourse unalligned small size*/
TEST(DAmemcpytest1024x16,memcpy){
    /*Define a dummy text with 1024 characters*/
    register int n = 1024;
    char vec[] = "Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligula eget dolor. Aenean massa. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Donec quam felis, ultricies nec, pellentesque eu, pretium quis, sem. Nulla consequat massa quis enim. Donec pede justo, fringilla vel, aliquet nec, vulputate eget, arcu. In enim justo, rhoncus ut, imperdiet a, venenatis vitae, justo. Nullam dictum felis eu pede mollis pretium. Integer tincidunt. Cras dapibus. Vivamus elementum semper nisi. Aenean vulputate eleifend tellus. Aenean leo ligula, porttitor eu, consequat vitae, eleifend ac, enim. Aliquam lorem ante, dapibus in, viverra quis, feugiat a, tellus. Phasellus viverra nulla ut metus varius laoreet. Quisque rutrum. Aenean imperdiet. Etiam ultricies nisi vel augue. Curabitur ullamcorper ultricies nisi. Nam eget dui. Etiam rhoncus. Maecenas tempus, tellus eget condimentum rhoncus, sem quam semper libero, sit amet adipiscing sem neque sed ipsum. Nam quam nunc, blandit ve";
    char vec2[n] __attribute__((aligned(16)));
    char vec3[n] __attribute__((aligned(16)));
    for (int i=0; i<n; i++){vec2[i] = '0';}
    for (int i=0; i<n; i++){vec3[i] = '0';}
    scalar_memcpy(vec2,vec,n);     
    vectorized_memcpy128i(vec3,vec,n);
    for (int i=0;i<n;i++){ASSERT_EQ(vec2[i],vec3[i]);}
}

/*unaligned dest and sourse alligned small size*/
TEST(SAmemcpytest65x16,memcpy){
    /*Define a dummy text with 65 characters*/
    register int n = 65;
    char vec[] __attribute__((aligned(16))) = "This is a dummy text with aim to test memcpy function by me tolis";
    char vec2[n];
    char vec3[n];
    for (int i=0; i<n; i++){vec2[i] = '0';}
    for (int i=0; i<n; i++){vec3[i] = '0';}
    scalar_memcpy(vec2,vec,n);     
    vectorized_memcpy128i(vec3,vec,n);
    for (int i=0;i<n;i++){ASSERT_EQ(vec2[i],vec3[i]);}
}

/*unaligned dest and sourse alligned small size*/
TEST(SAmemcpytest128x16,memcpy){
    /*Define a dummy text with 128 characters*/
    register int n = 128;
    char vec[] __attribute__((aligned(16))) = "Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligula eget dolor. Aenean massa. Cum sociis natoque pen";
    char vec2[n];
    char vec3[n];
    for (int i=0; i<n; i++){vec2[i] = '0';}
    for (int i=0; i<n; i++){vec3[i] = '0';}
    scalar_memcpy(vec2,vec,n);     
    vectorized_memcpy128i(vec3,vec,n);
    for (int i=0;i<n;i++){ASSERT_EQ(vec2[i],vec3[i]);}
}

/*unaligned dest and sourse alligned small size*/
TEST(SAmemcpytest1024x16,memcpy){
    /*Define a dummy text with 1024 characters*/
    register int n = 1024;
    char vec[] __attribute__((aligned(16))) = "Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligula eget dolor. Aenean massa. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Donec quam felis, ultricies nec, pellentesque eu, pretium quis, sem. Nulla consequat massa quis enim. Donec pede justo, fringilla vel, aliquet nec, vulputate eget, arcu. In enim justo, rhoncus ut, imperdiet a, venenatis vitae, justo. Nullam dictum felis eu pede mollis pretium. Integer tincidunt. Cras dapibus. Vivamus elementum semper nisi. Aenean vulputate eleifend tellus. Aenean leo ligula, porttitor eu, consequat vitae, eleifend ac, enim. Aliquam lorem ante, dapibus in, viverra quis, feugiat a, tellus. Phasellus viverra nulla ut metus varius laoreet. Quisque rutrum. Aenean imperdiet. Etiam ultricies nisi vel augue. Curabitur ullamcorper ultricies nisi. Nam eget dui. Etiam rhoncus. Maecenas tempus, tellus eget condimentum rhoncus, sem quam semper libero, sit amet adipiscing sem neque sed ipsum. Nam quam nunc, blandit ve";
    char vec2[n];
    char vec3[n];
    for (int i=0; i<n; i++){vec2[i] = '0';}
    for (int i=0; i<n; i++){vec3[i] = '0';}
    scalar_memcpy(vec2,vec,n);     
    vectorized_memcpy128i(vec3,vec,n);
    for (int i=0;i<n;i++){ASSERT_EQ(vec2[i],vec3[i]);}
}

/*Both dest and sourse unalligned small size*/
TEST(BUmemcpytest65x16,memcpy){
    /*Define a dummy text with 65 characters*/
    register int n = 65;
    char vec[] = "This is a dummy text with aim to test memcpy function by me tolis";
    char vec2[n];
    char vec3[n];
    for (int i=0; i<n; i++){vec2[i] = '0';}
    for (int i=0; i<n; i++){vec3[i] = '0';}
    scalar_memcpy(vec2,vec,n);     
    vectorized_memcpy128i(vec3,vec,n);
    for (int i=0;i<n;i++){ASSERT_EQ(vec2[i],vec3[i]);}
}

/*Both dest and sourse unalligned midle size*/
TEST(BUmemcpytest128x16,memcpy){
    /*Define a dummy text with 128 characters*/
    register int n = 128;
    char vec[] = "Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligula eget dolor. Aenean massa. Cum sociis natoque pen";
    char vec2[n];
    char vec3[n];
    for (int i=0; i<n; i++){vec2[i] = '0';}
    for (int i=0; i<n; i++){vec3[i] = '0';}
    scalar_memcpy(vec2,vec,n);     
    vectorized_memcpy128i(vec3,vec,n);
    for (int i=0;i<n;i++){ASSERT_EQ(vec2[i],vec3[i]);}
}

/*Both dest and sourse unalligned large size*/
TEST(BUmemcpytest1024x16,memcpy){
    /*Define a dummy text with 1024 characters*/
    register int n = 1024;
    char vec[] = "Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligula eget dolor. Aenean massa. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Donec quam felis, ultricies nec, pellentesque eu, pretium quis, sem. Nulla consequat massa quis enim. Donec pede justo, fringilla vel, aliquet nec, vulputate eget, arcu. In enim justo, rhoncus ut, imperdiet a, venenatis vitae, justo. Nullam dictum felis eu pede mollis pretium. Integer tincidunt. Cras dapibus. Vivamus elementum semper nisi. Aenean vulputate eleifend tellus. Aenean leo ligula, porttitor eu, consequat vitae, eleifend ac, enim. Aliquam lorem ante, dapibus in, viverra quis, feugiat a, tellus. Phasellus viverra nulla ut metus varius laoreet. Quisque rutrum. Aenean imperdiet. Etiam ultricies nisi vel augue. Curabitur ullamcorper ultricies nisi. Nam eget dui. Etiam rhoncus. Maecenas tempus, tellus eget condimentum rhoncus, sem quam semper libero, sit amet adipiscing sem neque sed ipsum. Nam quam nunc, blandit ve";
    char vec2[n];
    char vec3[n];
    for (int i=0; i<n; i++){vec2[i] = '0';}
    for (int i=0; i<n; i++){vec3[i] = '0';}
    scalar_memcpy(vec2,vec,n);     
    vectorized_memcpy128i(vec3,vec,n);
    for (int i=0;i<n;i++){ASSERT_EQ(vec2[i],vec3[i]);}
}

int main(int argc, char **argv) {  
  /*
  int size = 10;
  char vec[size] = "0123456789";
  char *buf1 = (char *) malloc(size);
  if (buf1 == NULL) {
        std::cout<<"Failed to allocate memory 10bytes";                   
        exit(1); // error!
  }

  register int n1 = ((intptr_t)vec & 0xF);
  register int n2 = ((intptr_t)buf1 & 0xF);

  std::cout<<"main n1 = "<<n1<<" ~ "<<std::hex<<(intptr_t)vec<<std::endl;
  std::cout<<"main n2 = "<<n2<<" ~ "<<(intptr_t)buf1<<std::dec<<std::endl;
  
  vectorized_memcpy128i(buf1,vec,size);
  
  free(buf1);
  return 0 ;
  */
  
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
  
}