#include "DepreciatingAsset.hpp"
#include <math.h>

double DepreciatingAsset::getValue(int years){
  return x->getValue(years) * pow((1-rate),years);
}
