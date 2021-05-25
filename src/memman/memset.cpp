/*In this file memset was vectorized with diferend aproaches as they will be 
  descruped during their bulid.
*/

#include<string.h>
#include<stdint.h>
#include<immintrin.h>
#include<iostream>
#include<vector>

/*προσπαθησα να το περασω ετσι οπως εδω αλλα δεν επεξε*/
/*
void *scalar_memsetcpp(std::vector<char>*s, int c, size_t n){
    std::cout<<"call memsetcpp"<< std::endl;
    std::vector<char> *sp=(std::vector<char> *)s;
    for (int i=0;i<n;i++){sp[i]=c;}
    std::cout<<"end memsetcpp"<< std::endl;
    return sp;
}
*/

void *scalar_memset(void *s, int c, size_t n){
    char *sp=(char *)s;
    for (int i=0;i<n;i++){sp[i]=c;}
    return sp;
}


void *vectorized_memset128i(void *s, int c, size_t n){
    char *sp=(char *)s;
    size_t len=n;

    int n1 = ((intptr_t)sp & 0xF); 
    if (n1!= 0) {
        /* unaligned pre-pass */
        scalar_memset(sp,c,16-n1);
        sp+=16-n1;
        len-=n1;
    } 

    int k = len/16;
    for (int i=0;i<k;i++){
        _mm_store_si128((__m128i*)sp,_mm_set1_epi8(c));
        sp+=16;
    }

    len-=k*16;
    if (len !=0){
        scalar_memset(sp,c,len);
    }

    return sp;
}


void *vectorized_memset256i(void *s, int c, size_t n){
    char *sp=(char *)s;
    size_t len=n;

    int n1 = ((intptr_t)sp & 0x1F); 
    if (n1!= 0) {
        /* unaligned pre-pass */
        scalar_memset(sp,c,32-n1);
        sp+=32-n1;
        len-=n1;
    } 

    int k = len/32;
    for (int i=0;i<k;i++){
        _mm256_store_si256((__m256i*)sp,_mm256_set1_epi8(c));
        sp+=32;
    }

    len-=k*32;
    if (len !=0){
        scalar_memset(sp,c,len);
    }

    return sp;

}

