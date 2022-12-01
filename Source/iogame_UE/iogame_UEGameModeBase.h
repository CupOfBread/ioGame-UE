// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "iogame_UEGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class IOGAME_UE_API Aiogame_UEGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable,Category="ioGame")
	void initLoginCommand();
};
