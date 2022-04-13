#include <iostream>
#include "player.h"
#include <sstream>

int main() {
  std::cout << "3 <=> misshot" << '\n' << "7 <=> enemy's ship was shot" << '\n' << "0 <=> free part of field" << '\n'
            << "1 <=> your ship" << '\n' << "2 <=> part of the ship was shot" << '\n';

  std::cout << "PLAYER_1 add four one-deck ships" << '\n';
  Point OO, OS, OT, OF, DO_B, DO_E, DS_B, DS_E, DT_B, DT_E, TO_B, TO_E, TS_B, TS_E, FO_B, FO_E;
  ProtectionField field;
  std::cout << field;
  std::cin >> OO; Ship<1> A(OO, OO); field.AddShip(A);
  std::cin >> OS; Ship<1> B(OS, OS); field.AddShip(B);
  std::cin >> OT; Ship<1> C(OT, OT); field.AddShip(C);
  std::cin >> OF; Ship<1> D(OF, OF); field.AddShip(D);
  std::cout << field;
  std::cout << "PLAYER_1 add three double-deck ships" << '\n';
  std::cin >> DO_B;
  std::cin >> DO_E; Ship<2> E(DO_B, DO_E); field.AddShip(E);
  std::cin >> DS_B;
  std::cin >> DS_E; Ship<2> F(DS_B, DS_E); field.AddShip(F);
  std::cin >> DT_B;
  std::cin >> DT_E; Ship<2> G(DT_B, DT_E); field.AddShip(G);
  std::cout << field;
  std::cout << "PLAYER_1 add two three-deck ships" << '\n';
  std::cin >> TO_B;
  std::cin >> TO_E; Ship<3> H(TO_B, TO_E); field.AddShip(H);
  std::cin >> TS_B;
  std::cin >> TS_E; Ship<3> I(TS_B, TS_E); field.AddShip(I);
  std::cout << field;
  std::cout << "PLAYER_1 add four-deck ship" << '\n';
  std::cin >> FO_B;
  std::cin >> FO_E; Ship<4> J(FO_B, FO_E); field.AddShip(J);
  Player player_1(OO, OS, OT, OF, DO_B, DO_E, DS_B, DS_E, DT_B, DT_E, TO_B, TO_E, TS_B, TS_E, FO_B, FO_E);

  std::cout << "PLAYER_2 add four one-deck ships" << '\n';
  Point OO_, OS_, OT_, OF_, DO_B_, DO_E_, DS_B_, DS_E_, DT_B_, DT_E_, TO_B_, TO_E_, TS_B_, TS_E_, FO_B_, FO_E_;
  ProtectionField field_;
  std::cout << field_;
  std::cin >> OO_; Ship<1> A_(OO_, OO_); field_.AddShip(A_);
  std::cin >> OS_; Ship<1> B_(OS_, OS_); field_.AddShip(B_);
  std::cin >> OT_; Ship<1> C_(OT_, OT_); field_.AddShip(C_);
  std::cin >> OF_; Ship<1> D_(OF_, OF_); field_.AddShip(D_);
  std::cout << field_;
  std::cout << "PLAYER_2" << "\n" << "add three double-deck ships" << '\n';
  std::cin >> DO_B_;
  std::cin >> DO_E_; Ship<2> E_(DO_B_, DO_E_); field_.AddShip(E_);
  std::cin >> DS_B_;
  std::cin >> DS_E_; Ship<2> F_(DS_B_, DS_E_); field_.AddShip(F_);
  std::cin >> DT_B_;
  std::cin >> DT_E_; Ship<2> G_(DT_B_, DT_E_); field_.AddShip(G_);
  std::cout << field_;
  std::cout << "PLAYER_2" << "\n" << "add two three-deck ships" << '\n';
  std::cin >> TO_B_;
  std::cin >> TO_E_; Ship<3> H_(TO_B_, TO_E_); field_.AddShip(H_);
  std::cin >> TS_B_;
  std::cin >> TS_E_; Ship<3> I_(TS_B_, TS_E_); field_.AddShip(I_);
  std::cout << field_;
  std::cout << "PLAYER_2" << "\n" << "add four-deck ship" << '\n';
  std::cin >> FO_B_;
  std::cin >> FO_E_; Ship<4> J_(FO_B_, FO_E_); field_.AddShip(J_);
  Player player_2 (OO_, OS_, OT_, OF_, DO_B_, DO_E_, DS_B_, DS_E_, DT_B_, DT_E_, TO_B_, TO_E_, TS_B_, TS_E_, FO_B_, FO_E_);
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
