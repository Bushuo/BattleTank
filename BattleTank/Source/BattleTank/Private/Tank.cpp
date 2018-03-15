// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "Engine/World.h"
#include "AimingComponent.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "TankMovementComponent.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	if (!ProjectileBlueprint)
	{
		UE_LOG(LogTemp, Error, TEXT("Projectile Blueprint not set"));
		return;
	}
}

void ATank::AimAt(FVector HitLocation) 
{
	if (!TankAimingComponent)
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAimingComponent not set"));
		return;
	}
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::Fire()
{
	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;

	if (Barrel && ProjectileBlueprint && isReloaded) {
		// spawn projectile at muzzle
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, Barrel->GetSocketLocation(TEXT("BarrelMuzzle")), Barrel->GetSocketRotation(TEXT("BarrelMuzzle")));

		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}
