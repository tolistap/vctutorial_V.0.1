# Makefile from scratch 
# Definition of variables with aim to complite the files
CC = g++
CXXFLAGS =  -std=c++11 -Wall -I src/include -DWITHOUT_NUMPY -I/usr/include/python3.8 -mavx -mavx2 -O2 -g3 
LDFLAGS = -lgtest -lpthread -lpython3.8

BENCHMARKEXE = bin/Benchmarks.exe

MEM1EXE = bin/test_memset.exe
MEM2EXE = bin/test_memchr.exe
MEM3EXE = bin/test_memcpy.exe

MATH1EXE = bin/test_Comparison_vectorized.exe
MATH2EXE = bin/test_Dot_product_vectorized.exe
MATH3EXE = bin/test_min_max_vectorized.exe
MATH4EXE = bin/test_lshift.exe

LAMATH1 = bin/test_Add_matrixes.exe
LAMATH2 = bin/test_Transpose_matrixes.exe
LAMATH3 = bin/test_Mul_matrixes.exe 


BENCHMARKSOBJ = obj/Benchmarks/Benchmarks.o obj/Benchmarks/Benchmark_memchr.o obj/Benchmarks/Benchmark_memset.o obj/Benchmarks/Benchmark_memcpy.o obj/memman/memset.o obj/memman/memchr.o obj/memman/memcpy.o obj/Maths/Comparison_vectorized.o obj/Benchmarks/Benchmark_Comparisons.o obj/Maths/Dot_product_vectorized.o obj/Benchmarks/Benchmark_Dotproduct.o  obj/Benchmarks/Benchmark_minmax.o obj/Maths/min_max_vectorized.o obj/Benchmarks/Benchmark_Add_matrixes.o obj/Linear_Algebra/Add_matrixes_vectorized.o obj/Benchmarks/Benchmark_Transpose_matrixes.o obj/Linear_Algebra/Transpose_matrixes_vectorized.o  obj/Benchmarks/Benchmark_Mul_matrixes.o obj/Linear_Algebra/Mul_matrixes_vectorized.o   obj/Prints/PrintVecs.o

# Define Print function
print-%: ; @echo $* = $($*)

#move all .o files in objectfiles directory
all: makedir  $(MEM1EXE) $(MEM2EXE) $(MEM3EXE) $(MATH1EXE) $(MATH2EXE) $(MATH3EXE) $(MATH4EXE) $(LAMATH1)  $(LAMATH2) $(LAMATH3) $(BENCHMARKEXE)


# Start memman executable creation
$(MEM1EXE): obj/memman/test_memset.o obj/memman/memset.o
	$(CC) obj/memman/test_memset.o obj/memman/memset.o $(LDFLAGS) -o $@

$(MEM2EXE): obj/memman/test_memchr.o obj/memman/memchr.o obj/memman/memset.o 
	$(CC) obj/memman/test_memchr.o obj/memman/memchr.o obj/memman/memset.o $(LDFLAGS) -o $@

$(MEM3EXE): obj/memman/test_memcpy.o obj/memman/memcpy.o obj/Prints/PrintVecs.o
	$(CC) obj/memman/test_memcpy.o obj/memman/memcpy.o obj/Prints/PrintVecs.o $(LDFLAGS) -o $@ 

$(MATH1EXE): obj/Maths/test_Comparison_vectorized.o obj/Maths/Comparison_vectorized.o
	$(CC) obj/Maths/test_Comparison_vectorized.o obj/Maths/Comparison_vectorized.o $(LDFLAGS) -o $@


$(MATH2EXE): obj/Maths/test_Dot_product_vectorized.o obj/Maths/Dot_product_vectorized.o obj/Prints/PrintVecs.o
	$(CC) obj/Maths/test_Dot_product_vectorized.o obj/Maths/Dot_product_vectorized.o obj/Prints/PrintVecs.o $(LDFLAGS) -o $@

$(MATH3EXE): obj/Maths/test_min_max_vectorized.o obj/Maths/min_max_vectorized.o obj/Prints/PrintVecs.o
	$(CC) obj/Maths/test_min_max_vectorized.o obj/Maths/min_max_vectorized.o  obj/Prints/PrintVecs.o $(LDFLAGS) -o $@

$(MATH4EXE): obj/Maths/test_lshift.o obj/Maths/lshift.o obj/Prints/PrintVecs.o
	$(CC) obj/Maths/test_lshift.o obj/Maths/lshift.o obj/Prints/PrintVecs.o $(LDFLAGS) -o $@

$(LAMATH1): obj/Linear_Algebra/test_Add_matrixes.o obj/Linear_Algebra/Add_matrixes_vectorized.o obj/Prints/PrintVecs.o
	$(CC) obj/Linear_Algebra/test_Add_matrixes.o obj/Linear_Algebra/Add_matrixes_vectorized.o obj/Prints/PrintVecs.o $(LDFLAGS) -o $@ 


$(LAMATH2): obj/Linear_Algebra/test_Transpose_matrixes.o obj/Linear_Algebra/Transpose_matrixes_vectorized.o obj/Prints/PrintVecs.o
	$(CC) obj/Linear_Algebra/test_Transpose_matrixes.o obj/Linear_Algebra/Transpose_matrixes_vectorized.o obj/Prints/PrintVecs.o $(LDFLAGS) -o $@ 

$(LAMATH3): obj/Linear_Algebra/test_Mul_matrixes.o  obj/Linear_Algebra/Mul_matrixes_vectorized.o  obj/Linear_Algebra/Transpose_matrixes_vectorized.o obj/Prints/PrintVecs.o
	$(CC)   obj/Linear_Algebra/test_Mul_matrixes.o  obj/Linear_Algebra/Mul_matrixes_vectorized.o  obj/Linear_Algebra/Transpose_matrixes_vectorized.o obj/Prints/PrintVecs.o $(LDFLAGS) -o $@ 


# Start Benchmark executable creation θα μπορουσα με μια wildcard να μαζεψω ολα τα αρχεια .ο 
$(BENCHMARKEXE): $(BENCHMARKSOBJ)
	$(CC) $(BENCHMARKSOBJ) $(LDFLAGS) -o $@


obj/memman/%.o:src/memman/%.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@

obj/Benchmarks/%.o:src/Benchmarks/%.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@

obj/Maths/%.o:src/Maths/%.cpp
	$(CC)  $(CXXFLAGS) -c $< -o $@

obj/Prints/%.o:src/Prints/%.cpp
	$(CC)  $(CXXFLAGS) -c $< -o $@

obj/Linear_Algebra/%.o:src/Linear_Algebra/%.cpp
	$(CC)  $(CXXFLAGS) -c $< -o $@

makedir: 
	mkdir -p obj/memman obj/Maths obj/Benchmarks obj/Prints obj/Linear_Algebra bin

# clear all .o .a files on currend directory and sub directories
clean: 
	rm -rf obj bin
