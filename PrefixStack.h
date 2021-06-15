#pragma once
#include <stack>
#include <string>
#include <iostream>

using std::stack;
using std::string;
using namespace std;

class PrefixStack {

	private:
		stack<double> stack;

		bool isOperand(char c) {
			return isdigit(c);
		}
	
	public:
		double evaluate(string exp) {

			double result;

			for (int i = exp.size() - 1; i >= 0; i--) {

				// subtract 0 to convert to int
				if (isOperand(exp[i])) {
					stack.push(exp[i] - '0');
				}
				else {
					double op1 = stack.top();
					stack.pop();
					double op2 = stack.top();
					stack.pop();

					switch (exp[i]) {
					case '+':
						stack.push(op1 + op2);
						break;
					case '-':
						stack.push(op1 - op2);
						break;
					case '*':
						stack.push(op1 * op2);
						break;
					case '/':
						stack.push(op1 / op2);
						break;
					}
				}
			}
			result = stack.top();
			stack.pop();
			return result;
		}
};

