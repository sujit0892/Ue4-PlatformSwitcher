// Fill out your copyright notice in the Description page of Project Settings.

#include "obstacleController.h"
#include "Components/BoxComponent.h"
#include "MainGameMode.h"
#include "GameFramework/Character.h" 
#include "Kismet/GameplayStatics.h"

// Sets default values
AobstacleController::AobstacleController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));
	RootBox->bGenerateOverlapEvents = true;
	RootBox->OnComponentBeginOverlap.AddDynamic(this,&AobstacleController::OnOverlap);
}

// Called when the game starts or when spawned
void AobstacleController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AobstacleController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AobstacleController::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* otherActor, UPrimitiveComponent* otherComponent, int32 otherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (otherActor == UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))
	{
		((AMainGameMode*)GetWorld()->GetAuthGameMode())->OnGameOver(false);
	}
}