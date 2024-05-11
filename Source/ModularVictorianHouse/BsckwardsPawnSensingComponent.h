// Copyright (C) 2024 James And Andrada - All Rights Reserved. You may use, distribute and modify this code with the permision of James And Andrada group.

#pragma once

#include "CoreMinimal.h"
#include "Perception/PawnSensingComponent.h"
#include "BsckwardsPawnSensingComponent.generated.h"

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class MODULARVICTORIANHOUSE_API UBsckwardsPawnSensingComponent : public UPawnSensingComponent
{
	GENERATED_BODY()
	
public:
	FRotator GetSensorRotation() const override;
};
