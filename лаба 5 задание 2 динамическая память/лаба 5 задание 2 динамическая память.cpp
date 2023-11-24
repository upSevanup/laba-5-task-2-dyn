#include <iostream>
#include <clocale>

using namespace std;

/*
* Лабораторная работа 5. Поливцев Михаил, ИВТ-31. Задание 2 (с динамическим выделением памяти).
* Индивидуальный вариант 16.
* Дан массив размера N. Обнулить элементы массива, расположенные между его
* минимальным и максимальным элементами (не включая минимальный и максимальный элементы).
*/

int main() {
	setlocale(LC_ALL, "ru");

	int n, max_i = 0, min_i = 0, m1, m2;
	cout << "Введите размер массива >> ";
	cin >> n;
	if (n < 1) {
		cout << "неверный ввод";
		return 1;
	}
	int* lst;
	lst = new int[n];	
	for (int i = 0; i < n; i++) {
		cout << "Введите элемент массива >> ";
		cin >> lst[i];
	}

	for (int i = 0; i < n; i++) {
		if (lst[i] < lst[min_i]) {
			min_i = i;
		}
		if (lst[i] > lst[max_i]) {
			max_i = i;
		}
	}

	if (max_i > min_i) {
		m1 = min_i + 1;
		m2 = max_i;
	}
	else {
		m1 = max_i + 1;
		m2 = min_i;
	}

	for (int i = m1; i < m2; i++) {
		lst[i] = 0;
	}

	for (int i = 0; i < n; i++) {
		cout << lst[i] << " ";
	}
	delete[] lst;
}