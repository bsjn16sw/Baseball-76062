#include <stdexcept>
using namespace std;

struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};

class Baseball {
public:
	explicit Baseball(const string& answer)
		: answer(answer) {

	}
	GuessResult guess(const string& guessNumber) {
		assertIllegalArgument(guessNumber);
		if (answer == guessNumber) {
			return { true, 3, 0 };
		}

		for (int i = 0; i < ANSWER_LENGTH; i++) {
			if (answer[i] == guessNumber[i]
				&& answer[(i + 1)% ANSWER_LENGTH] == guessNumber[(i + 1) % ANSWER_LENGTH]
				&& answer[(i + 2) % ANSWER_LENGTH] != guessNumber[(i + 2) % ANSWER_LENGTH]) {
				return { false, 2, 0 };
			}
		}
		return { false, 1, 2 };
	}
	void assertIllegalArgument(const std::string& guessNumber)
	{
		if (guessNumber.length() != ANSWER_LENGTH) {
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
private:
	string answer;
	const int ANSWER_LENGTH = 3;
};