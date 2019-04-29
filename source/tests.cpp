#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include vec2.hpp

std::cout << "Hello,printout !!!!!! \n";


int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
