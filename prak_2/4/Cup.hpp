#ifndef CUP_HPP
#define CUP_HPP

#include "Usable.hpp"

enum WaterType
{
  HOT_WATER = 1,
  NORMAL_WATER = 0,
  COLD_WATER = -1
};

class Cup : public Usable
{
private:
  /**
   * Volume air yang ditampung saat ini
   */
  int water_volume;

public:
  /**
   * Kapasitas maksimum volume cangkir
   */
  const int capacity;

  /**
   * @param capacity Kapasitas maksimum volume cangkir
   */
  Cup(int capacity);

  /**
   * @return Volume air yang ditampung saat ini
   */
  int get_water_volume();

  /**
   * Mengisi air ke dalam cangkir
   *
   * @param volume Dijamin dalam range [0, INTMAX)
   * @param type
   */
  virtual void fill(int volume, enum WaterType type);

  /**
   * Meminum air dari cangkir
   *
   * @param volume Dijamin dalam range [0, INTMAX)
   */
  virtual void drink(int volume);

  /**
   * Menjatuhkan cangkir dari ketinggian height
   *
   * @param height Dijamin dalam range [0, 100]
   */
  virtual void drop(int height);
};

#endif
