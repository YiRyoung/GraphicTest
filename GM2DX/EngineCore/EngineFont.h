#pragma once
#include "EngineResources.h"

#include "ThirdParty/FW1FontWrapper/Inc/FW1FontWrapper.h"

// ���� :
class UEngineFont : public UEngineResources
{
public:
	// constrcuter destructer
	UEngineFont();
	~UEngineFont();

	// delete Function
	UEngineFont(const UEngineFont& _Other) = delete;
	UEngineFont(UEngineFont&& _Other) noexcept = delete;
	UEngineFont& operator=(const UEngineFont& _Other) = delete;
	UEngineFont& operator=(UEngineFont&& _Other) noexcept = delete;

protected:

private:
	// FMOD::Syatem*
	IFW1FontWrapper* Font;
	void ResLoad(std::string_view _Path);
};

