#include "vec2.hpp"            
#include "mat2.hpp"
#include "rectangle.hpp"
#include <iostream>


#include <string>

 Rectangle::Rectangle():  //default -Init der privat Attrib. ??
      min_{0.0f,0.0f},
      max_{5.0f,5.0f},
      color_{0.5f, 0.5f, 0.5f} {} 

Rectangle::Rectangle(Vec2 const& mi, Vec2 const& ma, Color const& rgb):  // Custum-Init 
      min_{mi},
      max_{ma},
      color_{rgb} {} 

float Rectangle::circumference() const{
    float edge1 = max_.x - min_.x;
    float edge2 = max_.y - min_.y;
    float u = edge1+edge2+edge1+edge2;
    return u;
}    
/*
Circle::Circle():
                             //name_  {"Circle_default_constructed"},
  center_{0.0f, 0.0f},
  radius_{1.0f},
  color_ {0.5f, 0.5f, 0.5f} {}  // Wozu weitere geschweifte KLammer hier ???
                                // Warum hier Kommata statt Semikolon ?

Circle::Circle(Vec2 const& ctr, float r, Color const& rgb) :  // check übergabearten !!
  center_{ctr},
  radius_{r},
  color_ {rgb} {}     */