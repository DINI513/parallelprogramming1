#include <stdlib.h> 
#include <math.h>
#include <emmintrin.h> 
#include <ctime> 
#include <iostream> 

void normal(float* a, int N) 
{ 
	for (int i = 0; i < N; ++i) 
		a[i] = sqrt(a[i]); 
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
	normal(a, N); 
	unsigned int end_time = clock(); 
	char outString[50]; 
	sprintf(outString, "Normal: %d tick\n", end_time - start_time); 
	std::cout << outString; 
} 
