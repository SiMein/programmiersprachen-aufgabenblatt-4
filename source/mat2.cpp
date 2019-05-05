#include "mat2.hpp"
#include "vec2.hpp"
#include <iostream>
#include <cmath>

// TODO (in mat2 .cpp ) Definition v. operator *=

Mat2& Mat2::operator *=( Mat2 const& m){   // Memberfunktion (in .cpp mit Konstr)!!
                                  // Frage -warum hier vorm Operator nochmal Mat2:: und in hpp nicht ??
                                  // Weil Objekt sich so selberaufruft für die Operation ???
    float lo = e_00;          // Hilfsvariablen für Zwischenrechnung
    float ro = e_01;
    float lu = e_10;
    float ru = e_11;

    e_00 = lo*m.e_00 + ro*m.e_10;       
    e_01 = lo*m.e_01 + ro*m.e_11;       
    e_10 = lu*m.e_00 + ru*m.e_10;
    e_11 = lu*m.e_01 + ru*m.e_11; 
    return *this;  
};


float Mat2::det () const{
    float determin = e_00*e_11 - e_10*e_01;
    return determin;
};

Vec2 operator *( Mat2 const & m, Vec2 const & v){
    float x = m.e_00*v.x + m.e_10*v.y;
    float y = m.e_01*v.x + m.e_11*v.y;
    Vec2 result{x,y};
    return result;
};

Vec2 operator *( Vec2 const & v, Mat2 const & m){
    float x = m.e_00*v.x + m.e_10*v.y;
    float y = m.e_01*v.x + m.e_11*v.y;
    Vec2 result{x,y};
    return result;
};

Mat2 inverse ( Mat2 const & m){
    if (m.det() != 0) {
      Mat2 help;
      float d = 1/m.det();
      help.e_00 = d* m.e_11;
      help.e_01 = d* -1*(m.e_10);
      help.e_10 = d* -1*(m.e_01);
      help.e_11 = d* m.e_00;
    return help;
    
    } else {
        std::cout << "Invertierung nicht mgl. Det. = 0 \n";
        return m;
    }
};
Mat2 transpose ( Mat2 const & m){
    Mat2 temp{m};
    temp.e_01 = m.e_10;
    temp.e_10 = m.e_01;
    return temp;

};
Mat2 make_rotation_mat2 ( float phi ){
    Mat2 result {std::cos(phi), -std::sin(phi), std::sin(phi), std::cos(phi)};
    return result;
};

// TODO (in mat2 .cpp ) Definition v. operator *
Mat2 operator *( Mat2 const& m1 , Mat2 const& m2 ){ // Freie Funktion (in .cpp mit Konstr)!!
    return Mat2{m1}*=m2;
};


