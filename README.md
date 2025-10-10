# GameEnTeam10_Project
게임엔진기초_팀10

구현 기능:
록온
공격
체력
스테미나
대쉬
죽음 상태
구르기(무적 프레임 미구현)
캐릭터모델은 테스트용으로 설정했고 바꿀 수 있음

파일설명
All->콘텐츠->Assests) 여러 캐릭터애니매이션을 담아놓음. Anim안에 CanUse는 Maximo애니매이션을 리타겟팅한 애니매이션을 담아놓음
        L->Input )입력 관련한 IA와 입력 매핑 컨텍스트
       L->ThirdPerson) 블루프린트 파일들이 있음
                    L->ABP_PlayerCharacter) PlayerCharacterAnimInstance 라는 cpp을 상속받은 애니메이션 블루프린트파일, 디테일 페널에서 공격 모션, 구르기 모션, 데미지를 입었을 때 모션을 선택할 수 있음. 캐릭터에서 ABP를 선택해서 애니매이션을 관리할 수 있다.
                    L->ABP_AxeCharacter) ABP_PlayerCharacter를 복제해서 이름을 바꿨음. 다른 애니매이션 모션을 할당하였다. 현재 캐릭터에 적용된 애니메이션 블루프린트
                    L->BP_PlayerCharacter) PlayerCharacter라는 cpp을 상속받은 블루프린트파일, 캐릭터의 여러 속성값을 정할 수 있다. 애님클래스에서 ABP선택가능, 캐릭터 메시 선택가능, IA를 PlayerCharacter cpp가 찾지 못했을 때 직접 할당 가능, 무기를 추가할 때 컴포넌트 패널에서 캐릭터의 메시에 스태틱메시로 추가해서 뷰포트에서 위치 크기 수정가능, 무기로 추가한 후 arrow로 무기의 시작점과 끝점 위치에 만들고, 블루프린트에서 set Sword Start, set Sword End, set Sword Mesh 만든 것들을 설정해 줘야 공격모션에서 공격판정 인식가능(BP_AxePlayer의 이벤트그래프 참고)
                     L->BP_AxePlayer) BP_PlayerCharacter를 복제하고 이름을 바꾼것. ABP_AxeCharacter가 적용되었고 무기가 들어가 있음
                    L->BP_MyActorSpawner) MyActorSpawner cpp을 상속받은 블루프린트, 액터를 소환하는 액터.
                    L->BP_TargetLockActor) 록온시 타깃 캐릭터에 하얀색 원으로 타깃 캐릭터를 표시해주는 액터, WB_LockOn이라는 위젯을 담고있음
                    L->WB_LockOn) 하얀색 원을 담고 있는 위젯 블루프린트. 그 자체로는 스폰될 수 없고 이 위젯을 담는 액터가 있어야 한다
                    L->BS_PlayerCharacter) 캐릭터의 방향과 속도에 따라 이동하는 모션을 넣었음. 그냥 이동은 그대로 전진 모션만 이용되고 방향에 따른 다른 모션들은 록온시 적용됨
                    L->BS_AxeCharacter)BS_PlayerCharacter를 복제해서 이름을 바꿈. 무기에 맞는 모션을 추가했음. ABP_AxeCharacter 애니메이션 블루프린트에서는 BS_PlayerCharacter의 하체부분과 BS_AxeCharacter상체부분을 이용
                    L->WB_HUD) 화면에 표시되는 UI 위젯, 현재 스테미나 확인용로 스테미나를 나타내는 바를 넣음.


L-> MyActorSpawner) TargetLockActor를 스폰하는 기능
L-> PlayerCharacter) 캐릭터의 입력액션에 따른 처리를 하는 함수가 담겨 있음. 캐릭터의 속성값들도 정의되어 있음. 
L-> PlayerCharacterAnimInstance) 캐릭터의 입력에 따라 PlayerCharacter로 부터 신호를 받아서 몽타주를 재생하는 함수가 있음
L-> PlayerCharacterNotifyState) 캐릭터의 공격모션에서 공격 판정이 들어가는 구간을 결정하면(NotifyState) 그 NotifyState의 시작부분, 중간에 계속 실행되는 Tick, NotifyState의 끝부분 에 실행되는 동작을 구현가능. tick에 공격을 받는 액터를 추적해서 그 액터의 체력을 줄이는 형태로 구현.
    
