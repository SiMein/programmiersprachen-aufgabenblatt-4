#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"             // Frage -warum bei tests im header nur die hpps includen ?
#include "mat2.hpp"
#include <iostream>


TEST_CASE("vec2", "[vec2]")
{
  Vec2 a{};   

  REQUIRE(a.x == Approx(0.0));  //Attributzugriffckeck -default
  REQUIRE(a.y == Approx(0.0));

  Vec2 b{5.1f, -9.3f};

  REQUIRE(b.x == Approx(5.1f));  //Attributzugriffckeck -custom
  REQUIRE(b.y == Approx(-9.3f));



  Vec2 c{2.0f, 3.0f};         //  Memberfunktionen Operatoren !!!

  a+=c;                          // Vektoraddition
  REQUIRE(c.x == Approx(2.0f));
  REQUIRE(c.y == Approx(3.0f));
                            

  Vec2 ii{5.0f, 8.0f};
  Vec2 jj{2.0f, 3.0f};
  ii-=jj;                          // Vektorsubtraktion
  REQUIRE(ii.x == Approx(3.0f));
  REQUIRE(ii.y == Approx(5.0f));


  Vec2 kk{5.0f, 8.0f};
  kk *= 5.0f;                          // Multipl
  REQUIRE(kk.x == Approx(25.0f));
  REQUIRE(kk.y == Approx(40.0f));


  Vec2 ll{20.0f, 15.0f};
  ll /= 5.0f;                          // Div
  REQUIRE(ll.x == Approx(4.0f));
  REQUIRE(ll.y == Approx(3.0f));
  

  ll /= 0;
  REQUIRE(ll.x == Approx(4.0));
  REQUIRE(ll.y== Approx(3.0));




  Vec2 aaa{5.0f,6.0f};    // Freie Funktionen für Operatoren  !!!
  Vec2 bbb{3.0f,4.0f};
  Vec2 ccc{};

  ccc=aaa+bbb;
  REQUIRE(ccc.x == Approx(8.0f));
  REQUIRE(ccc.y == Approx(10.0f));


  Vec2 ddd{10.0f,15.0f};
  Vec2 eee{11.0f,16.0};
  Vec2 fff{};

  fff=ddd-eee;
  REQUIRE(fff.x == Approx(-1.0f));
  REQUIRE(fff.y == Approx(-1.0f));


  Vec2 ggg{42.0f,48.0f};
  Vec2 hhh{};

  hhh=ggg*-1.0f;
  REQUIRE(hhh.x == Approx(-42.0f));
  REQUIRE(hhh.y == Approx(-48.0f));


  Vec2 iii{33.0f,34.0f};
  Vec2 jjj{};

  jjj=iii/-2.0f;

  REQUIRE(jjj.x == Approx(-16.5f));
  REQUIRE(jjj.y == Approx(-17.0f));

 
  Vec2 kkk{4.0f,8.0f};
  Vec2 lll{};

  lll=-1.0f*kkk;
  REQUIRE(lll.x == Approx(-4.0f));
  REQUIRE(lll.y == Approx(-8.0f));

}

TEST_CASE("mat2", "[mat2]"){

  Mat2 mx_1{};
  Mat2 mx_2{};
  
  mx_1 *= mx_2;
  REQUIRE(mx_1.e_00 == Approx(1.0f));
  REQUIRE(mx_1.e_01 == Approx(0.0f));
  REQUIRE(mx_1.e_10 == Approx(0.0f));
  REQUIRE(mx_1.e_11 == Approx(1.0f));


  Mat2 mx_3{};
  
  mx_3 = mx_1*mx_2;
  REQUIRE(mx_3.e_00 == Approx(1.0f));
  REQUIRE(mx_3.e_01 == Approx(0.0f));
  REQUIRE(mx_3.e_10 == Approx(0.0f));
  REQUIRE(mx_3.e_11 == Approx(1.0f));


  Mat2 mx_4{};
  Mat2 mx_5{0.0f,0.0f,0.0f,0.0f};
 
  mx_4 = mx_4*=mx_5;
  REQUIRE(mx_4.e_00 == Approx(0.0f));
  REQUIRE(mx_4.e_01 == Approx(0.0f));
  REQUIRE(mx_4.e_10 == Approx(0.0f));
  REQUIRE(mx_4.e_11 == Approx(0.0f));
  
  
  Mat2 mx_8{};

  Mat2 mx_6{-1.0f,3.0f,2.0f,4.0f};
  Mat2 mx_7{5.0f,7.0f,6.0f,8.0f};
  
  mx_8 = mx_6 * mx_7;

  REQUIRE(mx_8.e_00 == Approx(9.0f));
  REQUIRE(mx_8.e_01 == Approx(10.0f));
  REQUIRE(mx_8.e_10 == Approx(43.0f));
  REQUIRE(mx_8.e_11 == Approx(50.0f));


  /*
  std::cout << mx_8.e_00 << "\n";
  std::cout << mx_8.e_01 << "\n";
  std::cout << mx_8.e_10 << "\n";
  std::cout << mx_8.e_11 << "\n";
  */
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
