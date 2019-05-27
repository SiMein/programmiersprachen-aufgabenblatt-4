// TestList.cpp (Programmiersprachen Aufgabe 4)

#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>
#include "list.hpp"


// * --------------- List-Tests --------------- * //
TEST_CASE("List check", "[aufgabe4.2]") {
  List<int> l1 {};
  REQUIRE(l1.empty() == true);
}

TEST_CASE("list-size", "[aufgabe4.2]") {
  List<int> l1 {};
  REQUIRE(l1.size() == 0);
}

int main(int argc, char * argv[]) {

  return Catch::Session().run(argc, argv);

}