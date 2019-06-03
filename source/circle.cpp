#include "circle.hpp"
#include <cmath>
#include <iostream>
                        //Klassenbeschreibung bzw. Art ein Objekt zu init. immer mit Signatur "Circle::Circle():"
Circle::Circle():
                             //name_  {"Circle_default_constructed"},
  center_{0.0f, 0.0f},
  radius_{1.0f},
  color_{0.5f, 0.5f, 0.5f},   // Wozu weitere geschweifte KLammer hier ???
  name_{"default-name"} {}    // Kammatrennung immer hier ?

Circle::Circle(Vec2 const& ctr, float r, Color const& rgb) :  
  center_{ctr},
  radius_{r},
  color_{rgb} {}

Circle::Circle(Vec2 const& ctr, float r, Color const& rgb, std::string const& na_) :  
  center_{ctr},
  radius_{r},
  color_{rgb},
  name_{na_} {}

Circle::Circle(Vec2 const& ctr, float r, Color const& rgb,float thickness) :  
  center_{ctr},
  radius_{r},
  color_{rgb} {}
  // thickness_{thickness} 
                //  Memberfkt. immer mit Typ vorne :: Name d memberfkt hinten
float Circle::circumference() const{
    float u = 2*M_PI * radius_;
    return u;
}

/*
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
*/
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

std::ostream& Circle::print(std::ostream& o) const
{
    o << "\nCirclename: " << name_ << ",\n Radius: " << radius_ << ",\n Mittelpunkt: x: " << center_.x << ", y: " << center_.y <<
    ",\n Farbe: r: " << color_.r << ", g: " << color_.g << ", b: " << color_.b;
    return o;
            // Konkatenation von Circleeigenschaften auf das ostream-Objekt mittels <<
}


std::ostream& operator<<(std::ostream& o, Circle const& c) {  //  Freie Funktion -wie auf Folie OOP-04 S.11 
    c.print(o);
    return o;

}

bool operator <( Circle const& a,Circle const& b){
    if(a.radius_ < b.radius_){
        return true;
    } else {
        return false;
    }

}
bool operator >( Circle const& a,Circle const& b){
    if(a.radius_ > b.radius_){
        return true;
    } else {
        return false;
    }
} 
bool operator ==( Circle const& a,Circle const& b){
    if(a.radius_ == b.radius_){
        return true;
    } else {
        return false;
    }
}