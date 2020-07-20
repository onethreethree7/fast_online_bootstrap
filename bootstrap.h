#ifndef BOOTSTRAP_H
#define BOOTSTRAP_H

#include <gsl/gsl_randist.h>

struct b_bin {
    unsigned long size;
    double mean;
};
typedef struct b_bin b_bin;

struct b_instance {
    gsl_rng* rng;
    int num;
    b_bin* bins;
    double mean;
    double error;
};
typedef struct b_instance b_instance;

b_instance* b_setup(int, gsl_rng*);
void b_add(b_instance*, double);
void b_upderr(b_instance*);
void b_clean(b_instance*);

#endif
