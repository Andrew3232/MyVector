#pragma once
#include <iostream>
#include <string>

using namespace std;

template <typename T>
class MyVector
{
private:
	T *Data;
	int VectorSize;
public: 
	//constructors
	//MyVector() { Data = nullptr; VectorSize = 0; cout << "\nConstruct Def ptr = " << Data; };
	MyVector(int NewSize=5) { 
		Data = new T[NewSize]; 
		if(Data == nullptr) 
			exception; 
		VectorSize = NewSize; 
		for (int i = 0; i < VectorSize; i++)
			Data[i] = 0;
	};
	MyVector(MyVector<T>& v) = delete;
	MyVector(MyVector<T>&& v);

	//methods
	int GetVectorSize();
	void SetVectorSize(int);

	
	int addElement(T);
	int delElement(int);

	//operators
	// vector with vector
	friend MyVector operator+(MyVector<T>& v1, MyVector<T>& v2) {
		//if (V.VectorSize == 0)
			//throw new CError("VectorSize = 0", 1, "operator+ ", "MyVector");
		//if (v1.VectorSize != v2.VectorSize)
			//throw new CError("VectorSize1 != VectorSize2", 2, "operator+ ", "CVector");
		MyVector<T> v3(v1.VectorSize);
		for (int i = 0; i < v1.VectorSize; i++)
			v3.Data[i] = v1.Data[i] + v2.Data[i];
		return v3;
	}
	friend MyVector operator-(MyVector<T>& v1, MyVector<T>& v2) {
		//if (V.VectorSize == 0)
			//throw new CError("VectorSize = 0", 1, "operator+ ", "MyVector");
		//if (v1.VectorSize != v2.VectorSize)
			//throw new CError("VectorSize1 != VectorSize2", 2, "operator+ ", "CVector");
		MyVector<T> v3(v1.GetVectorSize());
		for (int i = 0; i < v1.VectorSize; i++)
			v3.Data[i] = v1.Data[i] - v2.Data[i];
		return v3;
	}
	friend T operator*(MyVector<T>& v1, MyVector<T>& v2) { //scalar
		//if (V.VectorSize == 0)
			//throw new CError("VectorSize = 0", 1, "operator+ ", "MyVector");
		//if (v1.VectorSize != v2.VectorSize)
			//throw new CError("VectorSize1 != VectorSize2", 2, "operator+ ", "CVector");
		T res = 0;
		for (int i = 0; i < v1.VectorSize; i++)
			res += (v1.Data[i] * v2.Data[i]);
		return res;
	}
	//other
	friend MyVector operator/(MyVector<T>& v1, T b) {
		//if (V.VectorSize == 0)
			//throw new CError("VectorSize = 0", 1, "operator+ ", "MyVector");
		//if (v1.VectorSize != v2.VectorSize)
			//throw new CError("VectorSize1 != VectorSize2", 2, "operator+ ", "CVector");
		MyVector<T> v3(v1.GetVectorSize());
		for (int i = 0; i < v1.VectorSize; i++)
			v3.Data[i] = v1.Data[i] / b;
		return v3;
	}
	friend MyVector operator+(MyVector<T>& v1, T b) {	//add element b
		//if (V.VectorSize == 0)
			//throw new CError("VectorSize = 0", 1, "operator+ ", "MyVector");
		//if (v1.VectorSize != v2.VectorSize)
			//throw new CError("VectorSize1 != VectorSize2", 2, "operator+ ", "CVector");
		MyVector<T> v3(v1.GetVectorSize());
		for (int i = 0; i < v1.VectorSize; i++)
			v3.Data[i] = v1.Data[i] + b;
		return v3;
	}
	friend MyVector operator+(T b, MyVector<T>& v1) {	//add element b
		//if (V.VectorSize == 0)
			//throw new CError("VectorSize = 0", 1, "operator+ ", "MyVector");
		//if (v1.VectorSize != v2.VectorSize)
			//throw new CError("VectorSize1 != VectorSize2", 2, "operator+ ", "CVector");
		MyVector<T> v3(v1.GetVectorSize());
		for (int i = 0; i < v1.VectorSize; i++)
			v3.Data[i] = v1.Data[i] + b;
		return v3;
	}
	friend MyVector operator-(MyVector<T>& v1, int b) {  //delete element b		
		//if (v1.VectorSize == 0)
			//throw new CError("VectorSize = 0", 1, "operator- ", "MyVector");		
		MyVector<T> v2(v1.GetVectorSize() -1);
		for (int i = 0; i < b - 1; i++)
			v2.Data[i] = v1.Data[i];		
		for (int i = b; i < v1.GetVectorSize(); i++)
			v2.Data[i-1] = v1.Data[i];
		return v2;
	}
	friend MyVector operator*(MyVector<T>& v1, T b) {	//multiply all elemets in b
		//if (V.VectorSize == 0)
			//throw new CError("VectorSize = 0", 1, "operator* ", "MyVector");
		//if (v1.VectorSize != v2.VectorSize)
			//throw new CError("VectorSize1 != VectorSize2", 2, "operator+ ", "CVector");
		MyVector<T> v3(v1.GetVectorSize());
		for (int i = 0; i < v1.VectorSize; i++)
			v3.Data[i] = v1.Data[i] * b;
		return v3;
	}
	friend MyVector operator*(T b, MyVector<T>& v1) {	//multiply all elemets in b
		//if (V.VectorSize == 0)
			//throw new CError("VectorSize = 0", 1, "operator+ ", "MyVector");
		//if (v1.VectorSize != v2.VectorSize)
			//throw new CError("VectorSize1 != VectorSize2", 2, "operator+ ", "CVector");
		MyVector<T> v3(v1.GetVectorSize());
		for (int i = 0; i < v1.VectorSize; i++)
			v3.Data[i] = b * v1.Data[i];
		return v3;
	}
	
	//void operator=(MyVector<T>&);
	//void operator==(MyVector<T>&);

	//cin & cout
	friend ostream& operator<<(ostream& stream, MyVector<T>& V) {
		//if (V.VectorSize == 0)
			//throw new CError("VectorSize = 0", 1, "operator<< ", "MyVector");
		stream << "\nVector[" << V.VectorSize << "]" << " = (";
		for (int i = 0; i < V.VectorSize; i++)
			stream << V.Data[i] << " ";
		cout << ");" << endl;
		return stream;
	}

	friend istream& operator>>(istream& stream, MyVector<T>& V) {
		//if (V.VectorSize == 0)
			//throw new CError("VectorSize = 0", 1, "operator>> ", "MyVector");
		cout << "Enter vector:" << endl;
		for (int i = 0; i < V.VectorSize; i++)
		{
			//cout << "vector[" << i + 1 << "] = ";
			stream >> V.Data[i];
		}
		//cout << endl;
		return stream;
	}

	//destructor
	virtual ~MyVector<T>() { /*cout << "\nDestroy " << Data; */ delete[]Data; VectorSize = 0; };
};

template <typename T>
MyVector<T>::MyVector(MyVector<T>&& v) {
	Data = v.Data;
	v.Data = nullptr;
	VectorSize = v.VectorSize;
	v.VectorSize = 0;
}

template <typename T>
int MyVector<T>::GetVectorSize() {
	return VectorSize;
}

template <typename T>
void MyVector<T>::SetVectorSize(int NewSize) {
	 VectorSize = NewSize;
}

template <typename T>
int MyVector<T>::addElement(T NewElement) {
	T* tmp;
	tmp = new T[VectorSize + 1];
	if (tmp == nullptr)
		return 0;
	for (int i = 0; i < VectorSize; i++)
		tmp[i] = Data[i];
	tmp[VectorSize] = NewElement;
	delete []Data;
	VectorSize++;
	Data = tmp;
	return 1;
}

template <typename T>
int MyVector<T>::delElement(int indexDelEmelent) {
	T* tmp;
	tmp = new T[VectorSize - 1];
	if (tmp == nullptr)
		return 0;
	for (int i = 0; i < indexDelEmelent-1; i++)
		tmp[i] = Data[i];
	for (int i = indexDelEmelent; i < VectorSize; i++)
		tmp[i - 1] = Data[i];
	delete []Data;
	VectorSize--;
	Data = tmp;
	return 1;
}