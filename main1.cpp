#include "functions1.h"

int main()
{
    string s1, s2;
	int min_distance;
	setlocale(LC_ALL, "rus");
	cout << "Введите 2 строки:" << endl;
    cin >> s1 >> s2;
    min_distance = levenshtein(s1, s2);
	cout << "Редакционное расстояние = " << min_distance << endl;
    return 0;
}