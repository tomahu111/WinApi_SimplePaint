//﻿#if defined(UNICODE) && !defined(_UNICODE)

#define _UNICODE

//#elif defined(_UNICODE) && !defined(UNICODE)

#define UNICODE

//#endif



#include <tchar.h>

#include <string>

#include <windows.h>

//#include "resource.h"
// #include "menu.rc"



#define IDPRZYCISKU1 505



void AddMenus(HWND);

#define IDM_FILE_NEW 1

#define IDM_FILE_OPEN 2

#define IDM_FILE_QUIT 3


/* zmienne */


// int a = 150, b = 150;

/*  Declare Windows procedure  */

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);



/*  Make the class name into a global variable  */

TCHAR szClassName[] = _T("CodeBlocksWindowsApp");



HWND czarny, czerwony, zielony, niebieski, prostokat, linia; /* dodawanie kontroliki uchwytu dla przycisku */

HWND hText;

HDC hdc;

LPSTR bufor;

DWORD size;

HPEN kolorpisaka;

int x, y, lastx, lasty;

int WINAPI WinMain(HINSTANCE hThisInstance,

    HINSTANCE hPrevInstance,

    LPSTR lpszArgument,

    int nCmdShow)

{

    HWND hwnd;        /* This is the handle for our window */

    MSG messages;     /* Here messages to the application are saved */

    WNDCLASSEX wincl; /* Data structure for the windowclass */



    /* dodawanie menu programu */

    /* HMENU hMenu = LoadMenu(HINSTANCE hInstance, MAKEINTRESOURCE(200)); */



    /* The Window structure */

    wincl.hInstance = hThisInstance;

    wincl.lpszClassName = szClassName;

    wincl.lpfnWndProc = WindowProcedure; /* This function is called by windows */

    wincl.style = CS_DBLCLKS;            /* Catch double-clicks */

    wincl.cbSize = sizeof(WNDCLASSEX);



    /* Use default icon and mouse-pointer */

    wincl.hIcon = LoadIcon(NULL, IDI_APPLICATION);

    wincl.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

    wincl.hCursor = LoadCursor(NULL, IDC_ARROW);

    wincl.lpszMenuName = NULL; /* No menu */

    wincl.cbClsExtra = 0;      /* No extra bytes after the window class */

    wincl.cbWndExtra = 0;      /* structure or the window instance */

    /* Use Windows's default colour as the background of the window */

    wincl.hbrBackground = (HBRUSH)0;




    /* Register the window class, and if it fails quit the program */

    if (!RegisterClassEx(&wincl))

        return 0;



    /* The class is registered, let's create the program*/

    hwnd = CreateWindowEx(

        0,                                  /* Extended possibilites for variation */

        szClassName,                        /* Classname */

        _T("Pierwsza aplikacja okienkowa"), /* Title Text */

        WS_OVERLAPPEDWINDOW,                /* default window */

        CW_USEDEFAULT,                      /* Windows decides the position */

        CW_USEDEFAULT,                      /* where the window ends up on the screen */

        544,                                /* The programs width */

        375,                                /* and height in pixels */

        HWND_DESKTOP,                       /* The window is a child-window to desktop */

        NULL,                               /* No menu */

        hThisInstance,                      /* Program Instance handler */

        NULL                                /* No Window Creation data */

    );



    /* dodawanie przycisku */

    czarny = CreateWindowEx(

        0,

        _T("BUTTON"),

        _T("BLACK"),

        BS_BOTTOM | WS_CHILD | WS_VISIBLE,

        10, 10, 80, 20,

        hwnd,

        NULL,

        hThisInstance,

        NULL);



    czerwony = CreateWindowEx(

        0,

        _T("BUTTON"),

        _T("RED"),

        WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,

        100, 10, 80, 20,

        hwnd,

        NULL,

        hThisInstance,

        NULL);

    zielony = CreateWindowEx(

        0,

        _T("BUTTON"),

        _T("GREEN"),

        WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,

        190, 10, 80, 20,

        hwnd,

        NULL,

        hThisInstance,

        NULL);
    niebieski = CreateWindowEx(

        0,

        _T("BUTTON"),

        _T("BLUE"),

        WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,

        280, 10, 80, 20,

        hwnd,

        NULL,

        hThisInstance,

        NULL);
    prostokat = CreateWindowEx(

        0,

        _T("BUTTON"),

        _T("PROSTOKAT"),

        WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,

        370, 10, 80, 20,

        hwnd,

        NULL,

        hThisInstance,

        NULL);
    linia = CreateWindowEx(

        0,

        _T("BUTTON"),

        _T("LINIA"),

        WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,

        460, 10, 80, 20,

        hwnd,

        NULL,

        hThisInstance,

        NULL);
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    /*OBECNY PROGRESS!!!!!!*/
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //od tad
    //HANDLE czaIkona = LoadImage(hThisInstance, MAKEINTRESOURCE(IDR_BUTTON), IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR);
    //SendMessage(czarny, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)czaIkona);
    //do tad nie dziala

    /*hText = CreateWindowEx(

        0,

        _T("EDIT"),

        NULL,

        WS_CHILD | WS_VISIBLE | WS_BORDER,

        50, 20, 150, 25,

        hwnd,

        NULL,

        hThisInstance,

        NULL);*/

        /* Make the window visible on the screen */

    ShowWindow(hwnd, nCmdShow);

    /* Run the message loop. It will run until GetMessage() returns 0 */

    while (GetMessage(&messages, NULL, 0, 0))

    {

        /* Translate virtual-key messages into character messages */

        TranslateMessage(&messages);

        /* Send message to WindowProcedure */

        DispatchMessage(&messages);

    }



    /* The program return-value is 0 - The value that PostQuitMessage() gave */

    return messages.wParam;

}

void line(HDC _hdc, int x1, int y1, int x2, int y2, HPEN kolor)//This function draws line by the given four coordinates.
{
    SelectObject(_hdc, kolor);
    MoveToEx(_hdc, x1, y1, NULL);
    LineTo(_hdc, x2, y2);
}

void ellipse(HDC _hdc, int x1, int y1, int x2, int y2, HPEN kolor)//This function draws line by the given four coordinates.
{
    SelectObject(_hdc, kolor);
    //MoveToEx(_hdc, x1, y1, NULL);
    Ellipse(_hdc, x1, y1, x2, y2);
}

void rectangle(HDC _hdc, int x1, int y1, int x2, int y2, HPEN kolor)//This function draws line by the given four coordinates.
{
    SelectObject(_hdc, kolor);
    //MoveToEx(_hdc, x1, y1, NULL);
    Rectangle(_hdc, x1, y1, x2, y2);
}
/*  This function is called by the Windows function DispatchMessage()  */

/*void rysuj(HWND hwnd)
{
    HDC hdc;
    PAINTSTRUCT ps;
    HPEN kolorpisaka, apka, czarnykolor;
    hdc = BeginPaint(hwnd, &ps);

    kolorpisaka = CreatePen(PS_DASHDOTDOT, 2, 0x11AAFF);
    SelectObject(hdc, kolorpisaka);

    MoveToEx(hdc, 50, 50, NULL);
    for (int i = 0; i < 50; i++)
    {
        LineTo(hdc, i + 50, i * i / 80 + 50);
    }
    czarnykolor = CreatePen(PS_DASHDOT, 8, 0xDD3300);
    SelectObject(hdc, czarnykolor);
    MoveToEx(hdc, 50, 50, NULL);

    LineTo(hdc, 50, 100);
    LineTo(hdc, 100, 100);
    LineTo(hdc, 50, 50);

    MoveToEx(hdc, 150, 150, NULL);
    SelectObject(hdc, kolorpisaka);
    Ellipse(hdc, 250, 100, 20, 20);
    ////////////////////////////////////////////////*/
    /*HDC hdc;
    PAINTSTRUCT ps;
    hdc = BeginPaint(hwnd, &ps);
    */
    /*    EndPaint(hwnd, &ps);
    }*/

int tool = 1;
LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)

{
    bool spr;
    switch (message) /* handle the messages */
    {      //////////////////////
    case WM_LBUTTONDOWN:					//If Left mouse button is pressed
        lastx = LOWORD(lParam);			//Store the x-coordiante in lastx
        lasty = HIWORD(lParam);			//Store the y-coordinate in lasty
        return 0;
    case WM_LBUTTONUP:						//When mouse is moved on the client area (or form for VB users)
        hdc = GetDC(hwnd);					//hdc is handle to device context
        x = LOWORD(lParam);					//Store the current x 
        y = HIWORD(lParam);					//Store the current y
        //if (wParam & MK_LBUTTON)			//If Left mouse button is down then draw
        //{
            //line(hdc, lastx, lasty, x, y, kolorpisaka);		//Draw the line frome the last pair of coordiates to current
        if (tool == 0) rectangle(hdc, lastx, lasty, x, y, kolorpisaka);
        if (tool == 1) line(hdc, lastx, lasty, x, y, kolorpisaka);
        //lastx = x;						//The current x becomes the lastx for next line to be drawn
        //lasty = y;						//The current y becomes the lasty for next line to be drawn
    //}
        ReleaseDC(hwnd, hdc);
        return 0;

        /////////////////
    case WM_KEYDOWN:
        if (wParam == VK_RETURN)
        {
            MessageBox(NULL, __T("TEXT"), __T("Drugi?"), MB_OK);
            break;
        }
        /*if (wParam == VK_F10)
        {

            rysuj(hwnd);
        }*/
        break;
        /*case WM_PAINT:



            break;*/
    case WM_DESTROY:
        PostQuitMessage(0); /* send a WM_QUIT to the message queue */
        break;
    case WM_COMMAND:
        if (HWND(lParam) == czarny && HIWORD(wParam) == BN_CLICKED)
        {
            kolorpisaka = CreatePen(PS_DASHDOTDOT, 2, 0x000000);
            //SelectObject(hdc, kolorpisaka);
            //MessageBox(NULL, _T("result"), _T("b1"), NULL);

        }
        if (HWND(lParam) == czerwony && HIWORD(wParam) == BN_CLICKED)
        {
            kolorpisaka = CreatePen(PS_DASHDOTDOT, 2, 0x0000AA);
            //SelectObject(hdc, kolorpisaka);
        }
        if (HWND(lParam) == zielony && HIWORD(wParam) == BN_CLICKED)
        {
            kolorpisaka = CreatePen(PS_DASHDOTDOT, 2, 0x00AA00);
            //SelectObject(hdc, kolorpisaka);
        }
        if (HWND(lParam) == niebieski && HIWORD(wParam) == BN_CLICKED)
        {
            kolorpisaka = CreatePen(PS_DASHDOTDOT, 2, 0xAA0000);
            //SelectObject(hdc, kolorpisaka);
        }
        if (HWND(lParam) == prostokat && HIWORD(wParam) == BN_CLICKED)
        {
            tool = 0;
            //MessageBox(NULL, _T("result"), _T("b1"), NULL);
            //kolorpisaka = CreatePen(PS_DASHDOTDOT, 2, 0xAA0000);
            //SelectObject(hdc, kolorpisaka);
        }
        if (HWND(lParam) == linia && HIWORD(wParam) == BN_CLICKED)
        {
            tool = 1;
            //kolorpisaka = CreatePen(PS_DASHDOTDOT, 2, 0xAA0000);
            //SelectObject(hdc, kolorpisaka);
        }
        ////


    default: /* for messages that we don't deal with */

        return DefWindowProc(hwnd, message, wParam, lParam);

    }



    return 0;

}