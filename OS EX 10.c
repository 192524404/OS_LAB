#include <stdio.h>
#include <windows.h>

int main()
{
    HANDLE hSlot;
    HANDLE hFile;
    DWORD written, read;
    char message[] = "Hello, Message Queue!";
    char buffer[100];

    /* Create Message Queue */
    hSlot = CreateMailslot(
        "\\\\.\\mailslot\\MyMessageQueue",
        0,
        MAILSLOT_WAIT_FOREVER,
        NULL
    );

    if (hSlot == INVALID_HANDLE_VALUE)
    {
        printf("Message queue creation failed");
        return 1;
    }

    /* Open Message Queue for writing */
    hFile = CreateFile(
        "\\\\.\\mailslot\\MyMessageQueue",
        GENERIC_WRITE,
        FILE_SHARE_READ,
        NULL,
        OPEN_EXISTING,
        0,
        NULL
    );

    if (hFile == INVALID_HANDLE_VALUE)
    {
        printf("Cannot open message queue");
        CloseHandle(hSlot);
        return 1;
    }

    /* Producer */
    WriteFile(
        hFile,
        message,
        sizeof(message),
        &written,
        NULL
    );

    printf("Producer: Data sent: %s\n", message);

    CloseHandle(hFile);

    /* Consumer */
    ReadFile(
        hSlot,
        buffer,
        sizeof(buffer),
        &read,
        NULL
    );

    buffer[read] = '\0';

    printf("Consumer: Data received: %s\n", buffer);

    CloseHandle(hSlot);

    return 0;
}