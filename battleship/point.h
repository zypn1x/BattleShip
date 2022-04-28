#ifndef BATTLESHIP__POINT_H_
#define BATTLESHIP__POINT_H_
#include <iostream>
class Point {
 private:
  int abscissa_;
  int ordinate_;
 public:
  explicit Point(int a = 0, int o= 0): abscissa_(a), ordinate_(o) {}
  int GetAbscissa() const {
    return abscissa_;
  }
  int GetOrdinate() const {
    return ordinate_;
  }
  Point (const Point &other): abscissa_(other.GetAbscissa()), ordinate_(other.GetOrdinate()) {}

  Point& operator=(const Point &other) {
    if (abscissa_ == other.GetAbscissa() && ordinate_ == other.GetOrdinate()) {
      return *this;
    }
    abscissa_ = other.GetAbscissa();
    ordinate_ = other.GetOrdinate();
    return *this;
  }
  void SetAbscissa(size_t a) {
    abscissa_ = a;
  }
  void SetOrdinate(size_t o) {
    ordinate_ = o;
  }
  bool operator==(Point &other) const{
    return (other.ordinate_ == ordinate_ && other.abscissa_ == abscissa_);
  }
};

#endif