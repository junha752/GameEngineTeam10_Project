// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "CustomSaveGame.generated.h"


UCLASS()
class GAMEENTEAM10_PROJECT_API UCustomSaveGame : public USaveGame
{
	GENERATED_BODY()

public:

	int CurrentStage = 1;
	
	UFUNCTION(BlueprintCallable, Category = "SaveGame")int GetCurrentStage() const;
	UFUNCTION(BlueprintCallable, Category = "SaveGame")void SetCurrentStage(int Stage);

};
