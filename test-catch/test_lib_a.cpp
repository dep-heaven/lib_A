#include <catch2/catch.hpp>

#include <lib_A/lib_A.hpp>

TEST_CASE("Some demo test", "[demo]") {
    // We need to get the answer to all of our questions
    REQUIRE(42 == lib_A::fn_a());
}