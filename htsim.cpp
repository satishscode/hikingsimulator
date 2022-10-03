/*
 * Determine:
 *   1. the fastest time that the hikers can cross each bridge and
 *   2. The total time for all crossings.
 * The input to the program will be a yaml file that describes the 
 * speeds of each person, the bridges encountered, their length,
 * and the additional hikers encountered along the way.
 *
 * Your solution should assume any number of people and bridges 
 * can be provided as inputs.
 *
 * Referenced: https://yaml.org/refcard.html
 */

#include <iostream>
#include <fstream>
#include "parser.hpp"

using namespace std;

int main (int argc, char* argv[]) {
  // Accept input yaml file from command line
  HikeData hdata("hikedata.yaml");

  hdata.Parser();
  return 0;
}

