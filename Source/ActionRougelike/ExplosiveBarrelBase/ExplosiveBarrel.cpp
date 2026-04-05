
#include "ExplosiveBarrel.h"

#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "Components/AudioComponent.h"
#include "Kismet/GameplayStatics.h"
#include "PhysicsEngine/RadialForceComponent.h"


AExplosiveBarrel::AExplosiveBarrel()
{
	
	StaticMeshComponent=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	RootComponent=StaticMeshComponent;
	StaticMeshComponent->SetSimulatePhysics(true);
	StaticMeshComponent->SetCollisionProfileName("PhysicsActor");
	
	RadialForceComponent=CreateDefaultSubobject<URadialForceComponent>(TEXT("RadialForceComponent"));
	RadialForceComponent->SetupAttachment(StaticMeshComponent);
	RadialForceComponent->Radius=700.0f;
	RadialForceComponent->ImpulseStrength=150000.0f;
	
	LoopFireSound=CreateDefaultSubobject<UAudioComponent>(TEXT("LoopFireSound"));
	LoopFireSound->SetupAttachment(StaticMeshComponent);
	LoopFireSound->bAutoActivate=false;
	
	LoopFireNiagara=CreateDefaultSubobject<UNiagaraComponent>(TEXT("LoopFireNiagara"));
	LoopFireNiagara->SetupAttachment(StaticMeshComponent);
	LoopFireNiagara->bAutoActivate=false;

}

void AExplosiveBarrel::BeginPlay()
{
	Super::BeginPlay();
	OnTakeAnyDamage.AddDynamic(this,&AExplosiveBarrel::TakeDamage);
}


void AExplosiveBarrel::TakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType,AController* InstigatedBy, AActor* DamageCauser)
{
	if (!bIsExplode)
	{
		LoopFireSound->Play();
		LoopFireNiagara->Activate();
		FTimerHandle ExplodeHandle;
		float ExplodeTime=3.0f;
		GetWorldTimerManager().SetTimer(ExplodeHandle,this,&AExplosiveBarrel::Explode,ExplodeTime);
	}
	
	
}

void AExplosiveBarrel::Explode()
{
	bIsExplode=true;
	LoopFireSound->Stop();
	LoopFireNiagara->Deactivate();
	UGameplayStatics::PlaySoundAtLocation(this,ExplodeSound,GetActorLocation());
	UNiagaraFunctionLibrary::SpawnSystemAtLocation(this,ExplodeEffect,GetActorLocation());
	RadialForceComponent->FireImpulse();
}

