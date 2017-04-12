#include <stdlib.h>
#include <vector>
#include <iostream>
using namespace std;

int findLowest(vector<int> in) {

	int min = in[0];
	int index = 0;

	for (int i = 1; i < in.size(); i++) {
		if (in[i] < min) {
			min = in[i];
			index = i;
		}
	}

	return index;
}

void printVector(vector<int> in) {
	for (int i = 0; i < in.size(); i++) {
		cout << in[i] << endl;
	}
}

vector<int> randomArray(int size) {
	vector<int> temp;
	for (int i = 0; i < size; i++) {
		temp.push_back(rand() % 100);
	}
	return temp;
}

vector<int> selectionSort(vector<int> toSort) {
	vector<int> temp;

	int size = toSort.size();

	for (int i = 0; i < size; i++) {
		int tempIndex = findLowest(toSort);
		temp.push_back(toSort[tempIndex]);
		toSort.erase(toSort.begin() + tempIndex);
	}

	return temp;
}

void main() {
	vector<int> toSort = randomArray(100);
	printVector(toSort);

	cout << endl << endl;

	vector<int> sorted = selectionSort(toSort);
	printVector(sorted);

	cin.ignore();
}