// Fill out your copyright notice in the Description page of Project Settings.

#include"GameFramework/FloatingPawnMovement.h"
#include"Components/StaticMeshComponent.h"

#include "Paddle.h"

// Sets default values
APaddle::APaddle()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> PaddleMessAsset(TEXT("/Game/Meshes/SM_Paddle.SM_Paddle"));

	SM_Paddle = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SM Paddle"));
	RootComponent = SM_Paddle;

	SM_Paddle->SetStaticMesh(PaddleMessAsset.Object);

	SM_Paddle->SetEnableGravity(false);
	SM_Paddle->SetConstraintMode(EDOFMode::XZPlane);
	SM_Paddle->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	//cambio
	SM_Paddle->SetCollisionProfileName(TEXT("PhysicsActor"));

	FloatingMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Floating Pawn Movement"));

}

// Called when the game starts or when spawned
void APaddle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APaddle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APaddle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APaddle::MoveHorizontal(float AxisValue)
{
	AddMovementInput(FVector(AxisValue, 0.0f, 0.0f), 1.0f, false);
}

