#include <iostream>
#include "Node.h"
#include "Stack.h"
#include <string>
#include "CallCounter.h"
#include "MovingAverage.h"

bool validateChars(std::string str) {

	Stack<char> myStack;

	if (str.length() % 2 == 0) {
		for (char& c : str) {
			if (c == '(' || c == '{' || c == '[') {
				myStack.push(c);
			}
			else if (c == ')' && (myStack.isEmpty() || myStack.peek() != '(')) {
				return false;
			}
			else if (c == '}' && (myStack.isEmpty() || myStack.peek() != '{')) {
				return false;
			}
			else if (c == ']' && (myStack.isEmpty() || myStack.peek() != '[')) {
				return false;
			}
			else {
				myStack.pop();
			}

		}
	}
	else {
		return false;
	}

	return myStack.isEmpty();

}

bool compareKeyStrokes(std::string str1, std::string str2) {
	Stack<char> myStack1;

	for (char& c : str1) {
		if (c != '#') {
			myStack1.push(c);

		}
		else if (!myStack1.isEmpty()) {
			myStack1.pop();
		}
	}

	Stack<char> myStack2;

	for (char& c : str2) {
		if (c != '#') {
			myStack2.push(c);

		}
		else if (!myStack2.isEmpty()) {
			myStack2.pop();
		}
	}

	while (!myStack2.isEmpty() && !myStack1.isEmpty()) {
		if (myStack1.peek() == myStack2.peek()) {
			myStack1.pop();
			myStack2.pop();
		}
		else {
			return false;
		}
	}

	return myStack1.isEmpty() && myStack2.isEmpty();

}

std::string removeAdjacentDups(std::string str) {
	std::string newStr = "";
	Stack<char> myStack;

	
	for (int i = 0; i < str.length(); i++) {
		if (!myStack.isEmpty()) {
			if (myStack.peek() == str[str.length()-1-i]) {
				myStack.pop();
			}
			else {
				myStack.push(str[str.length() - 1 - i]);
			}
		}
		else {
			myStack.push(str[str.length() - 1 - i]);
		}
	}
		
	

	while (!myStack.isEmpty()) {
		newStr += myStack.peek();
		myStack.pop();
	}

	return newStr;

}

//Ron Carter



int main()
{
	std::string myStr = "((()))";
	std::string str1 = "cof#dim#ng";
	std::string str2 = "code";
	std::string str3 = "abccbefggfe";

	std::cout << removeAdjacentDups(str3) << " Stack\n";

	std::cout << compareKeyStrokes(str1, str2) << " Stack\n";

	std::cout << validateChars(myStr) << " Stack\n";

	CallCounter counter;
	std::cout << counter.ping(1) << "\n";
	std::cout << counter.ping(300) << "\n";
	std::cout << counter.ping(3000) << "\n";
	std::cout << counter.ping(3002) << "\n";
	std::cout << counter.ping(7000) << "\n";
	
	MovingAverage avg(3);
	std::cout << "\n" << avg.next(3) << "\n";
	std::cout <<  avg.next(5) << "\n";
	std::cout << avg.next(7) << "\n";
	std::cout << avg.next(6) << "\n";

	return 0;





}