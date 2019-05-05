#include "circle.hpp"
#include <cmath>
#include <iostream>

Circle::Circle():
                             //name_  {"Circle_default_constructed"},
  center_{0.0f, 0.0f},
  radius_{1.0f},
  color_{0.5f, 0.5f, 0.5f} {}  // Wozu weitere geschweifte KLammer hier ???
                                // Warum hier Kommata statt Semikolon ?

Circle::Circle(Vec2 const& ctr, float r, Color const& rgb) :  // check übergabearten !!  Gleiche Signatur in hpp !!
  center_{ctr},
  radius_{r},
  color_{rgb} {}

float Circle::circumference() const{
    float u = 2*M_PI * radius_;
    return u;
}
void Circle::draw(Window const& w) const{

}


/*

void Circle::draw() const {
  std::cout << "draw() -> name: "   << name_
  << "  center: {" << center_.x << ", " << center_.y << "}"
  << "  radius: "  << radius_
  << "  color: {"  << color_.r  << ", " << color_.g  << ", " << color_.b << "}"
  << std::endl;
}

// free function comparing two circles based on their area
bool smaller  (Circle const& lhs_c, Circle const& rhs_c) {
  return lhs_c.area() < rhs_c.area();
}

bool operator<(Circle const& lhs_c, Circle const& rhs_c) {
  return lhs_c.area() < rhs_c.area();
}
*/