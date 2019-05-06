#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"             // Frage -warum bei tests im header nur die hpps includen ?
#include "mat2.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
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

  a+=c;                          // Vek.-addition
  REQUIRE(c.x == Approx(2.0f));
  REQUIRE(c.y == Approx(3.0f));
                            

  Vec2 ii{5.0f, 8.0f};
  Vec2 jj{2.0f, 3.0f};
  ii-=jj;                          // Vek.-subtraktion
  REQUIRE(ii.x == Approx(3.0f));
  REQUIRE(ii.y == Approx(5.0f));


  Vec2 kk{5.0f, 8.0f};
  kk *= 5.0f;                          // Vek.-Multipl
  REQUIRE(kk.x == Approx(25.0f));
  REQUIRE(kk.y == Approx(40.0f));


  Vec2 ll{20.0f, 15.0f};
  ll /= 5.0f;                          // Vek.-Div
  REQUIRE(ll.x == Approx(4.0f));
  REQUIRE(ll.y == Approx(3.0f));
  

  ll /= 0;                            // Div by 0
  REQUIRE(ll.x == Approx(4.0));
  REQUIRE(ll.y== Approx(3.0));




  Vec2 aaa{5.0f,6.0f};    // Freie Funktionen für Operatoren  !!!
  Vec2 bbb{3.0f,4.0f};
  Vec2 ccc{};

  ccc=aaa+bbb;                          //Vek.-Add
  REQUIRE(ccc.x == Approx(8.0f));
  REQUIRE(ccc.y == Approx(10.0f));


  Vec2 ddd{10.0f,15.0f};
  Vec2 eee{11.0f,16.0};
  Vec2 fff{};

  fff=ddd-eee;                        //Vek.-Subktr.
  REQUIRE(fff.x == Approx(-1.0f));
  REQUIRE(fff.y == Approx(-1.0f));


  Vec2 ggg{42.0f,48.0f};
  Vec2 hhh{};

  hhh=ggg*-1.0f;                      // Vek.-Multip.
  REQUIRE(hhh.x == Approx(-42.0f));
  REQUIRE(hhh.y == Approx(-48.0f));


  Vec2 iii{33.0f,34.0f};
  Vec2 jjj{};

  jjj=iii/-2.0f;                    // Vek.-Div

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
  
  mx_1 *= mx_2;                       //Mat-Multipl. (Menberfkt)
  REQUIRE(mx_1.e_00 == Approx(1.0f));
  REQUIRE(mx_1.e_01 == Approx(0.0f));
  REQUIRE(mx_1.e_10 == Approx(0.0f));
  REQUIRE(mx_1.e_11 == Approx(1.0f));


  Mat2 mx_3{};                        //Mat-Multipl. (Freie Fkt)
  
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


  REQUIRE(mx_4.det() == Approx(0.0f));
  REQUIRE(mx_8.det() == Approx(20.0f));
  

  Mat2 to_inv{-1.0f,2.0f,3.0f,-2.0f};   // Matrix invert
  Mat2 inv = inverse(to_inv);
 
  REQUIRE(inv.e_00 == Approx(0.5f));
  REQUIRE(inv.e_01 == Approx(0.5f));
  REQUIRE(inv.e_10 == Approx(0.75f));
  REQUIRE(inv.e_11 == Approx(0.25f));

  Mat2 to_trans{-1.0f,2.0f,3.0f,-4.0f};   // Matrix transpose
  Mat2 trans = transpose(to_trans);

  REQUIRE (trans.e_10 == Approx(3.0));
  REQUIRE (trans.e_01 == Approx(2.0));

  Vec2 aaaa{0.0f,0.0f};                   // // Matrix rotate
  Vec2 bbbb{1.0f,1.0f};
  Mat2 mmmm = make_rotation_mat2(M_PI/2);
  REQUIRE(mmmm.e_00 == Approx(0.0f));
  REQUIRE(mmmm.e_01 == Approx(1.0f));
  REQUIRE(mmmm.e_10 == Approx(-1.0f));
  REQUIRE(mmmm.e_11 == Approx(0.0f));

}

TEST_CASE("circle", "[circle]"){

  Circle circ1;           // Default-circumference

  float c_1 = circ1.circumference();
  REQUIRE(c_1 == Approx(6.28319f));

 
  Vec2 v_5{9};            // Custum-circumference
  float ra_1 = 9.0f;
  Color co_5{};

  Circle circ2{v_5,ra_1,co_5};

  float c_5 = circ2.circumference();
  REQUIRE(c_5 == Approx(56.549));

}

TEST_CASE("rectangle", "[rectangle]"){

  Rectangle rect1;        // Default-circumference

  float r_1 = rect1.circumference();
  REQUIRE(r_1 == Approx(20.0f));

  Color co_1;           // Custum-circumference
  Vec2 v_1{1,1};
  Vec2 v_2{5,5};
  Rectangle rect2{v_1,v_2,co_1}; 
  
  float r_2 = rect2.circumference();
  REQUIRE(r_2 == Approx(16.0));

}

TEST_CASE("is_inside", "[is_inside]"){
  Circle cir;
  Vec2 a {0.0f,0.0f};
  Vec2 b {1.1f,1.1f};
  REQUIRE(cir.is_inside(a) == true);
  REQUIRE(cir.is_inside(b) == false);

  Rectangle rec;
  Vec2 c {1.0f,1.0f};
  Vec2 d {100.0f,100.0f};
  REQUIRE(rec.is_inside(c) == true);
  REQUIRE(rec.is_inside(d) == false);
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
