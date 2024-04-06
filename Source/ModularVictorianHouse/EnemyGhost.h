// Copyright (C) 2024 James And Andrada - All Rights Reserved. You may use, distribute and modify this code with the permision of James And Andrada group.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "EnemyGhost.generated.h"

UCLASS()
class MODULARVICTORIANHOUSE_API AEnemyGhost : public ACharacter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<AActor*> PathStops;
};
