// Copyright (C) 2024 James And Andrada - All Rights Reserved. You may use, distribute and modify this code with the permision of James And Andrada group.


#include "GameManager.h"

void UGameManager::GameOver()
{
	// TODO GAME OVER
}

void UGameManager::Victory(float TimeScore, int32 MaxTreasureAmount, int32 CurrentTreasureAmount)
{
	FGameScore NewScore;
	NewScore.TimeScore = TimeScore;
	NewScore.MaxTreasureAmount = MaxTreasureAmount;
	NewScore.CurrentTreasureAmount = CurrentTreasureAmount;
	Scores.Add(NewScore);
}
