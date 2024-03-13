#ifndef GLASS_HPP
#define GLASS_HPP

#include "Usable.hpp"

class Glass : public Usable
{
private:
  /**
   * Apakah kaca sudah pecah?
   */
  bool broken;

public:
  /**
   * Force terendah yang akan memecahkan kaca
   */
  const int breaking_force;

  /**
   * @param breaking_force Force terendah yang akan memecahkan kaca
   */
  Glass(int breaking_force);

  /**
   * @return Apakah kaca masih berfungsi (utuh)?
   */
  bool is_usable();

  /**
   * Mengaplikasikan sejumlah force terhadap kaca.
   * Jika force > breaking_force, kaca akan pecah.
   *
   * @param force Force yang diaplikasikan
   */
  void apply_force(int force);
};

#endif
