#include <SFML/Graphics.hpp>
#include "SearchMenu.h"
#include "SortMenu.h"

int main() {
    // Crear ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "Proyecto de Algoritmos", sf::Style::Close);
    window.setFramerateLimit(60);

    // Cargar fuente
    sf::Font font;
    if (!font.loadFromFile("C:\\Users\\frpat\\Fonts\\Tr2n.ttf")) {
        return -1; // Salir si no se puede cargar la fuente
    }

    // Crear textos para el menú principal
    sf::Text searchOption("Algoritmos de Busqueda", font, 30);
    sf::Text sortOption("Algoritmos de Ordenamiento", font, 30);
    sf::Text exitOption("Salir", font, 30);

    // Posicionar las opciones
    searchOption.setPosition(100.f, 100.f);
    sortOption.setPosition(100.f, 150.f);
    exitOption.setPosition(100.f, 200.f);

    // Colores iniciales
    searchOption.setFillColor(sf::Color::Green);
    sortOption.setFillColor(sf::Color::Green);
    exitOption.setFillColor(sf::Color::Green);

    sf::Vector2f mousePosition;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseMoved) {
                mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));

                // Cambiar color al pasar el ratón
                searchOption.setFillColor(searchOption.getGlobalBounds().contains(mousePosition) ? sf::Color::Red : sf::Color::Green);
                sortOption.setFillColor(sortOption.getGlobalBounds().contains(mousePosition) ? sf::Color::Red : sf::Color::Green);
                exitOption.setFillColor(exitOption.getGlobalBounds().contains(mousePosition) ? sf::Color::Red : sf::Color::Green);
            }

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                // Verificar qué opción fue seleccionada
                if (searchOption.getGlobalBounds().contains(mousePosition)) {
                    searchMenu(window, font); // Llamar al submenú de búsqueda
                } else if (sortOption.getGlobalBounds().contains(mousePosition)) {
                    sortMenu(window, font); // Llamar al submenú de ordenamiento
                } else if (exitOption.getGlobalBounds().contains(mousePosition)) {
                    window.close(); // Salir del programa
                }
            }
        }

        // Dibujar el menú principal
        window.clear(sf::Color::Black);
        window.draw(searchOption);
        window.draw(sortOption);
        window.draw(exitOption);
        window.display();
    }

    return 0;
}
