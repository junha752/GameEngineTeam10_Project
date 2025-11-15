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

	// save current stage of game.
	// 1: conversation, 2: progression, 3: combat
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Saved Player State")
	int CurrentStage;

	// save player character parameters from PlayerCharacter.h
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Saved Player State")
	EPlayerWeapon CurrentWeapon;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Saved Player State")
	float HealthPoints;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Saved Player State")
	float Stamina;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Saved Player State")
	int Strength;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Saved Player State")
	int Armer;
	
	UFUNCTION(BlueprintCallable, Category = "SaveGame")int GetCurrentStage() const;
	UFUNCTION(BlueprintCallable, Category = "SaveGame")void SetCurrentStage(int Stage);

};
