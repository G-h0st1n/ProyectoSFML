#include "QueueMenu.h"
#include <SFML/Graphics.hpp>
#include <queue>
#include <iostream>

// Clase para manejar la cola
class Queue {
public:
    std::queue<int> q;

    void enqueue(int value) {
        q.push(value);
    }

    void dequeue() {
        if (!q.empty()) {
            q.pop();
        }
    }

    bool isEmpty() {
        return q.empty();
    }

    int front() {
        return q.empty() ? -1 : q.front();
    }
};

// Función para dibujar la cola en pantalla
void drawQueue(sf::RenderWindow& window, sf::Font& font, Queue& queue) {
    float yOffset = 0.0f;
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);

    // Se crea una copia de la cola para procesarla
    std::queue<int> tempQueue = queue.q;

    // Iteramos sobre la cola utilizando front() y pop()
    while (!tempQueue.empty()) {
        text.setString(std::to_string(tempQueue.front()));
        text.setPosition(50.0f, 50.0f + yOffset);
        window.draw(text);
        tempQueue.pop();  // Elimina el elemento procesado
        yOffset += 30.0f; // Desplazamiento vertical para cada elemento
    }
}


// Función para manejar el submenú de Filas
void displayQueueMenu(sf::RenderWindow &window, sf::Font &font) {
    Queue queue;

    // Poner algunos valores iniciales en la cola
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    // Texto de las opciones
    sf::Text enqueueText("Enqueue (Agregar un valor)", font, 30);
    enqueueText.setPosition(100.f, 100.f);
    enqueueText.setFillColor(sf::Color::Green);

    sf::Text dequeueText("Dequeue (Eliminar el valor frente)", font, 30);
    dequeueText.setPosition(100.f, 150.f);
    dequeueText.setFillColor(sf::Color::Green);

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
        if (enqueueText.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
            enqueueText.setFillColor(sf::Color::Red);
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                queue.enqueue(4);  // Agregar un valor fijo para ilustrar el enqueue
            }
        } else {
            enqueueText.setFillColor(sf::Color::Green);
        }

        if (dequeueText.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
            dequeueText.setFillColor(sf::Color::Red);
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                queue.dequeue();  // Eliminar el valor al frente de la cola
            }
        } else {
            dequeueText.setFillColor(sf::Color::Green);
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
        window.draw(enqueueText);
        window.draw(dequeueText);
        window.draw(exitText);

        // Dibujar la cola
        drawQueue(window, font, queue);

        window.display();
    }
}
