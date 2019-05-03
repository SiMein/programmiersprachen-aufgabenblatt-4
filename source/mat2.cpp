#include "mat2.hpp"
// TODO (in mat2 .cpp ) Definition v. operator *=

Mat2& Mat2::operator *=( Mat2 const& m){   // Memberfunktion (in .cpp mit Konstr)!!
    e_00 = e_00*m.e_00 + e_01*m.e_10;       // Frage -warum hier vorm Operator nochmal Mat2:: und in hpp nicht ??
    e_01 = e_00*m.e_01 + e_01*m.e_11;       // Weil Objekt sich so selberaufruft für die Operation ???
    e_10 = e_10*m.e_00 + e_11*m.e_10;
    e_11 = e_10*m.e_01 + e_11*m.e_11; 
    return *this;  
};


// TODO (in mat2 .cpp ) Definition v. operator *
Mat2 operator *( Mat2 const& m1 , Mat2 const& m2 ){ // Freie Funktion (in .cpp mit Konstr)!!
    return Mat2{m1}*=m2;
};


