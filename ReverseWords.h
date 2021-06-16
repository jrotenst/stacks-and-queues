#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class ReverseWords {

	private:
		const string FILE_NAME = "ChuckNorrisJokes.txt";

		void reverseWords(string line) {
			stack<char> stack;
			for (int i = 0; i < line.length(); i++) {
				if (line[i] != ' ') {
					stack.push(line[i]);
				}
				else {
					printWord(stack);
				}
			}
			printWord(stack);
			cout << endl;
		}

		void printWord(stack<char>& stack) {
			while (!stack.empty()) {
				cout << stack.top();
				stack.pop();
			}
			cout << " ";
		}

		vector<string> readFile() {
			string line;
			vector<string> lines;
			ifstream file(FILE_NAME);
			if (file.is_open()) {
				while (getline(file, line)) {
					lines.push_back(line);
				}
				file.close();
			}
			else {
				cout << "Unable to open file";
			}
			return lines;
		}

	public:
		void reverseWordsInFile() {
			vector<string> lines = readFile();
			for (int i = 0; i < lines.size(); i++) {
				reverseWords(lines[i]);
			}
		}
};
