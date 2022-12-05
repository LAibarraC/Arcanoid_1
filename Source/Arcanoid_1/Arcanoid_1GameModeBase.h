// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Arcanoid_1GameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class ARCANOID_1_API AArcanoid_1GameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
private:

	AArcanoid_1GameModeBase();

	//Singleton
	UPROPERTY()
		class APaddle* Paddle;

public:
	virtual void BeginPlay() override;
};
