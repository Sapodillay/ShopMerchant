// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class MYPROJECT5_API PlayerWallet
{

	int m_Gold;
	int m_Gems;
	
public:
	PlayerWallet(int Gold, int Gems);
	~PlayerWallet();


	int GetGold();
	
	bool PurchaseWithGold(int Gold);
	
	bool PurchaseWithGems(int Gems);
	
};
