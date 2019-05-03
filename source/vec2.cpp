#include "vec2.hpp"
#include <iostream>

Vec2& Vec2::operator +=( Vec2 const & v){   //Memberfunktion (in .cpp mit Konstr) !!
    x = x+v.x;
    y = y+v.y;
    return *this;
}
Vec2& Vec2::operator -=( Vec2 const & v){
    x = x-v.x;
    y = y-v.y;
    return *this;
}
Vec2& Vec2::operator *=( float s){
    x = x*s;
    y = y*s;
    return *this;
}
Vec2& Vec2::operator /=( float s){
    if (s == 0){
        std::cout << "Div with 0 impossible \n";
        //  Vec2 nullvec {0,0};
        return *this;
    }
    x = x/s;
    y = y/s;
    return *this;
}

Vec2 operator +( Vec2 const& u, Vec2 const& v){   //  Freie Funktion (in .cpp mit Konstr)
    return Vec2{u}+=v;
}

Vec2 operator -( Vec2 const& u, Vec2 const& v){
    return Vec2{u}-=v;
}
Vec2 operator *( Vec2 const& v, float s){
    return Vec2{v}*=s;
}
Vec2 operator /( Vec2 const& v, float s){
    return Vec2{v}/=s;
}
Vec2 operator *( float s, Vec2 const& v){
    return Vec2{v}*=s;
}; 