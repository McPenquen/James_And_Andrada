// Copyright (C) 2024 James And Andrada - All Rights Reserved. You may use, distribute and modify this code with the permision of James And Andrada group.


#include "GameManager.h"

void UGameManager::NewGame()
{
	MaxNumberOfPaintings = 5;
	NumberOfPaintings = 0;
}

void UGameManager::GameOver()
{
	// TODO GAME OVER
}

void UGameManager::Victory(float TimeScore)
{
	FGameScore NewScore;
	NewScore.TimeScore = TimeScore;
	NewScore.MaxTreasureAmount = MaxNumberOfPaintings;
	NewScore.CurrentTreasureAmount = NumberOfPaintings;
	Scores.Add(NewScore);
}
