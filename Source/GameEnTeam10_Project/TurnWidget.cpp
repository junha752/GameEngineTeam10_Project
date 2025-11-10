#include "TurnWidget.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"

void UTurnWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (Btn_EquipBuy)      Btn_EquipBuy->OnClicked.AddDynamic(this, &UTurnWidget::OnEquipBuyClicked);
    if (Btn_Repair)        Btn_Repair->OnClicked.AddDynamic(this, &UTurnWidget::OnRepairClicked);
    if (Btn_Rest)          Btn_Rest->OnClicked.AddDynamic(this, &UTurnWidget::OnRestClicked);
    if (Btn_SwordTraining) Btn_SwordTraining->OnClicked.AddDynamic(this, &UTurnWidget::OnSwordTrainingClicked);
    if (Btn_MagicPractice) Btn_MagicPractice->OnClicked.AddDynamic(this, &UTurnWidget::OnMagicPracticeClicked);
    if (Btn_MagicStudy)    Btn_MagicStudy->OnClicked.AddDynamic(this, &UTurnWidget::OnMagicStudyClicked);

    RefreshTurnText();
}

void UTurnWidget::SetRemainingTurns(int32 InTurns)
{
    RemainingTurns = FMath::Max(0, InTurns);
    RefreshTurnText();
}

void UTurnWidget::RefreshTurnText()
{
    if (Txt_TurnCount)
    {
        Txt_TurnCount->SetText(FText::FromString(FString::Printf(TEXT("%d"), RemainingTurns)));
    }
}

void UTurnWidget::OnEquipBuyClicked()
{
    UE_LOG(LogTemp, Log, TEXT("장비 구매 클릭됨"));
    SetRemainingTurns(RemainingTurns - 1);
}

void UTurnWidget::OnRepairClicked()
{
    UE_LOG(LogTemp, Log, TEXT("장비 수리 클릭됨"));
    SetRemainingTurns(RemainingTurns - 1);
}

void UTurnWidget::OnRestClicked()
{
    UE_LOG(LogTemp, Log, TEXT("휴식 클릭됨"));
    SetRemainingTurns(RemainingTurns - 1);
}

void UTurnWidget::OnSwordTrainingClicked()
{
    UE_LOG(LogTemp, Log, TEXT("검술 훈련 클릭됨"));
    SetRemainingTurns(RemainingTurns - 3);
}

void UTurnWidget::OnMagicPracticeClicked()
{
    UE_LOG(LogTemp, Log, TEXT("마법 연마 클릭됨"));
    SetRemainingTurns(RemainingTurns - 4);
}

void UTurnWidget::OnMagicStudyClicked()
{
    UE_LOG(LogTemp, Log, TEXT("마법 학습 클릭됨"));
    SetRemainingTurns(RemainingTurns - 5);
}
