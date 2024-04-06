// Fill out your copyright notice in the Description page of Project Settings.

#include "DarknessTickSubsystem.h"

void UDarknessTickSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UDarknessTickSubsystem::Deinitialize() 
{
	Super::Deinitialize();
}

void UDarknessTickSubsystem::Tick(float DeltaTime)
{

}

TStatId UDarknessTickSubsystem::GetStatId() const
{
	return Super::GetStatId();
}