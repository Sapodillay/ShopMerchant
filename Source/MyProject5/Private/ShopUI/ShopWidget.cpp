// Fill out your copyright notice in the Description page of Project Settings.


#include "ShopUI/ShopWidget.h"

#include "Components/ScrollBox.h"

void UShopWidget::Setup(UShopSystem* shopSystem)
{

	M_ShopSystem = shopSystem;
	M_ShopSystem->OnPurchase.AddDynamic(this, &UShopWidget::RemoveItem);
	
	TMap<int, ItemStruct> Items = M_ShopSystem->GetItemDisplay();

	for (const auto Item : Items)
	{
		ParseItem(Item.Key, Item.Value.DisplayName, Item.Value.GemCost);
	}


	
}

void UShopWidget::ParseItem(int ID, FText DisplayString, int Cost)
{

	//register event to the id. hook to the menu system later
	
	//Create new MenuItemWidget.
	if (MenuItemClass)
	{
		UMenuItem* MenuItem = CreateWidget<UMenuItem>(this, MenuItemClass);
		MenuItem->SetData(ID, DisplayString, Cost);
		ItemBox->AddChild(MenuItem);
		MenuItems.Add(MenuItem);
	}
}

void UShopWidget::RemoveItem(int ID)
{
	for (auto MenuItem : MenuItems)
	{
		if(MenuItem->ShopID == ID)
		{
			MenuItems.Remove(MenuItem);
			ItemBox->RemoveChild(MenuItem);
		}
	}
}


