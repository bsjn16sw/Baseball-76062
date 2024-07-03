#include "pch.h"
#include "../Project36/baseball.cpp"

class BaseballFixture : public testing::Test {
public:
	Baseball game{ "123" };
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

TEST_F(BaseballFixture, CorrectAnswer) {
	GuessResult result = game.guess("123");
	EXPECT_TRUE(result.solved);
	EXPECT_EQ(3, result.strikes);
	EXPECT_EQ(0, result.balls);
}

TEST_F(BaseballFixture, Strikes2Balls0Answer) {
	GuessResult result = game.guess("127");
	EXPECT_FALSE(result.solved);
	EXPECT_EQ(2, result.strikes);
	EXPECT_EQ(0, result.balls);

	result = game.guess("423");
	EXPECT_FALSE(result.solved);
	EXPECT_EQ(2, result.strikes);
	EXPECT_EQ(0, result.balls);

	result = game.guess("193");
	EXPECT_FALSE(result.solved);
	EXPECT_EQ(2, result.strikes);
	EXPECT_EQ(0, result.balls);
}

TEST_F(BaseballFixture, Strikes1Balls2Answer) {
	GuessResult result = game.guess("132");
	EXPECT_FALSE(result.solved);
	EXPECT_EQ(1, result.strikes);
	EXPECT_EQ(2, result.balls);
}
