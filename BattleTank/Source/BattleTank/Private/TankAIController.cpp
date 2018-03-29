// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "TankPlayerController.h"
#include "AimingComponent.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!ensure(PlayerTank && GetPawn())) { return; }
	// Move towards the player
	MoveToActor(PlayerTank, AcceptanceRadius); //TODO check radius is in cm
	// Aim towards player
	auto AimingComponent = GetPawn()->FindComponentByClass<UAimingComponent>();
	AimingComponent->AimAt(PlayerTank->GetActorLocation());

	AimingComponent->Fire(); //TODO dont fire every frame
}



