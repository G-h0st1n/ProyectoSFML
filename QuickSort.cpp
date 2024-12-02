#include "QuickSort.h"
#include <vector>
#include <sstream>

// Función para particionar el arreglo
int partition(std::vector<int>& arr, int low, int high, sf::RenderWindow &window, sf::Font &font) {
    int pivot = arr[high];
    int i = low - 1;

    // Visualizar el proceso de partición
    window.clear(sf::Color::Black);
    for (int j = low; j < high; ++j) {
        sf::RectangleShape rect(sf::Vector2f(50.f, 50.f));
        rect.setPosition(100.f + (j * 60), 300.f);
        if (arr[j] == pivot) {
            rect.setFillColor(sf::Color::Blue); // Resaltar pivote
        } else if (j <= i) {
            rect.setFillColor(sf::Color::Red); // Resaltar elementos menores que el pivote
        } else {
            rect.setFillColor(sf::Color::Green);
        }
        window.draw(rect);
        sf::Text numText(std::to_string(arr[j]), font, 20);
        numText.setPosition(100.f + (j * 60), 350.f);
        window.draw(numText);
    }

    // Dibujar pivote
    sf::RectangleShape pivotRect(sf::Vector2f(50.f, 50.f));
    pivotRect.setPosition(100.f + (high * 60), 300.f);
    pivotRect.setFillColor(sf::Color::Yellow); // Resaltar pivote en amarillo
    window.draw(pivotRect);
    window.display();
    sf::sleep(sf::seconds(0.5f));

    // Realizar partición
    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Función recursiva de Quick Sort
void quickSortRecursive(std::vector<int>& arr, int low, int high, sf::RenderWindow &window, sf::Font &font) {
    if (low < high) {
        int pi = partition(arr, low, high, window, font); // Particionar el arreglo
        quickSortRecursive(arr, low, pi - 1, window, font); // Ordenar la parte izquierda
        quickSortRecursive(arr, pi + 1, high, window, font); // Ordenar la parte derecha
    }
}

void quickSort(sf::RenderWindow &window, sf::Font &font) {
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

    // Llamar a la función recursiva de Quick Sort
    quickSortRecursive(arr, 0, size - 1, window, font);

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
