#ifndef GLASS_CUP_HPP
#define GLASS_CUP_HPP

#include "Cup.hpp"
#include "Glass.hpp"

class GlassCup : public Cup, protected Glass
{
public:
  /**
   * Constructor cangkir kaca dengan breaking_force = capacity / 10.
   *
   * PERHATIKAN: Constructor tidak perlu didefinisikan lagi
   *
   * @param capacity Kapasitas maksimum volume cangkir
   */
  GlassCup(int capacity) : Cup(capacity), Glass(capacity / 10){};

  /**
   * @return Apakah cangkir kaca masih dapat digunakan?
   */
  bool is_usable();

  /**
   * Mengisi air ke dalam cangkir
   *
   * Jika cangkir tidak usable, tidak melakukan apapun
   *
   * @param volume Dijamin dalam range [0, INTMAX)
   * @param type
   */
  void fill(int volume, enum WaterType type);

  /**
   * Meminum air dari cangkir
   *
   * Jika cangkir tidak usable, tidak melakukan apapun
   *
   * @param volume Dijamin dalam range [0, INTMAX)
   */
  void drink(int volume);

  /**
   * Menjatuhkan cangkir dari ketinggian height
   *
   * Mengaplikasikan force sejumlah <height * volume air saat ini>
   * Jika volume air saat ini = 0, mengaplikasikan force hanya sejumlah <height>
   *
   * @param height Dijamin dalam range [0, 100]
   */
  void drop(int height);
};

#endif
