#include <iostream>

template <typename T>
struct Element {
    T data;
    Element<T>* next;

public:
    Element(T new_element) {
        data = new_element;
        next = nullptr;
    }

    ~Element() {
        Element<T>* next;
    }
};

template <typename T>
class OneList {
private:
    Element<T>* begin;
    Element<T>* end;
    int count;

public:
    OneList() : begin(nullptr), end(nullptr), count(0) {}
    ~OneList() {
        count = 0;
        begin->~Element();
        end->~Element();
    }

    T& operator[](int index) {
        int counter = 0;
        Element<T>* current_element = begin;
        if (count > 1) {
            if (index == -1) {
                while (current_element != nullptr) {
                    if (counter == count - 1) {
                        return current_element->data;
                    }
                    current_element = current_element->next;
                    counter++;
                }
            }
            else {
                while (current_element != nullptr) {
                    if (counter == index) {
                        return current_element->data;
                    }
                    current_element = current_element->next;
                    counter++;
                }
            }
        }
        else if (count == 1) {
            Element<T>* current_element = begin;
            return current_element->data;
        }
    }

    void push_front(T _data) {
        Element<T>* new_element = new Element<T>(_data);

        if (begin == nullptr) {
            begin = new_element;
            end = new_element;
        }

        else {
            new_element->next = begin;
            begin = new_element;
        }
        count++;
    }

    void push_back(T _data) {
        Element<T>* new_element = new Element<T>(_data);

        if (begin == nullptr) {
            begin = new_element;
            end = new_element;
        }

        else {
            end->next = new_element;
            end = new_element;
        }
        count++;
    }

    void pop_front() {
        if (begin != nullptr) {
            Element<T>* element_to_delete = begin;
            begin = begin->next;
            delete element_to_delete;
            count--;
        }

        else {
            throw "List size Error";
        }
    }

    void pop_back() {
        if (begin != nullptr) {
            Element<T>* point = begin;
            if (point->next != nullptr) {
                while (point->next->next != nullptr) {
                    point = point->next;
                }
            }
            point->next = nullptr;
            delete end;
            end = point;
            count--;
        }
    }

    void remove(T _data) {
        if (end != nullptr) {
            int current_element_index = 0;
            Element<T>* element = new Element<T>(_data);
            Element<T>* current_element = begin;

            if (current_element->data == _data) {
                pop_front();
            }
            else {
                for (int i = 0; i < count; i++) {
                    while (current_element->next != nullptr) {
                        if (current_element->next->data == element->data) {
                            if (current_element_index + 2 == count) {
                                pop_back();
                                break;
                            }
                            Element<T>* elemDel = current_element->next;
                            current_element->next = elemDel->next;
                            delete elemDel;
                            count--;
                            break;

                        }

                        current_element = current_element->next;
                        current_element_index++;
                    }
                }
            }

        }

        else {
            throw "List size Error";
        }
    }

    void insert(int position, T _data) {
        if (position == count) {
            push_back(_data);
        }
        else if (position == 0) {
            push_front(_data);
        }
        else if (position < count) {
            Element<T>* new_element = new Element<T>(_data);
            Element<T>* previos_element = begin;
            int counter = 1;
            while (counter != position) {
                counter++;
                previos_element = previos_element->next;
            }
            new_element->next = previos_element->next;
            previos_element->next = new_element;
            count++;
        }
    }

    int size() {
        return count;
    }

    Element<T>* front() {
        return begin;
    }

    Element<T>* back() {
        return end;
    }

    bool empty() {
        if (count == 0) return true;
        return false;
    }
};

template <typename T>
struct Element2 {
    T data;
    Element2<T>* next;
    Element2<T>* prev;

    Element2(T new_element) {
        data = new_element;
        next = nullptr;
        prev = nullptr;
    }

public:
    ~Element2() {
        Element2<T>* next;
        Element2<T>* prev;
    }
};

template <typename T>
class DoubleList {
private:
    Element2<T>* begin;
    Element2<T>* end;
    int count;

public:
    DoubleList() : begin(nullptr), end(nullptr), count(0) {}

    ~DoubleList() {
        count = 0;
        begin->~Element2();
        end->~Element2();
    }

    T& operator[](int index) {
        int counter = 0;
        Element2<T>* current_element = begin;
        if (count > 1) {
            if (index == -1) {
                while (current_element != nullptr) {
                    if (counter == count - 1) {
                        return current_element->data;
                    }
                    current_element = current_element->next;
                    counter++;
                }
            }
            else {
                while (current_element != nullptr) {
                    if (counter == index) {
                        return current_element->data;
                    }
                    current_element = current_element->next;
                    counter++;
                }
            }
        }
        else if (count == 1) {
            Element2<T>* current_element = begin;
            return current_element->data;
        }
    }

    void push_front(T _data) {
        Element2<T>* new_element = new Element2<T>(_data);

        if (begin == nullptr) {
            begin = new_element;
            end = new_element;
        }

        else {
            new_element->next = begin;
            begin = new_element;
        }
        count++;
    }

    void push_back(T _data) {
        Element2<T>* new_element = new Element2<T>(_data);

        if (begin == nullptr) {
            begin = new_element;
            end = new_element;
        }

        else {
            end->next = new_element;
            new_element->prev = end;
            end = new_element;
        }
        count++;
    }

    void pop_front() {
        if (begin != nullptr) {
            Element2<T>* element_to_delete = begin;
            begin = begin->next;
            delete element_to_delete;
            count--;
        }

        else {
            throw "List size Error";
        }

    }

    void pop_back() {
        if (count > 0) {
            Element2<T>* elem = begin;
            if (elem->next != nullptr) {
                while (elem->next->next != nullptr) {
                    elem = elem->next;
                }
            }
            elem->next = nullptr;
            delete end;
            end = elem;
            count--;
        }
    }

    void remove(T _data) {
        if (end != nullptr) {
            int current_element_index = 0;
            Element2<T>* element = new Element2<T>(_data);
            Element2<T>* current_element = begin;

            if (current_element->data == _data) {
                pop_front();
            }
            else {
                for (int i = 0; i < count; i++) {
                    while (current_element->next != nullptr) {
                        if (current_element->next->data == element->data) {
                            if (current_element_index + 2 == count) {
                                pop_back();
                                break;
                            }
                            Element2<T>* elemDel = current_element->next;
                            current_element->next = elemDel->next;
                            delete elemDel;
                            count--;
                            break;

                        }

                        current_element = current_element->next;
                        current_element_index++;
                    }
                }
            }

        }

        else {
            throw "List size Error";
        }
    }

    void insert(int position, T _data) {
        if (position < count) {
            if (position == 0) {
                push_front(_data);
            }
            else
            {
                Element2<T>* new_element = new Element2<T>(_data);
                Element2<T>* previos_element = begin;
                int counter = 1;
                while (counter != position) {
                    counter++;
                    previos_element = previos_element->next;
                }
                new_element->next = previos_element->next;
                previos_element->next = new_element;
                count++;
            }
        }
        else {
            if (position == count) {
                push_back(_data);
            }
            else
            {
                Element2<T>* new_element = new Element2<T>(_data);
                Element2<T>* previos_element = end;
                int counter = size();
                while (counter != position) {
                    counter--;
                    previos_element = previos_element->prev;
                }
                new_element->prev = previos_element->prev;
                previos_element->prev = new_element;
                count++;
            }
        }
    }

    int size() {
        return count;
    }

    Element2<T>* front() {
        return begin;
    }

    Element2<T>* back() {
        return end;
    }

    bool empty() {
        if (count == 0) return true;
        return false;
    }
};
