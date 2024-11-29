#include "SearchMenu.h"
#include "LinearSearch.h"
#include "BinarySearch.h"

void searchMenu(sf::RenderWindow &window, sf::Font &font) {
    sf::Text menuText[3];
    std::string menuItems[3] = {
        "1. Linear Search",
        "2. Binary Search",
        "3. Regresar"
    };

    // Configuración inicial de los textos
    for (int i = 0; i < 3; ++i) {
        menuText[i].setFont(font);
        menuText[i].setCharacterSize(30);
        menuText[i].setFillColor(sf::Color::Green);  // Color inicial verde
        menuText[i].setString(menuItems[i]);
        menuText[i].setPosition(100.f, 100.f + (i * 50));  // Espaciado entre opciones
    }

    bool menuActive = true;
    while (menuActive) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Capturar la posición del ratón
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

        // Cambiar color si el ratón está sobre el texto
        for (int i = 0; i < 3; ++i) {
            if (menuText[i].getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                menuText[i].setFillColor(sf::Color::Red); // Hover: rojo
            } else {
                menuText[i].setFillColor(sf::Color::Green); // Fuera del hover: verde
            }
        }

        // Limpiar la ventana con un color de fondo
        window.clear(sf::Color::Black);

        // Dibujar los textos en la ventana
        for (int i = 0; i < 3; ++i) {
            window.draw(menuText[i]);
        }

        // Mostrar el contenido de la ventana
        window.display();

        // Si se selecciona una opción
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (menuText[0].getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                // Llamar al algoritmo de Linear Search
                linearSearch(window, font);
            } else if (menuText[1].getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                // Llamar al algoritmo de Binary Search
                binarySearch(window, font);
            } else if (menuText[2].getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                // Regresar al menú principal
                menuActive = false;
            }
        }
    }
}
