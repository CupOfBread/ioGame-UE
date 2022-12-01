// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "WebsocketGameInstance.h"
#include "iogame/common.pb.h"
#include "iogame/eMsg.pb.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyActor::initLoginCommand()
{
	UWebsocketGameInstance* GameInstance = Cast<UWebsocketGameInstance>(GetGameInstance());
	
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Cyan, "Knock1");
	
	if (GameInstance)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Cyan, "Knock2");
		if (GameInstance->WebSocket->IsConnected())
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Cyan, "Knock3");
			pb::common::LoginVerify LoginVerify;
			LoginVerify.set_age(256);
			LoginVerify.set_jwt("haha");
			LoginVerify.set_loginbizcode(1);

			int lvlen = LoginVerify.ByteSizeLong();
			char* lvs = new char[lvlen];
			LoginVerify.SerializeToArray(lvs, lvlen);


			pb::common::ExternalMessage ExternalMessage;
			ExternalMessage.set_cmdcode(1);
			ExternalMessage.set_protocolswitch(0);
			ExternalMessage.set_cmdmerge(196609);
			ExternalMessage.set_responsestatus(0);
			ExternalMessage.set_data(lvs);

			int len = ExternalMessage.ByteSizeLong();
			char* req = new char[len];
			ExternalMessage.SerializeToArray(req, len);

			GameInstance->WebSocket->Send(req, len, true);
		}
	}
}


