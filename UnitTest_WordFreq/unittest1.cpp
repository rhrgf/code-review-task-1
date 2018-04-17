#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Word_Frequency_Generator/Word_Frequency.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest_WordFreq
{		
	TEST_CLASS(UnitTest_WordFreq)
	{
	public:
		
		TEST_METHOD(Test_CountWordFrequencyFromFile)
		{
			map<string, size_t> word_count;
			CountWordFrequencyFromFile("../words.txt", word_count);
			Assert::AreEqual(4, int(word_count["the"]));
			Assert::AreEqual(3, int(word_count["is"]));
			Assert::AreEqual(2, int(word_count["sunny"]));
			Assert::AreEqual(1, int(word_count["day"]));
		}

		TEST_METHOD(Test_SortWordFrequency)
		{
			map<string, size_t> word_count;
			CountWordFrequencyFromFile("../words.txt", word_count);
			auto word_freq = SortWordFrequency(word_count);

			ostringstream ans;
			for (auto element : word_freq) {
				ans << element.first << " " << element.second;
			}
			Assert::AreEqual("the 4is 3sunny 2day 1", ans.str().c_str());
		}

	};
}