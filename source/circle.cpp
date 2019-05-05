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
  color_ {rgb} {}

float Circle::circumference() const{
    float u = 2*M_PI * radius_;
    return u;
}


/*
Circle::Circle(Circle const& c) :
  name_  {"copy_of_" + c.name_},
  center_{c.center_},
  radius_{c.radius_},
  color_ {c.color_} {}

Circle::Circle(std::string const& name, Point2D const& ctr, float r, ColorRGB const& rgb) :
  name_  {name},
  center_{ctr},
  radius_{r},
  color_ {rgb} {}

Circle::~Circle() {
  std::cout << "destructor() -> name: " << name_
  << " destroyed" << std::endl;
}
Circle& Circle::operator=(Circle const& c) {
  name_   = name_ + "_assigned_from_" + c.name_;
  center_ = c.center_;
  radius_ = c.radius_;
  color_  = c.color_;
  return *this;
}

float Circle::area() const {
  return M_PI * radius_ * radius_;
}

float Circle::diameter() const {
  return 2 * radius_;
}


BBox Circle::bounding_box() const {
  return {{center_.x - radius_, center_.y - radius_}, {center_.x + radius_, center_.y + radius_}};
}


void Circle::color(ColorRGB const& clr) {
  color_ = clr;
}


ColorRGB Circle::color() const {
  return color_;
}


void Circle::center(Point2D const& ctr) {
  center_ = ctr;
}


Point2D Circle::center() const {
  return center_;
}


float Circle::radius() const {
  return radius_;
}


void Circle::radius(float r) {
  radius_ = r;
}


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