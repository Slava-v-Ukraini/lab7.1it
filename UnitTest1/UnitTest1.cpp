#include "pch.h"
#include "CppUnitTest.h"
#include "../PR7.1it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MatrixTests
{
    TEST_CLASS(MatrixTests)
    {
    public:

        TEST_METHOD(TestCreateMatrix)
        {
            const int rowCount = 8;
            const int colCount = 7;
            const int Low = -8;
            const int High = 42;
            int a[rowCount][colCount];

            Create(a, rowCount, colCount, Low, High);

            // ѕерев≥рка, що вс≥ елементи знаход€тьс€ в заданому д≥апазон≥
            for (int i = 0; i < rowCount; i++) {
                for (int j = 0; j < colCount; j++) {
                    Assert::IsTrue(a[i][j] >= Low && a[i][j] <= High);
                }
            }
        }

        TEST_METHOD(TestProcessMatrix)
        {
            int a[8][7] = {
                {1, -3, 5, 7, 8, -6, 2},
                {4, -2, 3, 5, 0, -1, 6},
                {-4, 7, 1, 8, -3, 0, 5},
                {6, 2, -5, -7, 3, -2, 1},
                {8, 1, -1, -4, 0, 9, -8},
                {4, -5, 6, 2, -3, 5, -2},
                {-3, 2, 1, 8, -6, 4, 7},
                {1, -2, 3, 4, -5, 6, 0}
            };
            int count = 0, sum = 0;

            ProcessMatrix(a, 8, 7, count, sum);

            // ѕерев≥рка, що к≥льк≥сть ≥ сума правильн≥
            Assert::AreEqual(107, sum);
            Assert::AreEqual(24, count);

            // ѕерев≥рка, що потр≥бн≥ елементи зам≥нен≥ на нул≥
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 7; j++) {
                    if (Criteria(a[i][j], i, j)) {
                        Assert::AreEqual(0, a[i][j]);
                    }
                }
            }
        }

        TEST_METHOD(TestSortMatrix)
        {
            int a[8][7] = {
                {5, 2, 3, 4, 5, 6, 7},
                {3, 1, 4, 5, 6, 7, 8},
                {4, 3, 5, 6, 7, 8, 9},
                {5, 3, 1, 2, 3, 4, 5},
                {5, 2, 2, 4, 6, 7, 8},
                {3, 2, 3, 4, 5, 6, 7},
                {4, 1, 2, 3, 4, 5, 6},
                {5, 3, 4, 5, 6, 7, 8}
            };

            SortMatrix(a, 8, 7);

            // ѕерев≥рка сортуванн€ за першими трьома стовпц€ми
            for (int i = 0; i < 7; i++) {
                bool sorted = CompareRows(a[i], a[i + 1]);
                Assert::IsTrue(sorted);
            }
        }
    };
}
