#include "test_tree_model.h"
#include "utils.h"
#include "data.h"
#include "likelihood.h"
#include "tree_summary.h"
#include "tree.h"

using boost::any_cast;

Data data()
{
  strom::Data::SharedPtr seq_data = strom::Data::SharedPtr(new strom::Data());
  
  seq_data->getDataFromFile("/Users/Everitt/Dropbox/projects/stromboli_cpp/stromboli_cpp/rbcL.nex");
  
  Data data;
  data("sequences") = seq_data;
  return data;
  /*
  size_t n = 100;
  //arma::colvec sampled = rnorm(rng,n);
  arma::colvec sampled(n);
  
  for (size_t i = 0; i<n; ++i)
    sampled[i] = rnorm(rng,0.0,1.0);
  
  data["y"] = sampled;
  return data;
  */
}

double evaluate_log_likelihood(const Parameters &inputs, const Data &observed_data)
{
  strom::Likelihood::SharedPtr _likelihood = strom::Likelihood::SharedPtr(new strom::Likelihood());
  
  strom::TreeSummary::SharedPtr _tree_summary = strom::TreeSummary::SharedPtr(new strom::TreeSummary());
  _tree_summary->readTreefile("/Users/Everitt/Dropbox/projects/stromboli_cpp/stromboli_cpp/rbcLjc.tre", 0);
  strom::Tree::SharedPtr tree = _tree_summary->getTree(0);
  
  _likelihood->setData(any_cast<strom::Data::SharedPtr>(observed_data("sequences")));
  return _likelihood->calcLogLikelihood(tree);
  
  //double precision = inputs["tau"][0];
  //return sum(dnorm(observed_data["y"], 0.0, 1.0/sqrt(precision)));
}

/*
double evaluate_log_prior(const Parameters &inputs)
{
  //std::cout<< inputs["tau"];
  return dlnorm(inputs["tau"][0], 1.0, 1.0);
}

Parameters simulate_prior(RandomNumberGenerator &rng)
{
  Parameters output;
  output["tau"] = rlnorm(rng, 1.0, 1.0);
  return output;
}

Data simulate_model(RandomNumberGenerator &rng,
                    const Parameters &parameters)
{
  Data output;
  size_t n = 100;
  //arma::mat tau = parameters["tau"];
  //std::cout << tau;
  double precision = parameters["tau"][0];
  output["y"] = rnorm(rng, n, 0.0, 1.0/sqrt(precision));
  return output;
}

Parameters simulate_independent_proposal(RandomNumberGenerator &rng,
                                         const Parameters &proposal_parameters)
{
  Parameters output;
  output["tau"] = rlnorm(rng, 1.0, 1.0);
  return output;
}

double evaluate_log_proposal(const Parameters &inputs)
{
  return dlnorm(inputs["tau"][0], 1.0, 1.0);
}
Parameters transform_parameters(const Parameters &input)
{
  return Parameters("tau",log(input["tau"][0]));
}

Parameters inverse_transform_parameters(const Parameters &input)
{
  return Parameters("tau",exp(input["tau"][0]));
}

Data summary_statistics(const Data &data)
{
  return Data("sd",arma::stddev(data["y"]));
}
*/
