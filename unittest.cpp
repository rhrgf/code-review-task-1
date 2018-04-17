#include "stdafx.h"
#include "CppUnitTest.h"
#include "functions_for_test.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace wordCounterTest
{		
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestCmp)
		{
			vector<int> res;
			vector<int> correct;

			correct.push_back(false);
			correct.push_back(false);
			correct.push_back(true);

			res.push_back(cmp(pair<string, int>("a", 1), pair<string, int>("b", 2)));
			res.push_back(cmp(pair<string, int>("a", 5), pair<string, int>("b", 5)));
			res.push_back(cmp(pair<string, int>("a", 7), pair<string, int>("b", 6)));

			for (int i = 0; i < correct.size(); i++)
				Assert::AreEqual(correct[i], res[i]);
		}

		TEST_METHOD(TestSortMap)
		{
			map<string, int> to_sort;
			vector<pair<string, int>> res;
			vector<pair<string, int>> correct;

			to_sort["a"] = 5;
			to_sort["b"] = 10;
			to_sort["c"] = 3;
			to_sort["d"] = 9;

			correct.push_back(pair<string, int>("b", 10));
			correct.push_back(pair<string, int>("d", 9));
			correct.push_back(pair<string, int>("a", 5));
			correct.push_back(pair<string, int>("c", 3));

			sortMap(to_sort, res, cmp);

			for (int i = 0; i < correct.size(); i++) {
				Assert::AreEqual(correct[i].first, res[i].first);
				Assert::AreEqual(correct[i].second, res[i].second);
			}
		}

	};
}