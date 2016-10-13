// Fill out your copyright notice in the Description page of Project Settings.

#include "tankBattle.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController not controlling a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController controlling %s"), *(ControlledTank->GetName()));
	}
	UE_LOG(LogTemp, Warning, TEXT("AIController Begin Play"));
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}