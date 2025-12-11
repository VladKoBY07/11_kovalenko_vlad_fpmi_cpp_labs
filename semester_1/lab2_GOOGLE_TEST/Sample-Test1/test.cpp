#include "pch.h"
#include "..\Task11\SupPrimeFunctions.cpp"
TEST(TestCaseName, TestName)
{
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(TestIsPrimeFunc, PrimeNumbers)
{
	EXPECT_TRUE(isprime(7));
	EXPECT_TRUE(isprime(11));
	EXPECT_TRUE(isprime(997));
}

TEST(TestIsPrimeFunc, NotPrimeNumbers)
{
	EXPECT_FALSE(isprime(4));
	EXPECT_FALSE(isprime(12));
	EXPECT_FALSE(isprime(1000));
}

TEST(LengthFunc, SomeNumbers)
{
	EXPECT_EQ(1, length(4));
	EXPECT_EQ(2, length(51));
	EXPECT_EQ(5, length(12345));
	EXPECT_EQ(0, length('\0'));
}

TEST(IsSupPrimeFunc, SupPrimeNumbers)
{
	EXPECT_TRUE(is_supprime(7));
	EXPECT_TRUE(is_supprime(11));
	EXPECT_TRUE(is_supprime(337));
}

TEST(IsSupPrimeFunc, NotSupPrimeNumbers)
{
	EXPECT_FALSE(is_supprime(23));
	EXPECT_FALSE(is_supprime(101));
	EXPECT_FALSE(is_supprime(227));
}

TEST(IsSupPrimeFunc, NotPrimeNumbers)
{
	EXPECT_FALSE(is_supprime(4));
	EXPECT_FALSE(is_supprime(100));
	EXPECT_FALSE(is_supprime(224));
}