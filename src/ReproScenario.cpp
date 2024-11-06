#include <catch2/catch_test_macros.hpp>

SCENARIO("Repro")
{
    GIVEN("ReproGiven")
    {
        WHEN("ReproWhenA")
        {
            THEN("ReproThenA1")
            {
                SUCCEED();
            }
            THEN("ReproThenA2")
            {
                SUCCEED();
            }
        }
        WHEN("ReproWhenB")
        {
            //SKIP("skip");
            SUCCEED();
        }
    }
}