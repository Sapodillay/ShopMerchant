// Fill out your copyright notice in the Description page of Project Settings.

#pragma once



#include "CoreMinimal.h"
#include "PlayerWallet.h"

#include "UShopSystem.generated.h"


UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPurchase, int, ID, int, Gold);


/**
 * 
 */

struct ItemStruct
{
	int ID;
	FText DisplayName;
	int GoldCost;
	int GemCost;
};

UCLASS()
class MYPROJECT5_API UShopSystem : public UObject
{
	GENERATED_BODY()
	
	//store in struct,
	TMap<int, ItemStruct> M_Items;

	PlayerWallet* M_Wallet;

	TMap<int, ItemStruct> GetItems();

	
public:
	void SetWallet(PlayerWallet* Wallet);
	
	FOnPurchase OnPurchase;

	//Returns item data, used for display.
	TMap<int, ItemStruct> GetItemDisplay();

	TOptional<ItemStruct*> PurchaseItem(int ItemID);
	
};
