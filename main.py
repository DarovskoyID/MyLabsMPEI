import ctypes, os

lib = ctypes.CDLL("./libunit_dll_M.dylib")

lib.countWords.argtypes = [ctypes.c_char_p, ctypes.c_bool]
lib.countWords.restype = ctypes.c_int
lib.splitter.argtypes = [ctypes.c_char_p, ctypes.POINTER(ctypes.POINTER(ctypes.c_char_p)), ctypes.c_int, ctypes.c_int]
lib.splitter.restype = None
lib.sortWordsByLen.argtypes = [ctypes.POINTER(ctypes.c_char_p), ctypes.c_int]
lib.sortWordsByLen.restype = None

filename = input("Введите имя файла: ").strip()
if (not os.path.exists(filename)):
    print("Файл не существует")
else:
    f = open(filename, "r", encoding="utf-8")
    s = f.read()

    s_bytes = s.encode('utf-8')
    len_str = len(s_bytes)

    len_words = lib.countWords(s_bytes, True)
    print(f"Количество слов: {len_words}")

    words_ptr = (ctypes.POINTER(ctypes.c_char_p))()
    lib.splitter(s_bytes, ctypes.byref(words_ptr), len_str, len_words)
    lib.sortWordsByLen(words_ptr, len_words)

    for i in range(len_words):
        print(ctypes.string_at(words_ptr[i]).decode('utf-8', errors='ignore'), end=' ')
    print()
