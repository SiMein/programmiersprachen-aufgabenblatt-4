#include "circle.hpp"
#include <cmath>
#include <iostream>

Circle::Circle():
                             //name_  {"Circle_default_constructed"},
  center_{0.0f, 0.0f},
  radius_{1.0f},
  color_{0.5f, 0.5f, 0.5f} {}  // Wozu weitere geschweifte KLammer hier ???
                              // Kammatrennung immer hier ?

Circle::Circle(Vec2 const& ctr, float r, Color const& rgb) :  
  center_{ctr},
  radius_{r},
  color_{rgb} {}

Circle::Circle(Vec2 const& ctr, float r, Color const& rgb,float thickness) :  
  center_{ctr},
  radius_{r},
  color_{rgb} {}
  // thickness_{thickness} 


float Circle::circumference() const{
    float u = 2*M_PI * radius_;
    return u;
}
void Circle::draw(Window const& w) const{

    Vec2 sp{center_.x, center_.y - radius_};  //startpoint 
    for(int i = 0; i < 100; ++i){
        float rot = ((2 * M_PI)/100);                //rotation-Var.
        Mat2 rm = make_rotation_mat2(rot);           //Rotation
        Vec2 np = center_ + (rm * (sp - center_));   //neuer punkt
        w.draw_line(sp.x, sp.y, np.x, np.y, color_.r,color_.g,color_.b);
        sp = np;  // Übergabe nächster Startpoint 
    }
}
void Circle::draw(Window const& w, float thickness) const{
  
   Vec2 sp{center_.x, center_.y - radius_};  //startpoint 
    for(int i = 0; i < 100; ++i){
        float rot = ((2 * M_PI)/100);                //rotation-Var.
        Mat2 rm = make_rotation_mat2(rot);           //Rotation
        Vec2 np = center_ + (rm * (sp - center_));   //neuer punkt
        w.draw_line(sp.x, sp.y, np.x, np.y, color_.r,color_.g,color_.b);
        sp = np;  // Übergabe nächster Startpoint 
    }
}

bool Circle::is_inside(Vec2 const& p) const{
    Vec2 rv = p - center_;
    float distance_to_center = sqrt(pow(rv.x,2) + pow(rv.y,2));
    if(distance_to_center > radius_){
        //std::cout << "Point is in Object..\n";
        return false;
    }
    else{
        //std::cout << "Point is in Object.\n";
        return true;
    }
}