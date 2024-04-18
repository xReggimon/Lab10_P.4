
#include <iostream>

using namespace std;

bool isCardValid(int digits[], int size);

int main() {

	int digits[8];

	while (true) {
		char input[10];
		cout << "Enter 8-digit credit card # or Q to quit: ";
		cin.getline(input, 10);

		if (input[0] == 'Q' || input[0] == 'q') {
			break;
		}

		int value = atoi(input);

		if (value < 0 || value > 99999999999) {
			cout << "invalid input."; continue;
		}
		for (int i = 7; i >= 0; i--) {
			digits[i] = value % 10;
			value /= 10;
		}

		if (isCardValid(digits, 8)) {
			cout << "Card is valid. " << endl;
		}
		else {
			cout << "Card is not valid" << endl;
		}
	}
	return 0;
}

bool isCardValid(int digits[], int size) {
	int sum1 = 0;
	int sum2 = 0;
	bool is_even = false;

	for (int i = size - 1; i >= 0; i--) {
		int digit = digits[i];

		if (is_even) {
			digit *= 2;
			if (digit >= 10) {
				digit = digit / 10 + digit % 10;
			}
			sum2 += digit;
		}
		else {
			sum1 += digit;
		}

		is_even = !is_even;
	}
	return(sum1 + sum2) % 10 == 0;
}