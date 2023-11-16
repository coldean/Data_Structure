//À¯Áö¼º 2019203102

#include <stdlib.h>
#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	unordered_map<string, int> umap;

	string str, subStr;
	int num;

	string maxStr;
	int max = 1;

	cin >> num >> str;

	if (num < 3 || 30 < num) {
		cout << "Error! password length : out of range\n";
		exit(-1);
	}

	for (int i = 0; i <= str.length() - num; i++) {
		subStr = str.substr(i, num);

		auto item = umap.find(subStr);
		if (umap.find(subStr) == umap.end()) {
			umap[subStr] = 1;
		}
		else {
			item->second = item->second + 1;
			if (item->second > max) {
				max = item->second;
				maxStr = item->first;
			}
		}
	}

	cout << maxStr << endl;
	return 0;
}