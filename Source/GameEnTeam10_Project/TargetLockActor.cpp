// Fill out your copyright notice in the Description page of Project Settings.


#include "TargetLockActor.h"
#include "GameFramework/Character.h"
// Sets default values
ATargetLockActor::ATargetLockActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATargetLockActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATargetLockActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (TargetActor)
	{
		this->AttachToActor(TargetActor, FAttachmentTransformRules::KeepWorldTransform, FName(TEXT("LockOn")));
	}
}

void ATargetLockActor::MoveLockOnWidget(AActor* TargetCharacter) 
{
	TargetActor = TargetCharacter;
}

