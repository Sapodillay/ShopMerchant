// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MenuItem.h"
#include "UShopSystem.h"
#include "Blueprint/UserWidget.h"
#include "ShopWidget.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT5_API UShopWidget : public UUserWidget
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UMenuItem> MenuItemClass;

	UPROPERTY()
	TArray<UMenuItem*> MenuItems;

	UShopSystem* M_ShopSystem;
	

	//Box to add the menu items too
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UScrollBox* ItemBox;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* GoldDisplay;

	
public:

	void Setup(UShopSystem* ShopSystem, int StartGold);
	
	void ParseItem(int ID, FText DisplayString, int Cost);

	UFUNCTION()
	void RemoveAndUpdate(int ID, int Gold);

	UFUNCTION()
	void SetGoldDisplay(int Gold);
	
};
