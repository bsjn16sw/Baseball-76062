#include <stdexcept>
using namespace std;

class Baseball {
public:
	void guess(const string& guessNumber) {
		if (guessNumber.length() != 3) {
			throw length_error("Input must be three letters.");
		}
		for (char c : guessNumber) {
			if (c < '0' || c > '9') {
				throw invalid_argument("Input must be number.");
			}
		}
		if (guessNumber[0] == guessNumber[1]
			|| guessNumber[1] == guessNumber[2]
			|| guessNumber[2] == guessNumber[0]) {
			throw invalid_argument("Input must not contain same number.");
		}
	}
};