#include "TurnCharacter.h"
#include "Animation/AnimBlueprint.h"

ATurnCharacter::ATurnCharacter()
{
    PrimaryActorTick.bCanEverTick = false;
    GetMesh()->SetRelativeLocation(FVector(0.0f, 0.0f, -90.0f));
    GetMesh()->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));
}

void ATurnCharacter::BeginPlay()
{
    Super::BeginPlay();
}

void ATurnCharacter::SetCharacterMeshAndAnim(USkeletalMesh* NewMesh, UAnimBlueprint* NewAnimBP)
{
    if (NewMesh)
        GetMesh()->SetSkeletalMesh(NewMesh);

    if (NewAnimBP)
        GetMesh()->SetAnimInstanceClass(NewAnimBP->GeneratedClass);
}
