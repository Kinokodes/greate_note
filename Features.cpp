#include "Features.h"

using namespace std;

vector <int> FindWord(string text, string word) {
	vector <int> result;
	for (int i = 0; i < text.length(); i++) {
		for (int j = 0, k = 0; j < word.length(); j++) {
			if (text[i + k] != word[j]) { break; }
			else {
				if (k == word.length() - 1) result.push_back(i);
				k++;
			}
		}
	}
	if (result.empty()) {
		result.push_back(-1);
	}
	return result;
	
}

int CheckBracket(string text) {
	int balance = 0;
	int coord = -1;
	
	for (int c = 0; c < text.length(); c++) {
		if (text[c] == '(') {
			balance++; 
			coord = c;
		}
		if (text[c] == ')') { 
			balance--;
			if (balance < 0) {
				return c;
			}
		}
	}
	if (balance == 0) {
		return -1;
	}
	else {
		return coord;
	}
	
}

bool IsOperation(char ch) {
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '>' || ch == '>' || ch == '=') {
		return true;
	}
	return false;
}

string GetSpace(string& text) {
	for (int i = 0; i < text.length(); i++) {
		bool isOperation = IsOperation(text[i]);
		
		if (isOperation == true) {
			if (i != text.length() - 1) {
				bool nextIsOper = IsOperation(text[i + 1]);
				if (!nextIsOper) {
					text.insert(i + 1, " ");
				}
			}
			if (i != 0) {
				bool prevIsOper = IsOperation(text[i - 1]);
				bool nextIsOper = IsOperation(text[i + 1]);
				if (prevIsOper == false && nextIsOper == false) {
					text.insert(i, " ");
					i++;
				}
			}
		}
	}
	return text;
}
