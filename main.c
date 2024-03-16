#include <stdio.h>
#include <windows.h>

// window procedure
LRESULT CALLBACK xdProcedure(HWND, UINT, WPARAM, LPARAM);

// menus
void AddMenus(HWND);

HMENU hMenu;

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE prevInst, LPSTR args, int ncmdshow) {
    
    // struct
    WNDCLASSW xd = {0};

    xd.hbrBackground = (HBRUSH)COLOR_WINDOW;
    xd.hCursor = LoadCursor(NULL, IDC_ARROW);
    xd.hInstance = hInst;
    xd.lpszClassName = L"deltaProject";
    xd.lpfnWndProc = xdProcedure;

    if (!(RegisterClassW(&xd)))
        return -1;

    CreateWindowW(L"deltaProject", L"Delta", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 0, 0, 500, 500, NULL, NULL, NULL, NULL);

    // struct
    MSG msg = {0};

    // window loop
    while (GetMessage(&msg, NULL, NULL, NULL)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK xdProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {

    switch (msg) {
        case WM_COMMAND:

            switch (wp) {
                case 0:
                    MessageBeep(MB_OK);
                    break;
                case 1:
                    MessageBox(NULL, "Not yet implemented", "Err", MB_OK);
                    MessageBeep(MB_YESNO);
                    break;
            }
         
            break;
        case WM_CREATE:
            AddMenus(hWnd);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProcW(hWnd, msg, wp, lp);
            break;
    }

}

void AddMenus(HWND hWnd) {

    hMenu = CreateMenu();
    HMENU hPrefMenu = CreateMenu();
    AppendMenu(hMenu, MF_STRING, 0, "File");
    AppendMenu(hMenu, MF_POPUP, (UINT_PTR) hPrefMenu, "Preferences");

    // preference menu
    {
        AppendMenu(hPrefMenu, MF_STRING, 1, "Settings");
        AppendMenu(hPrefMenu, MF_STRING, 1, "Theme");
    }

    SetMenu(hWnd, hMenu);

}