#include <iostream>

long long power_with_mod(int x, int y, int p) {

	long long res = 1;

	// update x if it is larger than or equal to p
	x %= p;

	if (x == 0) return 0;

	// until y != 0
	while (y) {

		if (y & 1)
			res = (res * x) % p;

		y >>= 1;
		x = (x * x) % p;
	}
	return res % p;
}

int main() {
	std::cout << power_with_mod(2, 3, 5) << std::endl;
	std::cout << power_with_mod(2, 5, 13) << std::endl;
}