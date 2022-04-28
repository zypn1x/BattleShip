#ifndef BATTLESHIP__ATTACK_FIELD_H_
#define BATTLESHIP__ATTACK_FIELD_H_
#include "field.h"
#include <array>
#include "point.h"
class AttackField: public Field {
 public:
  explicit AttackField(std::array<std::array<int, 10>, 10> field) : Field(field) {}
  AttackField(): Field(std::array<std::array<int, 10>, 10>()) {
    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < 10; ++j) {
        SetPoint (i, j, 0);
      }
    }
  }
  ~AttackField() = default;
};
#endif
