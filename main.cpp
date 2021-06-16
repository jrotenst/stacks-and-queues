#include "PrefixStack.h"
#include "StackFunctions.h"
#include <iostream>
#include <stack>
#include <list>
#include <vector>

#include <chrono>
using std::chrono::system_clock;
using std::chrono::steady_clock;
using std::chrono::duration_cast;
using std::chrono::seconds;
using std::chrono::milliseconds;

using namespace std;

void evaluatePrefixExpression();
void testStackSpeeds();
void testArrayBasedStack();
void testListBasedStack();
template <typename T>
void pushAndPop(stack<int, T> stack);
template <typename Func>
long long TimeFunc(Func f);
void testStackFunctions();

const int STACK_OPERATIONS = 10000000;

int main() {
	evaluatePrefixExpression();
	//testStackSpeeds();
	testStackFunctions();
}

void evaluatePrefixExpression() {
	PrefixStack stack;
	cout << stack.evaluate("-7+2*69") << endl;
}

void testStackSpeeds() {
	cout << endl << "Performing Stack Speed Test..." << endl;
	long long arrayStackSpeed = TimeFunc(testArrayBasedStack);
	long long listStackSpeed = TimeFunc(testListBasedStack);
	cout << "Stack Speed Test Results on " << STACK_OPERATIONS << " Operations:" << endl;
	cout << "Array Based Stack: " << arrayStackSpeed << " ms" << endl;
	cout << "Linked List Based Stack: " << listStackSpeed << " ms" << endl;
}

void testArrayBasedStack() {
	stack<int, vector<int> > stack;
	pushAndPop(stack);
}

void testListBasedStack() {
	stack<int, list<int> > stack;
	pushAndPop(stack);
}

template <typename T>
void pushAndPop(stack<int, T> stack) {
	for (int i = 0; i < STACK_OPERATIONS; i++) {
		stack.push(i);
	}
	for (int i = 0; i < STACK_OPERATIONS; i++) {
		stack.pop();
	}
}

template <typename Func>
long long TimeFunc(Func f) {
	auto begin = steady_clock::now();
	f();
	auto end = steady_clock::now();
	return duration_cast<milliseconds>(end - begin).count();
}

void testStackFunctions() {
	StackFunctions<int> stackFunctions;
	vector<int> integers;
	for (int i = 0; i < 10; i++) {
		integers.push_back(i);
	}

	cout << "Testing Stack Functions:" << endl;
	stackFunctions.addElements(integers);
	stackFunctions.printElements();
	stackFunctions.changeElement(25, 5);
	stackFunctions.printElements();
}


