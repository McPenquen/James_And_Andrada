// Copyright (C) 2024 James And Andrada - All Rights Reserved. You may use, distribute and modify this code with the permision of James And Andrada group.


#include "BsckwardsPawnSensingComponent.h"

FRotator UBsckwardsPawnSensingComponent::GetSensorRotation() const
{
	FRotator SensorRotation(FRotator::ZeroRotator);
	const AActor* SensorActor = GetSensorActor();
	if (SensorActor != NULL)
	{
		SensorRotation = SensorActor->GetActorRotation() * -1.0f;
	}

	return SensorRotation;
}
