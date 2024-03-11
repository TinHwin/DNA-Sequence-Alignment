// "Copyright [2023] <Truong-Thinh Huynh, Preston Luie>"

#include <iostream>
#include <fstream>
#include <string>

#include "EDistance.hpp"

#include <SFML/System.hpp>

int main(int argc, char* argv[]) {
  sf::Clock clock;
  sf::Time t;

  std::string stringCol;
  std::string stringRow;

  std::cin >> stringCol;
  std::cin >> stringRow;

  EDistance eDistance(stringCol, stringRow);

  int ans = eDistance.optDistance();

  t = clock.getElapsedTime();

  std::cout << "Edit distance = ";

  // Lambda expression that print out the edit distance.
  auto lamdaExpression = [=](){ std::cout << ans << std::endl; };

  lamdaExpression();

  std::cout << "Execution time is " << t.asSeconds() << " second\n";

  // Comment this out if you don't want the alignment.
  std::cout << eDistance.alignment();

  eDistance.clearMatrix();

  // Extra Credit
  /*
  sf::Clock eCClock;
  sf::Time eCT;

  EDistance eCEDistance(stringCol, stringRow);

  int eCAns = eCEDistance.eCOptDistance();

  eCT = eCClock.getElapsedTime();


  // Lambda expression that print out the edit distance.
  auto eCLamdaExpression = [=](){ std::cout << eCAns << std::endl; };

  eCLamdaExpression();

  std::cout << "Execution time is " << eCT.asSeconds() << " second\n";

  // Comment this out if you don't want the alignment.
  // std::cout << eDistance.alignment();

  eCEDistance.clearMatrix();
  */
  return 0;
}
