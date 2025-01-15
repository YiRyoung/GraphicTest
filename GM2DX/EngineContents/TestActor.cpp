#include "PreCompile.h"
#include "TestActor.h"

#include <EnginePlatform/EngineInput.h>

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/CameraActor.h>

#include "MyCustomRenderer.h"

TestActor::TestActor()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	Renderer = CreateDefaultSubObject<MyCustomRenderer>();
	Renderer->SetupAttachment(RootComponent);
	Renderer->SetScale3D({ 50, 80, 50 });
}

TestActor::~TestActor()
{
}

