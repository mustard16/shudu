#include "pch.h"
#include "CppUnitTest.h"
#include "../sudokuUnittest/game.h"
#include "../sudokuUnittest/main.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		Shudu s;
		TEST_METHOD(TestMethod_c1)
		{
			int argc = 3;
			char* argv[10];
			argv[1] = "-c";
			argv[2] = "0";
			Assert::AreEqual(0, unitest(argc, argv));
		}
		TEST_METHOD(TestMethod_c2)
		{
			int argc = 3;
			char* argv[10];
			argv[1] = "-c";
			argv[2] = "100";
			Assert::AreEqual(1, unitest(argc, argv));
		}
		TEST_METHOD(TestMethod_c3)
		{
			int argc = 3;
			char* argv[10];
			argv[1] = "-c";
			argv[2] = "1000001";
			Assert::AreEqual(0, unitest(argc, argv));
		}

		TEST_METHOD(TestMethod_s1)
		{
			int argc = 3;
			char* argv[10];
			argv[1] = "-s";
			argv[2] = "game.txt";
			Assert::AreEqual(1, unitest(argc, argv));
		}
		TEST_METHOD(TestMethod_s2)
		{
			int argc = 3;
			char* argv[10];
			argv[1] = "-s";
			argv[2] = "none.txt";
			Assert::AreEqual(1, unitest(argc, argv));
		}
		TEST_METHOD(TestMethod_n1)
		{
			int argc = 3;
			char* argv[10];
			argv[1] = "-n";
			argv[2] = "0";
			Assert::AreEqual(0, unitest(argc, argv));
		}
		TEST_METHOD(TestMethod_n2)
		{
			int argc = 3;
			char* argv[10];
			argv[1] = "-n";
			argv[2] = "10";
			Assert::AreEqual(0, unitest(argc, argv));
		}
		TEST_METHOD(TestMethod_n3)
		{
			int argc = 3;
			char* argv[10];
			argv[1] = "-n";
			argv[2] = "10000000";
			Assert::AreEqual(0, unitest(argc, argv));
		}
		TEST_METHOD(TestMethod_m1)
		{
			int argc = 5;
			char* argv[10];
			argv[1] = "-n";
			argv[2] = "0";
			argv[3] = "-m";
			argv[4] = "1";
			Assert::AreEqual(0, unitest(argc, argv));
		}
		TEST_METHOD(TestMethod_m2)
		{
			int argc = 5;
			char* argv[10];
			argv[1] = "-n";
			argv[2] = "20";
			argv[3] = "-m";
			argv[4] = "1";
			Assert::AreEqual(1, unitest(argc, argv));
		}
		TEST_METHOD(TestMethod_m3)
		{
			int argc = 5;
			char* argv[10];
			argv[1] = "-n";
			argv[2] = "20";
			argv[3] = "-m";
			argv[4] = "4";
			Assert::AreEqual(0, unitest(argc, argv));
		}
		TEST_METHOD(TestMethod_m4)
		{
			int argc = 5;
			char* argv[10];
			argv[1] = "-n";
			argv[2] = "30";
			argv[3] = "-m";
			argv[4] = "2";
			Assert::AreEqual(1, unitest(argc, argv));
		}
		TEST_METHOD(TestMethod_m5)
		{
			int argc = 5;
			char* argv[10];
			argv[1] = "-n";
			argv[2] = "10001";
			argv[3] = "-m";
			argv[4] = "1";
			Assert::AreEqual(0, unitest(argc, argv));
		}
		TEST_METHOD(TestMethod_m6)
		{
			int argc = 5;
			char* argv[10];
			argv[1] = "-n";
			argv[2] = "101";
			argv[3] = "-m";
			argv[4] = "3";
			Assert::AreEqual(1, unitest(argc, argv));
		}
		TEST_METHOD(TestMethod_r1)
		{
			int argc = 5;
			char* argv[10];
			argv[1] = "-n";
			argv[2] = "10";
			argv[3] = "-r";
			argv[4] = "18~20";
			Assert::AreEqual(0, unitest(argc, argv));
		}
		TEST_METHOD(TestMethod_r2)
		{
			int argc = 5;
			char* argv[10];
			argv[1] = "-n";
			argv[2] = "10";
			argv[3] = "-r";
			argv[4] = "55~57";
			Assert::AreEqual(0, unitest(argc, argv));
		}
		TEST_METHOD(TestMethod_r3)
		{
			int argc = 5;
			char* argv[10];
			argv[1] = "-n";
			argv[2] = "10";
			argv[3] = "-r";
			argv[4] = "30~50";
			Assert::AreEqual(1, unitest(argc, argv));
		}
		TEST_METHOD(TestMethod_r4)
		{
			int argc = 5;
			char* argv[10];
			argv[1] = "-n";
			argv[2] = "10";
			argv[3] = "-r";
			argv[4] = "16~70";
			Assert::AreEqual(0, unitest(argc, argv));
		}
		TEST_METHOD(TestMethod_u1)
		{
			int argc = 4;
			char* argv[10];
			argv[1] = "-n";
			argv[2] = "10";
			argv[3] = "-u";
			Assert::AreEqual(1, unitest(argc, argv));
		}
		TEST_METHOD(TestMethod_u2)
		{
			int argc = 4;
			char* argv[10];
			argv[1] = "-n";
			argv[2] = "0";
			argv[3] = "-u";
			Assert::AreEqual(0, unitest(argc, argv));
		}
	};
}
