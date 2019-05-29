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


TEST_CASE ("add an element with push_front and check front ", "[aufg4.3]"){
List <int> list ;
REQUIRE (list.empty()); // wenn liste leer dann direkt true 
std::cout << "Die Aktuelle Size befor ist : " << list.size() << "\n";
list.push_front(42);  // Zugriff auf Inhalte des front-Knotens durch dereferenzierung in der Methode front 
REQUIRE (42 == list.front());
list.push_front(41);
REQUIRE (41 == list.front());  
std::cout << "Die Aktuelle Size after ist : " << list.size() << "\n\n";
}


TEST_CASE ("add an element with push_back and check back", "[aufg4.3]"){
List <int> list ;
REQUIRE (list.empty());  // wenn liste leer dann direkt true 
std::cout << "Die Aktuelle Size befor ist : " << list.size() << "\n";
list.push_back(44);  // Zugriff auf Inhalte des front-Knotens durch dereferenzierung in der Methode front 
REQUIRE (44 == list.back());
list.push_back(45);
REQUIRE (45 == list.back());  // Bei nur einem list-element ,front und back zeigen auf gleiches element
std::cout << "Die Aktuelle Size after ist : " << list.size() << "\n\n";
}

TEST_CASE ("delete an element with pop_front and check front", "[aufg4.3]"){
List <int> list ;
REQUIRE (list.empty());  // wenn liste leer dann direkt true 
std::cout << "Die Aktuelle Size befor ist : " << list.size() << "\n";
list.push_back(44);  // Zugriff auf Inhalte des front-Knotens durch dereferenzierung in der Methode front 
REQUIRE (44 == list.back());
list.pop_front();

//list.push_back(45);
//REQUIRE (45 == list.back());  // Bei nur einem list-element ,front und back zeigen auf gleiches element

std::cout << "Die Aktuelle Size after ist : " << list.size() << "\n\n";
}


int main(int argc, char * argv[]) {

  return Catch::Session().run(argc, argv);

}