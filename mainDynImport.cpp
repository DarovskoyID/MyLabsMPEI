#include <cstdio>
#ifdef _WIN32
#include <windows.h>
#define PLATFORM_NAME "Windows"
#define DLL_NAME "./unit_dll_W.dll"
#else
#include <dlfcn.h>
    #define PLATFORM_NAME "macOS"
    #define DLL_NAME "./lib/libunit_dll_M.dylib"
#endif

typedef void (*T_inputStringFromFile)(char **, int *, FILE *);
typedef int (*T_countWords)(const char *, bool);
typedef void (*T_splitter)(const char *, char ***, int, int);
typedef int (*T_CalculateLen)(char *);
typedef void (*T_sortWordsByLen)(char **, int);

int main() {
    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);

        HMODULE handle = LoadLibrary(TEXT(DLL_NAME));
        if (!handle) {
            printf("Ошибка загрузки DLL: %lu\n", GetLastError());
            return 1;
        }

        T_inputStringFromFile inputStringFromFile =
                (T_inputStringFromFile)GetProcAddress(handle, "inputStringFromFile");
        T_countWords countWords =
                (T_countWords)GetProcAddress(handle, "countWords");
        T_splitter splitter =
                (T_splitter)GetProcAddress(handle, "splitter");
        T_sortWordsByLen sortWordsByLen =
                (T_sortWordsByLen)GetProcAddress(handle, "sortWordsByLen");

        if (!inputStringFromFile || !countWords || !splitter || !sortWordsByLen) {
            printf("Ошибка поиска функции\n");
            FreeLibrary(handle);
            return 1;
        }

    #else
        void* handle = dlopen(DLL_NAME, RTLD_LAZY);
        if (!handle) {
            printf("Ошибка загрузки %s: %s\n", DLL_NAME, dlerror());
            return 1;
        }

        dlerror(); // сброс ошибок

        T_inputStringFromFile inputStringFromFile =
            (T_inputStringFromFile)dlsym(handle, "inputStringFromFile");
        T_countWords countWords =
            (T_countWords)dlsym(handle, "countWords");
        T_splitter splitter =
            (T_splitter)dlsym(handle, "splitter");
        T_sortWordsByLen sortWordsByLen =
            (T_sortWordsByLen)dlsym(handle, "sortWordsByLen");

        const char* err = dlerror();
        if (err) {
            printf("Ошибка поиска функции: %s\n", err);
            dlclose(handle);
            return 1;
        }
    #endif

    FILE *file;
    char filename[100], *string = nullptr, **words = nullptr;
    int lenStr = 0, lenWords = 0;

    scanf("%99s", filename);

    file = fopen(filename, "r");
    if (!file) {
        printf("Файл не существует\n");
    } else {
        inputStringFromFile(&string, &lenStr, file);
        fclose(file);

        lenWords = countWords(string, true);
        splitter(string, &words, lenStr, lenWords);
        sortWordsByLen(words, lenWords);

        for (int i = 0; i < lenWords; i++)
            printf("%s ", words[i]);
        printf("\n");

        // --- освобождаем память ---
        for (int i = 0; i < lenWords; i++)
            delete[] words[i];
        delete[] words;
        delete[] string;
    }

#ifdef _WIN32
    FreeLibrary(handle);
#else
    dlclose(handle);
#endif

    return 0;
}
