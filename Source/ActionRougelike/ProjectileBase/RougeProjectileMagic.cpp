
#include "RougeProjectileMagic.h"

#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/AudioComponent.h"


ARougeProjectileMagic::ARougeProjectileMagic()
{
	SphereComponent=CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	RootComponent=SphereComponent;
	SphereComponent->SetSphereRadius(16.0f);
	SphereComponent->SetCollisionProfileName(TEXT("Projectiles"));
	
	ProjectileMovementComponent=CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	ProjectileMovementComponent->InitialSpeed=2000.0f;
	ProjectileMovementComponent->MaxSpeed=2000.0f;
	ProjectileMovementComponent->ProjectileGravityScale=0.0f;
	
	LoopNiagaraComponent=CreateDefaultSubobject<UNiagaraComponent>(TEXT("LoopNiagaraComponent"));
	LoopNiagaraComponent->SetupAttachment(RootComponent);
	
	LoopSoundComponent=CreateDefaultSubobject<UAudioComponent>(TEXT("LoopSoundComponent"));
	LoopSoundComponent->SetupAttachment(RootComponent);
	
}

void ARougeProjectileMagic::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	SphereComponent->OnComponentHit.AddDynamic(this,&ARougeProjectileMagic::OnSphereHit);
	SphereComponent->IgnoreActorWhenMoving(GetInstigator(),true);
	
}

void ARougeProjectileMagic::OnSphereHit(UPrimitiveComponent* HitComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	FVector HitDirection=GetActorRotation().Vector();
	UGameplayStatics::ApplyPointDamage(OtherActor,10.0f,HitDirection,Hit,GetInstigatorController(),this,DamageTypeClass);
	UNiagaraFunctionLibrary::SpawnSystemAtLocation(this,ExplosionEffect,GetActorLocation());
	UGameplayStatics::PlaySoundAtLocation(this,ExplosionSound,GetActorLocation());
	Destroy();
}

