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
