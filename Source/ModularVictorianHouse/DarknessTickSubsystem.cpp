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
	Super::Tick(DeltaTime);
	m_CurrentCountdown += DeltaTime;

	if (IsDark && m_CurrentCountdown >= DarknessLength)
	{
		m_CurrentCountdown = 0.0f;
		IsDark = false;
		OnDarknessStop.Broadcast();
	}
	else if (!IsDark && m_CurrentCountdown >= LightLength)
	{
		m_CurrentCountdown = 0.0f;
		IsDark = true;
		OnDarknessStart.Broadcast();
	}
}

TStatId UDarknessTickSubsystem::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(UDarknessTickSubsystem, STATGROUP_Tickables);
}