#include"gtest/gtest.h"
#include"count.h"

namespace
{
	class CountTest : public ::testing::Test
	{
		public:
			CountTest(){}
			virtual ~CountTest(){}
	};
	
	TEST_COUNT(CountTest)
	{
		map<string, int> WordMap;
		string word;
		EXPECT_EQ(0, ReadFile("test.txt", WordMap));
		word = "the";
		EXPECT_EQ(4, WordMap[word]);
		word = "is";
		EXPECT_EQ(3, WordMap[word]);
		word = "sunny";
		EXPECT_EQ(2, WordMap[word]);
		word = "day";
		EXPECT_EQ(1, WordMap[word]);
		EXPECT_EQ(0, PrintWord(WordMap));
	}
}
