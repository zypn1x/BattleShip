#ifndef BATTLESHIP__PROTECTION_FIELD_H_
#define BATTLESHIP__PROTECTION_FIELD_H_
#include "field.h"
#include "ship.h"
#include "point.h"
class ProtectionField : public Field {
 public:
  explicit ProtectionField(std::array<std::array<int, 10>, 10> field) : Field(field) {}
  ProtectionField() : Field(std::array<std::array<int, 10>, 10>()) {
    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < 10; ++j) {
        SetPoint(i, j, 0);
      }
    }
  }

  template<size_t N>
  void AddShip(Ship<N> &ship) {
    if (ship.GetBegin().GetOrdinate() == ship.GetEnd().GetOrdinate()) {
      for (int i = 0; i < N; ++i) {
        Field::SetPoint(ship.GetBegin().GetAbscissa() + i, ship.GetBegin().GetOrdinate(), 1);
      }
    } else {
      for (int i = 0; i < N; ++i) {
        Field::SetPoint(ship.GetBegin().GetAbscissa(), ship.GetBegin().GetOrdinate() + i, 1);
      }
    }
  }
  ~ProtectionField() = default;
};
#endif