// Copyright (C) 2024 James And Andrada - All Rights Reserved. You may use, distribute and modify this code with the permision of James And Andrada group.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"

#include "DarknessTickSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDarknessStop);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDarknessStart);

UCLASS()
class MODULARVICTORIANHOUSE_API UDarknessTickSubsystem : public UTickableWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase & Collection) override;
	virtual void Deinitialize() override;

	virtual void Tick(float DeltaTime) override;

	virtual TStatId GetStatId() const override;

public:
	UFUNCTION(BlueprintCallable)
	FString GetScoreTimeUIString() const { return m_TimeString; }

public:
	UPROPERTY(BlueprintAssignable)
	FOnDarknessStop OnDarknessStop;

	UPROPERTY(BlueprintAssignable)
	FOnDarknessStart OnDarknessStart;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DarknessLength = 3.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float LightLength = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsDark = true;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float TimeScore = 0.0f;

private:
	UPROPERTY()
	float m_CurrentCountdown = 0.0f;

	UPROPERTY()
	FString m_TimeString = "";
};
