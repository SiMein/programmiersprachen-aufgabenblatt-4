#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

TEST_CASE("vector_add", "[+]")
{
    vector <int> v_1 {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector <int> v_2 {9 ,8, 7, 6, 5, 4, 3, 2, 1};
    vector <int> v_3 (9);           //Init d zielvectors mit groesse 9

             //anfang und ende der quelle;  start d ziels, nimmt sich automatisch die entspr. werte
    transform(v_1.begin(), v_1.end(), v_2.begin(), v_3.begin(), [] (int a, int b) {
        return a + b;  // Def der Funkt./Lambdas     Lambda-Expression von []  bis  }
    });

    REQUIRE(all_of(v_3.begin(), v_3.end(), // all_of erwartet boolwert.  , Lambda an dieser stelle def. 
    [](int a)                               
    {                           // gibt true oder false zurück an genau dieser stelle 
        return a == 10;
    }));
    
}

int main (int argc, char* argv [])
{
    return Catch::Session().run(argc, argv);
}