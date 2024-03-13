#include "Cup.hpp"

Cup::Cup(int capacity) : water_volume(0), capacity(capacity)
{
}

int Cup::get_water_volume()
{
  return Cup::water_volume;
}

void Cup::fill(int volume, enum WaterType type)
{
  Cup::water_volume += volume;
  if (Cup::water_volume > Cup::capacity)
  {
    Cup::water_volume = Cup::capacity;
  }
}

void Cup::drink(int volume)
{
  Cup::water_volume -= volume;
  if (Cup::water_volume < 0)
  {
    Cup::water_volume = 0;
  }
}

void Cup::drop(int height)
{
}
