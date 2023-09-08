#include <Windows.h>
#include <windowsx.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
{
	static LPCTSTR szAppName = "EasyText";		// ������ Ŭ���� �̸�
	static LPCTSTR szTitleName = "Practice1-1";		// Ÿ��Ʋ �ٿ� ��µ� ���ڿ�

	HWND	hWnd;					// ������ �ڵ�
	MSG		msg;					// �޽��� ����ü
	WNDCLASSEX	WndClass;			// ������ Ŭ���� ����ü

	// 1. ������ Ŭ���� ����ü WndClass�� ���� ä�� ������ Ŭ������ ����Ѵ�.
	WndClass.cbSize = sizeof(WNDCLASSEX);		// ����ü ũ��
	WndClass.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;	// Ŭ���� ��Ÿ��
	WndClass.lpfnWndProc = WndProc;		// ������ ���ν���
	WndClass.cbClsExtra = 0;			// ������Ŭ���� �����Ϳ���
	WndClass.cbWndExtra = 0;			// �������� �����Ϳ���
	WndClass.hInstance = hInstance;		// �ν��Ͻ� �ڵ�
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION); // ������ �ڵ�
	WndClass.hCursor = LoadCursor(NULL, IDC_HAND); // Ŀ�� �ڵ�
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); // ��� �귯�� �ڵ�
	WndClass.lpszMenuName = NULL; // �޴� �̸�
	WndClass.lpszClassName = szAppName; // ������ Ŭ���� �̸�
	WndClass.hIconSm = 0; // �⺻���� ���� ������

	// ������ Ŭ������ ����Ѵ�.
	RegisterClassEx(&WndClass);

	// 2. ������ �����츦 �����Ѵ�.
	hWnd = CreateWindow(		// ������ ���� API �Լ�
		szAppName,		// ��ϵ� ������ Ŭ���� �̸�
		szTitleName,    // Ÿ��Ʋ �ٿ� ��µ� ���ڿ�
		WS_OVERLAPPEDWINDOW, // ������ ��Ÿ��
		CW_USEDEFAULT,		// ������ ���� ����� x��ǥ-> ����Ʈ
		CW_USEDEFAULT,		// ������ ���� ����� y��ǥ -> ����Ʈ
		CW_USEDEFAULT,		// �������� �ʺ� -> ����Ʈ
		CW_USEDEFAULT,		// �������� ���� -> ����Ʈ
		NULL,				// �θ� �������� �ڵ�
		NULL,				// �޴� �Ǵ� �ڽ� �������� �ڵ�
		hInstance,			// ���ø����̼� �ν��Ͻ� �ڵ�
		NULL				// ������ ���� �������� �ּ�
	);

	// ������ �����츦 ȭ�鿡 ǥ���Ѵ�.
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	// 3. �޽��� ť�κ��� �޽����� �޾ƿ� �޽����� �ش� ������ ���ν����� ������.
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);			// �޽����� �����Ѵ�.
		DispatchMessage(&msg);			// �޽����� �ش� ������ ���ν����� ������.
	}

	return msg.wParam;

}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hdc; // ����̽� ���ؽ�Ʈ
	RECT rect; // RECT ����ü
	PAINTSTRUCT ps; // ����Ʈ ����ü
	LPCTSTR szMsg1 = "I Love Window Programming!"; // �����쿡 ��µ� ���ڿ�
	LPCTSTR szMsg2 = "Ű���尡 ���������ϴ�."; // Ű���带 ������ �� ��µ� ���ڿ�
	LPCTSTR szMsg3 = "Ű���尡 ���������ϴ�."; // Ű���带 ������ �� ��µ� ���ڿ�
	LPCTSTR szMsg4 = "LButtonDown";
	LPCSTR szLMouseDownMessage = "���� ���콺�� Ŭ���Ǿ����ϴ�.";
	LPCSTR szRMouseDownMessage = "������ ���콺�� Ŭ���Ǿ����ϴ�.";
	LPCSTR szLMouseUpMessage = "���� ���콺�� ���������ϴ�.";
	LPCSTR szRMouseUpMessage = "������ ���콺�� ���������ϴ�.";
	LPCSTR szLMouseBlclkMessage = "���� ���콺�� ����Ŭ�� �Ͽ����ϴ�.";
	LPCSTR szMouseMoveMessage = "���콺�� �̵� �� �Դϴ�.";
	LPCSTR szEmptyMessage = "                                                             ";
	int x = GET_X_LPARAM(lParam);
	int y = GET_Y_LPARAM(lParam);

	// 1. Ŀ�ο��� ���� �޽����� switch���� �̿��Ͽ� ó��
	switch (message)
	{
	case WM_CREATE:			// �����찡 ó�� ���� �޽����� �� ���
		break;
	case WM_PAINT: // ȭ�鿡 ��� �޽����� �� ���
		hdc = BeginPaint(hWnd, &ps);
		TextOut(hdc, 10, 10, szMsg1, strlen(szMsg1)); // �����쿡 ���ڿ��� ���
		EndPaint(hWnd, &ps);
		break;
	case WM_KEYDOWN: // Ű���� ��ư�� ���� ���
		hdc = GetDC(hWnd);
		GetClientRect(hWnd, &rect);
		DrawText(hdc, szMsg2, strlen(szMsg2), &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		ReleaseDC(hWnd, hdc);
		break;
	case WM_KEYUP:		// Ű���� ��ư�� ����� ���
		hdc = GetDC(hWnd);
		GetClientRect(hWnd, &rect);
		DrawText(hdc, szMsg3, strlen(szMsg3), &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		ReleaseDC(hWnd, hdc);
		break;
	case WM_LBUTTONDBLCLK: // ���� ���콺�� ���� Ŭ�� �� ���
		MessageBox(hWnd, szLMouseBlclkMessage, "���콺 Ŭ��", MB_OK | MB_ICONASTERISK);
		break;
	case WM_LBUTTONDOWN:
		hdc = GetDC(hWnd);
		TextOut(hdc, 20, 528, szLMouseDownMessage, strlen(szLMouseDownMessage));
		WCHAR text[100];
		wsprintf((LPSTR)text, " x : %d \t y : %d", x, y);
		TextOut(hdc, x + 5, y, LPSTR(text), lstrlen(LPSTR(text)));
		break;
	case WM_MOUSEMOVE:
		hdc = GetDC(hWnd);
		GetClientRect(hWnd, &rect);
		DrawText(hdc, szMouseMoveMessage, strlen(szMouseMoveMessage), &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		break;
	case WM_RBUTTONDOWN:
		hdc = GetDC(hWnd);
		TextOut(hdc, 900, 524, szRMouseDownMessage, strlen(szRMouseDownMessage));
		break;
	case WM_RBUTTONUP:
		hdc = GetDC(hWnd);
		TextOut(hdc, 900, 524, szEmptyMessage, strlen(szEmptyMessage));
	case WM_LBUTTONUP:
		hdc = GetDC(hWnd);
		GetClientRect(hWnd, &rect);
		TextOut(hdc, 10, 528, szEmptyMessage, strlen(szEmptyMessage));
		break;
	case WM_DESTROY:		// ���α׷��� ����� ���
		PostQuitMessage(0);
		break;
	
	default:		// �� ���� �޽����� �� ���
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;


}