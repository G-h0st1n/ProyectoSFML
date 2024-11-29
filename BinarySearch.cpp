#include "BinarySearch.h"
#include <vector>
#include <sstream>
#include <algorithm> // Para std::sort

void binarySearch(sf::RenderWindow &window, sf::Font &font) {
    // Crear los textos para la interfaz
    sf::Text promptText, resultText;
    promptText.setFont(font);
    promptText.setCharacterSize(20);
    promptText.setFillColor(sf::Color::Green);

    // Instrucción para ingresar el tamaño del arreglo
    promptText.setString("Ingrese el tamano del arreglo:");
    promptText.setPosition(100.f, 100.f);

    // Mostrar la ventana mientras el usuario ingresa datos
    window.clear(sf::Color::Black);
    window.draw(promptText);
    window.display();

    int size = 0;
    bool waitingForSize = true;

    // Esperar que el usuario ingrese el tamaño
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
                    promptText.setString("Ingrese el tamano del arreglo: " + ss.str());
                    window.clear(sf::Color::Black);
                    window.draw(promptText);
                    window.display();
                } else if (event.text.unicode == 13) { // Enter
                    waitingForSize = false;
                }
            }
        }
    }

    // Crear un vector para almacenar los números del arreglo
    std::vector<int> arr(size);

    // Pedir los números al usuario
    promptText.setString("Ingrese los numeros del arreglo:");
    promptText.setPosition(100.f, 150.f);
    window.clear(sf::Color::Black);
    window.draw(promptText);
    window.display();

    for (int i = 0; i < size; ++i) {
        bool waitingForNumber = true;
        int num = 0;

        // Esperar que el usuario ingrese cada número
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
                        promptText.setString("Ingrese el numero " + std::to_string(i + 1) + ": " + ss.str());
                        window.clear(sf::Color::Black);
                        window.draw(promptText);
                        window.display();
                    } else if (event.text.unicode == 13) { // Enter
                        arr[i] = num;
                        waitingForNumber = false;
                    }
                }
            }
        }
    }

    // Ordenar el arreglo para la búsqueda binaria
    std::sort(arr.begin(), arr.end());

    // Pedir el número a buscar
    promptText.setString("Ingrese el numero a buscar:");
    promptText.setPosition(100.f, 200.f);
    window.clear(sf::Color::Black);
    window.draw(promptText);
    window.display();

    int searchValue = 0;
    bool waitingForSearch = true;

    // Esperar la entrada del número a buscar
    while (waitingForSearch) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode >= '0' && event.text.unicode <= '9') {
                    searchValue = searchValue * 10 + (event.text.unicode - '0');
                    std::stringstream ss;
                    ss << searchValue;
                    promptText.setString("Ingrese el numero a buscar: " + ss.str());
                    window.clear(sf::Color::Black);
                    window.draw(promptText);
                    window.display();
                } else if (event.text.unicode == 13) { // Enter
                    waitingForSearch = false;
                }
            }
        }
    }

    // Búsqueda binaria
    int left = 0, right = size - 1;
    int mid;
    bool found = false;
    while (left <= right) {
        mid = left + (right - left) / 2;

        // Resaltar los límites y el valor medio
        window.clear(sf::Color::Black);

        // Resaltar el rango actual
        sf::RectangleShape rangeLeft(sf::Vector2f(50.f, 50.f));
        rangeLeft.setPosition(100.f + (left * 60), 300.f);
        rangeLeft.setFillColor(sf::Color(255, 165, 0)); // Naranja
        window.draw(rangeLeft);

        sf::RectangleShape rangeRight(sf::Vector2f(50.f, 50.f));
        rangeRight.setPosition(100.f + (right * 60), 300.f);
        rangeRight.setFillColor(sf::Color(255, 165, 0)); // Naranja
        window.draw(rangeRight);

        // Resaltar el valor medio
        sf::RectangleShape midRect(sf::Vector2f(50.f, 50.f));
        midRect.setPosition(100.f + (mid * 60), 300.f);
        midRect.setFillColor(sf::Color::Red);
        window.draw(midRect);

        // Mostrar el arreglo y los valores
        for (int i = 0; i < size; ++i) {
            sf::Text numText;
            numText.setFont(font);
            numText.setCharacterSize(20);
            numText.setFillColor(sf::Color::Green);
            numText.setString(std::to_string(arr[i]));
            numText.setPosition(100.f + (i * 60), 350.f);
            window.draw(numText);
        }

        window.display();

        // Comparar el valor medio con el número a buscar
        if (arr[mid] == searchValue) {
            found = true;
            break;
        } else if (arr[mid] < searchValue) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }

        // Esperar un poco para la animación
        sf::sleep(sf::seconds(0.5f));
    }

    // Mostrar el resultado de la búsqueda
    window.clear(sf::Color::Black);
    if (found) {
        resultText.setString("Numero encontrado en el indice: " + std::to_string(mid));
    } else {
        resultText.setString("Numero no encontrado");
    }
    resultText.setFont(font);
    resultText.setCharacterSize(20);
    resultText.setFillColor(sf::Color::Green);
    resultText.setPosition(100.f, 250.f);

    window.clear(sf::Color::Black);
    window.draw(resultText);
    window.display();

    // Esperar unos segundos para que el usuario vea el resultado
    sf::sleep(sf::seconds(3));
}
