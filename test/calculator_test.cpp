#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "calculator.hpp"

TEST_CASE("简单加减乘除") {
    Calculator c;
    CHECK(c.add(1.5, 2.5) == doctest::Approx(4.0));
    CHECK(c.subtract(5.0, 3.0) == doctest::Approx(2.0));
    CHECK(c.multiply(2.0, 3.5) == doctest::Approx(7.0));
    CHECK(c.divide(7.0, 2.0) == doctest::Approx(3.5));
}

TEST_CASE("除以零抛出异常") {
    Calculator c;
    CHECK_THROWS_AS(c.divide(1.0, 0.0), std::invalid_argument);
}
