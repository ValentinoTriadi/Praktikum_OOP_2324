#ifndef PLASTIC_HPP
#define PLASTIC_HPP

#include "Usable.hpp"

class Plastic : public Usable
{
private:
  /**
   * Seberapa banyak microplastic yang terurai
   */
  int microplastic_rate;

  /**
   * Maksimum total penggunaan plastik (dinamis tergantung penggunaan)
   */
  int maximum_use;

  /**
   * Total penggunaan
   */
  int used_count;

public:
  /**
   * @param microplastic_rate Jumlah awal seberapa banyak microplastic yang terurai
   * @param maximum_use Jumlah awal maksimum total penggunaan plastik
   */
  Plastic(int microplastic_rate, int maximum_use);

  /**
   * "Menggunakan" plastik. Menambah jumlah total penggunaan sebanyak 1.
   */
  void use();

  /**
   * Menguraikan microplastic sejumlah rasio (pembilang/penyebut) terhadap microplastic_rate, penyebut dijamin tidak 0
   * Pembilang dan penyebut akan DIPROSES TERLEBIH DAHULU agar FPB(PEMBILANG,PENYEBUT) = 1
   * 
   * @return "Jumlah" microplastic yang terurai
   */
  int shred_microplastics(int pembilang,int penyebut);

  /**
   * @return Apakah plastik masih layak pakai?
   */
  bool is_usable();
};

#endif
