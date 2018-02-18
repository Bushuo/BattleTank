// Fill out your copyright notice in the Description page of Project Settings.

#include "AimingComponent.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"


// Sets default values for this component's properties
UAimingComponent::UAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UAimingComponent::SetBarrelReference(UStaticMeshComponent * BarrelToSet)
{
	Barrel = BarrelToSet;
}

// Called when the game starts
void UAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

// Called every frame
void UAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel) { return; }
	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(TEXT("BarrelMuzzle"));
	TArray<AActor*> ActorsToIgnore;
	// Calculate the out LauchVelocity
	if (UGameplayStatics::SuggestProjectileVelocity(
		this, // Context
		OutLaunchVelocity, 
		StartLocation, 
		HitLocation, 
		LaunchSpeed
	)) {
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		UE_LOG(LogTemp, Warning, TEXT("Firing at %s"), *AimDirection.ToString());
		MoveBarrelTowards(AimDirection);
	}
}

void UAimingComponent::MoveBarrelTowards(const FVector AimDirection)
{
	// at a maximum turn speed move the barrel each frame towards the desired barrel direction
	// when it can be reached within one frame just set
	// when not lerp the rotation
	// consider the minimum possible turning angle. there is one direction to come from in each rotation axis. -360 +360
}
