// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerWallet.h"

PlayerWallet::PlayerWallet(int Gold, int Gems) : m_Gold(Gold), m_Gems(Gems)
{
}

PlayerWallet::~PlayerWallet()
{
}

int PlayerWallet::GetGold()
{
	return m_Gold;
}

bool PlayerWallet::PurchaseWithGold(int Gold)
{
	if (m_Gold >= Gold)
	{
		UE_LOG(LogTemp, Warning, TEXT("Purchased"))
		m_Gold = m_Gold - Gold;
		return true;
	}
	return false;
}

bool PlayerWallet::PurchaseWithGems(int Gems)
{
	if (m_Gems >= Gems)
	{
		m_Gems = m_Gems - Gems;
		return true;
	}
	return false;
}
