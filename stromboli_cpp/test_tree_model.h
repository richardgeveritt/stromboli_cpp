#include <RcppArmadillo.h>
using namespace Rcpp;

#include "ilike_header.h"

Data data();

double evaluate_log_likelihood(const Parameters &inputs, const Data &observed_data);

/*
double evaluate_log_prior(const Parameters &inputs);

Parameters simulate_prior(RandomNumberGenerator &rng);

Data simulate_model(RandomNumberGenerator &rng,
                    const Parameters &parameters);

Parameters simulate_independent_proposal(RandomNumberGenerator &rng);

double evaluate_log_proposal(const Parameters &inputs);

//double evaluate_log_abc_kernel(const Data &simulated_data, const Data &observed_data);

Parameters transform_parameters(const Parameters &input);

Parameters inverse_transform_parameters(const Parameters &input);

Data summary_statistics(const Data &data);
*/
