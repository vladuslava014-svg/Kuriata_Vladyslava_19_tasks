#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <Windows.h>

using namespace std;

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int k;
    cout << "Введіть число k (мінімальна кількість слів у реченні): ";
    cin >> k;
    cin.ignore(); 

    ifstream inputFile("input.txt"); 
    ofstream outputFile("output.txt");

    if (!inputFile.is_open()) {
        cout << "Помилка: не вдалося відкрити вхідний файл!" << endl;
        return 1;
    }

    string sentence;
    int countProcessed = 0;

    while (getline(inputFile, sentence)) {
        if (sentence.empty()) continue; 

        int wordCount = 0;
        stringstream ss(sentence);
        string word;

        while (ss >> word) {
            wordCount++;
        }

        if (wordCount >= k) {
            outputFile << sentence << endl;
            countProcessed++;
        }
    }

    cout << "Обробку завершено. Знайдено речень: " << countProcessed << endl;
    cout << "Результати збережено в output.txt" << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
