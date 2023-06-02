#include <algorithm>
#include <iostream>
#include <set>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

class LengthChecker
{
public:
	int check(string str1, string str2)
	{
		if (str1.length() == str2.length()) {
			return 60;
		} 
		if (str1.length() * 2 == str2.length() ||
			str2.length() * 2 == str1.length()) {
			return 0;
		} else
		{
			int shortStr = str1.length();
			int longStr = str2.length();

			if (longStr < shortStr)
			{
				int tmp = shortStr;
				shortStr = longStr;
				longStr = tmp;
			}
			return ((1 - (static_cast<double>(longStr - shortStr) / shortStr)) * 60);
		}
	}
};
class AlphaChecker
{
public:
	int getSameAlphabetScore(const string &str1, const string &str2)
	{
		set<char> sortedStr1 = getAlphaSetfromString(str1);
		set<char> sortedStr2 = getAlphaSetfromString(str2);
		set<char> totalAlphaSet;
		merge(sortedStr1.begin(), sortedStr1.end(), sortedStr2.begin(), sortedStr2.end(), std::inserter(totalAlphaSet, totalAlphaSet.begin()));
		int samecnt = 0;
		for (char curChar : totalAlphaSet)
		{
			if (isExistString(str1, curChar)
				&& isExistString(str2, curChar)) samecnt += 1;
		}
		return static_cast<double>(samecnt) / totalAlphaSet.size() * 40;
		return totalAlphaSet.size();
	}
	int check(const string& str1, const string& str2)
	{
		if (isLowerCase(str1) || isLowerCase(str2))
		{
			throw std::invalid_argument(("we support uppercase"));
		}
		return getSameAlphabetScore(str1, str2);
	}

	bool isLowerCase(const string& str1)
	{
		for (int i = 0; i < str1.length(); i++)
		{
			if (str1.at(i) < 'A' || str1.at(i) > 'Z') return true;
		}
		return false;
	}

	set<char> getAlphaSetfromString(const string& str1)
	{
		set<char> alphaList;
		for (int i = 0; i < str1.length(); i++)
		{
			alphaList.insert(str1.at(i));
		}
		return alphaList;
	}

	bool isExistString(const string& str1, char curChar)
	{
		return str1.find(curChar) <= str1.length();
	}
};