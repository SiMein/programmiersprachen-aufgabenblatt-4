// TestList.cpp (Programmiersprachen Aufgabe 4)

#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>
#include "list.hpp"
#include <iostream>


// * --------------- List-Tests --------------- * //
TEST_CASE("List check", "[aufgabe4.2]") {
  List<int> l1 {};
  REQUIRE(l1.empty() == true);
}

TEST_CASE("list-size", "[aufgabe4.2]") {
  List<int> l1 {};
  REQUIRE(l1.size() == 0);
}

TEST_CASE ("add an element with push_front ", "[aufg4.3  modifiers ]")
{
List <int> list ;
std::cout << "Die Aktuelle Size befor ist : " << list.size() << "\n";
list.push_front(42);  // Zugriff auf Inhalte des front-Knotens durch dereferenzierung in der Methode fronzt 
REQUIRE (42 == list.front());

std::cout << "Die Aktuelle Size after ist : " << list.size() << "\n";
}

int main(int argc, char * argv[]) {

  return Catch::Session().run(argc, argv);

}