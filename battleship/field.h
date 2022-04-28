#ifndef BATTLESHIP__FIELD_H_
#define BATTLESHIP__FIELD_H_
#include <array>
#include "point.h"
class Field {
 private:
  std::array<std::array<int, 10>, 10> field_;
 public:
  explicit Field(std::array<std::array<int, 10>, 10> field) : field_(field) {
    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < 10; ++j) {
        field_[j][i] = 0;
      }
    }
  }
  Field() : field_(std::array<std::array<int, 10>, 10>()) {
    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < 10; ++j) {
        field_[j][i] = 0;
      }
    }
  }
  int GetPoint(size_t abscissa, size_t ordinate) {
    return field_[abscissa][ordinate];
  }
  int GetPoint(Point &pnt) {
    return field_[pnt.GetAbscissa()][pnt.GetOrdinate()];
  }
  void SetPoint(Point &pnt, int t) {
    field_[pnt.GetAbscissa()][pnt.GetOrdinate()] = t;
  }
  void SetPoint(int a, int o, int t) {
    field_[a][o] = t;
  }
  friend std::ostream &operator<<(std::ostream &out, Field field);
};
std::ostream &operator<<(std::ostream &out, Field field) {
  out << "   A B C D E F G H I J" << '\n';
  for (int i = 0; i < 10; ++i) {
    (i < 9) ? (out << i + 1 << "  ") : (out << i + 1 << " ");
    for (int j = 0; j < 10; ++j) {
      out << field.field_[j][i] << " ";
    }
    out << '\n';
  }
  return out;
}
#endif

