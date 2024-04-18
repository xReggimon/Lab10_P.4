
#include <iostream>

using namespace std;

int main() {


	int value;

	cout << "Please enter 8-digit card number or Q to quit: ";
	cin >> value;

	if (value < 0  ) {
		return 1;
	}
	int sum1 = 0;
	int sum2 = 0;
	int digit;
	int new_value = value;

	bool is_even = false;

		for (int i = 0; i < 8; ++i) {
			digit = new_value % 10;
			new_value /= 10;

			if (i % 2 == 0) {

				if (digit >= 10) {
					digit = digit / 10 + digit % 10;

				}
				sum1 += digit;
			}
		} new_value = value;
		for (int i = 0; i < 8; ++i) {
			digit = new_value % 10;
			new_value /= 10;

			if (i % 2 != 0) {
				digit *= 2;

				if (digit >= 10) {
					digit = digit / 10 + digit % 10;

				}
				sum2 += ((2 * digit) % 10) + ((2 * digit) % 100) / 10;
			}
		}
		cout << endl;

		cout <<"Sum of every other digit from the right: " << sum1 << endl; 
		cout <<"Every other number doubled and each placeholder added: " << sum2 << endl;

		// Check if sum is divisible by 10 to be valid
		if ((sum1 + sum2) % 10 == 0) {
			cout << "Card is valid." << endl;
		}
		else {
			cout << "Card is not valid." << endl;
	}
		return 0;

}