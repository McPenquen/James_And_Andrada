// Copyright (C) 2024 James And Andrada - All Rights Reserved. You may use, distribute and modify this code with the permision of James And Andrada group.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GameManager.generated.h"

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
	void GameOver();

	UFUNCTION(BlueprintCallable)
	void Victory(float TimeScore, int32 MaxTreasureAmount, int32 CurrentTreasureAmount);

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FGameScore> Scores;
};
