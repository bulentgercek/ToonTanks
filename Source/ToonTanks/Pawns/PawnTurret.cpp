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

// Called every frame
void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APawnTurret::CheckFireCondition() 
{
    // if Player == null | is Dead Then BAIL!!
	if (!PlayerPawn)
	{
		return;
	}
	// if Player is in range then FIRE!!
	if (ReturnDistanceToPlayer() <= FireRange)
	{
		// Fire
		UE_LOG(LogTemp, Warning, TEXT("Fire Condition Success!"));
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
