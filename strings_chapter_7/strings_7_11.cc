#include <iostream>
using namespace std;

void append_chars(const string& source, string& dest, int start, int increment) {
	for(int i = start; i < source.length(); i += increment) {
		dest += source[i];
	}
}

string sinusoidal(const string& s) {
	string result = "";
	append_chars(s, result, 1, 4);
	append_chars(s, result, 0, 2);
	append_chars(s, result, 3, 4);
	return result;
}

int main() {
	// your code goes here
	string s;
	cin >> s;
	cout << sinusoidal(s);
	return 0;
}
