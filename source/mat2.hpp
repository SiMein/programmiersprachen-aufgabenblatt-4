#ifndef MAT2_HPP
#define MAT2_HPP
//# include <array >

struct Mat2 {

// matrix layout :
// e_00 e_10
// e_01 e_11

float e_00 = 1.0f;     // Memberattrib.
float e_10 = 0.0f;
float e_01 = 0.0f;
float e_11 = 1.0f;

Mat2& operator*=( Mat2 const& m);    //Memberfunktion (im .hpp ohne Konstr.)

};


// hier FREIE FUNKTION ((im .hpp ohne Konstr.) für Vektoren , da NICHT in den geschweiften Klammern oben
Mat2 operator *( Mat2 const& m1 , Mat2 const& m2 );

#endif // MAT2_HPP