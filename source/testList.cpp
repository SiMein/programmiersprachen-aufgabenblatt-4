// TestList.cpp (Programmiersprachen Aufgabe 4)

#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>
#include "list.hpp"
#include <iostream>


// * --------------- List-Tests --------------- * //
TEST_CASE("TestCase_0    List check", "[aufgabe4.2]") {
  List<int> l1 {};
  REQUIRE(l1.empty() == true);
}


TEST_CASE("TestCase_0     list-size", "[aufgabe4.2]") {
  List<int> l1 {};
  REQUIRE(l1.size() == 0);
}


TEST_CASE ("TestCase_1  add an element with push_front and check front ", "[aufg4.3]"){
List <int> list ;
REQUIRE (list.empty()); // wenn liste leer dann direkt true 
std::cout << "Die Aktuelle Size befor ist : " << list.size() << "      TestCase_1 \n";
list.push_front(42);  // Zugriff auf Inhalte des front-Knotens durch dereferenzierung in der Methode front 
REQUIRE (42 == list.front());
list.push_front(41);
REQUIRE (41 == list.front());  
std::cout << "Die Aktuelle Size after ist : " << list.size() << "      TestCase_1\n\n";
}


TEST_CASE ("TestCase_2  add an element with push_back and check back", "[aufg4.3]"){
List <int> list ;
REQUIRE (list.empty());  // wenn liste leer dann direkt true 
std::cout << "Die Aktuelle Size befor ist : " << list.size() << "      TestCase_2 \n";
list.push_back(44);  // Zugriff auf Inhalte des front-Knotens durch dereferenzierung in der Methode front 
REQUIRE (44 == list.back());
list.push_back(45);
REQUIRE (45 == list.back());  // Bei nur einem list-element ,front und back zeigen auf gleiches element
std::cout << "Die Aktuelle Size after ist : " << list.size() << "      TestCase_2\n\n";
}


TEST_CASE ("TestCase_3     delete an element with pop_front and check front", "[aufg4.3]"){
List <int> list ;
REQUIRE (list.empty());  // wenn liste leer dann direkt true 
list.pop_front();
std::cout << "Die Aktuelle Size befor ist : " << list.size() << "      TestCase_3  \n";
list.push_front(44);  // Zugriff auf Inhalte des front-Knotens durch dereferenzierung in der Methode front 
REQUIRE (44 == list.front());
list.pop_front();

list.push_front(47);
list.push_front(48);
list.pop_front();
REQUIRE (47 == list.front());

std::cout << "Die Aktuelle Size after ist : " << list.size() << "      TestCase_3  \n\n";
}


TEST_CASE ("TestCase_4       delete an element with pop_back and check back", "[aufg4.3]"){
List <int> list ;
REQUIRE (list.empty());  // wenn liste leer dann direkt true 
list.pop_back();
std::cout << "Die Aktuelle Size befor ist : " << list.size() << "      TestCase_4\n";
list.push_back(44);  // Zugriff auf Inhalte des front-Knotens durch dereferenzierung in der Methode front 
REQUIRE (44 == list.back());
list.pop_back();

list.push_back(48);
list.push_back(49);
list.pop_back();
REQUIRE (48 == list.back());

std::cout << "Die Aktuelle Size after ist : " << list.size() << "      TestCase_4  \n\n";
}

int main(int argc, char * argv[]) {

  return Catch::Session().run(argc, argv);

}