#include <stdio.h>
#include <windows.h>

int main()
{
    HANDLE hMapFile;
    char *sharedMemory;

    hMapFile = CreateFileMapping(
        INVALID_HANDLE_VALUE,
        NULL,
        PAGE_READWRITE,
        0,
        1024,
        "MySharedMemory"
    );

    if (hMapFile == NULL)
    {
        printf("Shared memory creation failed");
        return 1;
    }

    sharedMemory = (char *)MapViewOfFile(
        hMapFile,
        FILE_MAP_ALL_ACCESS,
        0,
        0,
        1024
    );

    if (sharedMemory == NULL)
    {
        printf("Could not map shared memory");
        CloseHandle(hMapFile);
        return 1;
    }

    sprintf(sharedMemory, "Hello from Shared Memory!");

    printf("Data written to shared memory: %s\n", sharedMemory);

    UnmapViewOfFile(sharedMemory);
    CloseHandle(hMapFile);

    return 0;
}