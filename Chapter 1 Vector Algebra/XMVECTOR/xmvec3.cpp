/*
#include <windows.h> // 为了使用函数XMVerifyCPUSupport，检查是否支持SSE2
#include <DirectXMath.h>
#include <DirectXPackedVector.h>
#include <iostream>
using namespace std;
using namespace DirectX;
using namespace DirectX::PackedVector;

// 重载  "<<" 运算符，用于输出XMVECTOR类型的对象
ostream& XM_CALLCONV operator << (ostream& os, FXMVECTOR v)
{
    // XMVECTOR数据不能直接访问，因此要进行转换！
    XMFLOAT3 dest;
    XMStoreFloat3(&dest, v);

    os << "(" << dest.x << ", " << dest.y << ", " << dest.z << ")";
    return os;
}

int main()
{
    cout.setf(ios_base::boolalpha);

    // 检查是否支持SSE2 (Pentium4, AMD K8, and above).
    if (!XMVerifyCPUSupport())
    {
        cout << "directx math not supported" << endl;
        return 0;
    }

    XMVECTOR n = XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f);
    XMVECTOR u = XMVectorSet(1.0f, 2.0f, 3.0f, 0.0f);
    XMVECTOR v = XMVectorSet(-2.0f, 1.0f, -3.0f, 0.0f);
    XMVECTOR w = XMVectorSet(0.707f, 0.707f, 0.0f, 0.0f);

    // Vector addition: XMVECTOR operator + 
    XMVECTOR a = u + v;

    // Vector subtraction: XMVECTOR operator - 
    XMVECTOR b = u - v;

    // Scalar multiplication: XMVECTOR operator * 
    XMVECTOR c = 10.0f*u;

    // 向量的模 ||u||
    XMVECTOR L = XMVector3Length(u);

    // d = u / ||u||
    XMVECTOR d = XMVector3Normalize(u);

    // s = u dot v
    XMVECTOR s = XMVector3Dot(u, v);

    // e = u x v
    XMVECTOR e = XMVector3Cross(u, v);

    // 计算w平行于n、垂直于n的两个分量
    XMVECTOR projW;
    XMVECTOR perpW;
    XMVector3ComponentsFromNormal(&projW, &perpW, w, n);

    // Does projW + perpW == w?
    bool equal = XMVector3Equal(projW + perpW, w) != 0;
    bool notEqual = XMVector3NotEqual(projW + perpW, w) != 0;

    //  projW 和 perpW 成90度.
    XMVECTOR angleVec = XMVector3AngleBetweenVectors(projW, perpW);
    float angleRadians = XMVectorGetX(angleVec);
    float angleDegrees = XMConvertToDegrees(angleRadians);

    cout << "u                   = " << u << endl;
    cout << "v                   = " << v << endl;
    cout << "w                   = " << w << endl;
    cout << "n                   = " << n << endl;
    cout << "a = u + v           = " << a << endl;
    cout << "b = u - v           = " << b << endl;
    cout << "c = 10 * u          = " << c << endl;
    cout << "d = u / ||u||       = " << d << endl;
    cout << "e = u x v           = " << e << endl;
    cout << "L  = ||u||          = " << L << endl;
    cout << "s = u.v             = " << s << endl;
    cout << "projW               = " << projW << endl;
    cout << "perpW               = " << perpW << endl;
    cout << "projW + perpW == w  = " << equal << endl;
    cout << "projW + perpW != w  = " << notEqual << endl;
    cout << "angle               = " << angleDegrees << endl;

    system("pause");
    return 0;
}
*/