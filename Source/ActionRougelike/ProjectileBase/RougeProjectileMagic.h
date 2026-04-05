
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RougeProjectileMagic.generated.h"

class UNiagaraSystem;
class UNiagaraComponent;
class UProjectileMovementComponent;
class USphereComponent;
class USoundBase;
class UAudioComponent;

UCLASS()
class ACTIONROUGELIKE_API ARougeProjectileMagic : public AActor
{
	GENERATED_BODY()

public:
	
	ARougeProjectileMagic();
	virtual void PostInitializeComponents() override;

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Damage")
	TSubclassOf<UDamageType> DamageTypeClass;
	
	UPROPERTY(EditDefaultsOnly, Category = "NiagaraSystem")
	TObjectPtr<UNiagaraSystem>ExplosionEffect;
	
	UPROPERTY(EditDefaultsOnly, Category = "SoundComponent")
	TObjectPtr<USoundBase>ExplosionSound;
	
	UPROPERTY(VisibleAnywhere,Category = "Componement")
	TObjectPtr<USphereComponent>SphereComponent;
	
	UPROPERTY(VisibleAnywhere,Category = "Componement")
	TObjectPtr<UProjectileMovementComponent>ProjectileMovementComponent;
	
	UPROPERTY(VisibleAnywhere, Category = "NiagaraComponent")
	TObjectPtr<UNiagaraComponent>LoopNiagaraComponent;
	
	UPROPERTY(EditDefaultsOnly, Category = "SoundComponent")
	TObjectPtr<UAudioComponent>LoopSoundComponent;
	
	
	UFUNCTION()
	void OnSphereHit(UPrimitiveComponent* HitComponent,AActor* OtherActor,UPrimitiveComponent* OtherComp,FVector NormalImpulse,const FHitResult& Hit);
	

};
