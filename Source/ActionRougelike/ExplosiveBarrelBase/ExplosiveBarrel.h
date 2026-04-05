
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ExplosiveBarrel.generated.h"

class URadialForceComponent;
class UNiagaraComponent;
class UStaticMeshComponent;
class UAudioComponent;
class USoundBase;
class UNiagaraSystem;


UCLASS()
class ACTIONROUGELIKE_API AExplosiveBarrel : public AActor
{
	GENERATED_BODY()

public:
	AExplosiveBarrel();
	
protected:
	
	UPROPERTY(EditDefaultsOnly,Category = "Sound")
	TObjectPtr<UAudioComponent>LoopFireSound;
	
	UPROPERTY(EditDefaultsOnly,Category="Sound")
	TObjectPtr<USoundBase>ExplodeSound;
	
	UPROPERTY(EditDefaultsOnly,Category="NiagaraSystem")
	TObjectPtr<UNiagaraComponent>LoopFireNiagara;
	
	UPROPERTY(EditDefaultsOnly,Category="NiagaraSystem")
	TObjectPtr<UNiagaraSystem>ExplodeEffect;
	
	UPROPERTY(EditDefaultsOnly,Category = "ExplosiveBarrel")
	TObjectPtr<URadialForceComponent>RadialForceComponent;
	
	UPROPERTY(EditDefaultsOnly, Category = "ExplosiveBarrel")
	TObjectPtr<UStaticMeshComponent>StaticMeshComponent;
	
	UPROPERTY(VisibleAnywhere, Category = "ExplosiveBarrel")
	bool bIsExplode=false;
	
	UFUNCTION()
	void TakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType,
	AController* InstigatedBy, AActor* DamageCauser);
	void Explode();
	
	virtual void BeginPlay() override;



};
