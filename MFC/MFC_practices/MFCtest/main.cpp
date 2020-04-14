#include <windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(HINSTANCE hInstance, 
    HINSTANCE,
    PWSTR pCmdLine, 
    int nCmdShow)
{
    // Register the window class.
    //wchar_t 宽字符类型         L放在字符串前表示声明为宽字符串
    const wchar_t CLASS_NAME[] = L"Sample Window Class";

    WNDCLASS wc = { };

    //lpfnWndProc 长函数指针(lp: 长指针, fn: 函数)
    wc.lpfnWndProc = WindowProc;
    //实例句柄
    wc.hInstance = hInstance;
    // 窗口类名
    wc.lpszClassName = CLASS_NAME;

    //注册窗口类
    RegisterClass(&wc);

    // Create the window.

    //创建窗口
    HWND hwnd = CreateWindowEx(
        0,                              // Optional window styles.可选窗口样式
        CLASS_NAME,                     // Window class 窗口类
        L"test",                        // Window text  窗口(标题)文本
        WS_OVERLAPPEDWINDOW,            // Window style 窗口样式

        // Size and position 尺寸和位置
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL,       // Parent window 父窗口    
        NULL,       // Menu 菜单
        hInstance,  // Instance handle 实例句柄
        NULL        // Additional application data 额外应用程序数据
    );

    //窗口创建失败
    if (hwnd == NULL)
    {
        return 0;
    }

    //显示窗口
    ShowWindow(hwnd, nCmdShow);

    // Run the message loop.

    //消息
    MSG msg = { };
    //获取消息
    while (GetMessage(&msg, NULL, 0, 0))
    {
        //处理消息
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, //窗口句柄
    UINT uMsg, //消息
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
        //开始绘制
        HDC hdc = BeginPaint(hwnd, &ps);


        //绘制矩形                  HBRUSH 画刷句柄
        FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

        //结束绘制
        EndPaint(hwnd, &ps);
    }
    return 0;

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}