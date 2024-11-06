#include <iostream>
#include <iomanip>
#include <algorithm>
#include <ctime>

using namespace std;

void Create(int a[8][7], const int rowCount, const int colCount, const int Low,
	const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}
void Print(const int a[8][7], int rowCount, int colCount) {
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            cout << setw(4) << a[i][j];
        }
        cout << endl;
    }
}
bool Criteria(int value, int row, int col) {
    return value > 0 && !(row % 2 == 0 && col % 2 == 0);
}
void ProcessMatrix(int a[8][7], int rowCount, int colCount, int& count, int& sum) {
    count = 0;
    sum = 0;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            if (Criteria(a[i][j], i, j)) {
                sum += a[i][j];
                count++;
                a[i][j] = 0;  // Заміна на нуль
            }
        }
    }
}
bool CompareRows(const int row1[7], const int row2[7]) {
    if (row1[0] != row2[0]) {
        return row1[0] > row2[0]; // Спадання за першим стовпчиком
    }
    else if (row1[1] != row2[1]) {
        return row1[1] > row2[1]; // Спадання за другим стовпчиком
    }
    else {
        return row1[2] < row2[2]; // Зростання за третім стовпчиком
    }
}
void SortMatrix(int a[8][7], int rowCount, int colCount) {
    for (int i = 0; i < rowCount - 1; i++) {
        for (int j = i + 1; j < rowCount; j++) {
            // Використання порівняння для визначення, чи потрібно міняти рядки місцями
            if (!CompareRows(a[i], a[j])) {
                // Обмін рядками
                for (int k = 0; k < colCount; k++) {
                    int temp = a[i][k];
                    a[i][k] = a[j][k];
                    a[j][k] = temp;
                }
            }
        }
    }
}
int main() {
    srand(static_cast<unsigned>(time(0)));

    const int rowCount = 8;
    const int colCount = 7;
    const int Low = -8;
    const int High = 42;

    int a[rowCount][colCount];
    int count = 0, sum = 0;

    // Генерація матриці
    Create(a, rowCount, colCount, Low, High);
    cout << "Initial Matrix:" << endl;
    Print(a, rowCount, colCount);

    // Обробка матриці
    ProcessMatrix(a, rowCount, colCount, count, sum);
    cout << "\nMatrix after processing (elements replaced by zero):" << endl;
    Print(a, rowCount, colCount);
    cout << "Count of elements matching criteria: " << count << endl;
    cout << "Sum of elements matching criteria: " << sum << endl;

    // Сортування матриці
    SortMatrix(a, rowCount, colCount);
    cout << "\nSorted Matrix:" << endl;
    Print(a, rowCount, colCount);

    return 0;
}