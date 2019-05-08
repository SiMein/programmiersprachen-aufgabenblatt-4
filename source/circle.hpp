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
    Circle(Vec2 const& ctr, float r, Color const& rgb,float thickness );
    float circumference() const; 
    void draw(Window const& w)const; 
    void draw(Window const& win, float thickness) const;
    bool is_inside(Vec2 const& p) const;


/*
    Circle(Circle const& c);
    Circle(Point2D const& ctr, float r, ColorRGB const& rgb);
    Circle(std::string const& name, Point2D const& ctr, float r, ColorRGB const& rgb);
    ~Circle();

    Circle&       operator=(Circle const& c);

    float          area() const;
    float          diameter() const;
    BBox           bounding_box() const;
    void           color(ColorRGB const& clr);
    ColorRGB       color() const;
    void           center(Point2D const& ctr);
    Point2D        center() const;
    void           radius(float r);
    float          radius() const;
    void           draw() const;
*/
private:
    Vec2  center_;
    float radius_;
    Color color_;
};

/* both fucntions return true, if the left-hand-side (lhs) circle 
   has a smaller area than the right-hand-side (rhs) one */
//bool smaller  (Circle const& lhs_c, Circle const& rhs_c);
//bool operator<(Circle const& lhs_c, Circle const& rhs_c);

#endif