/*
* file test/src/firtest_sys.c
* brief system/conformity test for output vectors of miscellaneous algorithms
* author
* date
*/

/* dependencies */
#include <firtest.h>

 /*
  * system/conformity test for output vectors of miscellaneous algorithms
  */
Boolean firtest_sys(	TestSystem_obj *conformity,
						float *src1,
						float *src2,
						uint64_t size) {
	register int i;
	register float diff, diff_percent, max_percent=0.0f, errorMax;
	register uint64_t nbError=0;
	
	/* initialization */
	errorMax = conformity->error_margin;

	/* conformity test procedure */
	for (i=0; i<size-1; i++) {

		diff = (float) fabs ( (double) (src1[i] - src2[i]));
		diff_percent = (diff * 100.0f) / src1[i];

		if (diff_percent > max_percent)
			max_percent = diff_percent;

		if (diff_percent > errorMax) {
			nbError++;
		}
	}

	/* back up */
	conformity->error_percent = max_percent;
	conformity->error_samples = nbError;
	if (conformity->error_samples != 0) {
		strcpy(conformity->error_status, "NOK");
		return FALSE;
	} else {
		strcpy(conformity->error_status, "OK");
		return TRUE;
	}
}
