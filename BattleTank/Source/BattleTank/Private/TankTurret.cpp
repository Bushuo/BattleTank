// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Engine/World.h"

void UTankTurret::Turn(float RelativeSpeed)
{
	/// at a maximum turn speed move the barrel each frame towards the desired barrel elevation
	/// consider the minimum possible turning angle. there is one direction to come from in each rotation axis. -360 +360
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	auto DeltaTurn = MaxDegreesPerSecond * RelativeSpeed * GetWorld()->DeltaTimeSeconds;
	auto NewTurn = RelativeRotation.Yaw + DeltaTurn;

	SetRelativeRotation(FRotator(0, NewTurn, 0));
}
