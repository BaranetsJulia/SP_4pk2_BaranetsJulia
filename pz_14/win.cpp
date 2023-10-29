#include <windows.h> //�� 14, 15

HWND hwnd;

// �������� ����������� ����
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

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
    WCHAR buffer[] = L"���� ������";
    WCHAR buffer2[] = L"�������";

    switch (uMsg)
    {
    case WM_CLOSE:
        DestroyWindow(hwnd);
        break;
    case WM_ACTIVATE:
        if (a)
        {
            a = false;
            MessageBox(
                hwnd, // ������������ ����. ��� NULL, ���� ��� ���.
                buffer, // ��������� ���������.
                buffer2, // ����� ��������� ����.
                MB_ICONINFORMATION); // ��������� ������ � ������ ���� ���������.
        }
        break;
    case WM_PAINT:
        hDC = BeginPaint(hwnd, &ps);
        GetClientRect(hwnd, &rect);
        DrawText(hDC, TEXT("������ �������: �������, ����, �����, �����, ������!"), -1, &rect, DT_SINGLELINE |
            DT_CENTER | DT_VCENTER);
        EndPaint(hwnd, &ps);
        return 0;
    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }

    return 0;
}