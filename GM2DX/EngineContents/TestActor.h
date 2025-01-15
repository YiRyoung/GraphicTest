#pragma once
#include <EngineCore/Actor.h>

#include "MyCustomRenderer.h"

// Ό³Έν :
class TestActor : public AActor
{
public:
	// constrcuter destructer
	TestActor();
	~TestActor();

	// delete Function
	TestActor(const TestActor& _Other) = delete;
	TestActor(TestActor&& _Other) noexcept = delete;
	TestActor& operator=(const TestActor& _Other) = delete;
	TestActor& operator=(TestActor&& _Other) noexcept = delete;

protected:

private:
	std::shared_ptr<class MyCustomRenderer> Renderer;
};

