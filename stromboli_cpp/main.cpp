//
//  main.cpp
//  my_beagle
//
//  Created by Everitt on 16/03/2023.
//  Copyright © 2023 Richard Everitt. All rights reserved.
//

#include <iostream>
#include "parameters.h"
#include "test_tree_model.h"
#include "node.h"

const double strom::Node::_smallest_edge_length = 1.0e-12;

int main(int argc, const char * argv[]) {
  
  Data the_data = data();
  std::cout << the_data;
  
  double result = evaluate_log_likelihood(Parameters(),the_data);
  
  std::cout << result;
  return 0;
}
