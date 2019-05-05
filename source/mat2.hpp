#ifndef MAT2_HPP
#define MAT2_HPP
#include "vec2.hpp"            
#include "mat2.hpp"
//# include <array >

struct Mat2 {

// matrix layout :
// e_00 e_10
// e_01 e_11

float e_00 = 1.0f;     // Memberattrib.
float e_10 = 0.0f;
float e_01 = 0.0f;
float e_11 = 1.0f;

float det () const ;
Mat2& operator*=( Mat2 const& m);    //Memberfunktion (im .hpp ohne Konstr.)

};


// hier FREIE FUNKTION ((im .hpp ohne Konstr.) für Vektoren , da NICHT in den geschweiften Klammern oben
Mat2 operator*( Mat2 const& m1 , Mat2 const& m2 );

Vec2 operator*( Mat2 const& m, Vec2 const& v);
Vec2 operator*( Vec2 const& v, Mat2 const& m);

Mat2 inverse ( Mat2 const& m);
Mat2 transpose ( Mat2 const& m);
Mat2 make_rotation_mat2 ( float phi );

#endif // MAT2_HPP