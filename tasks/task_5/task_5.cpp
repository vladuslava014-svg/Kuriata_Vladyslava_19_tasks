#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

struct Car {
    string brand;   
    string name;   
    double engineVol;
    double fuelCons; 
    int passengers; 
};

void addCar() {
    ofstream outFile("cars.txt", ios::app);
    Car c;

    cout << "Марка: "; cin >> c.brand;
    cout << "Модель: "; cin >> c.name;
    cout << "Об'єм двигуна: "; cin >> c.engineVol;
    cout << "Розхід палива: "; cin >> c.fuelCons;
    cout << "К-сть пасажирів: "; cin >> c.passengers;

    outFile << c.brand << " " << c.name << " " << c.engineVol << " "
        << c.fuelCons << " " << c.passengers << endl;

    outFile.close();
}

void showCars() {
    ifstream inFile("cars.txt");
    Car c;
    cout << "\nСписок всіх авто:\n";
    while (inFile >> c.brand >> c.name >> c.engineVol >> c.fuelCons >> c.passengers) {
        cout << c.brand << " " << c.name << " | " << c.fuelCons << " л/100км" << endl;
    }
    inFile.close();
}

void findMinMax() {
    ifstream inFile("cars.txt");
    Car c, minC, maxC;
    bool first = true;

    while (inFile >> c.brand >> c.name >> c.engineVol >> c.fuelCons >> c.passengers) {
        if (first) {
            minC = maxC = c;
            first = false;
        }
        else {
            if (c.fuelCons < minC.fuelCons) minC = c;
            if (c.fuelCons > maxC.fuelCons) maxC = c;
        }
    }
    inFile.close();

    if (!first) {
        cout << "\nНайекономічніше: " << minC.brand << " " << minC.name << " (" << minC.fuelCons << " л)";
        cout << "\nНайзатратніше: " << maxC.brand << " " << maxC.name << " (" << maxC.fuelCons << " л)\n";
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int menu;
    do {
        cout << "\n1. Додати авто | 2. Список | 3. Мін/Макс розхід | 0. Вихід\nВаш вибір: ";
        cin >> menu;

        if (menu == 1) addCar();
        else if (menu == 2) showCars();
        else if (menu == 3) findMinMax();

    } while (menu != 0);

    return 0;
}