// Fill out your copyright notice in the Description page of Project Settings.


#include "TankGameModeBase.h"


void ATankGameModeBase::BeginPlay() 
{
    
}


void ATankGameModeBase::ActorDied(AActor* DeadActor) 
{
    // Check what type of Actor died. If Turret, tally. If Player -> go to lose condition.
}


void ATankGameModeBase::HandleGameStart() 
{
    // Initialise the start countdown, turret activation, pawn check etc.
    // Call Blueprint version GameStart();
}


void ATankGameModeBase::HandleGameOver(bool PlayerWon) 
{
    // See if the player has destroyed all the turrets, show win result.
    // else if turret destroyed player, show lose result.
    // Call blueprint version GameOver(bool).
}



