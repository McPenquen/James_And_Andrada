// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"

#include "DarknessTickSubsystem.generated.h"

//DECLARE_DYNAMIC_DELEGATE(FOnDarknessStop);
//DECLARE_DYNAMIC_DELEGATE(FOnDarknessStart);


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
	//UPROPERTY(BlueprintAssignable)
	//FOnDarknessStop OnDarknessStop;

	//UPROPERTY(BlueprintAssignable)
	//FOnDarknessStart OnDarknessStart;

};
