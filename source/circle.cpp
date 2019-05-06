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

    Vec2 sp{center_.x, center_.y - radius_};  //startpoint 
    for(int i = 0; i < 100; ++i){
        float rot = ((2 * M_PI)/100);                //rotation-Var.
        Mat2 rm = make_rotation_mat2(rot);           //Rotation
        Vec2 np = center_ + (rm * (sp - center_));   //neuer punkt
        w.draw_line(sp.x, sp.y, np.x, np.y, color_.r,color_.g,color_.b);
        sp = np;  // Übergabe nächster Startpoint 
    }
}

//void draw(Window const& win, float thickness) const{
 // }
/*
   Vec2 sp{center_.x, center_.y - radius_};  //startpoint 
    for(int i = 0; i < 100; ++i){
        float rot = ((2 * M_PI)/100);                //rotation-Var.
        Mat2 rm = make_rotation_mat2(rot);           //Rotation
        Vec2 np = center_ + (rm * (sp - center_));   //neuer punkt
        w.draw_line(sp.x, sp.y, np.x, np.y, color_.r,color_.g,color_.b);
        sp = np;  // Übergabe nächster Startpoint 
    }
}
*/
