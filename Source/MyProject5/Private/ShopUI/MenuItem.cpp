// Fill out your copyright notice in the Description page of Project Settings.


#include "ShopUI/MenuItem.h"

#include "ShopCharacter.h"
#include "Kismet/GameplayStatics.h"

void UMenuItem::SetData(int id, FText DisplayString, int Cost)
{
	ShopID = id;
	DisplayText->SetText(DisplayString);
	CostDisplayText->SetText(FText::AsNumber(Cost));
}


//registed in bp
void UMenuItem::OnButtonClick()
{
	AShopCharacter* ShopCharacter = Cast<AShopCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (ShopCharacter)
	{
		//Try purchase the item.
		ShopCharacter->M_ShopSystem->PurchaseItem(ShopID);
	}
	
}
