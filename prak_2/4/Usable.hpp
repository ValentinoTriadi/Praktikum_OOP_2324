#ifndef USABLE_HPP
#define USABLE_HPP

class Usable
{
public:
  /**
   * @return Apakah benda dapat digunakan?
   */
  virtual bool is_usable() = 0;
};

#endif
