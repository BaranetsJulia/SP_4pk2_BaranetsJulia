#include <iostream>
#include <windows.h>

int main() {
    setlocale(LC_ALL, "Russian");
    MEMORYSTATUSEX memoryStatus;
    memoryStatus.dwLength = sizeof(memoryStatus);

    GlobalMemoryStatusEx(&memoryStatus);

    DWORDLONG physicalMemory = memoryStatus.ullTotalPhys;
    DWORDLONG availableMemory = memoryStatus.ullAvailPhys;
    DWORDLONG pageFile = memoryStatus.ullTotalPageFile;
    DWORDLONG availablePageFile = memoryStatus.ullAvailPageFile;
    DWORDLONG virtualMemory = memoryStatus.ullTotalVirtual;
    DWORDLONG availableVirtualMemory = memoryStatus.ullAvailVirtual;
    DWORD processMemory = memoryStatus.dwMemoryLoad;

    std::cout << "����� ���������� ������: " << physicalMemory << " ����" << std::endl;
    std::cout << "����� ������, ��������� � ������ ������: " << availableMemory << " ����" << std::endl;
    std::cout << "����� ����� ��������: " << pageFile << " ����" << std::endl;
    std::cout << "����� ����� ��������, ���������� � ������ ������: " << availablePageFile << " ����" << std::endl;
    std::cout << "����� ����������� ������: " << virtualMemory << " ����" << std::endl;
    std::cout << "����� ����������� ������, ��������� � ������ ������: " << availableVirtualMemory << " ����" << std::endl;
    std::cout << "����� ������, ������������ ���������: " << processMemory << "%" << std::endl;

    return 0;
}