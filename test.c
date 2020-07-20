#include "bootstrap.h"
#include <time.h>

int main(int argc, char *argv[])
{
	gsl_rng* rng = gsl_rng_alloc(gsl_rng_mt19937);
	gsl_rng_set(rng, time(NULL));
	b_instance* boot = b_setup(1000, rng);
	double data[] = {3.0, 2.9, 3.1, 3.2, 3.3, 3.1, 2.8};
	for(int i = 0; i < 7; i++)
		b_add(boot, data[i]);
	b_upderr(boot);
	printf("%f, %f\n", boot->mean, boot->error);
	return 0;
}
