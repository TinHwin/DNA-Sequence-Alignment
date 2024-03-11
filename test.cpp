// "Copyright [2023] <Truong-Thinh Huynh, Preston Luie>"

#include "EDistance.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(testStepInstr1) {
  std::string lhs = "a";
  std::string rhs = "a";

  EDistance eDistance(lhs, rhs);

  BOOST_REQUIRE_EQUAL(eDistance.penalty(lhs[0], rhs[0]), 0);
}
