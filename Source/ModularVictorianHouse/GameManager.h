// Copyright (C) 2024 James And Andrada - All Rights Reserved. You may use, distribute and modify this code with the permision of James And Andrada group.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GameManager.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLifeLost, int, NewLivesNum);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPaintingFound, int, NewPaintingsNum);

USTRUCT(BlueprintType)
struct FGameScore
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float TimeScore = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 MaxTreasureAmount = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 CurrentTreasureAmount = 0;
};

UCLASS()
class MODULARVICTORIANHOUSE_API UGameManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void NewGame(int32 LivesNum, int32 NewMaxNumberOfPaintings);

	UFUNCTION(BlueprintCallable)
	bool IsGameOver();

	UFUNCTION(BlueprintCallable)
	void Victory(float TimeScore);

	UFUNCTION(BlueprintCallable)
	void SetNewLivesNum(int32 LivesNum);

	UFUNCTION(BlueprintCallable)
	int32 GetNumOfLives() const { return m_NumberOfLives; }

	UFUNCTION(BlueprintCallable)
	void LoseLife();

	UFUNCTION(BlueprintCallable)
	void SetNewCollectedPaintingsNum(int32 NewPaintingNum);

	UFUNCTION(BlueprintCallable)
	int32 GetNewCollectedPaintingsNum() const { return m_NumberOfPaintings; }

	UFUNCTION(BlueprintCallable)
	void GainPainting();

	UFUNCTION(BlueprintCallable)
	bool HasAllPaintings();

public:
	UPROPERTY(BlueprintAssignable)
	FPaintingFound OnPaintingFound;

	UPROPERTY(BlueprintAssignable)
	FOnLifeLost OnLifeLost;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FGameScore> Scores;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MaxNumberOfPaintings = 5;

private:
	UPROPERTY()
	int32 m_NumberOfPaintings = 0;

	UPROPERTY()
	int32 m_NumberOfLives = 0;
};
