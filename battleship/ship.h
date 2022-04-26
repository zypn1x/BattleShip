#ifndef BATTLESHIP__SHIP_H_
#define BATTLESHIP__SHIP_H_
#include <array>
#include "point.h"
#include<iostream>

template<size_t N>
class Ship {
 private:
  Point begin_;
  Point end_;
  int* ship_ = new int[N];
 public:
  bool condition = true;
  explicit Ship(): begin_(0, 0), end_(0, 0 + N - 1) {
    for (int i = 0; i < N; ++i) {
      ship_[i] = 1;
    }
  }
  explicit Ship (Point &beg, Point &end ) : begin_(beg), end_(end) {
    if ((begin_.GetOrdinate() == end_.GetOrdinate() && begin_.GetAbscissa() > end_.GetAbscissa()) ||
        (begin_.GetOrdinate() > end_.GetOrdinate() && begin_.GetAbscissa() == end_.GetAbscissa()) ) {
      std::swap(begin_,end_);
    }
    for (int i = 0; i < N; ++i) {
      ship_[i] = 1;
    }
  }
  void Wound(Point &other) {
    if (begin_.GetAbscissa() == end_.GetAbscissa()) {
      if (begin_.GetAbscissa() != other.GetAbscissa()) {
        return;
      }
      if ((other.GetOrdinate() - begin_.GetOrdinate()) * (other.GetOrdinate() - end_.GetOrdinate()) > 0) {
        return;
      }
      size_t num = std::abs(other.GetOrdinate() - begin_.GetOrdinate());
      ship_[num] = -1;
    } else if (begin_.GetOrdinate() == end_.GetOrdinate()){
      if (begin_.GetOrdinate() != other.GetOrdinate()) {
        return;
      }
      if ((other.GetAbscissa() - begin_.GetAbscissa()) * (other.GetAbscissa() - end_.GetAbscissa()) > 0) {
        return;
      }
      size_t num = std::abs(other.GetAbscissa() - begin_.GetAbscissa());
      ship_[num] = -1;
    }
    bool alive = false;
    for (int i = 0; i < N; ++i) {
      if (ship_[i] > 0) {
        alive = true;
        break;
      }
    }
    condition = alive;
    CheckOut();
  }
  void CheckOut() {
    if (not condition) {
      std::cout << "ship len " << N << " was defeated" << '\n';
    }
  }
  void SetBegin (Point &pnt) {
    begin_ = pnt;
  }
  void SetEnd (Point &pnt) {
    end_ = pnt;
  }
  Point GetBegin() const {
    return begin_;
  };
  Point GetEnd() const {
    return end_;
  }
  ~Ship() {
    delete[] ship_;
  }
};

#endif
