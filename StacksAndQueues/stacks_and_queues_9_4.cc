#include <iostream>
#include <vector>
using namespace std;

string get_shortest_path(const string& path) {
	vector<string> track_paths;
	for(int i = 0; i < path.length();) {
		int next_index = path.find('/', i);
		string subs = "";
		if(next_index != string::npos) {
			subs = path.substr(i, next_index - i);
		} else {
			subs = path.substr(i, path.length() - i);
			next_index = path.length();
		}
		if(subs.compare("..") == 0) {
			track_paths.pop_back();
		} else if(subs.length() > 0 && subs.compare(".") != 0) {
			track_paths.push_back(subs);
		}
		i = next_index + 1;
	}
	string result = "";
	for(auto &s : track_paths) {
		result += "/";
		result += s;
	}
	return result;
}

int main() {
	// your code goes here
	string s;
	cin >> s;
	cout << get_shortest_path(s);
	return 0;
}
