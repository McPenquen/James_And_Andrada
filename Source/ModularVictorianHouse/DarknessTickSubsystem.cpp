// Copyright (C) 2024 James And Andrada - All Rights Reserved. You may use, distribute and modify this code with the permision of James And Andrada group.

#include "DarknessTickSubsystem.h"

void UDarknessTickSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	TimeScore = 0.0f;
}

void UDarknessTickSubsystem::Deinitialize() 
{
	Super::Deinitialize();
}

void UDarknessTickSubsystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	m_CurrentCountdown += DeltaTime;
	TimeScore += DeltaTime;

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

	int Minutes = int(TimeScore / 60);
	float Remainder = TimeScore - (float(Minutes) * 60.f);
	int Seconds = int(Remainder);
	m_TimeString = FString::FromInt(Minutes) + " : " + FString::FromInt(Seconds);
}

TStatId UDarknessTickSubsystem::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(UDarknessTickSubsystem, STATGROUP_Tickables);
}