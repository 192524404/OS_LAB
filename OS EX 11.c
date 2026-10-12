#include <stdio.h>
#include <windows.h>

DWORD WINAPI threadFunction(LPVOID arg)
{
    printf("%s\n", (char *)arg);
    return 0;
}

int main()
{
    HANDLE t1, t2;

    t1 = CreateThread(NULL, 0, threadFunction,
                      "Hello from Thread 1!", 0, NULL);

    t2 = CreateThread(NULL, 0, threadFunction,
                      "Hello from Thread 2!", 0, NULL);

    if (t1 == NULL || t2 == NULL)
    {
        printf("Thread creation failed\n");
        return 1;
    }

    WaitForSingleObject(t1, INFINITE);
    WaitForSingleObject(t2, INFINITE);

    CloseHandle(t1);
    CloseHandle(t2);

    return 0;
}