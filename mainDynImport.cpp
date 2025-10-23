#include <cstdio>
#include <dlfcn.h>

typedef void (*T_inputStringFromFile)(char **, size_t *, FILE *);
typedef int (*T_countWords)(const char *);
typedef void (*T_splitter)(const char *, char ***, int, int);
typedef int (*T_CalculateLen)(char *);
typedef void (*T_sortWordsByLen)(char **, int);

int main() {
    void* handle = dlopen("./lib/libunit_dll_M.dylib", RTLD_LAZY);
    if (!handle) {
        printf("Ошибка загрузки libunit_dll_M.dylib: %s\n", dlerror());
        return 1;
    }

    dlerror();

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

    FILE *file;
    char filename[100], *string = nullptr, **words;
    int lenStr = 0, lenWords = 0;

    printf("Введите имя файла: ");
    scanf("%99s", filename);

    file = fopen(filename, "r");
    if (!file) {
        printf("file not exists\n");
        dlclose(handle);
        return 1;
    }

    inputStringFromFile(&string, (size_t*)&lenStr, file);
    fclose(file);

    lenWords = countWords(string);
    splitter(string, &words, lenStr, lenWords);
    sortWordsByLen(words, lenWords);

    for (int i = 0; i < lenWords; i++)
        printf("%s ", words[i]);
    printf("\n");

    dlclose(handle);
    return 0;
}
