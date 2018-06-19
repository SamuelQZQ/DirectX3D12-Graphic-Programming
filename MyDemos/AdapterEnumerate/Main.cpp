#include <iostream>
#include "../../Common/d3dApp.h"
using namespace std;

void LogOutputDisplayModes(IDXGIOutput* output)
{

    DXGI_FORMAT format = DXGI_FORMAT_R8G8B8A8_UNORM;
    UINT count = 0;
    UINT flags = 0;

    // Call with nullptr to get list count.
    output->GetDisplayModeList(format, flags, &count, nullptr);

    vector<DXGI_MODE_DESC> modeList(count);
    output->GetDisplayModeList(format, flags, &count, &modeList[0]);

    for (auto& x : modeList)
    {
        UINT n = x.RefreshRate.Numerator;
        UINT d = x.RefreshRate.Denominator;
        wstring text =
            L"Width = " + std::to_wstring(x.Width) + L" " +
            L"Height = " + std::to_wstring(x.Height) + L" " +
            L"Refresh = " + std::to_wstring(n) + L"/" + std::to_wstring(d);

        wcout << "   " << text << endl;
    }
}

/*Output the monitor managed by the graphic card*/
void LogAdapterOutputs(IDXGIAdapter* adapter)
{
    UINT i = 0;
    Microsoft::WRL::ComPtr<IDXGIOutput> output = nullptr;
    while(adapter->EnumOutputs(i++, output.GetAddressOf()) != DXGI_ERROR_NOT_FOUND)
    {
        DXGI_OUTPUT_DESC desc;
        output->GetDesc(&desc);

        wstring text = L"***Output: ";
        text += desc.DeviceName;
        wcout << text << endl;
        LogOutputDisplayModes(output.Get());
    }
}

int main()
{
    // get DXGIFactory
    Microsoft::WRL::ComPtr<IDXGIFactory> dxgiFactory;
    ThrowIfFailed(CreateDXGIFactory(IID_PPV_ARGS(&dxgiFactory)));

    UINT i = 0;
    Microsoft::WRL::ComPtr<IDXGIAdapter> adapter = nullptr;
    
    while (dxgiFactory->EnumAdapters(i++, adapter.GetAddressOf()) != DXGI_ERROR_NOT_FOUND)
    {
        DXGI_ADAPTER_DESC desc;
        adapter->GetDesc(&desc); 

        wstring text = L"###Adapter: ";
        text += desc.Description;
        wcout << text << endl;
        LogAdapterOutputs(adapter.Get());
    }

    system("pause");
    return 0;
}