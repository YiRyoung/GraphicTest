#include "PreCompile.h"
#include "EngineFont.h"

#ifdef _DEBUG
#pragma comment(lib, "FW1FontWrapper.lib")
#else
#pragma comment(lib, "FW1FontWrapper.lib")
#endif

// dll이므로 여기에다 둘겁니다.
// 이 팩토리를 먼저 만들고
IFW1Factory* FontFactory = nullptr;

class UFontFactoryCreator
{
public:
	UFontFactoryCreator()
	{
		FW1CreateFactory(FW1_VERSION, &FontFactory);
	}
	~UFontFactoryCreator()
	{
		if (nullptr != FontFactory)
		{
			FontFactory->Release();
			FontFactory = nullptr;
		}
	}
};

UFontFactoryCreator Inst;

UEngineFont::UEngineFont()
{
}

UEngineFont::~UEngineFont()
{
}

void UEngineFont::ResLoad(std::string_view _Path)
{
	std::wstring WPath = UEngineString::AnsiToUnicode(_Path);

	D3D11_BLEND_DESC blendDesc = { 0, };
	for (int i = 0; i < 4; ++i)
	{
		blendDesc.RenderTarget[i].BlendEnable = true;
		blendDesc.RenderTarget[i].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;
		blendDesc.RenderTarget[i].BlendOp = D3D11_BLEND_OP_ADD;
		blendDesc.RenderTarget[i].SrcBlend = D3D11_BLEND_SRC_ALPHA;
		blendDesc.RenderTarget[i].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;
		blendDesc.RenderTarget[i].BlendOpAlpha = D3D11_BLEND_OP_ADD;
		blendDesc.RenderTarget[i].SrcBlendAlpha = D3D11_BLEND_ONE;
		blendDesc.RenderTarget[i].DestBlendAlpha = D3D11_BLEND_ONE;
	}

	

	if (FontFactory->CreateFontWrapper(UEngineCore::GetDevice().GetDevice(), WPath.c_str(), blendDesc, &Font))
	{

	}
	
}