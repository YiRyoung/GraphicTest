#include "PreCompile.h"
#include "TestGameMode.h"

#include <EnginePlatform/EngineInput.h>

#include <EngineCore/CameraActor.h>
#include <EngineCore/DefaultSceneComponent.h>

#include "TestActor.h"
#include "MyCustomRenderer.h"

ATestGameMode::ATestGameMode()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	Actor = GetWorld()->SpawnActor<TestActor>();
}

ATestGameMode::~ATestGameMode()
{
}

void ATestGameMode::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
	Actor->AddActorRotation({ 0.0f, 0.0f, 100.0f * _DeltaTime });

	if (UEngineInput::IsDown('P'))
	{
		GetWorld()->GetMainCamera()->FreeCameraSwitch();
	}
}

