#pragma once
#include<iostream>
using namespace std;

template<class T>
class ArrayList {
private:
	T* list;
	int curr;
	int size;

public:
	//constructors
	ArrayList() :list(NULL), curr(-1), size(0) {
	}

	ArrayList(int s) {
		if (s > 0) {
			list = new T[s];
			curr = -1;
			size = s;
		}
	}

	//Getters
	int getSize() const {
		return size;
	}

	int getTotalElements() const {
		return curr + 1;
	}

	double getElement(int index) {
		if (list != NULL) {
			return list[index];
		}
	}

	//Main functions
	bool insertAtEnd(const T& d) {
		if (list != NULL) {
			if (curr < size - 1) {
				curr++;
				list[curr] = d;
				return true;
			}

			else {
				size *= 2;
				T* ptr = new T[size];

				for (int i = 0; i <= curr; i++) {
					ptr[i] = list[i];
				}

				delete[] list;
				list = new T[size];

				for (int i = 0; i <= curr; i++) {
					list[i] = ptr[i];
				}

				curr++;
				list[curr] = d;
			}
		}
		return false;
	}

	void insertAtGivenPosition(const T& num, int index) {
		if (index >= 0 && index <= curr && curr < size - 1) {
			for (int i = curr; i >= index; i--) {
				list[i + 1] = list[i];
			}
			list[index] = num;
			curr++;
		}
	}

	void remove(const T& d) {
		for (int i = 0; i <= curr; i++) {
			if (list[i] == d) {
				for (int j = i; j <= curr; j++) {
					list[j] = list[j + 1];
				}
				curr--;
			}
		}
	}

	void printTheList() {
		for (int i = 0; i <= curr; i++) {
			cout << list[i] << " ";
		}
		cout << endl;
	}

	bool isEmpty() {
		if (curr == -1) {
			return true;
		}
		return false;
	}

	bool replace(const T& num, const T& replaceWith) {
		for (int i = 0; i <= curr; i++) {
			if (list[i] == replaceWith) {
				list[i] = num;
				return true;
			}
		}
		return false;
	}

	void clearTheList() {
		delete[] list;
		curr = -1;
		size = 0;
	}

	void sort() {
		T temp;
		int j;
		for (int i = 1; i <= curr; i++) {
			temp = list[i];

			for (j = i; j >= 0 && temp < list[j - 1]; j--) {
				list[j] = list[j - 1];
			}
			list[j] = temp;
		}
	}

	int search(const T& num) {
		for (int i = 0; i <= curr; i++) {
			if (list[i] == num) {
				return i;
			}
		}

		return -1;
	}

	bool duplicate() {
		T temp;
		for (int i = 0; i <= curr; i++) {
			temp = list[i];
			for (int j = 0; j <= curr; j++) {
				if (i != j && list[j] == temp) {
					return true;
				}
			}
		}
		return false;
	}
};

