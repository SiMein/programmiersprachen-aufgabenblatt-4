// TestList.cpp (Programmiersprachen Aufgabe 4)

#define CATCH_CONFIG_RUNNER
#include "circle.hpp"
#include "list.hpp"
#include <catch.hpp>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>


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

  REQUIRE(1.0 == (*circle_list.begin()).radius_); 

  auto itt = circle_list.begin();
  itt++;
  REQUIRE(1.0 == (*itt).radius_);
}


TEST_CASE (" should be an empty range after default construction ","[ iterators aufg 4.6  1]"){

  List <int> list;
  auto b = list.begin();
  auto e = list.end();
  REQUIRE (b == e);
}


TEST_CASE (" provide access to the first element with begin aufg 4.6.", "[ iterators  aufg 4.6  2 ]"){
  List <int> list ;         
  list.push_front(42);
  REQUIRE (42 == *list.begin());
  list.pop_back();
  std::cout << "Die Size der Liste ist : " << list.size() << "      aufg 4.6  2 \n";

REQUIRE (list.end() == list.begin());
}


TEST_CASE ("TestCase_7 memberfunction  ==  !=   ", "[ iterators  aufg 4.7   ]"){
  List<int> list1a; 
  List<int> list1b;

  REQUIRE(list1a==list1b);  // when both lists empty, also true  ==

  list1a.push_back(66);

  REQUIRE (!(list1a==list1b)); // when list have different sizes  

  list1b.push_back(66);

  REQUIRE(list1a==list1b);  // when same elements(values) in both lists, also true with ==

  list1a.push_back(67); // when different elements in the lists
  list1b.push_back(68);

  REQUIRE(list1a!=list1b); // Ungleichoperator checken 

  std::cout << "\nDie Size der list1 ist : " << list1a.size() << "      aufg 4.7   \n";
  std::cout << "Die Size der list2 ist : " << list1b.size() << "      aufg 4.7   \n";
}


TEST_CASE ("TestCase_8   copy constructor", "[constructor  aufg 4.8  ]")
{
    List<int> list; 
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);
    List<int> list2{list};
    REQUIRE(list == list2);
    REQUIRE(list.size() == list2.size());
}


TEST_CASE ("TestCase_9      insert-function          ", "[ insert-function  aufg 4.9 ]"){
  List<int> list1;
  List<int> list2;                              // ERSTES element
  REQUIRE(5 == *list2.insert(list1.begin(),5)); // Einuegen an erster Stelle wenn list leer, iterator beliegig-hier mit begin
  list2.push_back(88);  // ZWEITES element hinten einfuegen ,, derefenzierter zurückgegebenr iterator ist der eingefuegte int
  REQUIRE(list2.size()==2);

  List<int> list3;
  list3.push_front(3);
  list3.push_front(4);
  list3.push_front(5);
  REQUIRE(88 == *list2.insert(list3.end(),22));  // DRITTES elemt,    Tatsaechliches einfuegen am ende der Liste
  REQUIRE(list3.size()==3);
/*
  List<int> list4;
  list4.push_front(333);
  list4.push_front(444);

  ListIterator iter02 = list3.begin();
  REQUIRE(22 == *list2.insert(iter02,666));  // VIERTES elemt,  mit irgendwo/beliebigen  Iterator
  REQUIRE(list3.size()==4);
*/
}

TEST_CASE ("TestCase_10      reverse-function  free and member        ", "[ reverse-function  aufg 4.10 ]"){ 
  
  List<int> listr; 

  List<int> list_bee{1,2,3,4};
  ListIterator between = list_bee.begin();
  between++;
  REQUIRE(2 == *between);

  listr.push_front(24);
  listr.push_front(25);
  listr.push_front(26);
  listr.push_front(27);
  
  //listr.reverse(between,5);

  //List<int> list2{24,25,26,27};
  //REQUIRE (listr == list2);
  std::cout << std::endl;
  

  List<int> list_free; 
  
  list_free.push_back(524);
  list_free.push_back(525);
  list_free.push_back(526);
  list_free.push_back(527);

  List<int> list_free_rev = reverse(list_free);
  REQUIRE(527 == *list_free_rev.begin());
  auto xyz = list_free_rev.begin();
  REQUIRE(527 == *xyz);     //Einzelpruefung
  xyz++;
  REQUIRE(526 == *xyz);
  xyz++;
  REQUIRE(525 == *xyz);
  xyz++;
  REQUIRE(524 == *xyz);

  REQUIRE(527 == *list_free_rev.begin()); // Pruefung mit begin
  //REQUIRE(524 == *list_free_rev.end()); // Pruefung mit end nicht möglich ?? Warum --zeigt bereits hinter das letzte element
  std::cout << "aufg 4.10 free-fkt-reverse   list_free_rev enthält von begin to end folgende elemente : ";
  for(auto ix : list_free_rev){
    std::cout << (ix) << "  ";
  }
}

TEST_CASE ("TestCase_11  copy own list into vector    ", "[ constructor  aufg 4.11 ]"){

  List<int> from_list ;
  from_list.push_front(1);
  from_list.push_front(2);
  from_list.push_front(3);
  from_list.push_front(4);

  std::vector<int> to_vector;

  std::copy(from_list.begin(), from_list.end(), std::back_inserter(to_vector));

  std::cout << "\nAufg 4.11    from_vectors size : " << to_vector.size() << "   to_vector contains: \n";

  REQUIRE(4 == to_vector.size());

  REQUIRE(4 == to_vector.at(0));
  REQUIRE(3 == to_vector.at(1));
  REQUIRE(2 == to_vector.at(2));
  REQUIRE(1 == to_vector.at(3));
 
  std::copy(to_vector.begin(), to_vector.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << '\n';
}


TEST_CASE ("TestCase_12  implem. zuweisungsoperator wie in vorlesung vorgest.  ", "[ constructor  aufg 4.12 ]"){
}


TEST_CASE ("TestCase_13  move constructor   ", "[ constructor  aufg 4.13 ]"){

  List<int> list ;
  list.push_front(1);
  list.push_front(2);
  list.push_front(3);
  list.push_front(4);
  List<int> list2 = std::move(list);  // rhs wird ubertragen auf lhs, kennzeichnung move intern mit && 
  REQUIRE(0 == list.size ());
  REQUIRE(list.empty());
  REQUIRE(4 == list2.size ());
}

TEST_CASE ("TestCase_14  list konkat. and more   ", "[ constructor  aufg 4.14 ]"){

  List<int> int_list{9,5,38,100};
 
  REQUIRE(4 == int_list.size());

  ListIterator i3 = int_list.begin();  // eigenen Iterator erstellen, beginnend auf erstem element
  REQUIRE (9 == *i3);
  i3++;               // hier mal manuelles weiterschalten d Iterators mit ++operator getestet
  REQUIRE (5 == *i3);
  i3++;
  REQUIRE (38 == *i3);
  i3++;
  REQUIRE (100 == *i3);
  i3++;

  List<int> int_list_empty{};
  REQUIRE(0 == int_list_empty.size());  // funktioniert auch mit leerem {}-konstr


  
  List<int> konka_list = List<int>{1,2} + List<int>{5,6};
  REQUIRE(4 == konka_list.size());
  List<int> kuno{1,2,5,6};
  REQUIRE(konka_list==kuno);

  auto l = List <int >{1 , 2, 3, 4, 5} + List <int >{6 , 7, 8, 9};
  REQUIRE(9 == l.size());
  
}



int main(int argc, char * argv[]) {

  return Catch::Session().run(argc, argv);

}