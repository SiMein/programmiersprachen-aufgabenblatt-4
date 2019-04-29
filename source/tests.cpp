#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"


TEST_CASE("vec2", "[vec2]")
{
  Vec2 a{};   

  REQUIRE(a.x == Approx(0.0));  //Attributzugriffckeck -default
  REQUIRE(a.y == Approx(0.0));

  Vec2 b{5.1f, -9.3f};

  REQUIRE(b.x == Approx(5.1f));  //Attributzugriffckeck -custom
  REQUIRE(b.y == Approx(-9.3f));

  Vec2 c{2.0f, 3.0f};

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








  //Vec2 d {4.0f, 8.0f};           
  //Vec3 e {1.0f, 1.0f};
  
  //d-=e;
  //REQUIRE(d.x == Approx(-4.0f));
  //REQUIRE(d.y == Approx(-8.0f));

  

  //a-=d;                
  //REQUIRE(b.x == Approx(-4.0f));
  //REQUIRE(b.y == Approx(-8.0f));


//  Vec2 e {2.0f, 3.0f};

  
  //REQUIRE(b.*=c == Approx(-9.3f));
  //REQUIRE(b./=c == Approx(-9.3f));

}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
