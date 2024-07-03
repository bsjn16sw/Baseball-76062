#include "pch.h"
#include "../Project36/baseball.cpp"

class BaseballFixture : public testing::Test {
public:
	Baseball game;
	void assertIllegalArgument(string guessNumber) {
		try {
			game.guess(guessNumber);
			FAIL();
		}
		catch (exception e) {
			// PASS
		}
	}
};

TEST_F(BaseballFixture, ThrowExcptInvalidInput) {
	assertIllegalArgument("12");
	assertIllegalArgument("12s");
	assertIllegalArgument("121");
}
