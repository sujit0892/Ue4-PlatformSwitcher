// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "MainGameMode.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API AMainGameMode : public AGameMode
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	bool Switch;
	void OnSwitch();
	void OnGameOver(bool Win);
	void OnRestart();

	UFUNCTION(BlueprintCallable, Category = "UMG Game")
		void ChanegeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UMG Game")
		TSubclassOf<UUserWidget> StartingWidget;

	UPROPERTY()
		UUserWidget* CurrentWidget;
	
	
};
