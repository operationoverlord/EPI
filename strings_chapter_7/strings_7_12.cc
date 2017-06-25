#include <iostream>
#include <string>
using namespace std;

int get_next_index(const string& s, int start) {
	int result = start;
	for(;result < s.length() && s[result] == s[start]; ++result)
		;
	return result;
}

string encode(const string& s) {
	string result = "";
	for(int i = 0; i < s.length();) {
		char current_char = s[i];
		int count = 0;
		int next_index = get_next_index(s, i);
		count = next_index - i;
		i = next_index;
		result += to_string(count);
		result += current_char;
	}
	return result;
}


int get_next_alphabet_index(const string& s, int start) {
	int result = start;
	for(; result < s.length() && !isalpha(s[result]); ++result)
	;
	return result;
}

string decode(const string& s) {
	string result = "";
	for(int i = 0; i < s.length();) {
		int next_index = get_next_alphabet_index(s, i);
		string n = s.substr(i, next_index - i);
		int count = stoi(n);
		result += string(count, s[next_index]);
		i = next_index + 1;
	}
	return result;
}

int main() {
	// your code goes here
	string s;
	cin >> s;
	cout << decode(encode(s));
	return 0;
}
