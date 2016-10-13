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
	//UE_LOG(LogTemp, Warning, TEXT("PlayerController ticking"));
	if (!GetControlledTank())
	{
		return;
	}

	// Get world location of hit location from crosshair raycast
	// If it hits the landscape
		// Tell controlled tank to aim for this point
}