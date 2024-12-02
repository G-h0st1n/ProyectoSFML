#include "LinkedListMenu.h"
#include <SFML/Graphics.hpp>
#include <iostream>

// Definir la estructura de un nodo en la lista
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Clase para manejar la lista enlazada
class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void deleteAtFront() {
        if (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    Node* search(int value) {
        Node* temp = head;
        while (temp) {
            if (temp->data == value) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void clear() {
        while (head) {
            deleteAtFront();
        }
    }
};

// Función para dibujar la lista enlazada
void drawLinkedList(sf::RenderWindow &window, sf::Font &font, LinkedList &list) {
    float offsetX = 200.f;
    float offsetY = 200.f;
    int i = 0;
    Node* current = list.head;

    while (current) {
        sf::RectangleShape block(sf::Vector2f(80.f, 30.f));
        block.setFillColor(sf::Color(100, 255, 100));
        block.setPosition(offsetX + i * 90.f, offsetY);

        sf::Text text(std::to_string(current->data), font, 20);
        text.setFillColor(sf::Color::White);
        text.setPosition(offsetX + i * 90.f + 25.f, offsetY + 5.f);

        window.draw(block);
        window.draw(text);

        if (current->next) {
            sf::VertexArray arrow(sf::Lines, 2);
            arrow[0].position = sf::Vector2f(offsetX + i * 90.f + 80.f, offsetY + 15.f);
            arrow[1].position = sf::Vector2f(offsetX + (i + 1) * 90.f, offsetY + 15.f);
            arrow[0].color = arrow[1].color = sf::Color::White;
            window.draw(arrow);
        }

        current = current->next;
        i++;
    }
}

// Función para manejar el submenú de Listas Enlazadas
void displayLinkedListMenu(sf::RenderWindow &window, sf::Font &font) {
    LinkedList list;

    // Insertar algunos nodos iniciales
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);

    // Texto de las opciones
    sf::Text insertText("Insertar un nodo al final", font, 30);
    insertText.setPosition(100.f, 100.f);
    insertText.setFillColor(sf::Color::Green);

    sf::Text deleteText("Eliminar nodo al frente", font, 30);
    deleteText.setPosition(100.f, 150.f);
    deleteText.setFillColor(sf::Color::Green);

    sf::Text searchText("Buscar un nodo", font, 30);
    searchText.setPosition(100.f, 200.f);
    searchText.setFillColor(sf::Color::Green);

    sf::Text exitText("Regresar al menú anterior", font, 30);
    exitText.setPosition(100.f, 250.f);
    exitText.setFillColor(sf::Color::Green);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Detectar el hover y clic en las opciones
        if (insertText.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
            insertText.setFillColor(sf::Color::Red);
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                int value = 40;  // Valor fijo para insertar
                list.insertAtEnd(value);
            }
        } else {
            insertText.setFillColor(sf::Color::Green);
        }

        if (deleteText.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
            deleteText.setFillColor(sf::Color::Red);
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                list.deleteAtFront();
            }
        } else {
            deleteText.setFillColor(sf::Color::Green);
        }

        if (searchText.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
            searchText.setFillColor(sf::Color::Red);
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                int value = 20;  // Valor fijo para buscar
                Node* foundNode = list.search(value);
                if (foundNode) {
                    std::cout << "Nodo encontrado: " << foundNode->data << std::endl;
                } else {
                    std::cout << "Nodo no encontrado." << std::endl;
                }
            }
        } else {
            searchText.setFillColor(sf::Color::Green);
        }

        if (exitText.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
            exitText.setFillColor(sf::Color::Red);
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                return;  // Regresar al menú anterior
            }
        } else {
            exitText.setFillColor(sf::Color::Green);
        }

        // Limpiar y dibujar
        window.clear(sf::Color::Black);
        window.draw(insertText);
        window.draw(deleteText);
        window.draw(searchText);
        window.draw(exitText);

        // Dibujar la lista enlazada
        drawLinkedList(window, font, list);

        window.display();
    }
}
