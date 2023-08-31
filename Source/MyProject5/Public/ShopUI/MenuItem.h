// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "MenuItem.generated.h"


/**
 * 
 */
UCLASS()
class MYPROJECT5_API UMenuItem : public UUserWidget
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UTextBlock* DisplayText;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UTextBlock* CostDisplayText;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UButton* BuyButton;

public:
	int ShopID;
	
	void SetData(int ID, FText DisplayString, int Cost);

	UFUNCTION(BlueprintCallable)
	void OnButtonClick();
	
};
