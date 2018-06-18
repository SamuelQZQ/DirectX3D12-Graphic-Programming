#include <iostream>
#include "../../Common/d3dApp.h"
using namespace std;



int main()
{
    // get DXGIFactory
    Microsoft::WRL::ComPtr<IDXGIFactory> dxgiFactory;
    ThrowIfFailed(CreateDXGIFactory(IID_PPV_ARGS(&dxgiFactory)));

    UINT i = 0;
    IDXGIAdapter* adapter = nullptr;
    
    while (dxgiFactory->EnumAdapters(i++, &adapter) != DXGI_ERROR_NOT_FOUND)
    {
        DXGI_ADAPTER_DESC desc;
        adapter->GetDesc(&desc); 

        std::wstring text = L"***Adapter: ";
        text += desc.Description;

        wcout << text << endl;
        ReleaseCom(adapter);
    }

    system("pause");
    return 0;
}