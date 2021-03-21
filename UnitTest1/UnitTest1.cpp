#include "pch.h"
#include "CppUnitTest.h"
#include "../lab2.4/Matr.h"
#include "../lab2.4/Matr.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Matr m(2, 3);
			double t = m.Norm(m);
			Assert::AreEqual(t, 0.0);
		}
	};
}
