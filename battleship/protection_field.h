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
  bool AddShip(Ship<N> &ship) {
    if (ship.GetBegin().GetOrdinate() == ship.GetEnd().GetOrdinate()) {
      for (int i = 0; i < N; ++i) {
        if (Field::GetPoint(ship.GetBegin().GetAbscissa() + i, ship.GetBegin().GetOrdinate()) == 1) {
          return false;
        }
      }
      if (ship.GetBegin().GetOrdinate() > 0) {
        for (int i = 0; i < N; ++i) {
          if (Field::GetPoint(ship.GetBegin().GetAbscissa() + i, ship.GetBegin().GetOrdinate() - 1) == 1) {
            return false;
          }
        }
      }
      if (ship.GetBegin().GetOrdinate() < 9) {
        for (int i = 0; i < N; ++i) {
          if (Field::GetPoint(ship.GetBegin().GetAbscissa() + i, ship.GetBegin().GetOrdinate() + 1) == 1) {
            return false;
          }
        }
      }
      if (ship.GetBegin().GetAbscissa() > 0 && ship.GetEnd().GetAbscissa() > 0) {
        if (Field::GetPoint(ship.GetBegin().GetAbscissa() - 1, ship.GetBegin().GetOrdinate()) == 1) {
          return false;
        }
      }
      if (ship.GetBegin().GetAbscissa() < 9 && ship.GetEnd().GetAbscissa() < 9) {
        if (Field::GetPoint(ship.GetEnd().GetAbscissa() + 1, ship.GetEnd().GetOrdinate()) == 1) {
          return false;
        }
      }
      for (int i = 0; i < N; ++i) {
        Field::SetPoint(ship.GetBegin().GetAbscissa() + i, ship.GetBegin().GetOrdinate(), 1);
      }
    } else {
      for (int i = 0; i < N; ++i) {
        if (Field::GetPoint(ship.GetBegin().GetAbscissa(), ship.GetBegin().GetOrdinate() + i) == 1) {
          return false;
        }
      }
      if (ship.GetBegin().GetAbscissa() > 0) {
        for (int i = 0; i < N; ++i) {
          if (Field::GetPoint(ship.GetBegin().GetAbscissa() - 1, ship.GetBegin().GetOrdinate() + i) == 1) {
            return false;
          }
        }
      }
      if (ship.GetBegin().GetAbscissa() < 9) {
        for (int i = 0; i < N; ++i) {
          if (Field::GetPoint(ship.GetBegin().GetAbscissa() + 1, ship.GetBegin().GetOrdinate() + i) == 1) {
            return false;
          }
        }
      }
      if (ship.GetBegin().GetOrdinate() > 0 && ship.GetEnd().GetOrdinate() > 0) {
        if (Field::GetPoint(ship.GetBegin().GetAbscissa(), ship.GetBegin().GetOrdinate() - 1) == 1) {
          return false;
        }
      }
      if (ship.GetBegin().GetOrdinate() < 9 && ship.GetEnd().GetOrdinate() < 9) {
        if (Field::GetPoint(ship.GetEnd().GetAbscissa(), ship.GetEnd().GetOrdinate() + 1) == 1) {
          return false;
        }
      }
      for (int i = 0; i < N; ++i) {
        Field::SetPoint(ship.GetBegin().GetAbscissa(), ship.GetBegin().GetOrdinate() + i, 1);
      }
    }
    return true;
  }
  ~ProtectionField() = default;
};
#endif