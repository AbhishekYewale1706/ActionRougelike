
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RougeCharacter.generated.h"

class UNiagaraSystem;
class ARougeProjectileMagic;
struct FInputActionValue;
class UInputAction;
class USpringArmComponent;
class UCameraComponent;
class UAnimMontage;
class USoundBase;


UCLASS()
class ACTIONROUGELIKE_API ARougeCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ARougeCharacter();

protected:

	UPROPERTY(EditDefaultsOnly,Category = "PrimaryAttack")
	TSubclassOf<ARougeProjectileMagic>ProjectileClass;
	
	UPROPERTY(VisibleAnywhere,Category="PrimaryAttack")
	FName PrimaryAttackSocketName;
	
	UPROPERTY(EditDefaultsOnly,Category="PrimaryAttack")
	TObjectPtr<UAnimMontage>PrimaryAttackAnimMontage;
    
	UPROPERTY(EditDefaultsOnly,Category = "Sound")
	TObjectPtr<USoundBase>CastSound;
	
	UPROPERTY(EditDefaultsOnly,Category="Effect")
	TObjectPtr<UNiagaraSystem>CastEffect;
	
	
	UPROPERTY(VisibleAnywhere,Category = "Camera")
	TObjectPtr<UCameraComponent>CameraComponent;
	
	UPROPERTY(VisibleAnywhere,Category = "Camera")
	TObjectPtr<USpringArmComponent>SpringArmComponent;
	
	UPROPERTY(EditDefaultsOnly,Category = "Input")
	TObjectPtr<UInputAction>IA_Move;
	
	UPROPERTY(EditDefaultsOnly,Category = "Input")
	TObjectPtr<UInputAction>IA_Look;
	
	UPROPERTY(EditDefaultsOnly,Category = "Input")
	TObjectPtr<UInputAction>IA_PrimaryAttack;
	
	UPROPERTY(EditDefaultsOnly,Category = "Input")
	TObjectPtr<UInputAction>IA_Jump;
	
	//InputFunction
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void PrimaryAttack();
	
	void PrimaryAttackTime();
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
};
