#define CATCH_CONFIG_RUNNER
#include <catch.hpp>

#include <vector>
#include "vec2.hpp"
#include "circle.hpp"
#include "color.hpp"
#include <string>
#include <iostream>
#include <algorithm>

/*
CMakeFiles/aufgabe_6.dir/aufgabe_6.cpp.o: in function `____C_A_T_C_H____T_E_S_T____13()':
aufgabe_6.cpp:(.text+0x73f3): undefined reference to `Circle::Circle(Vec2 const&, float, Color const&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&)'
collect2: error: ld returned 1 exit status
*/

// TESTFAELLE FÜR AUFGABE 6 SIND IM ./test !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!, weil hier war es nicht ausfuehrbar ?!?!


int main(int argc, char* argv[])
{
     return Catch::Session().run(argc, argv);
}
