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
#include "List.h"
#include "Queue.h"
int main(){
    std::cout << "List =================================" << std::endl;
    List<int> interlist, interlist2, interlist3;
    interlist.push_back(1);
    interlist.push_back(2);
    interlist.push_back(3);
    interlist.push_front(4);
    interlist.push_front(5);
    interlist.print();
    interlist.pop_back();
    interlist.pop_front();
    interlist.print();
    std::cout << interlist.size() << interlist.get_back() << interlist.get_front() << std::endl;
    interlist += 7;
    interlist += 90;
    interlist -= 1;
    interlist.print();
    interlist2.push_back(1);
    interlist2.push_back(2);
    interlist2.push_back(3);
    interlist3 = interlist + interlist2;
    interlist3 = interlist3 + 10;
    std::cout << interlist3;
    std::cout << interlist3[4] << std::endl;
    try{
        int a = interlist3[100];
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "======================================" << std::endl;

    std::cout << "Queue =================================" << std::endl;
    Queue<int> interqueue, interqueue2, interqueue3;
    interqueue.push(1);
    interqueue.push(2);
    interqueue.push(3);
    interqueue.push(4);
    interqueue.push(5);
    interqueue.print();
    interqueue.pop();
    interqueue.pop();
    interqueue.print();
    std::cout << interqueue.size() << interqueue.front() << std::endl;
    interqueue += 7;
    interqueue += 90;
    interqueue -= 1;
    interqueue.print();
    interqueue2.push(1);
    interqueue2.push(2);
    interqueue2.push(3);
    interqueue3 = interqueue + interqueue2;
    interqueue3 = interqueue3 + 10;
    std::cout << interqueue3;
    std::cout << "======================================" << std::endl;

    //char

    std::cout << "List =================================" << std::endl;
    List<char> charlist, charlist2, charlist3;
    charlist.push_back('a');
    charlist.push_back('2');
    charlist.push_back('!');
    charlist.push_front('c');
    charlist.push_front('5');
    charlist.print();
    charlist.pop_back();
    charlist.pop_front();
    charlist.print();
    std::cout << charlist.size() << charlist.get_back() << charlist.get_front() << std::endl;
    charlist += '7';
    charlist += 'j';
    charlist -= 1;
    charlist.print();
    charlist2.push_back('1');
    charlist2.push_back('h');
    charlist2.push_back('u');
    charlist3 = charlist + charlist2;
    charlist3 = charlist3 + '[';
    std::cout << charlist3;
    std::cout << charlist3[4] << std::endl;
    try{
        int a = charlist3[100];
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "======================================" << std::endl;

    std::cout << "Queue =================================" << std::endl;
    Queue<char> charqueue, charqueue2, charqueue3;
    charqueue.push('a');
    charqueue.push('b');
    charqueue.push('c');
    charqueue.push('d');
    charqueue.push('e');
    charqueue.print();
    charqueue.pop();
    charqueue.pop();
    charqueue.print();
    std::cout << charqueue.size() << charqueue.front() << std::endl;
    charqueue += '!';
    charqueue += ']';
    charqueue -= 1;
    charqueue.print();
    charqueue2.push('h');
    charqueue2.push('g');
    charqueue2.push('3');
    charqueue3 = charqueue + charqueue2;
    charqueue3 = charqueue3 + '1';
    std::cout << charqueue3;
    std::cout << "======================================" << std::endl;

    return 0;
}
