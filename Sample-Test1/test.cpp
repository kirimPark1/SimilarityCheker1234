#include "pch.h"
#include "../3-1SimilarityChecker/3-1SimiliarChecker.cpp"
using namespace std;

TEST(TestCaseName, sameLengthCheck) {
	LengthChecker lengthChecker;
	std::string str1 = "ASD";
	std::string str2 = "DSA";
	EXPECT_EQ(60, lengthChecker.check(str1, str2));
}
TEST(TestCaseName, LengthCheckDiff2X) {
	LengthChecker lengthChecker;
	std::string str1 = "A";
	std::string str2 = "BB";
	EXPECT_EQ(0, lengthChecker.check(str1, str2));
}
TEST(TestCaseName, LengthCheckDiffPartial1) {
	LengthChecker lengthChecker;
	std::string str1 = "AAABB";
	std::string str2 = "BAA";
	EXPECT_EQ(20, lengthChecker.check(str1, str2));
}
TEST(TestCaseName, LengthCheckDiffPartial2) {
	LengthChecker lengthChecker;
	std::string str1 = "AA";
	std::string str2 = "AAA";
	EXPECT_EQ(30, lengthChecker.check(str1, str2));
}

TEST(TestCaseName, sameAlphaCheck) {
	AlphaChecker alphaChecker;
	std::string str1 = "ASD";
	std::string str2 = "DSA";
	EXPECT_EQ(40, alphaChecker.check(str1, str2));
}

TEST(TestCaseName, diffAlphaCheck) {
	AlphaChecker alphaChecker;
	std::string str1 = "A";
	std::string str2 = "BB";
	EXPECT_EQ(0, alphaChecker.check(str1, str2));
}

TEST(TestCaseName, lowercaseAlphaCheck) {
	AlphaChecker alphaChecker;
	std::string str1 = "asd";
	std::string str2 = "DSA";
	EXPECT_THROW(alphaChecker.check(str1, str2), std::invalid_argument);
}

TEST(TestCaseName, AlphaDiffCheck) {
	AlphaChecker alphaChecker;
	std::string str1 = "AA";
	std::string str2 = "AAE";
	EXPECT_EQ(20, alphaChecker.check(str1, str2));
}