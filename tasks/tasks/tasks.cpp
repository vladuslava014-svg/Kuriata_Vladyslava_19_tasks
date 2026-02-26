#include <iostream>
#include <chrono>
#include <future>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <iomanip>

using namespace std;
using namespace chrono;

void printArray(int* arr, int n)
{
	int limit = (n > 20) ? 20 : n;
	for (int i = 0; i < limit; i++)
		cout << arr[i] << " ";
	if (n > 20) cout << "...";
	cout << endl;
}

void generateArray(int* arr, int n)
{
	for (int i = 0; i < n; i++)
		arr[i] = rand() % 10000;
}

void copyArray(int* source, int* dest, int n)
{
	for (int i = 0; i < n; i++)
		dest[i] = source[i];
}

void bubbleSort(int* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
}

void insertionSort(int* arr, int n)
{
	for (int i = 1; i < n; i++)
	{
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

int partition(int* arr, int low, int high)
{
	int pivot = arr[high];
	int i = low - 1;

	for (int j = low; j < high; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}

	swap(arr[i + 1], arr[high]);
	return i + 1;
}

void quickSort(int* arr, int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

long long measureSync(void(*func)(int*, int), int* arr, int n)
{
	auto start = high_resolution_clock::now();
	func(arr, n);
	auto stop = high_resolution_clock::now();
	return duration_cast<microseconds>(stop - start).count();
}

long long measureAsync(void(*func)(int*, int), int* arr, int n)
{
	auto start = high_resolution_clock::now();
	auto fut = async(launch::async, func, arr, n);
	fut.get();
	auto stop = high_resolution_clock::now();
	return duration_cast<microseconds>(stop - start).count();
}

int binarySearch(int* arr, int n, int key)
{
	int left = 0;
	int right = n - 1;

	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (arr[mid] == key)
			return mid;
		else if (arr[mid] < key)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return -1;
}

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	srand((unsigned int)time(0));

	int sizes[6] = { 10, 50, 800, 5000, 40000, 120000 };
	const int runs = 3;

	cout << "\n+----------+-----------+-----------+-----------------------+" << endl;
	cout << "|    N     |  Bubble   | Insertion |      Quick Sort       |" << endl;
	cout << "|          |  (sync)   |  (sync)   |   Sync   |   Async    |" << endl;
	cout << "+----------+-----------+-----------+----------+------------+" << endl;

	for (int s = 0; s < 6; s++)
	{
		int n = sizes[s];
		long long bS = 0, bA = 0, iS = 0, iA = 0, qS = 0, qA = 0;

		for (int r = 0; r < runs; r++)
		{
			int* original = new int[n];
			generateArray(original, n);

			if (n <= 5000)
			{
				int* a1 = new int[n];
				copyArray(original, a1, n);
				int* a2 = new int[n];
				copyArray(original, a2, n);
				bS += measureSync(bubbleSort, a1, n);
				bA += measureAsync(bubbleSort, a2, n);
				delete[] a1; delete[] a2;

				int* a3 = new int[n];
				copyArray(original, a3, n);
				int* a4 = new int[n];
				copyArray(original, a4, n);
				iS += measureSync(insertionSort, a3, n);
				iA += measureAsync(insertionSort, a4, n);
				delete[] a3; delete[] a4;
			}

			int* a5 = new int[n];
			copyArray(original, a5, n);
			int* a6 = new int[n];
			copyArray(original, a6, n);
			qS += measureSync([](int* arr, int n) { quickSort(arr, 0, n - 1); }, a5, n);
			qA += measureAsync([](int* arr, int n) { quickSort(arr, 0, n - 1); }, a6, n);
			delete[] a5; delete[] a6;
			delete[] original;
		}

		cout << "| " << left << setw(8) << n << " | ";
		if (n <= 5000) {
			cout << setw(9) << bS / runs << " | " << setw(9) << iS / runs << " | ";
		}
		else {
			cout << setw(9) << "---" << " | " << setw(9) << "---" << " | ";
		}
		cout << setw(8) << qS / runs << " | " << setw(10) << qA / runs << " |" << endl;

	}
	cout << "+----------+-----------+-----------+----------+------------+" << endl;

	int search_n = 50;
	int* search_arr = new int[search_n];
	generateArray(search_arr, search_n);

	cout << "\nПочатковий масив:\n";
	printArray(search_arr, search_n);

	quickSort(search_arr, 0, search_n - 1);

	cout << "\nВідсортований масив:\n";
	printArray(search_arr, search_n);

	int key;
	cout << "\n>>> Введіть число для пошуку: ";
	cin >> key;

	int pos = binarySearch(search_arr, search_n, key);
	if (pos != -1)
		cout << "Елемент знайдено на позиції: " << pos << endl;
	else
		cout << "Елемент не знайдено\n";

	delete[] search_arr;
	return 0;
}