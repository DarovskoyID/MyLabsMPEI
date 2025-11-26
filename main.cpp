/*Для чётных вариантов:
двунаправленный список;
очередь на основе массива.

 Если в списке из символов есть латинские буквы, удалить из списка знаки препинания.
*/
#include <iostream>
#include "List.h"
#include "Queue.h"

template<class T>
int GetQueueSize(Queue<T>& q) {
    int size = 0;
    Queue<T> temp = q;
    while (!!temp) {
        size++;
        --temp;
    }
    return size;
}

bool checkChar(Queue<char>& q) {
    bool flag = false;
    Queue<char> temp = q;

    while (!!temp) {
        char c = *temp;
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            flag = true;
            break;
        }
        --temp;
    }

    return flag;
}

void clearSymbol(Queue<char>& q) {
    if (!checkChar(q)) {
        return;
    }

    Queue<char> temp;
    Queue<char> original = q;

    while (!!original) {
        char c = *original;
        if (c != '!' && c != ',' && c != '.' && c != '?' && c != ':' && c != ';' &&
            c != '-' && c != '\'' && c != '\"' && c != '(' && c != ')') {
            temp += c;
        }
        --original;
    }

    q = temp;
}

bool checkChar(List<char>::Node* head) {
    bool flag = false;

    for (List<char>::Node* p = head; p; p = p->next) {
        char c = p->data;
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            flag = true;
            break;
        }
    }

    return flag;
}

void clearSymbol(List<char>::Node*& head) {
    if (!checkChar(head)) {
        return;
    }

    List<char> list;
    List<char>::Node* new_head = nullptr;

    for (List<char>::Node* p = head; p; p = p->next) {
        char c = p->data;
        if (c != '!' && c != ',' && c != '.' && c != '?' && c != ':' && c != ';' &&
            c != '-' && c != '\'' && c != '\"' && c != '(' && c != ')') {
            list.AddLast(new_head, c);
        }
    }

    while (head) {
        list.DelLast(head);
    }

    for (List<char>::Node* p = new_head; p; p = p->next) {
        list.AddLast(head, p->data);
    }

    while (new_head) {
        list.DelLast(new_head);
    }
}

int GetSize(List<int>::Node* head) {
    int count = 0;
    List<int>::Node* current = head;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

int& GetAt(List<int>::Node* head, int index) {
    if (index < 0) throw std::out_of_range("Negative index");
    List<int>::Node* current = head;
    for (int i = 0; i < index && current; i++) {
        current = current->next;
    }
    if (!current) throw std::out_of_range("Index out of range");
    return current->data;
}

int GetSize(List<char>::Node* head) {
    int count = 0;
    List<char>::Node* current = head;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

char& GetAt(List<char>::Node* head, int index) {
    if (index < 0) throw std::out_of_range("Negative index");
    List<char>::Node* current = head;
    for (int i = 0; i < index && current; i++) {
        current = current->next;
    }
    if (!current) throw std::out_of_range("Index out of range");
    return current->data;
}

List<int>::Node* Concat(List<int>::Node* head1, List<int>::Node* head2) {
    List<int> list;
    List<int>::Node* result = nullptr;
    List<int>::Node* current = head1;
    while (current) {
        list.AddLast(result, current->data);
        current = current->next;
    }
    current = head2;
    while (current) {
        list.AddLast(result, current->data);
        current = current->next;
    }
    return result;
}

List<char>::Node* Concat(List<char>::Node* head1, List<char>::Node* head2) {
    List<char> list;
    List<char>::Node* result = nullptr;
    List<char>::Node* current = head1;
    while (current) {
        list.AddLast(result, current->data);
        current = current->next;
    }
    current = head2;
    while (current) {
        list.AddLast(result, current->data);
        current = current->next;
    }
    return result;
}

int main(){
    std::cout << "List =================================" << std::endl;

    List<int>::Node* head = nullptr;
    List<int> list;

    list.AddLast(head, 1);
    list.AddLast(head, 2);
    list.AddLast(head, 3);
    list.AddFirst(head, 4);
    list.AddFirst(head, 5);
    list.Print(head);
    list.DelLast(head);
    list.DelFirst(head);
    list.Print(head);
    std::cout << "Size: " << GetSize(head) << " First: " << list.GetFirst(head) << " Last: " << list.GetLast(head) << std::endl;

    list.AddLast(head, 7);
    list.AddLast(head, 90);
    list.DelLast(head);
    list.Print(head);

    List<int>::Node* head2 = nullptr;
    list.AddLast(head2, 1);
    list.AddLast(head2, 2);
    list.AddLast(head2, 3);

    List<int>::Node* head3 = Concat(head, head2);
    list.AddLast(head3, 10);
    std::cout << head3;
    std::cout << "Element at index 4: " << GetAt(head3, 4) << std::endl;

    try{
        int a = GetAt(head3, 100);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    while (head) list.DelLast(head);
    while (head2) list.DelLast(head2);
    while (head3) list.DelLast(head3);

    std::cout << "======================================" << std::endl;

    std::cout << "Queue ================================" << std::endl;
    Queue<int> interqueue, interqueue2, interqueue3;
    interqueue += 1;
    interqueue += 2;
    interqueue += 3;
    interqueue += 4;
    interqueue += 5;
    interqueue.Print();
    --interqueue;
    --interqueue;
    interqueue.Print();
    std::cout << "First: " << *interqueue << " Last: " << interqueue[GetQueueSize(interqueue)-1] << std::endl;
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
    List<char> charlist;
    List<char>::Node* char_head = nullptr;

    charlist.AddLast(char_head, 'a');
    charlist.AddLast(char_head, '2');
    charlist.AddLast(char_head, '!');
    charlist.AddFirst(char_head, 'c');
    charlist.AddFirst(char_head, '5');
    charlist.Print(char_head);
    charlist.DelLast(char_head);
    charlist.DelFirst(char_head);
    charlist.Print(char_head);
    std::cout << "Size: " << GetSize(char_head) << " First: " << charlist.GetFirst(char_head) << " Last: " << charlist.GetLast(char_head) << std::endl;
    charlist.AddLast(char_head, '7');
    charlist.AddLast(char_head, 'j');
    charlist.DelLast(char_head);
    charlist.Print(char_head);

    List<char>::Node* char_head2 = nullptr;
    charlist.AddLast(char_head2, '1');
    charlist.AddLast(char_head2, 'h');
    charlist.AddLast(char_head2, 'u');

    List<char>::Node* char_head3 = Concat(char_head, char_head2);
    charlist.AddLast(char_head3, '[');
    std::cout << char_head3;
    std::cout << "Element at index 4: " << GetAt(char_head3, 4) << std::endl;

    try{
        char b = GetAt(char_head3, 100);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    while (char_head) charlist.DelLast(char_head);
    while (char_head2) charlist.DelLast(char_head2);
    while (char_head3) charlist.DelLast(char_head3);

    std::cout << "======================================" << std::endl;

    std::cout << "Queue ================================" << std::endl;
    Queue<char> charqueue, charqueue2, charqueue3;
    charqueue += 'a';
    charqueue += 'b';
    charqueue += 'c';
    charqueue += 'd';
    charqueue += 'e';
    charqueue.Print();
    --charqueue;
    --charqueue;
    charqueue.Print();
    std::cout << "First: " << *charqueue << " Last: " << charqueue[GetQueueSize(charqueue)-1] << std::endl;
    charqueue += '!';
    charqueue += ']';
    --charqueue;
    charqueue.Print();

    charqueue2 += 'h';
    charqueue2 += 'g';
    charqueue2 += '3';

    charqueue3 = charqueue + charqueue2;
    charqueue3 += '1';
    std::cout << charqueue3 << std::endl;
    std::cout << "======================================" << std::endl;

    std::cout << "List(cleared) =================================" << std::endl;
    List<char> char1list;
    List<char>::Node* char1_head = nullptr;

    char1list.AddLast(char1_head, 'a');
    char1list.AddLast(char1_head, '2');
    char1list.AddLast(char1_head, '!');
    char1list.AddFirst(char1_head, 'c');
    char1list.AddFirst(char1_head, '5');
    char1list.Print(char1_head);
    char1list.DelLast(char1_head);
    char1list.DelFirst(char1_head);
    char1list.Print(char1_head);
    std::cout << "Size: " << GetSize(char1_head) << " First: " << char1list.GetFirst(char1_head) << " Last: " << char1list.GetLast(char1_head) << std::endl;
    char1list.AddLast(char1_head, '7');
    char1list.AddLast(char1_head, 'j');
    char1list.DelLast(char1_head);
    char1list.Print(char1_head);

    List<char>::Node* char1_head2 = nullptr;
    char1list.AddLast(char1_head2, '1');
    char1list.AddLast(char1_head2, 'h');
    char1list.AddLast(char1_head2, 'u');

    List<char>::Node* char1_head3 = Concat(char1_head, char1_head2);
    char1list.AddLast(char1_head3, '[');
    std::cout << char1_head3;
    std::cout << "Element at index 4: " << GetAt(char1_head3, 4) << std::endl;

    try{
        char b = GetAt(char1_head3, 100);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n";
    char1list.AddLast(char1_head, '!');
    std::cout << char1_head << std::endl;

    if (checkChar(char1_head)){
        clearSymbol(char1_head);
    }
    std::cout << "cleared" << std::endl;
    std::cout << char1_head << std::endl;

    while (char1_head) char1list.DelLast(char1_head);
    while (char1_head2) char1list.DelLast(char1_head2);
    while (char1_head3) char1list.DelLast(char1_head3);

    std::cout << "======================================" << std::endl;

    std::cout << "Queue(cleared) ================================" << std::endl;
    Queue<char> char1queue, char1queue2, char1queue3;
    char1queue += 'a';
    char1queue += 'b';
    char1queue += 'c';
    char1queue += 'd';
    char1queue += 'e';
    char1queue.Print();
    --char1queue;
    --char1queue;
    char1queue.Print();
    std::cout << "First: " << *char1queue << " Last: " << char1queue[GetQueueSize(char1queue)-1] << std::endl;
    char1queue += '!';
    char1queue += ']';
    --char1queue;
    char1queue.Print();

    char1queue2 += 'h';
    char1queue2 += 'g';
    char1queue2 += '3';

    char1queue3 = char1queue + char1queue2;
    char1queue3 += '1';
    std::cout << char1queue3;
    std::cout << "\n";
    std::cout << char1queue << std::endl;
    if (checkChar(char1queue)){
        clearSymbol(char1queue);
    }
    std::cout << "cleared" << std::endl;
    std::cout << char1queue << std::endl;

    std::cout << "======================================" << std::endl;
    return 0;
}

