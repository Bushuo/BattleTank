// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"

void UTankBarrel::Elevate(float DegreesPerSecond)
{
	// at a maximum turn speed move the barrel each frame towards the desired barrel elevation
	// when it can be reached within one frame just set
	// when not lerp the elevation rotation
	// consider the minimum possible turning angle. there is one direction to come from in each rotation axis. -360 +360
	UE_LOG(LogTemp, Warning, TEXT("called Barrel->Elevate()"));
}
