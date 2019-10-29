// Vector.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include "MyVector.h"

using namespace std;
int main()
{
	MyVector<double> v1(5);
	
	cin >> v1;
    cout << v1 << endl;
	MyVector<double> v2;
	cin >> v2;
	cout << v2 << endl;
	MyVector<double> v3(v1 + v2);
	cout << v3 << endl;
	cout << v1 * v2 << endl;
	MyVector<double> v4(v1 / 3);
	cout << v4 << endl;
	MyVector<double> v5(v1 - 2), v6;
	cout << v5 << endl;
	v4.delElement(3);	
	cout << v4 << endl;	
	v6=v1+v2;
	cout << (v1 == v6) << endl;
	cout << v6 << endl;
}
