// Fill out your copyright notice in the Description page of Project Settings.

#include "MainGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "GameWidget.h"
#include "Runtime/Engine/Classes/GameFramework/Character.h"



void AMainGameMode::BeginPlay()
{
	Super::BeginPlay();

	ChanegeMenuWidget(StartingWidget);
	((UGameWidget*)CurrentWidget)->Load();

	GetWorld()->GetFirstPlayerController()->InputComponent->BindAction("Switch", IE_Pressed, this, &AMainGameMode::OnSwitch);
	GetWorld()->GetFirstPlayerController()->InputComponent->BindAction("Restart", IE_Pressed, this, &AMainGameMode::OnRestart).bExecuteWhenPaused=true;

}

void AMainGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void AMainGameMode::OnSwitch()
{
	if (Switch)
	{
		FVector NewLocation = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->GetActorLocation();
		NewLocation.X = 1200.0f;
		UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->SetActorLocation(NewLocation);
	}
	else
	{
		FVector NewLocation = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->GetActorLocation();
		NewLocation.X = 280.0f;
		UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->SetActorLocation(NewLocation);
		
	}
	Switch = !Switch;
}

void AMainGameMode::OnGameOver(bool win)
{
	((UGameWidget*)CurrentWidget)->OnGameover(win);
	UGameplayStatics::SetGamePaused(GetWorld(), true);
	
}

void AMainGameMode::ChanegeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass)
{
	if (CurrentWidget != nullptr)
	{
		CurrentWidget->RemoveFromViewport();
		CurrentWidget = nullptr;
	}

	if (NewWidgetClass != nullptr)
	{
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), NewWidgetClass);
		if (CurrentWidget != nullptr)
		{
			CurrentWidget->AddToViewport();
		}
	}
}

void AMainGameMode::OnRestart()
{
	UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
}