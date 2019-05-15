#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "vec2.hpp"            
#include "mat2.hpp"
#include "color.hpp"
#include "window.hpp"
#include <iostream>


#include <string>

class Circle {
public:
    Circle();                                //default -Init der privat Attrib. ??
    Circle(Vec2 const& ctr, float r, Color const& rgb);  // Custum-Init  ACHTUNG - gleiche Signatur inkl const und & in cpp erstellen  
    Circle(Vec2 const& ctr, float r, Color const& rgb, std::string const& na_);
    Circle(Vec2 const& ctr, float r, Color const& rgb,float thickness );
    float circumference() const; 
    void draw(Window const& w)const; 
    void draw(Window const& win, float thickness) const;
    bool is_inside(Vec2 const& p) const;
    std::ostream& print(std::ostream& o) const;
    
    Vec2  center_;
    float radius_;
    Color color_;
    std::string name_;
};

std::ostream& operator<<(std::ostream& o, Circle const& c);
#endif