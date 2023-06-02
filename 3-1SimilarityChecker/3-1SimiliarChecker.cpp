#include <string>
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