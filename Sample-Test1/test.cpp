#include "pch.h"
#include "../Project36/baseball.cpp"

TEST(BaseballGame, ThrowExcptInputhLenUnmatched) {
	Baseball game;
	EXPECT_THROW(game.guess(string("12")), length_error);
}

TEST(BaseballGame, ThrowExcptInputhInvalidChar) {
	Baseball game;
	EXPECT_THROW(game.guess(string("12s")), invalid_argument);
}