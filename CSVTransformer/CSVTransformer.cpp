// CSVTransformer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[])
{
	if (argc < 3) {
		cout << "Expected IN OUT\n";
		return 1;
	}

	vector<char> data;
	{
		ifstream in(argv[1]);
		if (!in) {
			cout << "File open failed...\n";
			return 1;
		}
		auto it = std::back_inserter(data);
		int x;
		while (in >> x) {
			*it++ = (char)x;
		}
	}

	// convert data to raw bytes
	ofstream out(argv[2], ios_base::binary);
	if (!out) {
		cout << "Output file open failed...\n";
		return 1;
	}
	out.write(data.data(), data.size());
}
