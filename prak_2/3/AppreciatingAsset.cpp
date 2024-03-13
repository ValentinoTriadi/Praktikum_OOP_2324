#include "AppreciatingAsset.hpp"
#include <math.h>

double AppreciatingAsset::getValue(int years){
  return x->getValue(years) * pow((1+rate),years);
}
