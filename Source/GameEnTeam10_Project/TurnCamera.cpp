#include "TurnCamera.h"

ATurnCamera::ATurnCamera()
{
    PrimaryActorTick.bCanEverTick = false;

    // 루트 컴포넌트 생성
    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

    // 카메라 컴포넌트 생성
    PreviewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PreviewCamera"));
    PreviewCamera->SetupAttachment(RootComponent);

    // 기본 위치 조정 (살짝 위쪽에서 바라보는 각도)
    PreviewCamera->SetRelativeLocation(FVector(-300.0f, 0.0f, 150.0f));
    PreviewCamera->SetRelativeRotation(FRotator(-10.0f, 0.0f, 0.0f));
}

void ATurnCamera::BeginPlay()
{
    Super::BeginPlay();
}
