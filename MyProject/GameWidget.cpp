// Fill out your copyright notice in the Description page of Project Settings.

#include "GameWidget.h"




void UGameWidget::Load()
{
	const FName TextBlockName = FName(TEXT("MessageBlock1"));

	if (MessageBlock == nullptr)
	{
		MessageBlock = (UTextBlock*)(WidgetTree->FindWidget(TextBlockName));
	}
}

void UGameWidget::OnGameover(bool win)
{
	if (MessageBlock != nullptr)
	{
		if (win)
		{
			MessageBlock->SetText(FText::FromString(FString(TEXT("U Won\n Press R to Play Again"))));
		}
		else
			MessageBlock->SetText(FText::FromString(FString(TEXT("U Lose\n Press R to Play Again"))));
	}
}

