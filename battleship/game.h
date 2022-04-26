#ifndef BATTLESHIP__GAME_H_
#define BATTLESHIP__GAME_H_
#include <iostream>
#include "player.h"
#include <sstream>

template<size_t len>
void Position(Point &begin, Point &end, ProtectionField &field) {
  bool id = false;
  while (!id) {
    if (&begin == &end) {
      std::cin >> begin;
    } else {
      std::cin >> begin;
      std::cin >> end;
    }
    if ((begin.GetAbscissa() < 10 && begin.GetAbscissa() > -1 &&
        begin.GetOrdinate() < 10 && begin.GetOrdinate() > -1) &&
        (end.GetAbscissa() < 10 && end.GetAbscissa() > -1 &&
            end.GetOrdinate() < 10 && end.GetOrdinate() > -1)) {
      if ((begin.GetAbscissa() == end.GetAbscissa() && std::abs(begin.GetOrdinate() - end.GetOrdinate()) == (len - 1))
          || std::abs((begin.GetAbscissa() - end.GetAbscissa())) == (len - 1) && begin.GetOrdinate() == end.GetOrdinate()) {
        Ship<len> A(begin, end);
        id = field.AddShip(A);
      }
    }
    if (!id) {
      std::cout << "you cannot choose this position for your ship!" << '\n';
    }
  }
}

void Game() {
  std::cout << "3 <=> misshot" << '\n' << "7 <=> enemy's ship was shot" << '\n' << "0 <=> free part of field" << '\n'
            << "1 <=> your ship" << '\n' << "2 <=> part of the ship was shot" << '\n';

  std::cout << "PLAYER_1 add four one-deck ships" << '\n';
  Point OO, OS, OT, OF, DO_B, DO_E, DS_B, DS_E, DT_B, DT_E, TO_B, TO_E, TS_B, TS_E, FO_B, FO_E;
  ProtectionField field;
  std::cout << field;
  Position<1>(OO, OO, field);
  std::cout << field;
  Position<1>(OS, OS, field);
  std::cout << field;
  Position<1>(OT, OT, field);
  std::cout << field;
  Position<1>(OF, OF, field);
  std::cout << field;
  std::cout << "PLAYER_1 add three double-deck ships" << '\n';
  Position<2>(DO_B, DO_E, field);
  std::cout << field;
  Position<2>(DS_B, DS_E, field);
  std::cout << field;
  Position<2>(DT_B, DT_E, field);
  std::cout << field;
  std::cout << "PLAYER_1 add two three-deck ships" << '\n';
  Position<3>(TO_B, TO_E, field);
  std::cout << field;
  Position<3>(TS_B, TS_E, field);
  std::cout << field;
  std::cout << "PLAYER_1 add four-deck ship" << '\n';
  Position<4>(FO_B, FO_E, field);
  std::cout << field;
  Player player_1(OO, OS, OT, OF, DO_B, DO_E, DS_B, DS_E, DT_B, DT_E, TO_B, TO_E, TS_B, TS_E, FO_B, FO_E);
  system("clear");
  std::cout << "PLAYER_2 add four one-deck ships" << '\n';
  Point OO_, OS_, OT_, OF_, DO_B_, DO_E_, DS_B_, DS_E_, DT_B_, DT_E_, TO_B_, TO_E_, TS_B_, TS_E_, FO_B_, FO_E_;
  ProtectionField field_;
  std::cout << field_;
  Position<1>(OO_, OO_, field_);
  std::cout << field_;
  Position<1>(OS_, OS_, field_);
  std::cout << field_;
  Position<1>(OT_, OT_, field_);
  std::cout << field_;
  Position<1>(OF_, OF_, field_);
  std::cout << field_;
  std::cout << "PLAYER_2 add three double-deck ships" << '\n';
  Position<2>(DO_B_, DO_E_, field_);
  std::cout << field_;
  Position<2>(DS_B_, DS_E_, field_);
  std::cout << field_;
  Position<2>(DT_B_, DT_E_, field_);
  std::cout << field_;
  std::cout << "PLAYER_2" << "\n" << "add two three-deck ships" << '\n';
  Position<3>(TO_B_, TO_E_, field);
  std::cout << field_;
  Position<3>(TS_B_, TS_E_, field_);
  std::cout << field_;
  std::cout << "PLAYER_2" << "\n" << "add four-deck ship" << '\n';
  Position<4>(FO_B_, FO_E_, field_);
  std::cout << field_;
  Player
      player_2(OO_, OS_, OT_, OF_, DO_B_, DO_E_, DS_B_, DS_E_, DT_B_, DT_E_, TO_B_, TO_E_, TS_B_, TS_E_, FO_B_, FO_E_);
  std::cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n';
  bool ID = true;
  while (player_1.life && player_2.life) {
    std::cout << '\n' << '\n' << '\n' << '\n' << '\n';
    if (ID) {
      std::cout << "PLAYER_1 attack" << '\n';
      Point point;
      std::cout << player_1.attack_;
      std::cout << player_1.protection_;
      std::cin >> point;
      ID = player_1.Attack(player_2, point);
      std::cout << player_1.attack_;
    } else {
      std::cout << "PLAYER_2 attack" << '\n';
      Point point;
      std::cout << player_2.attack_;
      std::cout << player_2.protection_;
      std::cin >> point;
      ID = not(player_2.Attack(player_1, point));
      std::cout << player_2.attack_;
    }
    system("clear");
  }
}

#endif
