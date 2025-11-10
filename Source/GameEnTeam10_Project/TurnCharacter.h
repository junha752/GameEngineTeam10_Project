#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TurnCharacter.generated.h"

UCLASS()
class GAMEENTEAM10_PROJECT_API ATurnCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    ATurnCharacter();

protected:
    virtual void BeginPlay() override;

public:
    // 미리보기용 애니메이션 세팅
    UFUNCTION(BlueprintCallable, Category = "Preview")
    void SetCharacterMeshAndAnim(USkeletalMesh* NewMesh, UAnimBlueprint* NewAnimBP);
};
