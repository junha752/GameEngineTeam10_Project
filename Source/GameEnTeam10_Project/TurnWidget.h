#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TurnWidget.generated.h"

UCLASS()
class GAMEENTEAM10_PROJECT_API UTurnWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    virtual void NativeConstruct() override;

    // 남은 턴 설정 함수
    UFUNCTION(BlueprintCallable)
    void SetRemainingTurns(int32 InTurns);

protected:
    // 남은 턴 표시 텍스트
    UPROPERTY(meta = (BindWidget))
    class UTextBlock* Txt_TurnCount;

    // 버튼 6개
    UPROPERTY(meta = (BindWidgetOptional)) class UButton* Btn_EquipBuy;
    UPROPERTY(meta = (BindWidgetOptional)) class UButton* Btn_Repair;
    UPROPERTY(meta = (BindWidgetOptional)) class UButton* Btn_Rest;
    UPROPERTY(meta = (BindWidgetOptional)) class UButton* Btn_SwordTraining;
    UPROPERTY(meta = (BindWidgetOptional)) class UButton* Btn_MagicPractice;
    UPROPERTY(meta = (BindWidgetOptional)) class UButton* Btn_MagicStudy;

    // 각 버튼 하위 텍스트 (이름 + 턴수)
    UPROPERTY(meta = (BindWidgetOptional)) class UTextBlock* Txt_EquipBuy;
    UPROPERTY(meta = (BindWidgetOptional)) class UTextBlock* Txt_EquipBuyCount;

    UPROPERTY(meta = (BindWidgetOptional)) class UTextBlock* Txt_Repair;
    UPROPERTY(meta = (BindWidgetOptional)) class UTextBlock* Txt_RepairCount;

    UPROPERTY(meta = (BindWidgetOptional)) class UTextBlock* Txt_Rest;
    UPROPERTY(meta = (BindWidgetOptional)) class UTextBlock* Txt_RestCount;

    UPROPERTY(meta = (BindWidgetOptional)) class UTextBlock* Txt_SwordTraining;
    UPROPERTY(meta = (BindWidgetOptional)) class UTextBlock* Txt_SwordTrainingCount;

    UPROPERTY(meta = (BindWidgetOptional)) class UTextBlock* Txt_MagicPractice;
    UPROPERTY(meta = (BindWidgetOptional)) class UTextBlock* Txt_MagicPracticeCount;

    UPROPERTY(meta = (BindWidgetOptional)) class UTextBlock* Txt_MagicStudy;
    UPROPERTY(meta = (BindWidgetOptional)) class UTextBlock* Txt_MagicStudyCount;

private:
    // 남은 턴
    int32 RemainingTurns = 15;

    // 텍스트 갱신
    void RefreshTurnText();

    // 버튼 클릭 이벤트
    UFUNCTION() void OnEquipBuyClicked();
    UFUNCTION() void OnRepairClicked();
    UFUNCTION() void OnRestClicked();
    UFUNCTION() void OnSwordTrainingClicked();
    UFUNCTION() void OnMagicPracticeClicked();
    UFUNCTION() void OnMagicStudyClicked();
};
