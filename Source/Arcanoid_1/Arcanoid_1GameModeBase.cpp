// Copyright Epic Games, Inc. All Rights Reserved.


#include "Arcanoid_1GameModeBase.h"
#include"Paddle.h"


AArcanoid_1GameModeBase::AArcanoid_1GameModeBase()
{
}

void AArcanoid_1GameModeBase::BeginPlay()
{
	Super::BeginPlay();

	FVector SpawnPaddle1(100.0f, 0.0f, 5.0f);
	FVector SpawnPaddle2(-200.0f, 0.0f, 0.0f);

	// Crear dos Paddles
	for (int i = 0; i <= 1; i++)
	{
		APaddle* SpawnedPaddle = GetWorld()->SpawnActor<APaddle>(APaddle::StaticClass(), SpawnPaddle1, FRotator::ZeroRotator);

		if (SpawnedPaddle)
		{
			Paddle = SpawnedPaddle;
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green, FString::Printf(TEXT("Paddle Creado"), *Paddle->GetName()));
		}
		SpawnPaddle1 = SpawnPaddle1 + SpawnPaddle2;
	}
}
