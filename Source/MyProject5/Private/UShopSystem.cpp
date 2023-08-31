// Fill out your copyright notice in the Description page of Project Settings.


#include "UShopSystem.h"

//Dummy items
TMap<int, ItemStruct> UShopSystem::GetItems()
{

	TMap<int, ItemStruct> DummyData;

	ItemStruct Item1;
	Item1.DisplayName = FText::FromString("Wood");
	Item1.GemCost = 5;
	Item1.GoldCost = 100;
	DummyData.Add(1, Item1);
	
	ItemStruct Item2;
	Item2.DisplayName = FText::FromString("Dirt");
	Item2.GemCost = 5;
	Item2.GoldCost = 100;
	DummyData.Add(2, Item2);
	
	ItemStruct Item3;
	Item3.DisplayName = FText::FromString("Iron");
	Item3.GemCost = 5;
	Item3.GoldCost = 100;
	DummyData.Add(3, Item3);

	ItemStruct Item4;
	Item4.DisplayName = FText::FromString("Test1");
	Item4.GemCost = 5;
	Item4.GoldCost = 100;
	DummyData.Add(4, Item4);

	ItemStruct Item5;
	Item5.DisplayName = FText::FromString("Test2");
	Item5.GemCost = 5;
	Item5.GoldCost = 100;
	DummyData.Add(5, Item5);

	ItemStruct Item6;
	Item6.DisplayName = FText::FromString("Test3");
	Item6.GemCost = 5;
	Item6.GoldCost = 100;
	DummyData.Add(6, Item6);

	
	return DummyData;
}

TOptional<ItemStruct*> UShopSystem::PurchaseItem(int ItemID)
{
	UE_LOG(LogTemp, Warning, TEXT("tried to buy item"))
	if (M_Items.Contains(ItemID))
	{
		ItemStruct* Item = M_Items.Find(ItemID);
		if (M_Wallet->PurchaseWithGems(Item->GoldCost))
		{
			UE_LOG(LogTemp, Warning, TEXT("Bought item"))
			OnPurchase.Broadcast(ItemID);
			M_Items.Remove(ItemID);
			return Item;
		}
		return nullptr;
	}
	return nullptr;
}

void UShopSystem::SetWallet(PlayerWallet* Wallet)
{
	M_Wallet = Wallet;

	M_Items = GetItems();
}

TMap<int, ItemStruct> UShopSystem::GetItemDisplay()
{
	return M_Items;
}
