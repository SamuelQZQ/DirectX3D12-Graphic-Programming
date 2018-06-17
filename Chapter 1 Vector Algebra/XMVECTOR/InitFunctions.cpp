/*
#include <windows.h> // 为了使用函数XMVerifyCPUSupport，检查是否支持SSE2
#include <DirectXMath.h>
#include <DirectXPackedVector.h>
#include <iostream>
using namespace std;
using namespace DirectX;
using namespace DirectX::PackedVector;

// 重载  "<<" 运算符，用于输出XMVECTOR类型的对象
ostream& XM_CALLCONV operator<<(ostream& os, FXMVECTOR v)
{
    // XMVECTOR数据不能直接访问，因此要进行转换！
    XMFLOAT3 dest;
    XMStoreFloat3(&dest, v);

    os << "(" << dest.x << ", " << dest.y << ", " << dest.z << ")";
    return os;
}

int main()
{
    // 检查是否支持SSE2 (Pentium4, AMD K8, and above).
    if (!XMVerifyCPUSupport())
    {
        cout << "directx math not supported" << endl;
        return 0;
    }
    
    // 一些常用的获取XMVECTOR对象的函数
    XMVECTOR p = XMVectorZero();
    XMVECTOR q = XMVectorSplatOne();
    XMVECTOR u = XMVectorSet(1.0f, 2.0f, 3.0f, 0.0f);
    XMVECTOR v = XMVectorReplicate(-2.0f);
    XMVECTOR w = XMVectorSplatZ(u);

    cout << "p = " << p << endl;
    cout << "q = " << q << endl;
    cout << "u = " << u << endl;
    cout << "v = " << v << endl;
    cout << "w = " << w << endl;
    
    system("pause");
    return 0;
}
*/