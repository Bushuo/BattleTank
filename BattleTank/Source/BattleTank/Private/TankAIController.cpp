// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "TankPlayerController.h"
#include "Tank.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	ATank* ControlledTank = GetControlledTank();
	ATank* PlayerTank = GetPlayerTank();
	if (!PlayerTank) {
		//UE_LOG(LogTemp, Warning, TEXT("%s is not possessing a tank"), *GetName());
		UE_LOG(LogTemp, Warning, TEXT("%s cant get PlayerTank"), *GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController got: %s"), *PlayerTank->GetName());
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank()) {
		// Move towards the player
		// Aim towards player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
		// Fire if ready
	}
}

ATank * ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}




