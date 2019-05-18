#define CATCH_CONFIG_RUNNER
#include <catch.hpp>

#include <vector>
#include "vec2.hpp"
#include "circle.hpp"
#include "color.hpp"
#include <string>
#include <iostream>
#include <algorithm>


TEST_CASE("sort","[Circles]"){


    Vec2 vec_x10{};
    Color col_x10{};

    std::cout << "--------------------------------------------------------------------";

    //Circle cp_10;

   // std::vector<Circle> sorted_circles;
   // sorted_circles.push_back(cp_10);

 /*   Circle cp_x10(vec_x10, 50.0f, col_x10, "Circle_x10");
    Circle cp_x20(vec_x10, 66.0f, col_x10, "Circle_x20");
    Circle cp_x30(vec_x10, 97.0f, col_x10, "Circle_x30");
    Circle cp_x40(vec_x10, 18.0f, col_x10, "Circle_x40");
    Circle cp_x50(vec_x10, 25.0f, col_x10, "Circle_x50");
*/
//    std::vector<Circle> sorted_circles{cp_10}; //hier nur geschweifte Klammern, weil Konstr !!
//    std::cout << "\n" << sorted_circles.size() << std::endl;

    //sorted_circles.insert({"Circle_x3", cp_x30}); // hier aussen runde Klammern weil Methode und innen geschweifte Klammern
    //sorted_circles.insert({"Circle_x4", cp_x40});
    //sorted_circles.insert({"Circle_x4", cp_x50});

}
int main(int argc, char* argv[])
{
     return Catch::Session().run(argc, argv);
}
