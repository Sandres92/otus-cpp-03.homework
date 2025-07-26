#define BOOST_TEST_MODULE test_version

#include "lib.h"
#include "custom_allocator.h"
#include "utils.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_allocator)

BOOST_AUTO_TEST_CASE(test_valid_version)
{
	BOOST_CHECK(version() > 0);
}

BOOST_AUTO_TEST_CASE(test_valid_sum)
{
	BOOST_CHECK(1 + 1 == 2);
}

BOOST_AUTO_TEST_CASE(test_factorial_1)
{
	int factorial = otus::utils::factorial(0);
	BOOST_CHECK(factorial == 0);
}

BOOST_AUTO_TEST_CASE(test_factorial_2)
{
	int factorial = otus::utils::factorial(4);
	BOOST_CHECK(factorial == 24);
}

BOOST_AUTO_TEST_SUITE_END()
