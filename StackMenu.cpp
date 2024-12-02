#include "StackMenu.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

// Clase para manejar la pila
class Stack {
public:
    std::vector<int> stack;

    void push(int value) {
        stack.push_back(value);
    }

    void pop() {
        if (!stack.empty()) {
            stack.pop_back();
        }
    }

    bool isEmpty() {
        return stack.empty();
    }

    int top() {
        return stack.empty() ? -1 : stack.back();
    }
};

// Función para dibujar la pila en pantalla
void drawStack(sf::RenderWindow &window, sf::Font &font, Stack &stack) {
    float offsetY = 300.f;
    for (size_t i = 0; i < stack.stack.size(); ++i) {
        sf::RectangleShape block(sf::Vector2f(100.f, 30.f));
        block.setFillColor(sf::Color(100, 100, 255));
        block.setPosition(250.f, offsetY - i * 40.f);

        sf::Text text(std::to_string(stack.stack[i]), font, 20);
        text.setFillColor(sf::Color::White);
        text.setPosition(260.f, offsetY - i * 40.f + 5.f);

        window.draw(block);
        window.draw(text);
    }
}

// Función para manejar el submenú de Pilas
void displayStackMenu(sf::RenderWindow &window, sf::Font &font) {
    Stack stack;

    // Poner algunos valores iniciales en la pila (simulando una torre de discos)
    stack.push(1);
    stack.push(2);
    stack.push(3);

    // Texto de las opciones
    sf::Text pushText("Push (Agregar un valor)", font, 30);
    pushText.setPosition(100.f, 100.f);
    pushText.setFillColor(sf::Color::Green);

    sf::Text popText("Pop (Eliminar el valor superior)", font, 30);
    popText.setPosition(100.f, 150.f);
    popText.setFillColor(sf::Color::Green);

    sf::Text exitText("Regresar al menú anterior", font, 30);
    exitText.setPosition(100.f, 200.f);
    exitText.setFillColor(sf::Color::Green);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Detectar el hover y clic en las opciones
        if (pushText.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
            pushText.setFillColor(sf::Color::Red);
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                stack.push(4);  // Agregar un valor fijo para ilustrar el push
            }
        } else {
            pushText.setFillColor(sf::Color::Green);
        }

        if (popText.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
            popText.setFillColor(sf::Color::Red);
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                stack.pop();  // Eliminar el valor superior de la pila
            }
        } else {
            popText.setFillColor(sf::Color::Green);
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
        window.draw(pushText);
        window.draw(popText);
        window.draw(exitText);

        // Dibujar la pila
        drawStack(window, font, stack);

        window.display();
    }
}
