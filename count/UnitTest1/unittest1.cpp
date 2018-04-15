#include "stdafx.h"
#include "CppUnitTest.h"
#include "../count/DealWithString.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			std::string s("how are you\nfine thank you and you\ni am fine too");
			DealWithString dws;
			vector <Save> save(100);
			save = dws.count(s);
			Assert::IsTrue(save[0].number == 3 && save[1].number == 2 && save[2].number == 1 && save[3].number == 1);
			
		}

	};
}