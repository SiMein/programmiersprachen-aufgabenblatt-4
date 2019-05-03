#ifndef VEC2_HPP
#define VEC2_HPP

// Vec2 data type definition
struct Vec2
{
    float x = 0.0f;       //Memberattribute 
    float y = 0.0f;

    Vec2 & operator +=( Vec2 const & v);    //Memberfunktion (im .hpp ohne Konstr.)
    Vec2 & operator -=( Vec2 const & v);
    Vec2 & operator *=( float s);
    Vec2 & operator /=( float s);

/* TODO add member variables with
default member initialisation */
};


// hier FREIE FUNKTION ((im .hpp ohne Konstr.) für Vektoren , da NICHT in den geschweiften Klammern oben
Vec2 operator +( Vec2 const& u, Vec2 const& v);
Vec2 operator -( Vec2 const& u, Vec2 const& v);
Vec2 operator *( Vec2 const& v, float s);
Vec2 operator /( Vec2 const& v, float s);
Vec2 operator *( float s, Vec2 const& v);  //Multipl 2fach angeben wegen der richtung



# endif // VEC2_HPP

