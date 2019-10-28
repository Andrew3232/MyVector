#pragma once
#include <iostream>
#include <string>

using namespace std;

template <typename T>
class MyVector
{
protected:
	T *Data;
	int VectorSize;
public: 
	//constructors
	MyVector() { Data = nullptr; VectorSize = 0; cout << "\nConstruct Def ptr = " << Data; };
	MyVector(int NewSize) { Data = new T[NewSize]; if(Data == null) exception; VectorSize = NewSize; };
	MyVector(MyVector<T>& v) = delete;
	MyVector(MyVector<T>&& v);

	//methods
	int GetVectorSize(); 
	
	void addElement(T);
	void delElement(int);

	//operators
	// vector with vector
	MyVector operator+(MyVector<T>&, MyVector<T>&);
	MyVector operator-(MyVector<T>&, MyVector<T>&);
	T operator*(MyVector<T>&, MyVector<T>&); //scalar
	MyVector operator/(MyVector<T>&, MyVector<T>&);
	//other
	MyVector operator+(MyVector<T>&, T);	//add element b
	MyVector operator+(T, MyVector<T>&);	//add element b	
	MyVector operator-(MyVector<T>&, int);  //delet element b
	MyVector operator*(MyVector<T>&, T);	//multiply all elemets in b
	MyVector operator*(T, MyVector<T>&);	//multiply all elemets in b
	
	//void operator=(MyVector<T>&);
	//void operator==(MyVector<T>&);

	//cin & cout
	friend ostream& operator<<(ostream& stream, MyVector<T>& V) {
		//if (V.VectorSize == 0)
			//throw new CError("VectorSize = 0", 1, "operator<< ", "MyVector");
		stream << "\nVector[" << V.VectorSize << "] at " << V.Data << " = (";
		for (int i = 0; i < V.VectorSize; i++)
			stream << V.Data[i] << " ";
		cout << ");" << endl;
		return stream;
	}

	friend istream& operator>>(istream& stream, MyVector<T>& V) {
		//if (V.VectorSize == 0)
			//throw new CError("VectorSize = 0", 1, "operator>> ", "MyVector");
		for (int i = 0; i < V.VectorSize; i++)
		{
			cout << "vector[" << i + 1 << "] = ";
			stream >> V.Data[i];
		}
		cout << endl;
		return stream;
	}

	//destructor
	virtual ~MyVector<T>() { cout << "\nDestroy " << Data; delete[]Data; VectorSize = 0; };
};

template <typename T>
int MyVector<T>::GetVectorSize() {
	return VectorSize;
}

template <typename T>
void MyVector<T>::addElement(T NewElement) {
	T* tmp;
	tmp = new T[VectorSize + 1];
	if (tmp == null)
		return 0;
	for (int i = 0; i < VectorSize; i++)
		tmp[i] = Data[i];
	tmp[VectorSize] = NewElement;
	delete* Data;
	VectorSize++;
	Data = tmp;
}

template <typename T>
void MyVector<T>::delElement(int indexDelEmelent) {
	T* tmp;
	tmp = new T[VectorSize - 1];
	if (tmp == null)
		return 0;
	for (int i = 0; i < indexDelEmelent; i++)
		tmp[i] = Data[i];
	for (int i = indexDelEmelent + 1; i < VectorSize; i++)
		tmp[i - 1] = Data[i];
	delete* Data;
	VectorSize--;
	Data = tmp;
}