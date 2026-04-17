#include <iostream>
#include <iomanip> 
#include <ctime>   
#include <Windows.h>

using namespace std;

int** createMatrix(int n) {
    int** matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }
    return matrix;
}

void fillMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 21 - 10;
        }
    }
}

void printMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand(time(0));

    int n;
    cout << "Введіть розмір квадратної матриці n: ";
    cin >> n;

    int** matrix = createMatrix(n);
    fillMatrix(matrix, n);

    cout << "\nПочаткова матриця:" << endl;
    printMatrix(matrix, n);

    int minVal = matrix[0][0];
    int minRow = 0, minCol = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j <= i && j <= (n - 1 - i)) {
                if (matrix[i][j] < minVal) {
                    minVal = matrix[i][j];
                    minRow = i;
                    minCol = j;
                }
            }
        }
    }
    cout << "\nСектор 2: Найменший елемент = " << minVal << " у позиції [" << minRow << "][" << minCol << "]" << endl;

    int maxDiag = matrix[0][0];
    for (int i = 0; i < n; i++) {
        if (matrix[i][i] > maxDiag) {
            maxDiag = matrix[i][i];
        }
    }

    int count6 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j >= i && (i + j) >= (n - 1)) {
                count6++;
                matrix[i][j] = maxDiag;
            }
        }
    }

    cout << "Сектор 6: Кількість елементів = " << count6 << endl;
    cout << "Усі елементи Сектора 6 замінено на максимум з діагоналі: " << maxDiag << endl;

    cout << "\nМатриця після виконання заміни:" << endl;
    printMatrix(matrix, n);

    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}

#include <iostream>
#include <iomanip> 
#include <ctime>   
#include <Windows.h>

using namespace std;

int** createMatrix(int n) {
    int** matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }
    return matrix;
}

void fillMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 21 - 10;
        }
    }
}

void printMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand(time(0));

    int n;
    cout << "Введіть розмір квадратної матриці n: ";
    cin >> n;

    int** matrix = createMatrix(n);
    fillMatrix(matrix, n);

    cout << "\nПочаткова матриця:" << endl;
    printMatrix(matrix, n);

    int minVal = matrix[0][0];
    int minRow = 0, minCol = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j <= i && j <= (n - 1 - i)) {
                if (matrix[i][j] < minVal) {
                    minVal = matrix[i][j];
                    minRow = i;
                    minCol = j;
                }
            }
        }
    }
    cout << "\nСектор 2: Найменший елемент = " << minVal << " у позиції [" << minRow << "][" << minCol << "]" << endl;

    int maxDiag = matrix[0][0];
    for (int i = 0; i < n; i++) {
        if (matrix[i][i] > maxDiag) {
            maxDiag = matrix[i][i];
        }
    }

    int count6 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j >= i && (i + j) >= (n - 1)) {
                count6++;
                matrix[i][j] = maxDiag;
            }
        }
    }

    cout << "Сектор 6: Кількість елементів = " << count6 << endl;
    cout << "Усі елементи Сектора 6 замінено на максимум з діагоналі: " << maxDiag << endl;

    cout << "\nМатриця після виконання заміни:" << endl;
    printMatrix(matrix, n);

    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}

