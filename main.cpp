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
    CharSet s(a, 'a');
    s.Add("i");
    s.Add(a);
    s.Add("i");
    s.Add("i");
    s.Add("i");
    s.Add("b");
    s.Add("c");
    a.Delete("F");
    a.Delete("babddd");
    s.Delete(a);
    a.print();
    std::cout << "size: " << a.Size() << std::endl;
    s.print();
    std::cout << "size: " << s.Size() << std::endl;
    std::cout << std::endl;

    std::cout << "have a: " << a.inSet('a') << std::endl;
    std::cout << "(char) a: " << a.ToChar() << std::endl;
    std::cout << std::endl;
    s.print();
    std::cout << "size: " << s.Size() << std::endl;
    return 0;
}
