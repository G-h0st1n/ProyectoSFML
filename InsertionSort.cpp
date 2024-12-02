#include "InsertionSort.h"
#include <vector>
#include <sstream>

void insertionSort(sf::RenderWindow &window, sf::Font &font) {
    // Ingresar datos
    sf::Text promptText;
    promptText.setFont(font);
    promptText.setCharacterSize(20);
    promptText.setFillColor(sf::Color::Green);
    promptText.setString("Ingrese el tamaño del arreglo:");
    promptText.setPosition(100.f, 100.f);

    window.clear(sf::Color::Black);
    window.draw(promptText);
    window.display();

    int size = 0;
    bool waitingForSize = true;

    // Esperar tamaño
    while (waitingForSize) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode >= '0' && event.text.unicode <= '9') {
                    size = size * 10 + (event.text.unicode - '0');
                    std::stringstream ss;
                    ss << size;
                    promptText.setString("Ingrese el tamaño del arreglo: " + ss.str());
                    window.clear(sf::Color::Black);
                    window.draw(promptText);
                    window.display();
                } else if (event.text.unicode == 13) {
                    waitingForSize = false;
                }
            }
        }
    }

    // Crear arreglo
    std::vector<int> arr(size);
    promptText.setString("Ingrese los números del arreglo:");
    promptText.setPosition(100.f, 150.f);
    window.clear(sf::Color::Black);
    window.draw(promptText);
    window.display();

    for (int i = 0; i < size; ++i) {
        int num = 0;
        bool waitingForNumber = true;

        while (waitingForNumber) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();

                if (event.type == sf::Event::TextEntered) {
                    if (event.text.unicode >= '0' && event.text.unicode <= '9') {
                        num = num * 10 + (event.text.unicode - '0');
                        std::stringstream ss;
                        ss << num;
                        promptText.setString("Ingrese el número " + std::to_string(i + 1) + ": " + ss.str());
                        window.clear(sf::Color::Black);
                        window.draw(promptText);
                        window.display();
                    } else if (event.text.unicode == 13) {
                        arr[i] = num;
                        waitingForNumber = false;
                    }
                }
            }
        }
    }

    // Insertion Sort con visualización
    for (int i = 1; i < size; ++i) {
        int key = arr[i];
        int j = i - 1;

        // Resaltar el elemento a insertar
        while (j >= 0 && arr[j] > key) {
            // Resaltar los elementos desplazados
            window.clear(sf::Color::Black);
            for (int k = 0; k < size; ++k) {
                sf::RectangleShape rect(sf::Vector2f(50.f, 50.f));
                rect.setPosition(100.f + (k * 60), 300.f);
                if (k == i) {
                    rect.setFillColor(sf::Color::Red); // Resaltar el elemento a insertar
                } else if (k == j) {
                    rect.setFillColor(sf::Color::Yellow); // Resaltar los elementos desplazados
                } else {
                    rect.setFillColor(sf::Color::Green);
                }
                window.draw(rect);
                sf::Text numText(std::to_string(arr[k]), font, 20);
                numText.setPosition(100.f + (k * 60), 350.f);
                window.draw(numText);
            }

            window.display();
            sf::sleep(sf::seconds(0.5f));

            arr[j + 1] = arr[j]; // Desplazar el elemento hacia la derecha
            --j;
        }
        arr[j + 1] = key; // Insertar el elemento en la posición correcta

        // Mostrar el arreglo después de la inserción
        window.clear(sf::Color::Black);
        for (int k = 0; k < size; ++k) {
            sf::RectangleShape rect(sf::Vector2f(50.f, 50.f));
            rect.setPosition(100.f + (k * 60), 300.f);
            rect.setFillColor(sf::Color::Green);
            window.draw(rect);
            sf::Text numText(std::to_string(arr[k]), font, 20);
            numText.setPosition(100.f + (k * 60), 350.f);
            window.draw(numText);
        }

        window.display();
        sf::sleep(sf::seconds(0.5f));
    }

    // Resultado final
    window.clear(sf::Color::Black);
    for (int k = 0; k < size; ++k) {
        sf::RectangleShape rect(sf::Vector2f(50.f, 50.f));
        rect.setPosition(100.f + (k * 60), 300.f);
        rect.setFillColor(sf::Color::Green);
        window.draw(rect);
        sf::Text numText(std::to_string(arr[k]), font, 20);
        numText.setPosition(100.f + (k * 60), 350.f);
        window.draw(numText);
    }

    window.display();
    sf::sleep(sf::seconds(3)); // Esperar para mostrar el resultado
}