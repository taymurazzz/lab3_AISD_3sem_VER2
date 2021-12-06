#include "pch.h"
#include "CppUnitTest.h"
#include "../lab3_ver2/Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(contains)
		{
			tree a;
			a.insert(1);
			a.insert(2);
			a.insert(3);
			a.insert(4);
			Assert::IsTrue(a.contains(4));
		}
		TEST_METHOD(insert)
		{
			tree a;
			a.insert(1);
			a.insert(2);
			a.insert(3);
			a.insert(4);
			Assert::IsTrue(a.head->l->key == 2);
		}
		TEST_METHOD(remove)
		{
			tree a;
			a.insert(1);
			a.insert(2);
			a.insert(3);
			a.insert(4);
			a.remove(2);
			Assert::IsTrue(a.head->l->key == 4);
		}
		TEST_METHOD(Shirina)
		{
			tree a;
			a.insert(1);
			a.insert(2);
			a.insert(3);
			a.insert(4);
			int i = 1;

			iteratorS* a_iteratorS = a.create_iteratorS();
			while (a_iteratorS->has_next()) {
				Assert::IsTrue(a_iteratorS->next() == i);
				i++;
			}
		}
		TEST_METHOD(Glubina)
		{
			tree a;
			a.insert(1);
			a.insert(2);
			a.insert(3);
			a.insert(4);
			int arr[4];
			arr[0] = 1;
			arr[1] = 2;
			arr[2] = 4;
			arr[3] = 3;
			int j = 0;

			iteratorG* a_iteratorG = a.create_iteratorG();
			int ii = 1;
			while (ii <= a.size) {
				Assert::IsTrue(a_iteratorG->Next() == arr[j]);
				j++;
				ii++;
			}
		}
	};
}
