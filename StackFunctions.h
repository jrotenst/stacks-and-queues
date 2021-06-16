#pragma once
#include <stack>
#include <vector>
#include <iostream>

template <class T>
class StackFunctions {
	private:
		stack<T> stack;

	public:
		void addElements(vector<T> vector) {
			for (int i = 0; i < vector.size(); i++) {
				stack.push(vector[i]);
			}
		}

		void printElements() {
			std::stack<T> temp;
			while (!stack.empty()) {
				cout << stack.top() << endl;
				temp.push(stack.top());
				stack.pop();
			}
			
			while (!temp.empty()) {
				stack.push(temp.top());
				temp.pop();
			}
		}

		// changes the value of element based on index,
		// starting from the top of the stack.
		void changeElement(T val, int index) {
			int count = 0;
			bool changed = false;
			std::stack<T> temp;
			while (!stack.empty() && !changed) {
				if (count == index) {
					stack.pop();
					stack.push(val);
					changed = true;
				}
				else {
					temp.push(stack.top());
					stack.pop();
				}
				count++;
			}
			
			while (!temp.empty()) {
				stack.push(temp.top());
				temp.pop();
			}
		}
};

