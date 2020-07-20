#include <math.h>
#include "bootstrap.h"

b_instance* b_setup(int num, gsl_rng* rng) {
	b_instance* inst = malloc(sizeof(b_instance));
	inst->rng = rng;
	inst->num = num;
	inst->mean = 0;
	inst->error = 0;
	inst->samples = 0;
	inst->bins = calloc(num, sizeof(b_bin));
	return inst;
}

void b_add(b_instance* inst, double val) {
	int poiss;
	double mean = 0;
	b_bin* curbin;
	for(int j = 0; j < inst->num; j++) {
		curbin = &inst->bins[j];
		poiss = gsl_ran_poisson(inst->rng, 1.0);
		for(int k = 0; k < poiss; k++) {
		    curbin->mean = (curbin->mean*curbin->size + val)/((curbin->size) + 1);
		    curbin->size += 1;
		}
		mean += curbin->mean;
	}
	inst->mean = mean/inst->num;
	inst->samples++;
	return;
}

void b_upderr(b_instance* inst) {
	double calc = 0;
	for (int i = 0; i < inst->num; i++) {
		calc += (inst->bins[i].mean - inst->mean)*(inst->bins[i].mean - inst->mean);
	}
	calc /= (inst->num - 1);
	inst->error = sqrt(calc);
	return;
}

void b_clean(b_instance* inst) {
	free(inst->bins);
	free(inst);
	return;
}
