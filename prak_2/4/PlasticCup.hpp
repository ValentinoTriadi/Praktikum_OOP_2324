#ifndef PLASTIC_CUP_HPP
#define PLASTIC_CUP_HPP

#include "Cup.hpp"
#include "Plastic.hpp"

class PlasticCup : public Cup, protected Plastic
{
private:
  /**
   * Kandungan microplastic di dalam cangkir saat ini
   */
  int current_microplastics;

public:
  /**
   * Limit kandungan microplastic
   */
  const int maximum_microplastics;

  /**
   * Constructor cangkir plastik dengan microplastic_rate awal = 1 dan
   * maximum_use awal = 1.
   *
   * PERHATIKAN: Constructor tidak perlu didefinisikan lagi
   *
   * @param capacity Kapasitas maksimum volume cangkir
   * @param maximum_microplastics Limit kandungan microplastic
   */
  PlasticCup(int capacity, int maximum_microplastics) : Cup(capacity), Plastic(1, capacity), maximum_microplastics(maximum_microplastics), current_microplastics(0)
  {
  }

  /**
   * Cangkir plastik layak digunakan jika plastik masih layak,
   * DAN kandungan microplastic di dalamnya di bawah maximum_microplastics.
   *
   * @return Apakah cangkir plastik masih layak digunakan?
   */
  bool is_usable();

  /**
   * Mengisi air ke dalam cangkir.
   *
   * 1. Kandungan air bertambah.
   * 2. Plastik "digunakan".
   * 3. Microplastic terurai berdasarkan rasio <volume air setelah ditambah / kapasitas maksimum>.
   *    Penguraian microplastic menjadi dua kali lipatnya jika air adalah air panas.
   * 4. Kandungan microplastic bertambah sesuai hasil no. 3
   *
   * Jika cangkir tidak usable, tidak melakukan apapun.
   *
   * @param volume Dijamin dalam range [0, INTMAX)
   * @param type
   */
  void fill(int volume, enum WaterType type);

  /**
   * Meminum air dari cangkir.
   *
   * 1. Kandungan air berkurang.
   * 2. Plastik "digunakan".
   * 3. Kandungan microplastic berkurang sejumlah parameter <volume>, bila hasil pengurangan bernilai negatif set nilai kandungan microplastic = 0.
   *
   * Jika cangkir tidak usable, tidak melakukan apapun
   *
   * @param volume Dijamin dalam range [0, INTMAX)
   */
  void drink(int volume);

  /**
   * Menjatuhkan cangkir dari ketinggian height.
   *
   * Kandungan microplastic bertambah sejumlah penguraian microplastic
   * dengan rasio berupa <volume air * height / kapasitas>
   *
   * @param height Dijamin dalam range [0, 100]
   */
  void drop(int height);
};

#endif
