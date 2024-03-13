#include "Plastic.hpp"

int fpb(int x,int y){
    if(y == 0)return x;
    else return fpb(y,x%y);
}

Plastic::Plastic(int microplastic_rate, int maximum_use) : microplastic_rate(microplastic_rate), maximum_use(maximum_use), used_count(0)
{
}

void Plastic::use()
{
  Plastic::used_count++;
  Plastic::microplastic_rate += (Plastic::microplastic_rate / 2) + 1;
}

int Plastic::shred_microplastics(int pembilang,int penyebut)
{
  Plastic::maximum_use--;
  if (Plastic::maximum_use < 0)
  {
    Plastic::maximum_use = 0;
  }

  int maxDivisor = fpb(pembilang,penyebut);

  pembilang /= maxDivisor;
  penyebut /= maxDivisor;

  return (Plastic::microplastic_rate * pembilang) / penyebut;
}

bool Plastic::is_usable()
{
  return Plastic::used_count <= Plastic::maximum_use;
}
