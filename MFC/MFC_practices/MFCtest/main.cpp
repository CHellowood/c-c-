#include <windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(HINSTANCE hInstance, 
    HINSTANCE,
    PWSTR pCmdLine, 
    int nCmdShow)
{
    // Register the window class.
    //wchar_t ���ַ�����         L�����ַ���ǰ��ʾ����Ϊ���ַ���
    const wchar_t CLASS_NAME[] = L"Sample Window Class";

    WNDCLASS wc = { };

    //lpfnWndProc ������ָ��(lp: ��ָ��, fn: ����)
    wc.lpfnWndProc = WindowProc;
    //ʵ�����
    wc.hInstance = hInstance;
    // ��������
    wc.lpszClassName = CLASS_NAME;

    //ע�ᴰ����
    RegisterClass(&wc);

    // Create the window.

    //��������
    HWND hwnd = CreateWindowEx(
        0,                              // Optional window styles.��ѡ������ʽ
        CLASS_NAME,                     // Window class ������
        L"test",                        // Window text  ����(����)�ı�
        WS_OVERLAPPEDWINDOW,            // Window style ������ʽ

        // Size and position �ߴ��λ��
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL,       // Parent window ������    
        NULL,       // Menu �˵�
        hInstance,  // Instance handle ʵ�����
        NULL        // Additional application data ����Ӧ�ó�������
    );

    //���ڴ���ʧ��
    if (hwnd == NULL)
    {
        return 0;
    }

    //��ʾ����
    ShowWindow(hwnd, nCmdShow);

    // Run the message loop.

    //��Ϣ
    MSG msg = { };
    //��ȡ��Ϣ
    while (GetMessage(&msg, NULL, 0, 0))
    {
        //������Ϣ
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, //���ھ��
    UINT uMsg, //��Ϣ
    WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        //��ʼ����
        HDC hdc = BeginPaint(hwnd, &ps);


        //���ƾ���                  HBRUSH ��ˢ���
        FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

        //��������
        EndPaint(hwnd, &ps);
    }
    return 0;

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}