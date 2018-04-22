// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class UAimingComponent;

/**
 * Responsible for helping the player aim.
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	virtual void SetPawn(APawn* InPawn) override;

	/** start the tank moving the barrel 
	 * so that a shot would hit where the crosshair intersects world
	 */
	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const;

	UPROPERTY(EditDefaultsOnly, Category = "Settings")
	float CrossHairXLocation = 0.5f;

	UPROPERTY(EditDefaultsOnly, Category = "Settings")
	float CrossHairYLocation = 0.33333f;

	UPROPERTY(EditDefaultsOnly, Category = "Settings")
	float LineTraceRange = 1000000.f;

	UFUNCTION()
	void OnPawnDeath();

protected:

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FoundAimingComponent(UAimingComponent* AimCompRef);
};
