#include <stdlib.h>
#include <math.h>
#include <emmintrin.h> 
#include <ctime> 
#include <iostream> 

void sse(float* a, int N) 
{ 
	// We assume N % 4 == 0. 
	int nb_iters = N / 4; 
	__m128* ptr = (__m128*)a; 

	for (int i = 0; i < nb_iters; ++i, ++ptr, a += 4) 
		_mm_store_ps(a, _mm_sqrt_ps(*ptr)); 
} 

int main(int argc, char** argv)
{
	if (argc != 2)
		return 1;
	int N = atoi(argv[1]); 

	float* a; 
	posix_memalign((void**)&a, 16, N * sizeof(float)); 

	for (int i = 0; i < N; ++i) 
		a[i] = 3141592.65358; 

	unsigned int start_time = clock();
	sse(a, N); 
	unsigned int end_time = clock(); 
	char outString[50]; 
	sprintf(outString, "SSE: %d tick\n", end_time - start_time); 
	std::cout << outString; 
} 

