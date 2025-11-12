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
    CharSet a("abcd");
    CharSet b("efgh");
    CharSet d("igklmnru");
    CharSet s(a, 'a');
    std::cout << "SET A:" << std::endl;
    a.print();
    a = std::move(b);
    b = "efgh";
    std::cout << "SET A AFTER = *B:" << std::endl;
    a.print();
    a = "abcd";
    std::cout << "SET A AFTER = abcd:" << std::endl;
    a.print();
    a += "Russia";
    std::cout << "SET A AFTER += Russia:" << std::endl;
    a.print();
    s = std::move(a + b);
    std::cout << "SET S = A + B:" << std::endl;
    s.print();
    s = std::move(a - d);
    std::cout << "SET S = A - D:" << std::endl;
    s.print();
    s = std::move(a * d);
    std::cout << "SET S = A * D:" << std::endl;
    s.print();
    std::cout << "\n";
    a << std::cout;
    a -= "abcd";
    a << std::cout;
    a = std::move(!a);
    a << std::cout;
    auto t1 = a < d, t2 = a <= d, t3 = a > d, t4 = a >= d;
    std::cout << "a < d " << t1 << " " << "a <= d " << t2 << " " << "a > d " << t3 << " " << "a >= d " << t4 << std::endl;

    a.print();
    b.print();
    d.print();
    return 0;
}
