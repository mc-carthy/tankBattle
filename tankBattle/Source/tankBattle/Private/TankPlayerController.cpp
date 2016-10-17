// Fill out your copyright notice in the Description page of Project Settings.

#include "tankBattle.h"
#include "TankPlayerController.h"

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not controlling a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController controlling %s"),*(ControlledTank->GetName()));
	}
	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank())
	{
		return;
	}

	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation))
	{
		//UE_LOG(LogTemp, Warning, TEXT("Hit location: %s"), *HitLocation.ToString())
			// Get world location of hit location from crosshair raycast
			// If it hits the landscape
				// Tell controlled tank to aim for this point
	}
}

/// Fires raycast along crosshair, returns true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	HitLocation = FVector(1.0f);

	int32 ViewportSizeX, ViewportSizeY;

	GetViewportSize(ViewportSizeX, ViewportSizeY);

	FVector2D ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);

	//UE_LOG(LogTemp, Warning, TEXT("ScreenLocation: %s"), *ScreenLocation.ToString());

	return true;
}