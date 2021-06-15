#include "PrefixStack.h"
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
void timeArrayBasedStack();
void timeListBasedStack();
template <typename T>
void pushAndPop(stack<int, T>);
template <typename Func>
long long TimeFunc(Func f);

const int OPERATIONS = 10000000;


int main() {
	evaluatePrefixExpression();
	testStackSpeeds();
}

void evaluatePrefixExpression() {
	PrefixStack stack;
	cout << stack.evaluate("-7+2*69") << endl;
}

void testStackSpeeds() {
	cout << endl << "Performing Stack Speed Test..." << endl;
	long long arrayStackSpeed = TimeFunc(timeArrayBasedStack);
	long long listStackSpeed = TimeFunc(timeListBasedStack);
	cout << "Stack Speed Test Results on " << OPERATIONS << " Operations:" << endl;
	cout << "Array Based Stack: " << arrayStackSpeed << " ms" << endl;
	cout << "Linked List Based Stack: " << listStackSpeed << " ms" << endl;
}

void timeArrayBasedStack() {
	stack<int, vector<int> > stack;
	pushAndPop(stack);
}

void timeListBasedStack() {
	stack<int, list<int> > stack;
	pushAndPop(stack);
}

template <typename T>
void pushAndPop(stack<int, T> stack) {
	for (int i = 0; i < OPERATIONS; i++) {
		stack.push(i);
	}
	for (int i = 0; i < OPERATIONS; i++) {
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
