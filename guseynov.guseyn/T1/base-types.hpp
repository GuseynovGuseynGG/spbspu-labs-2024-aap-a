#ifndef BASE-TYPES_HPP
#define BASE-TYPES_HPP

namespace guseynov
{
  struct point_t
  {
    double x;
    double y;
  };

  struct rectangle_t
  {
    double width;
    double height;
    point_t pos;
  };

#endif
