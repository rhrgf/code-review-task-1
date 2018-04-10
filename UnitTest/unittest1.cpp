#include "stdafx.h"
#include "CppUnitTest.h"
#include "sort.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			istringstream test_str("aa aa b bbb bb bb b b ab a a a aa a b");
			vector<PAIR> result = sortWordFromStream(test_str);
			Assert::IsTrue(result[0].second == 4 && result[1].second == 4
				&& result[2].second == 3 && result[3].second == 2
				&& result[4].second == 1 && result[5].second == 1);
		}

	};
}