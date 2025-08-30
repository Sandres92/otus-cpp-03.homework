#define BOOST_TEST_MODULE test_version

#include <iostream>

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
	BOOST_CHECK(factorial == 1);
}

BOOST_AUTO_TEST_CASE(test_factorial_2)
{
	int factorial = otus::utils::factorial(4);
	BOOST_CHECK(factorial == 24);
}

BOOST_AUTO_TEST_CASE(test_allocator_1)
{
	otus::CustomAllocator<int, 4> allocator;
	int *num1 = allocator.allocate(1);

	int *num2 = allocator.allocate(1);

	BOOST_CHECK(num1 != nullptr && num2 != nullptr);
}

// BOOST_AUTO_TEST_CASE(test_allocator_2)
//{
//	bool result = true;
//	otus::CustomAllocator<int, 0> allocator;
//	try
//	{
//		int *num1 = allocator.allocate(5);
//		if (num1[0])
//		{
//			result = false;
//		}
//	}
//	catch (const std::invalid_argument &e)
//	{
//		result = true;
//	}
//	BOOST_CHECK(result);
// }

BOOST_AUTO_TEST_CASE(test_allocator_3)
{
	bool result = false;
	otus::CustomAllocator<int, 4> allocator;
	try
	{
		int *num1 = allocator.allocate(5);
		if (num1[0])
		{
			result = false;
		}
	}
	catch (const std::bad_alloc &e)
	{
		result = true;
	}
	BOOST_CHECK(result);
}

struct TestStruct4
{
	int a;
	TestStruct4(int a) : a(a)
	{
	}
};

BOOST_AUTO_TEST_CASE(test_allocator_4)
{
	otus::CustomAllocator<TestStruct4, 1> allocator;
	TestStruct4 *t = allocator.allocate(1);
	allocator.construct(t, 10);
	BOOST_CHECK(t->a == 10);
}

struct TestStruct5
{
	inline static int counter = 0;
	TestStruct5()
	{
		++counter;
	}
	~TestStruct5()
	{
		--counter;
	}
};

BOOST_AUTO_TEST_CASE(test_allocator_5)
{
	otus::CustomAllocator<TestStruct5, 1> allocator;
	TestStruct5 *t = allocator.allocate(1);
	allocator.construct(t);
	allocator.destroy(t);
	BOOST_CHECK(TestStruct5::counter == 0);
}

BOOST_AUTO_TEST_CASE(test_allocator_6)
{
	otus::CustomAllocator<int, 10>::template rebind<float>::other float_allocator;
	float *num = float_allocator.allocate(1);

	BOOST_CHECK(num != nullptr);
}

BOOST_AUTO_TEST_CASE(test_allocator_7)
{
	otus::CustomAllocator<int, 4> allocator;
	int *n = allocator.allocate(2);

	allocator.deallocate(n, 2);
	allocator.deallocate(n, 2);

	BOOST_CHECK(allocator.GetPosition() == 0);
}

BOOST_AUTO_TEST_SUITE_END()
