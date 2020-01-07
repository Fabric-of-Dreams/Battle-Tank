// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	if (!GetControlledTank())
		UE_LOG(LogTemp, Warning, TEXT("AIController is not possedding a tank"))
	else
		UE_LOG(LogTemp, Warning, TEXT("AI is possessing %s"), *GetControlledTank()->GetName())

	if (!GetPlayerTank())
		UE_LOG(LogTemp, Warning, TEXT("AIController can't get a PlayerTank"))
	else
		UE_LOG(LogTemp, Warning, TEXT("AIController found a PlayerTank %s"), *GetPlayerTank()->GetName())
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetPlayerTank())
		AimTowardsPlayer();

	// Fire if ready
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

void ATankAIController::AimTowardsPlayer()
{
		FVector PlayerLocation = GetPlayerTank()->GetActorLocation();
		GetControlledTank()->AimAt(PlayerLocation);
}

