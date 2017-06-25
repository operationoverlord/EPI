#include <iostream>
#include <string>
using namespace std;

long get_hash_code(const string& s, long start, long end) {
	long result = 0;
	for(long i = start; i < end && i < s.length(); ++i) {
		result = (result * 26) % 10001;
		result += long(s[i] - 'a');
		result = result % 10001;
	}
	return result;
}

long get_power_hash(long p, long k) {
	long result = 1;
	for(long i = 0; i < k; ++i) {
		result = (result * 26) % 10001;
	}
	return result;
}

long update_hash(const string& s, long end, long p, long power_hash, long current_hash, long l) {
	long result = ((current_hash - power_hash * long(s[end - l] - 'a')) * p + long(s[end] - 'a')) % 10001;
	return result;
}

long rabin_karp(const string& s, const string& t) {
	long result = -1;
	long hs = get_hash_code(s, 0, s.length());
	long ht = get_hash_code(t, 0, s.length());
	long power_hash = get_power_hash(26, s.length() - 1);
	if(hs == ht && t.compare(0, s.length(), s) == 0) {
		result = 0;
	}
	for(long i = s.length(); i < t.length() && result < 0; ++i) {
		ht = update_hash(t, i, 26, power_hash, ht, s.length());
		if(ht == hs && t.compare(i - s.length() + 1, s.length(), s) == 0) {
			result = i - s.length() + 1;
		}
	}
	return result;
}

int main() {
	// your code goes here
	string s, t;
	cin >> s;
	cin >> t;
	cout << rabin_karp(s, t);
	return 0;
}
