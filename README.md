# Introduction

Bootstrap is an excellent algorithm for computing the statistical error of an estimate in a wide variety of situations through the use of resampling. Usually this error analysis requires the sample to be entirely present in order to analyse it.

This library uses Poisson statistics to perform an *online* error analysis, where each data value is only considered once. It is extremely light and allows for arbitrary sample sizes.


# Usage

## Initialise your favourite RNG from `GSL`

`gsl_rng* rng = gsl_rng_alloc(gsl_rng_mt19937);`

Seed to taste.


## Initialise the bootstrap library
`b_instance* boot = b_setup(20, rng);`

Here we are using 20 bins (standard)

## Add data as you go

`b_add(boot, datavalue);`

## Update error as required

`b_upderr(boot);`

This only has to be done when the error is required, e.g for a visual output of the current error. The current mean and error are accessed with `boot->mean` and `boot->error`.

## Clean up when done

`b_clean(boot)`

