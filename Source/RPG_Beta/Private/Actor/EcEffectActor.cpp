

#include "Actor/EcEffectActor.h"
#include "Components/SphereComponent.h"


AEcEffectActor::AEcEffectActor()
{

	PrimaryActorTick.bCanEverTick = false;
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);

	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	Sphere->SetupAttachment(GetRootComponent());
}


void AEcEffectActor::BeginPlay()
{
	Super::BeginPlay();

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AEcEffectActor::OnOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &AEcEffectActor::EndOverlap);
}

void AEcEffectActor::OnOverlap(
	UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 8, FColor::Blue, "Overlap");
}

void AEcEffectActor::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}
