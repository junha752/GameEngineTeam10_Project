
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Camera/CameraComponent.h"
#include "TurnCamera.generated.h"

UCLASS()
class GAMEENTEAM10_PROJECT_API ATurnCamera : public AActor
{
	GENERATED_BODY()

public:
	ATurnCamera();

protected:
	virtual void BeginPlay() override;

public:
	// 카메라 컴포넌트
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	UCameraComponent* PreviewCamera;
};
