#include "Glass.hpp"

Glass::Glass(int breaking_force) : breaking_force(breaking_force), broken(false)
{
}

bool Glass::is_usable()
{
  return !Glass::broken;
}

void Glass::apply_force(int force)
{
  if (!Glass::broken && force >= breaking_force)
  {
    Glass::broken = true;
  }
}
