// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomSaveGame.h"

int UCustomSaveGame::GetCurrentStage() const
{
	return CurrentStage;
}

void UCustomSaveGame::SetCurrentStage(int Stage)
{
	CurrentStage = Stage;
}