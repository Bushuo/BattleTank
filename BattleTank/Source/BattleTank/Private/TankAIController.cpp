// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "TankPlayerController.h"
#include "AimingComponent.h"
#include "Engine/World.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		auto PossessedTank = Cast<ATank>(InPawn);
		if (!ensure(PossessedTank)) { return; }
		// Subscribe our local method to tank death event
		PossessedTank->OnTankDeath.AddUniqueDynamic(this, &ATankAIController::OnPawnDeath);
	}
}

void ATankAIController::OnPawnDeath()
{
	if (!GetPawn()) { return; }
	GetPawn()->DetachFromControllerPendingDestroy();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!(PlayerTank && GetPawn())) { return; }
	// Move towards the player
	MoveToActor(PlayerTank, AcceptanceRadius);
	// Aim towards player
	auto AimingComponent = GetPawn()->FindComponentByClass<UAimingComponent>();
	AimingComponent->AimAt(PlayerTank->GetActorLocation());
	
	if(AimingComponent->GetFiringStatus() == EFiringStatus::Locked)
	{
		AimingComponent->Fire(); //TODO dont fire every frame
	}
}




