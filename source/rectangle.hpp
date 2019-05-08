#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "vec2.hpp"            
#include "mat2.hpp"
#include "color.hpp"
#include "window.hpp"
#include <iostream>


#include <string>

class Rectangle {
public:
    Rectangle(); //default -Init der privat Attrib. ??
    Rectangle(Vec2 const& mi, Vec2 const& ma, Color const& rgb);       // Custum-Init
    Rectangle(Vec2 const& mi, Vec2 const& ma, Color const& rgb, float thickness);  // Custum-Init
    float circumference() const; 
    void draw(Window const& w)const;
    void draw(Window const& w, float thickness) const;
    bool is_inside(Vec2 const& p) const;

private:
    Vec2  min_;
    Vec2  max_;
    Color color_;
};

#endif