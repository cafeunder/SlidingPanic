#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "Util.h"

vector<string> SeparateString(string str, const char delimiter) {
	vector<string> record(0);

	string item;
	istringstream separater(str);
	while (!separater.eof()) {
		getline(separater, item, delimiter);
		record.push_back(item);
	}

	return record;
}
