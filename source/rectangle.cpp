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

Rectangle::Rectangle(Vec2 const& mi, Vec2 const& ma, Color const& rgb, float thickness):  // Custum-Init 
      min_{mi},
      max_{ma},
      color_{rgb} {}
      // thickness_{thickness} {} 

float Rectangle::circumference() const{
    float edge1 = max_.x - min_.x;
    float edge2 = max_.y - min_.y;
    float u = edge1+edge2+edge1+edge2;
    return u;
} 

void Rectangle::draw(Window const& w)const{
    w.draw_line(min_.x, min_.y, max_.x, min_.y, color_.r, color_.g, color_.b);
    w.draw_line(min_.x, max_.y, max_.x, max_.y, color_.r, color_.g, color_.b);
    w.draw_line(min_.x, min_.y, min_.x, max_.y, color_.r, color_.g, color_.b);
    w.draw_line(max_.x, min_.y, max_.x, max_.y, color_.r, color_.g, color_.b);      
} 

void Rectangle::draw(Window const& w, float thickness)const{
    if (thickness > 0){
     w.draw_line(min_.x, min_.y, max_.x, min_.y, color_.r, color_.g, color_.b, thickness);
        w.draw_line(min_.x, max_.y, max_.x, max_.y, color_.r, color_.g, color_.b, thickness);
        w.draw_line(min_.x, min_.y, min_.x, max_.y, color_.r, color_.g, color_.b, thickness);
        w.draw_line(max_.x, min_.y, max_.x, max_.y, color_.r, color_.g, color_.b, thickness);   
    }
} 
bool Rectangle::is_inside(Vec2 const& p) const{
    if(p.x < max_.x && p.y < max_.y && p.x > min_.x && p.y > min_.y){
        //std::cout << "Point is in Object.\n";
        return true;
    }
    else{
        //std::cout << "Point outside from object.\n";
        return false;
    }
}