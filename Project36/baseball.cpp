#include <stdexcept>
using namespace std;

class Baseball {
public:
	void guess(const string& guessNumber) {
		assertIllegalArgument(guessNumber);
	}
	void assertIllegalArgument(const std::string& guessNumber)
	{
		if (guessNumber.length() != 3) {
			throw length_error("Input must be three letters.");
		}
		for (char c : guessNumber) {
			if (c >= '0' && c <= '9') continue;
			throw invalid_argument("Input must be number.");
		}
		if (hasSameNumber(guessNumber)) {
			throw invalid_argument("Input must not contain same number.");
		}
	}
	bool hasSameNumber(const std::string& guessNumber)
	{
		return guessNumber[0] == guessNumber[1]
			|| guessNumber[1] == guessNumber[2]
			|| guessNumber[2] == guessNumber[0];
	}
};