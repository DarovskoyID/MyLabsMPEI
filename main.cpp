#include <iostream>
#include "ListInt.h"
#include "ListChar.h"
#include "QueueChar.h"
#include "QueueInt.h"

int main(){
    std::cout << "List =================================" << std::endl;

    IntList::Node* head = nullptr;
    IntList list;

    list.AddLast(head, 1);
    list.AddLast(head, 2);
    list.AddLast(head, 3);
    list.AddFirst(head, 4);
    list.AddFirst(head, 5);
    list.Print(head);
    list.DelLast(head);
    list.DelFirst(head);
    list.Print(head);
    std::cout << "Size: " << list.GetSize(head) << " First: " << list.GetFirst(head) << " Last: " << list.GetLast(head) << std::endl;

    list.AddLast(head, 7);
    list.AddLast(head, 90);
    list.DelLast(head);
    list.Print(head);

    IntList::Node* head2 = nullptr;
    list.AddLast(head2, 1);
    list.AddLast(head2, 2);
    list.AddLast(head2, 3);

    IntList::Node* head3 = list.Concat(head, head2);
    list.AddLast(head3, 10);
    std::cout << head3;
    std::cout << "Element at index 4: " << list.GetAt(head3, 4) << std::endl;

    try{
        int a = list.GetAt(head3, 100);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "non sorted"<< std::endl;
    std::cout << head3<< std::endl;
    list.Sort(head3);

    std::cout << "sorted"<< std::endl;
    std::cout << head3 << std::endl;

    while (head) list.DelLast(head);
    while (head2) list.DelLast(head2);
    while (head3) list.DelLast(head3);

    std::cout << "======================================" << std::endl;

    std::cout << "Queue ================================" << std::endl;
    QueueInt interqueue, interqueue2, interqueue3;
    interqueue += 1;
    interqueue += 2;
    interqueue += 3;
    interqueue += 4;
    interqueue += 5;
    interqueue.Print();
    --interqueue;
    --interqueue;
    interqueue.Print();
    std::cout << "First: " << *interqueue << std::endl;
    interqueue += 7;
    interqueue += 90;
    --interqueue;
    interqueue.Print();

    interqueue2 += 3;
    interqueue2 += 1;
    interqueue2 += 2;

    interqueue2 += -1;
    interqueue2 += -5;

    interqueue3 += 10;
    std::cout << "non sorted"<< std::endl;
    std::cout << interqueue2<< std::endl;
    interqueue2.Sort();

    std::cout << "sorted"<< std::endl;
    std::cout << interqueue2 << std::endl;
    std::cout << "======================================" << std::endl;

    std::cout << "List =================================" << std::endl;
    CharList charlist;
    CharList::Node* char_head = nullptr;

    charlist.AddLast(char_head, 'a');
    charlist.AddLast(char_head, '2');
    charlist.AddLast(char_head, '!');
    charlist.AddFirst(char_head, 'c');
    charlist.AddFirst(char_head, '5');
    charlist.Print(char_head);
    charlist.DelLast(char_head);
    charlist.DelFirst(char_head);
    charlist.Print(char_head);
    std::cout << "Size: " << charlist.GetSize(char_head) << " First: " << charlist.GetFirst(char_head) << " Last: " << charlist.GetLast(char_head) << std::endl;
    charlist.AddLast(char_head, '7');
    charlist.AddLast(char_head, 'j');
    charlist.DelLast(char_head);
    charlist.Print(char_head);

    CharList::Node* char_head2 = nullptr;
    charlist.AddLast(char_head2, '1');
    charlist.AddLast(char_head2, 'h');
    charlist.AddLast(char_head2, 'u');

    CharList::Node* char_head3 = charlist.Concat(char_head, char_head2);
    charlist.AddLast(char_head3, '[');
    std::cout << char_head3;
    std::cout << "Element at index 4: " << charlist.GetAt(char_head3, 4) << std::endl;

    try{
        char b = charlist.GetAt(char_head3, 100);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "non sorted"<< std::endl;
    std::cout << char_head3<< std::endl;
    charlist.Sort(char_head3);

    std::cout << "sorted"<< std::endl;
    std::cout << char_head3 << std::endl;

    while (char_head) charlist.DelLast(char_head);
    while (char_head2) charlist.DelLast(char_head2);
    while (char_head3) charlist.DelLast(char_head3);

    std::cout << "======================================" << std::endl;

    std::cout << "Queue ================================" << std::endl;
    QueueChar charqueue, charqueue2, charqueue3;
    charqueue += 'a';
    charqueue += 'b';
    charqueue += 'c';
    charqueue += 'd';
    charqueue += 'e';
    charqueue.Print();
    --charqueue;
    --charqueue;
    charqueue.Print();
    std::cout << "First: " << *charqueue << std::endl;
    charqueue += '!';
    charqueue += ']';
    --charqueue;
    charqueue.Print();

    charqueue2 += 'h';
    charqueue2 += 'g';
    charqueue2 += '3';

    charqueue3 += '1';
    std::cout << charqueue3 << std::endl;

    std::cout << "non sorted"<< std::endl;
    std::cout << charqueue<< std::endl;
    charqueue.Sort();

    std::cout << "sorted"<< std::endl;
    std::cout << charqueue << std::endl;

    std::cout << "======================================" << std::endl;

    std::cout << "List(cleared) =================================" << std::endl;
    CharList char1list;
    CharList::Node* char1_head = nullptr;

    char1list.AddLast(char1_head, 'a');
    char1list.AddLast(char1_head, '2');
    char1list.AddLast(char1_head, '!');
    char1list.AddFirst(char1_head, 'c');
    char1list.AddFirst(char1_head, '5');
    char1list.Print(char1_head);
    char1list.DelLast(char1_head);
    char1list.DelFirst(char1_head);
    char1list.Print(char1_head);
    std::cout << "Size: " << char1list.GetSize(char1_head) << " First: " << char1list.GetFirst(char1_head) << " Last: " << char1list.GetLast(char1_head) << std::endl;
    char1list.AddLast(char1_head, '7');
    char1list.AddLast(char1_head, 'j');
    char1list.DelLast(char1_head);
    char1list.Print(char1_head);

    CharList::Node* char1_head2 = nullptr;
    char1list.AddLast(char1_head2, '1');
    char1list.AddLast(char1_head2, 'h');
    char1list.AddLast(char1_head2, 'u');

    CharList::Node* char1_head3 = char1list.Concat(char1_head, char1_head2);
    char1list.AddLast(char1_head3, '[');
    std::cout << char1_head3;
    std::cout << "Element at index 4: " << char1list.GetAt(char1_head3, 4) << std::endl;

    try{
        char b = char1list.GetAt(char1_head3, 100);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    char1list.AddLast(char1_head, '!');
    std::cout << char1_head << std::endl;

    if (char1list.checkChar(char1_head)){
        char1list.clearSymbol(char1_head);
    }
    std::cout << "cleared" << std::endl;
    std::cout << char1_head << std::endl;

    while (char1_head) char1list.DelLast(char1_head);
    while (char1_head2) char1list.DelLast(char1_head2);
    while (char1_head3) char1list.DelLast(char1_head3);

    std::cout << "======================================" << std::endl;

    std::cout << "Queue(cleared) ================================" << std::endl;
    QueueChar char1queue, char1queue2, char1queue3;
    char1queue += 'a';
    char1queue += 'b';
    char1queue += 'c';
    char1queue += 'd';
    char1queue += 'e';
    char1queue.Print();
    --char1queue;
    --char1queue;
    char1queue.Print();
    std::cout << "First: " << *char1queue << std::endl;
    char1queue += '!';
    char1queue += ']';
    --char1queue;
    char1queue.Print();

    char1queue2 += 'h';
    char1queue2 += 'g';
    char1queue2 += '3';

    char1queue3 += '1';
    std::cout << char1queue3;
    std::cout << std::endl;
    std::cout << char1queue << std::endl;

    if (char1queue.checkChar()){
        char1queue.clearSymbol();
    }
    std::cout << "cleared" << std::endl;
    std::cout << char1queue << std::endl;

    std::cout << "======================================" << std::endl;
    return 0;
}
