#pragma once
#include<string>
#include<iostream>

using namespace std;

class MyError {
protected:
	int ErrorCode;
	string ErrorDescription;
	string ErrorInitObject;
	string ErrorInitMethod;
public:
	MyError() { ErrorCode = 0; };
	MyError(string Description, int Code = 0, string  Method = "Undefined", string ErrObject = "Undefined") {
		ErrorDescription = Description;
		ErrorCode = Code;
		ErrorInitMethod = Method;
		ErrorInitObject = ErrObject;
	};
	string SpellError() {
		return "\nError ocured!\n" + ErrorInitMethod + " generate error in " + ErrorInitObject + "\nErrorDescription: " + ErrorDescription;
	};
};