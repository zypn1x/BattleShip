#ifndef BATTLESHIP__PLAYER_H_
#define BATTLESHIP__PLAYER_H_
#include "attack_field.h"
#include "protection_field.h"
#include "ship.h"
#include <array>

class Player {
 private:
  Ship<1> *one_deck;
  Ship<2> *two_deck;
  Ship<3> *three_deck;
  Ship<4> *four_deck;
 public:
  AttackField attack_;
  ProtectionField protection_;

  bool life = true;
  Player(Point OO, Point OS, Point OT, Point OF,
         Point DO_B, Point DO_E, Point DS_B, Point DS_E, Point DT_B,Point DT_E,
         Point TO_B, Point TO_E, Point TS_B, Point TS_E,
         Point FO_B, Point FO_E)
      : one_deck(new Ship<1>[4]()), two_deck(new Ship<2>[3]), three_deck(new Ship<3>[2]), four_deck(new Ship<4>[1]),
        attack_(), protection_() {
    one_deck[0].SetBegin(OO); one_deck[0].SetEnd(OO);
    one_deck[1].SetBegin(OS); one_deck[1].SetEnd(OS);
    one_deck[2].SetBegin(OT); one_deck[2].SetEnd(OT);
    one_deck[3].SetBegin(OF); one_deck[3].SetEnd(OF);
    two_deck[0].SetBegin(DO_B); two_deck[0].SetEnd(DO_E);
    two_deck[1].SetBegin(DS_B); two_deck[1].SetEnd(DS_E);
    two_deck[2].SetBegin(DT_B); two_deck[2].SetEnd(DT_E);
    three_deck[0].SetBegin(TO_B); three_deck[0].SetEnd(TO_E);
    three_deck[1].SetBegin(TS_B); three_deck[1].SetEnd(TS_E);
    four_deck[0].SetBegin(FO_B); four_deck[0].SetEnd(FO_E);
    for (int i = 0; i < 4; ++i) {
      protection_.AddShip(one_deck[i]);
    }
    for (int i = 0; i < 3; ++i ) {
      protection_.AddShip(two_deck[i]);
    }
    for (int i = 0; i < 2; ++i) {
      protection_.AddShip(three_deck[i]);
    }
    protection_.AddShip(four_deck[0]);
  }
  bool Def (Point &pnt) {
    if (protection_.GetPoint(pnt) == 1) {
      protection_.SetPoint(pnt, 2);
      std::cout << "good shot" << '\n';
      for (int i = 0; i < 4; ++i) {
        one_deck[i].Wound(pnt);
      }
      for (int i = 0; i < 3; ++i ) {
        two_deck[i].Wound(pnt);
      }
      for (int i = 0; i < 2; ++i) {
        three_deck[i].Wound(pnt);
      }
      four_deck[0].Wound(pnt);
      bool ID = true;
      for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
          if (protection_.GetPoint(i, j) == 1) {
            ID = false;
            break;
          }
        }
      }
      if (ID) {
        std::cout << "It was last shot. Player lost the Game" << '\n';
        life = false;
      }
      return true;
    } else if(protection_.GetPoint(pnt) == 2) {
      std::cout << "You shot this point before" <<'\n';
      return true;
    }
    std::cout << "nice try, dude" << '\n';
    return false;
  }
  bool Attack(Player &other, Point pnt) {
    bool ID = other.Def(pnt);
    if (ID) {
      attack_.SetPoint(pnt, 7);
    } else {
      attack_.SetPoint(pnt, 3);
    }
    return ID;
  }
  ~Player() {
    delete[] one_deck;
    delete[] two_deck;
    delete[] three_deck;
    delete[] four_deck;
  }
};
#endif
