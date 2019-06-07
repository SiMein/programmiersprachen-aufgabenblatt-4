// TestList.cpp (Programmiersprachen Aufgabe 4)

#define CATCH_CONFIG_RUNNER
#include "circle.hpp"
#include "list.hpp"
#include <catch.hpp>
#include <cmath>
#include <algorithm>
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


TEST_CASE ("TestCase_5     clear    should be empty after clearing     ", "[aufg4.4]"){
List <int> list ;
list.push_front(1);
list.push_front(2);
list.push_front(3);
list.push_front(4);
std::cout << "Die Aktuelle Size befor clear ist : " << list.size() << "      TestCase_5 \n";
list.clear();
std::cout << "Die Aktuelle Size after clear ist : " << list.size() << "      TestCase_5\n\n";
list.clear();
REQUIRE (list.empty());
list.push_front(1);
list.~List();
REQUIRE (list.empty());
}


TEST_CASE ("TestCase_6    test Iterator and list with circle-Obj.    ", "[aufg4.5]"){
Circle c_1;
Circle c_2;
Circle c_3;
Circle c_4;
List<Circle> circle_list ;
auto c_it = circle_list.begin();
std::cout << "Die Size der Liste ist : " << circle_list.size() << "      TestCase_6 \n";
REQUIRE (c_it == nullptr); // Abfrage des Iterators bei leerer Liste moeglich ??

circle_list.push_back(c_1);
circle_list.push_back(c_2);
circle_list.push_back(c_3);
circle_list.push_back(c_4);

//auto c_it = circle_list.begin();
//std :: cout << "Der Radius des 1. Circles in der Liste ist: ";
//<< c_it->.radius_ << std::endl;     // statt nethodenaufruf getter auch .attribut zugriff moeglich ??

}



TEST_CASE (" should be an empty range after default construction ","[ iterators aufg 4.6  1]"){

List <int> list;
auto b = list.begin();
auto e = list.end();
REQUIRE (b == e);
}


TEST_CASE (" provide access to the first element with begin aufg 4.6.", "[ iterators  aufg 4.6  2 ]")
{
List <int> list ;         //  SIGSEGV - Segmentation violation signal  ???
list.push_front(42);
REQUIRE (42 == *list.begin());
list.pop_back();
std::cout << "Die Size der Liste ist : " << list.size() << "      aufg 4.6  2 \n";

REQUIRE (list.end() == list.begin());
}


TEST_CASE (" memberfunction  ==  !=   ", "[ iterators  aufg 4.7   ]"){
List<int> list1;        
list1.push_front(42);
List<int> list1b{list1};

//REQUIRE (list1==list1b);

List<int> list2;
list2.push_front(98);
list2.push_back(99);

std::cout << "\nDie Size der list1 ist : " << list1.size() << "      aufg 4.7   \n";
std::cout << "Die Size der list2 ist : " << list2.size() << "      aufg 4.7   \n";

//REQUIRE (list.end() == list.begin());
}



int main(int argc, char * argv[]) {

  return Catch::Session().run(argc, argv);

}