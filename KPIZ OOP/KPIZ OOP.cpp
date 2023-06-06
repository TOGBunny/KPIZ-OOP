#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(const T& data) : data(data), next(nullptr) {}
};

template <typename T>
class LinkedList {
public:
    Node<T>* head;

    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* temp = current;
            current = current->next;
            delete temp;
        }
    }

    void add(const T& data) {
        Node<T>* new_node = new Node<T>(data);
        new_node->next = head;
        head = new_node;
    }

    void print() {
        Node<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    LinkedList<T> operator+(const T& data) {
        LinkedList<T> result;
        Node<T>* current = head;
        while (current != nullptr) {
            result.add(current->data);
            current = current->next;
        }
        result.add(data);
        return result;
    }

    bool operator==(const LinkedList<T>& other) const {
        Node<T>* current = head;
        Node<T>* other_current = other.head;
        while (current != nullptr && other_current != nullptr) {
            if (current->data != other_current->data) {
                return false;
            }
            current = current->next;
            other_current = other_current->next;
        }
        return (current == nullptr && other_current == nullptr);
    }
};

int main() {
    LinkedList<char> charList;
    charList.add('a');
    charList.add('b');
    charList.add('c');

    LinkedList<int> intList;
    intList.add(1);
    intList.add(2);
    intList.add(3);

    LinkedList<float> floatList;
    floatList.add(1.1f);
    floatList.add(2.2f);
    floatList.add(3.3f);

    LinkedList<std::string> stringList;
    stringList.add("Hello");
    stringList.add("World");

    LinkedList<char> charList2 = charList + 'd';
    std::cout << "Char List 2: ";
    charList2.print();

    LinkedList<int> intList2 = intList + 4;
    std::cout << "Int List 2: ";
    intList2.print();

    LinkedList<float> floatList2 = floatList + 4.4f;
    std::cout << "Float List 2: ";
    floatList2.print();

    LinkedList<std::string> stringList2 = stringList + "!";
    std::cout << "String List 2: ";
    stringList2.print();

    if (charList == charList2) {
        std::cout << "Char List 1 is equal to Char List 2" << std::endl;
    }
    else {
        std::cout << "Char List 1 is not equal to Char List 2" << std::endl;
    }

    if (intList == intList2) {
        std::cout << "Int List 1 is equal to Int List 2" << std::endl;
    }
    else {
        std::cout << "Int List 1 is not equal to Int List";
            if (floatList == floatList2) {
                std::cout << "Float List 1 is equal to Float List 2" << std::endl;
            }
            else {
                std::cout << "Float List 1 is not equal to Float List 2" << std::endl;
            }

        if (stringList == stringList2) {
            std::cout << "String List 1 is equal to String List 2" << std::endl;
        }
        else {
            std::cout << "String List 1 is not equal to String List 2" << std::endl;
        }

        return 0;
    }