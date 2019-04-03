/*
* file test\src\firtest_main.c
* brief conformity and performance tests for FIR algorithms library
* author
* date
*/

#include <firtest.h>
#include <xk_sp_8Kb.h>
#include <a_sp.h>

/* input and ouputs vectors */
float yk_sp_cn[YK_LENGTH] __attribute__((aligned(16)));
float yk_sp[YK_LENGTH] __attribute__((aligned(16)));

/*
 * flush pipeline and read current TSC value (Time Stamp Counter)
 */
inline unsigned long long __attribute__((always_inline)) rdtsc_inline() {
	unsigned int hi, lo;
	__asm__ __volatile__(
		// flush core pipeline
		"xorl %%eax, %%eax\n\t"
		"cpuid\n\t"
		// read current TSC value
		"rdtsc"
			: "=a"(lo), "=d"(hi)
			: // no parameters
			: "rbx", "rcx");
	return ((unsigned long long)hi << 32ull) | (unsigned long long)lo;
}

/*
 * main entry point
 */
int main(int argc, char* argv[])
{
	TestSystem_obj 	conformity;
	int 			validity;
	long			start, stop, duration;

	/* initializations */
	conformity.error_margin = 1.0f;

	/* fir benchmarking : single precision in canonical c 
	 * genuine Intel corei7 Haswell micro-architecture (full cacheability) 
	 */
	printf(	"\n--> fir algorithm : single precision in canonical c" 
			"\n--> genuine Intel corei7 Haswell micro-architecture"
			"\nmemory model : full cacheability");

	start = rdtsc_inline();
	fir_sp (xk_sp, a_sp, yk_sp_cn, A_LENGTH, YK_LENGTH);
	stop = rdtsc_inline();
	duration = stop - start;

	printf(	"\nperformance : %ld cycles, "
			"%.3f ms, %.3f MACS per cycle\n"
						, duration
						, (float) duration * CPU_CLOCK_MS
						, (float) FIR_NB_MACS / (float) duration);

	/* fir benchmarking : single precision in radix 4 canonical c 
	 * genuine Intel corei7 Haswell micro-architecture (full cacheability) 
	 */
	printf(	"\n--> fir algorithm : single precision in radix 4 canonical c" 
			"\n--> genuine Intel corei7 Haswell micro-architecture"
			"\nmemory model : full cacheability");

	start = rdtsc_inline();
	fir_sp_r4 (xk_sp, a_sp, yk_sp, A_LENGTH, YK_LENGTH);
	stop = rdtsc_inline();
	duration = stop - start;

	validity = firtest_sys (&conformity, yk_sp_cn, yk_sp, YK_LENGTH);
	printf("\nconformity : status %s, max %3.3f%%, %ld samples\n"	
									, conformity.error_status
									, conformity.error_percent
									, conformity.error_samples);
	if ( validity ) {
		printf(	"\nperformance : %ld cycles, "
			"%.3f ms, %.3f MACS per cycle\n", duration
							, (float) duration * CPU_CLOCK_MS
							, (float) FIR_NB_MACS / (float) duration);
	}

	/* fir benchmarking : single precision in radix 4 vectorized C
	 * genuine Intel corei7 Haswell micro-architecture (full cacheability)
	 * ISA extension : SSE4.1 (DSP extension)		 
	 */
	printf(	"\n--> fir algorithm : single precision in SSE4.1 vectorized c" 
			"\n--> genuine Intel corei7 Haswell micro-architecture"
			"\n--> ISA extension : SSE4.1 (DSP extension)"
			"\nmemory model : full cacheability");

	start = rdtsc_inline();
	fir_sp_sse_r4 (xk_sp, a_sp, yk_sp, A_LENGTH, YK_LENGTH);
	stop = rdtsc_inline();
	duration = stop - start;

	validity = firtest_sys (&conformity, yk_sp_cn, yk_sp, YK_LENGTH);
	printf("\nconformity : status %s, max %3.3f%%, %ld samples\n"	
									, conformity.error_status
									, conformity.error_percent
									, conformity.error_samples);
	if ( validity ) {
		printf(	"\nperformance : %ld cycles, "
				"%.3f ms, %.3f MACS per cycle\n"
							, duration
							, (float) duration * CPU_CLOCK_MS
							, (float) FIR_NB_MACS / (float) duration);
	}

	return 0;
}
