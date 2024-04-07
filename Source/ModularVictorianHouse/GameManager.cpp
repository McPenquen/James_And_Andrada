// Copyright (C) 2024 James And Andrada - All Rights Reserved. You may use, distribute and modify this code with the permision of James And Andrada group.


#include "GameManager.h"

void UGameManager::NewGame(int32 LivesNum, int32 NewMaxNumberOfPaintings)
{
	MaxNumberOfPaintings = NewMaxNumberOfPaintings;
	m_NumberOfPaintings = 0;
	m_NumberOfLives = LivesNum;
}

bool UGameManager::IsGameOver()
{
	return m_NumberOfLives <= 0;
}

void UGameManager::Victory(float TimeScore)
{
	FGameScore NewScore;
	NewScore.TimeScore = TimeScore;
	NewScore.MaxTreasureAmount = MaxNumberOfPaintings;
	NewScore.CurrentTreasureAmount = m_NumberOfPaintings;
	Scores.Add(NewScore);
}

void UGameManager::SetNewLivesNum(int32 LivesNum)
{
	m_NumberOfLives = LivesNum;
}

void UGameManager::LoseLife()
{
	m_NumberOfLives--;
	OnLifeLost.Broadcast(m_NumberOfLives);
}

void UGameManager::SetNewCollectedPaintingsNum(int32 NewPaintingNum)
{
	m_NumberOfPaintings = NewPaintingNum;
}

void UGameManager::GainPainting()
{
	m_NumberOfPaintings++;
	OnPaintingFound.Broadcast(m_NumberOfPaintings);
}

bool UGameManager::HasAllPaintings()
{
	return m_NumberOfPaintings >= MaxNumberOfPaintings;
}