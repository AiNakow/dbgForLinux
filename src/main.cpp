#include <iostream>
#include "windows.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " [cmdline]" << std::endl;
        return -1;
    }
    char* pName = argv[1];

    STARTUPINFOA si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(STARTUPINFOA));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(PROCESS_INFORMATION));

    if (!CreateProcessA(NULL,
        pName, 
        NULL,
        NULL,
        FALSE, 
        0, 
        NULL,
        NULL,
        &si,
        &pi)
    )
    {
        std::cerr << "Fail to start target program." << std::endl;
        return -1;
    }

    WaitForSingleObject(pi.hProcess, INFINITE);

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}