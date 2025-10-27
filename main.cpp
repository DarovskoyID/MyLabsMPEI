/*Разработать класс для представления
объекта множество символов*.
Определить конструктор с одним
параметром-строкой, который задаёт
элементы множества и который можно
использовать как конструктор умолчания.
Определить конструктор, который копирует
в новое множество элементы другого множества,
не превышающие заданное значение, который можно
использовать как конструктор копирования.
Определить деструктор. Определить преобразования из переменной типа
char в множество и из множества в переменную типа char.*/
#include <iostream>
#include "CharSet.h"
int main(){
    CharSet a("abfgCDEF78@bdfibdfjkbjkbjskbjeiuwIYVSYIUVSYVSY((");
    CharSet s(a, '2');
    s.Add('i');
    s.Add('i');
    s.Add('i');
    s.Add('a');
    s.Add('b');
    s.Add('c');
    a.Delete('F');
    a.Delete('b');
    a.print();
    std::cout << "size: " << a.Size() << std::endl;
    a.Sort();
    a.print();
    std::cout << "size: " << a.Size() << std::endl;
    std::cout << std::endl;
    if(a.Get(3) != '\0') std::cout << "3 element s: " << a.Get(3)  << std::endl;
    else std::cout << "3 element a: don't exists" << std::endl;
    if(a.Get(100) != '\0') std::cout << "100 element a: " << a.Get(100)  << std::endl;
    else std::cout << "10 element a: don't exists" << std::endl;
    std::cout << "have a: " << a.inSet('a') << std::endl;
    std::cout << "(char) a: " << (char)a << std::endl;
    std::cout << std::endl;
    s.print();
    std::cout << "size: " << s.Size() << std::endl;
    return 0;
}
