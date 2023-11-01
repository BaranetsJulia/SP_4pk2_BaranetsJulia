#include <windows.h> //�� 14, 15, 16
#include <string>
#include "MathLib.h"

HWND hwnd;

// �������� ����������� ����
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

HWND hButton1;
HWND hButton2;
HWND hButton3;
HWND hButton4;
HWND hButton5;
HWND hButton6;
HWND hInput1;
HWND hInput2;
HWND hOutput;

// ������� �������
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // �������� ��������� WNDCLASSEX
    WNDCLASSEX wcex;
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WindowProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = NULL;
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = L"MyWin32Class";
    wcex.hIconSm = NULL;

    // ����������� ������ ����
    if (!RegisterClassEx(&wcex))
    {
        MessageBox(NULL, L"�� ������� ���������������� ����� ����.", L"������", MB_ICONERROR);
        return 1;
    }

    // �������� �������� ����
    hwnd = CreateWindowEx(
        0,
        L"MyWin32Class",
        L"������������ ���������� Win32",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    if (!hwnd)
    {
        MessageBox(NULL, L"�� ������� ������� ������� ����.", L"������", MB_ICONERROR);
        return 1;
    }

    //�������� ������
    hButton1 = CreateWindow(TEXT("BUTTON"), TEXT("+"), WS_VISIBLE | WS_CHILD,
        10, 10, 50, 30, hwnd, NULL, hInstance, NULL);
    hButton2 = CreateWindow(TEXT("BUTTON"), TEXT("-"), WS_VISIBLE | WS_CHILD,
        60, 10, 50, 30, hwnd, NULL, hInstance, NULL);
    hButton3 = CreateWindow(TEXT("BUTTON"), TEXT("*"), WS_VISIBLE | WS_CHILD,
        110, 10, 50, 30, hwnd, NULL, hInstance, NULL);
    hButton4 = CreateWindow(TEXT("BUTTON"), TEXT("/"), WS_VISIBLE | WS_CHILD,
        160, 10, 50, 30, hwnd, NULL, hInstance, NULL);
    hButton5 = CreateWindow(TEXT("BUTTON"), TEXT("pow"), WS_VISIBLE | WS_CHILD,
        210, 10, 50, 30, hwnd, NULL, hInstance, NULL);
    hButton6 = CreateWindow(TEXT("BUTTON"), TEXT("sqrt"), WS_VISIBLE | WS_CHILD,
        260, 10, 50, 30, hwnd, NULL, hInstance, NULL);

    //���� �����
    hInput1 = CreateWindow(TEXT("EDIT"), TEXT(""), WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
        10, 50, 200, 30, hwnd, NULL, hInstance, NULL);
    hInput2 = CreateWindow(TEXT("EDIT"), TEXT(""), WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
        10, 90, 200, 30, hwnd, NULL, hInstance, NULL);

    //���� ������
    hOutput = CreateWindow(TEXT("EDIT"), TEXT(""), WS_VISIBLE | WS_CHILD | WS_BORDER | ES_READONLY | ES_AUTOHSCROLL,
        10, 130, 200, 30, hwnd, NULL, hInstance, NULL);

    // ����������� � ���������� �������� ����
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    // ���� ��������� ���������
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}

HDC hDC; // �������� ����������
PAINTSTRUCT ps;
RECT rect;
bool a = true;

// ���������� ����
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    WCHAR buffer[] = L"����� �� �������";
    WCHAR buffer2[] = L"�������";
    WCHAR buffer3[] = L"���� ����������";
    WCHAR buffer4[] = L"�������";
    WCHAR buffer5[] = L"���������� �������������� �������";
    WCHAR buffer6[] = L"�������";

    switch (uMsg)
    {
    case WM_CLOSE:
        DestroyWindow(hwnd);
        break;
    case WM_RBUTTONDBLCLK:
        MessageBox(
            hwnd, // ������������ ����. ��� NULL, ���� ��� ���.
            buffer, // ��������� ���������.
            buffer2, // ����� ��������� ����.
            MB_ICONINFORMATION); // ��������� ������ � ������ ���� ���������.
        return 1;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    case WM_MOVE:
        MessageBox(
            hwnd, // ������������ ����. ��� NULL, ���� ��� ���.
            buffer3, // ��������� ���������.
            buffer4, // ����� ��������� ����.
            MB_ICONINFORMATION); // ��������� ������ � ������ ���� ���������.
        break;
    case WM_ACTIVATE:
        if (a)
        {
            a = false;
            MessageBox(
                hwnd, // ������������ ����. ��� NULL, ���� ��� ���.
                buffer5, // ��������� ���������.
                buffer6, // ����� ��������� ����.
                MB_ICONINFORMATION); // ��������� ������ � ������ ���� ���������.
        }
        break;
    case WM_COMMAND:
        //������� �� ������� ��������� ����������
        if (HIWORD(wParam) == BN_CLICKED && (HWND)lParam == hButton1)
        {
            //��������� �������� �� ����� �����
            TCHAR inputText1[256];
            GetWindowText(hInput1, inputText1, sizeof(inputText1));
            TCHAR inputText2[256];
            GetWindowText(hInput2, inputText2, sizeof(inputText2));
            //���������� ��������
            double result;
            double value1 = std::stod(inputText1);
            double value2 = std::stod(inputText2);
            result = MathLibrary::Arithmetic::Add(value1, value2);
            //������ ���������� � ���� ������
            std::string outputText = std::to_string(result);
            SetWindowText(hOutput, (LPCWSTR)outputText.c_str());
        }
        if (HIWORD(wParam) == BN_CLICKED && (HWND)lParam == hButton2)
        {
            //��������� �������� �� ����� �����
            TCHAR inputText1[256];
            GetWindowText(hInput1, inputText1, sizeof(inputText1));
            TCHAR inputText2[256];
            GetWindowText(hInput2, inputText2, sizeof(inputText2));
            //���������� ���������
            double result;
            double value1 = std::stod(inputText1);
            double value2 = std::stod(inputText2);
            result = MathLibrary::Arithmetic::Subtract(value1, value2);
            //������ ���������� � ���� ������
            std::string outputText = std::to_string(result);
            SetWindowText(hOutput, (LPCWSTR)outputText.c_str());
        }
        if (HIWORD(wParam) == BN_CLICKED && (HWND)lParam == hButton3)
        {
            //��������� �������� �� ����� �����
            TCHAR inputText1[256];
            GetWindowText(hInput1, inputText1, sizeof(inputText1));
            TCHAR inputText2[256];
            GetWindowText(hInput2, inputText2, sizeof(inputText2));
            //���������� ���������
            double result;
            double value1 = std::stod(inputText1);
            double value2 = std::stod(inputText2);
            result = MathLibrary::Arithmetic::Multiply(value1, value2);
            //������ ���������� � ���� ������
            std::string outputText = std::to_string(result);
            SetWindowText(hOutput, (LPCWSTR)outputText.c_str());
        }
        if (HIWORD(wParam) == BN_CLICKED && (HWND)lParam == hButton4)
        {
            //��������� �������� �� ����� �����
            TCHAR inputText1[256];
            GetWindowText(hInput1, inputText1, sizeof(inputText1));
            TCHAR inputText2[256];
            GetWindowText(hInput2, inputText2, sizeof(inputText2));
            //���������� �������
            double result;
            double value1 = std::stod(inputText1);
            double value2 = std::stod(inputText2);
            result = MathLibrary::Arithmetic::Divide(value1, value2);
            //������ ���������� � ���� ������
            std::string outputText = std::to_string(result);
            SetWindowText(hOutput, (LPCWSTR)outputText.c_str());
        }
        if (HIWORD(wParam) == BN_CLICKED && (HWND)lParam == hButton5)
        {
            //��������� �������� �� ����� �����
            TCHAR inputText1[256];
            GetWindowText(hInput1, inputText1, sizeof(inputText1));
            TCHAR inputText2[256];
            GetWindowText(hInput2, inputText2, sizeof(inputText2));
            //���������� ���������� � �������
            double result;
            double value1 = std::stod(inputText1);
            double value2 = std::stod(inputText2);
            result = MathLibrary::Arithmetic::Exponentiation(value1, value2);
            //������ ���������� � ���� ������
            std::string outputText = std::to_string(result);
            SetWindowText(hOutput, (LPCWSTR)outputText.c_str());
        }
        if (HIWORD(wParam) == BN_CLICKED && (HWND)lParam == hButton6)
        {
            //��������� �������� �� ����� �����
            TCHAR inputText1[256];
            GetWindowText(hInput1, inputText1, sizeof(inputText1));
            TCHAR inputText2[256];
            GetWindowText(hInput2, inputText2, sizeof(inputText2));
            //���������� ���������� �����
            double result;
            double value1 = std::stod(inputText1);
            double value2 = std::stod(inputText2);
            result = MathLibrary::Arithmetic::Root(value1, value2);
            //������ ���������� � ���� ������
            std::string outputText = std::to_string(result);
            SetWindowText(hOutput, (LPCWSTR)outputText.c_str());
        }
        break;

    case WM_PAINT:
        hDC = BeginPaint(hwnd, &ps);
        GetClientRect(hwnd, &rect);
        DrawText(hDC, TEXT("�������������� �������"), -1, &rect, DT_SINGLELINE |
            DT_CENTER | DT_VCENTER);
        EndPaint(hwnd, &ps);
        return 0;
    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }

    return 0;
}