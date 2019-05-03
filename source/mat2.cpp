#include "mat2.hpp"
// TODO (in mat2 .cpp ) Definition v. operator *=

Mat2& Mat2::operator *=( Mat2 const& m){   // Memberfunktion (in .cpp mit Konstr)!!

    float lo = e_00;               // Hilfsvariablen für Zwischenrechnung
    float ro = e_01;
    float lu = e_10;
    float ru = e_11;

    e_00 = lo*m.e_00 + ro*m.e_10;       // Frage -warum hier vorm Operator nochmal Mat2:: und in hpp nicht ??
    e_01 = lo*m.e_01 + ro*m.e_11;       // Weil Objekt sich so selberaufruft für die Operation ???
    e_10 = lu*m.e_00 + ru*m.e_10;
    e_11 = lu*m.e_01 + ru*m.e_11; 
    return *this;  
};


// TODO (in mat2 .cpp ) Definition v. operator *
Mat2 operator *( Mat2 const& m1 , Mat2 const& m2 ){ // Freie Funktion (in .cpp mit Konstr)!!
    return Mat2{m1}*=m2;
};


