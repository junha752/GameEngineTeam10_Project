# 게임엔진기초_팀10

## 구현 기능
* 록온 공격
* 체력, 스테미나, 대쉬, 죽음 상태
* 구르기 (무적 프레임 미구현)
* 캐릭터 모델은 테스트용이며 변경 가능

---

## 파일 설명 (All->콘텐츠->Assests)
* **여러 캐릭터애니매이션**을 담아놓음.
* **Anim** : CanUse 안에 Maximo 애니메이션을 리타겟팅한 애니메이션을 담아놓음.
* **L->Input** : 입력 관련 IA와 입력 매핑 컨텍스트.
* **L->ThirdPerson** : 블루프린트 파일들이 있음.
    * **ABP_PlayerCharacter** : `PlayerCharacterAnimInstance` 라는 cpp를 상속받은 애니메이션 블루프린트 파일. 디테일 패널에서 공격, 구르기, 데미지 모션을 선택 가능.
    * **ABP_AxeCharacter** : `ABP_PlayerCharacter`를 복제하여 이름을 바꾼 것. 다른 애니메이션 모션을 할당함.
    * **BP_PlayerCharacter** : `PlayerCharacter`라는 cpp를 상속받은 블루프린트 파일. 캐릭터 속성값 설정 가능.
    * **BP_AxePlayer** : `BP_PlayerCharacter`를 복제하고 이름을 바꾼 것. `ABP_AxeCharacter`가 적용되었고 무기가 포함됨.
    * **BP_MyActorSpawner** : `MyActorSpawner` cpp를 상속받은 블루프린트. 액터를 소환하는 액터.
    * **BP_TargetLockActor** : 록온 시 타깃 캐릭터를 표시해주는 액터. `WB_LockOn` 위젯을 담고 있음.
    * **WB_LockOn** : 하얀색 원을 담고 있는 위젯 블루프린트.
    * **WB_HUD** : 화면에 표시되는 UI 위젯. 현재 스테미나를 나타내는 바를 포함.
    * **BS_PlayerCharacter** : 캐릭터 방향과 속도에 따른 이동 모션을 넣었음.
    * **BS_AxeCharacter** : `BS_PlayerCharacter`를 복제. 무기에 맞는 모션을 추가함. `ABP_AxeCharacter`에서는 `BS_PlayerCharacter` 하체와 `BS_AxeCharacter` 상체를 이용.

---

## CPP 파일 설명
* **MyActorSpawner** : `TargetLockActor`를 스폰하는 기능.
* **PlayerCharacter** : 캐릭터의 입력 액션에 따른 처리 함수와 속성값들이 정의되어 있음.
* **PlayerCharacterAnimInstance** : 캐릭터 입력에 따라 `PlayerCharacter`로부터 신호를 받아 몽타주를 재생하는 함수.
* **PlayerCharacterNotifyState** : 공격 모션에서 공격 판정 구간을 결정하는 기능.
