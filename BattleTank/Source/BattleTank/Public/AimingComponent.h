// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "AimingComponent.generated.h"

class UTankBarrel;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAimingComponent();

	void SetBarrelReference(UTankBarrel* BarrelToSet);

	// TODO set turret reference

	void AimAt(FVector HitLocation, float LaunchSpeed);

private:
	void MoveBarrelTowards(const FVector AimDirection);

	UTankBarrel* Barrel = nullptr;
};
