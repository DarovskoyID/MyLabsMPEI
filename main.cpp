#include <iostream>
#include "ListInt.h"
#include "ListChar.h"
#include "QueueChar.h"
#include "QueueInt.h"
//Если в списке из символов есть латинские буквы, удалить из списка знаки препинания.

//удалить из структур элементы не входящие в диапозон
int main(){
    std::cout << "List =================================" << std::endl;

    IntList::Node* head = nullptr;
    IntList::Node* tail = nullptr;
    IntList list;

    list.AddLast(head, tail, 1);
    list.AddLast(head, tail, 2);
    list.AddLast(head, tail, 3);
    list.AddFirst(head, tail, 4);
    list.AddFirst(head, tail, 5);
    list.Print(head,  tail);
    list.DelLast(head, tail);
    list.DelFirst(head, tail);
    list.Print(head, tail);
    std::cout << "Size: " << list.GetSize(head, tail) << " First: " << list.GetFirst(head, tail) << " Last: " << list.GetLast(head, tail) << std::endl;

    list.AddLast(head, tail, 7);
    list.AddLast(head, tail, 90);
    list.DelLast(head, tail);
    list.Print(head, tail);

    IntList::Node* head2 = nullptr;
    IntList::Node* tail2 = nullptr;
    list.AddLast(head2, tail, 1);
    list.AddLast(head2, tail, 2);
    list.AddLast(head2, tail, 3);

    IntList::Node* head3 = list.Concat(head, head2,  tail, tail2);
    IntList::Node* tail3 = nullptr;
    list.AddLast(head3, tail, 10);
    std::cout << head3;

    try{
        int a = list.GetAt(head3, tail, 100);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }


    list.Clean(head, tail);
    list.Clean(head2,  tail2);
    list.Clean(head3, tail3);


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

    interqueue2 += 1;
    interqueue2 += 2;
    interqueue2 += 3;

    interqueue3 += 10;
    std::cout << interqueue3;
    std::cout << "======================================" << std::endl;

    std::cout << "List =================================" << std::endl;
    CharList charlist;
    CharList::Node* char_head = nullptr;
    CharList::Node* char_tail = nullptr;

    charlist.AddLast(char_head,char_tail, 'a');
    charlist.AddLast(char_head,char_tail, '2');
    charlist.AddLast(char_head,char_tail, '!');
    charlist.AddFirst(char_head,char_tail, 'c');
    charlist.AddFirst(char_head,char_tail, '5');
    charlist.Print(char_head, char_tail);
    charlist.DelLast(char_head, char_tail);
    charlist.DelFirst(char_head, char_tail);
    charlist.Print(char_head, char_tail);
    std::cout << "Size: " << charlist.GetSize(char_head, char_tail) << " First: " << charlist.GetFirst(char_head, char_tail) << " Last: " << charlist.GetLast(char_head, char_tail) << std::endl;
    charlist.AddLast(char_head,char_tail, '7');
    charlist.AddLast(char_head,char_tail, 'j');
    charlist.DelLast(char_head,char_tail);
    charlist.Print(char_head,char_tail);

    CharList::Node* char_head2 = nullptr;
    CharList::Node* char_tail2 = nullptr;
    charlist.AddLast(char_head2,char_tail2, '1');
    charlist.AddLast(char_head2,char_tail2, 'h');
    charlist.AddLast(char_head2,char_tail2, 'u');

    CharList::Node* char_head3 = nullptr;
    CharList::Node* char_tail3 = nullptr;
    charlist.AddLast(char_head3,char_tail3, '[');
    std::cout << char_head3;

    try{
        char b = charlist.GetAt(char_head3, char_tail3, 100);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    charlist.Clean(char_head, char_tail);
    charlist.Clean(char_head2, char_tail2);
    charlist.Clean(char_head3, char_tail3);

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

    std::cout << "======================================" << std::endl;

    std::cout << "List(cleared) =================================" << std::endl;
    CharList char1list;
    CharList::Node* char1_head = nullptr;
    CharList::Node* char1_tail = nullptr;

    char1list.AddLast(char1_head,char1_tail, 'a');
    char1list.AddLast(char1_head,char1_tail, '2');
    char1list.AddLast(char1_head,char1_tail, '!');
    char1list.AddFirst(char1_head,char1_tail, 'c');
    char1list.AddFirst(char1_head,char1_tail, '5');
    char1list.Print(char1_head, char1_tail);
    char1list.DelLast(char1_head, char1_tail);
    char1list.DelFirst(char1_head, char1_tail);
    char1list.Print(char1_head, char1_tail);
    std::cout << "Size: " << char1list.GetSize(char1_head, char1_tail) << " First: " << char1list.GetFirst(char1_head, char1_tail) << " Last: " << char1list.GetLast(char1_head, char1_tail) << std::endl;
    char1list.AddLast(char1_head, char1_tail ,'7');
    char1list.AddLast(char1_head, char1_tail, 'j');
    char1list.DelLast(char1_head, char1_tail);
    char1list.Print(char1_head, char1_tail);

    CharList::Node* char1_head2 = nullptr;
    CharList::Node* char1_tail2 = nullptr;
    char1list.AddLast(char1_head2,char1_tail2, '1');
    char1list.AddLast(char1_head2,char1_tail2, 'h');
    char1list.AddLast(char1_head2,char1_tail2, 'u');

    CharList::Node* char1_head3 = nullptr;
    CharList::Node* char1_tail3 = nullptr;
    char1list.AddLast(char1_head3,char1_tail3, '[');
    std::cout << char1_head3;

    try{
        char b = char1list.GetAt(char1_head3,char1_tail3, 100);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    char1list.AddLast(char1_head,char1_tail, '!');
    std::cout << char1_head << std::endl;

    if (char1list.checkChar(char1_head, char1_tail)){
        char1list.clearSymbol(char1_head, char1_tail);
    }
    std::cout << "cleared" << std::endl;
    std::cout << char1_head << std::endl;

    char1list.Clean(char1_head, char1_tail);
    char1list.Clean(char1_head2, char1_tail2);
    char1list.Clean(char1_head3, char1_tail3);

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
    std::cout << "IntList(cleared) =============================" << std::endl;

    IntList intList;
    IntList::Node* int_head = nullptr;
    IntList::Node* int_tail = nullptr;

    intList.AddLast(int_head, int_tail, 7);
    intList.AddLast(int_head, int_tail, 14);
    intList.AddLast(int_head, int_tail, 3);
    intList.AddFirst(int_head, int_tail, 21);
    intList.AddFirst(int_head, int_tail, 8);

    intList.Print(int_head, int_tail);
    intList.DelLast(int_head, int_tail);
    intList.DelFirst(int_head, int_tail);
    intList.Print(int_head, int_tail);

    std::cout << "Size: " << intList.GetSize(int_head, int_tail)
              << " First: " << intList.GetFirst(int_head, int_tail)
              << " Last: " << intList.GetLast(int_head, int_tail)
              << std::endl;

    intList.AddLast(int_head, int_tail, 7);
    intList.AddLast(int_head, int_tail, 5);
    intList.DelLast(int_head, int_tail);
    intList.Print(int_head, int_tail);

    IntList::Node* int_head2 = nullptr;
    IntList::Node* int_tail2 = nullptr;
    intList.AddLast(int_head2, int_tail2, 7);
    intList.AddLast(int_head2, int_tail2, 2);
    intList.AddLast(int_head2, int_tail2, 3);

    IntList::Node* int_head3 = nullptr;
    IntList::Node* int_tail3 = nullptr;
    intList.AddLast(int_head3, int_tail3, 49);
    std::cout << int_head3 << std::endl;

    try {
        int x = intList.GetAt(int_head3, int_tail3, 100);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    intList.AddLast(int_head, int_tail, 28);
    std::cout << int_head << std::endl;

    if (intList.checkDiv7(int_head, int_tail)) {
        intList.clearEven(int_head, int_tail);
    }

    std::cout << "cleared" << std::endl;
    std::cout << int_head << std::endl;

    intList.Clean(int_head, int_tail);
    intList.Clean(int_head2, int_tail2);
    intList.Clean(int_head3, int_tail3);

    std::cout << "======================================" << std::endl;
    std::cout << "QueueInt(cleared) ===============================" << std::endl;
    QueueInt intQ1, intQ2, intQ3;
    intQ1 += 7;
    intQ1 += 14;
    intQ1 += 3;
    intQ1 += 21;
    intQ1 += 5;
    intQ1.Print();
    --intQ1;
    --intQ1;
    intQ1.Print();
    std::cout << "First: " << *intQ1 << std::endl;
    intQ1 += 7;
    intQ1 += 8;
    --intQ1;
    intQ1.Print();
    intQ2 += 3;
    intQ2 += 14;
    intQ2 += 7;
    intQ3 += 49;
    std::cout << intQ3 << std::endl;
    std::cout << intQ1 << std::endl;
    if (intQ1.checkDiv7()) {
        intQ1.clearEven();
    }
    std::cout << "cleared" << std::endl;
    std::cout << intQ1 << std::endl;
    std::cout << "======================================" << std::endl;
    std::cout << "DEFENSE======================================" << std::endl;
    IntList::Node* headd = nullptr;
    IntList::Node* taild = nullptr;


    list.AddLast(headd, taild, 1);
    list.AddLast(headd, taild, 2);
    list.AddLast(headd, taild, 3);
    list.AddFirst(headd, taild, 4);
    list.AddFirst(headd, taild, 5);
    std::cout << headd << std::endl;

    if(list.checkRange(headd, taild,2, 5)) list.clearForRange(headd, taild,2, 5);

    std::cout << "cleared";
    std::cout << headd << std::endl;
    std::cout << "======================================" << std::endl;
    CharList::Node* headdc = nullptr;
    CharList::Node* taildc = nullptr;


    charlist.AddLast(headdc, taildc, 'a');
    charlist.AddLast(headdc, taildc, 'v');
    charlist.AddLast(headdc, taildc, 'c');
    charlist.AddFirst(headdc, taildc, 'd');
    charlist.AddFirst(headdc, taildc, 'e');
    std::cout << headdc << std::endl;

    if(charlist.checkRange(headdc, taildc,'a', 'c')) charlist.clearForRange(headdc, taildc,'a',
                                                                            'c');

    std::cout << "cleared";

    std::cout << headdc << std::endl;
    std::cout << "======================================" << std::endl;
    QueueInt interqueue1;
    interqueue1 += 1;
    interqueue1 += 2;
    interqueue1 += 3;
    interqueue1 += 4;
    interqueue1 += 5;
    if(interqueue1.checkRange(1, 3)) interqueue1.clearForRange(1, 3);
    std::cout << interqueue1 << std::endl;
    std::cout << "cleared";
    std::cout << interqueue1 << std::endl;
    std::cout << "======================================" << std::endl;
    QueueChar charqueue1;
    charqueue1 += 'a';
    charqueue1 += 'b';
    charqueue1 += 'c';
    charqueue1 += 'd';
    charqueue1 += 'e';
    std::cout << charqueue1 << std::endl;

    if(charqueue1.checkRange('a', 'b')) charqueue1.clearForRange('a', 'b');
    std::cout << "cleared";

    std::cout << charqueue1 << std::endl;

    return 0;
}
