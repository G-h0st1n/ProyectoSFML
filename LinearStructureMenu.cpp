#include "LinearStructureMenu.h"
#include "StackMenu.h"
#include "QueueMenu.h"
#include "LinkedListMenu.h"
#include <SFML/Graphics.hpp>

// Función para manejar el submenú de Estructuras Lineales
void displayLinearStructureMenu(sf::RenderWindow &window, sf::Font &font) {
    // Textos de opciones del menú
    sf::Text stackText("Pilas (Stacks)", font, 30);
    stackText.setPosition(100.f, 100.f);
    stackText.setFillColor(sf::Color::Green);

    sf::Text queueText("Colas (Queues)", font, 30);
    queueText.setPosition(100.f, 150.f);
    queueText.setFillColor(sf::Color::Green);

    sf::Text linkedListText("Listas Enlazadas (Linked Lists)", font, 30);
    linkedListText.setPosition(100.f, 200.f);
    linkedListText.setFillColor(sf::Color::Green);

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
        if (stackText.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
            stackText.setFillColor(sf::Color::Red);
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                displayStackMenu(window, font); // Llamar a la función del submenú de pilas
            }
        } else {
            stackText.setFillColor(sf::Color::Green);
        }

        if (queueText.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
            queueText.setFillColor(sf::Color::Red);
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                displayQueueMenu(window, font); // Llamar a la función del submenú de colas
            }
        } else {
            queueText.setFillColor(sf::Color::Green);
        }

        if (linkedListText.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
            linkedListText.setFillColor(sf::Color::Red);
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                displayLinkedListMenu(window, font); // Llamar a la función del submenú de listas enlazadas
            }
        } else {
            linkedListText.setFillColor(sf::Color::Green);
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
        window.draw(stackText);
        window.draw(queueText);
        window.draw(linkedListText);
        window.draw(exitText);

        window.display();
    }
}
