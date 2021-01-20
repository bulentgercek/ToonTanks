// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTurret.h"
#include "Kismet/GameplayStatics.h"
#include "PawnTank.h"

#define OutParam

// Called when the game starts or when spawned
void APawnTurret::BeginPlay()
{
	Super::BeginPlay();

    GetWorld()->GetTimerManager().SetTimer(OutParam FireRateTimerHandle, this, &APawnTurret::CheckFireCondition, FireRate, true);
	PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));
}


void APawnTurret::HandleDestruction() 
{
	// Call base pawn class HandleDestruction to play effects.
	Super::HandleDestruction();
	Destroy();
}

// Called every frame
void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!PlayerPawn || ReturnDistanceToPlayer() > FireRange)
	{
		return;
	}

	RotateTurret(PlayerPawn->GetActorLocation());
}


void APawnTurret::CheckFireCondition() 
{
    // if Player == null | is Dead Then BAIL!!
	if (!PlayerPawn || !PlayerPawn->GetIsPlayerAlive())
	{
		return;
	}
	// if Player is in range then FIRE!!
	if (ReturnDistanceToPlayer() <= FireRange)
	{
		Fire();
	}
}


float APawnTurret::ReturnDistanceToPlayer() 
{
	if (!PlayerPawn)
	{
		return 0.0f;
	}

	return FVector::Dist(PlayerPawn->GetActorLocation(), GetActorLocation()); 
}
