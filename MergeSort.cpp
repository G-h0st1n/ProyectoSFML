#include "MergeSort.h"
#include <vector>
#include <sstream>

// Función para realizar la fusión de dos subarreglos ordenados
void merge(std::vector<int>& arr, int left, int mid, int right, sf::RenderWindow &window, sf::Font &font) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> leftArr(n1), rightArr(n2);

    // Copiar datos a los subarreglos temporalmente
    for (int i = 0; i < n1; ++i)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; ++i)
        rightArr[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        // Resaltar los elementos comparados
        window.clear(sf::Color::Black);
        for (int m = 0; m < arr.size(); ++m) {
            sf::RectangleShape rect(sf::Vector2f(50.f, 50.f));
            rect.setPosition(100.f + (m * 60), 300.f);
            if (m == left + i || m == mid + 1 + j) {
                rect.setFillColor(sf::Color::Red); // Resaltar los elementos comparados
            } else {
                rect.setFillColor(sf::Color::Green);
            }
            window.draw(rect);
            sf::Text numText(std::to_string(arr[m]), font, 20);
            numText.setPosition(100.f + (m * 60), 350.f);
            window.draw(numText);
        }

        window.display();
        sf::sleep(sf::seconds(0.5f));

        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            ++i;
        } else {
            arr[k] = rightArr[j];
            ++j;
        }
        ++k;
    }

    // Copiar los elementos restantes
    while (i < n1) {
        arr[k] = leftArr[i];
        ++i;
        ++k;
    }
    while (j < n2) {
        arr[k] = rightArr[j];
        ++j;
        ++k;
    }

    // Mostrar el arreglo después de la fusión
    window.clear(sf::Color::Black);
    for (int m = 0; m < arr.size(); ++m) {
        sf::RectangleShape rect(sf::Vector2f(50.f, 50.f));
        rect.setPosition(100.f + (m * 60), 300.f);
        rect.setFillColor(sf::Color::Green);
        window.draw(rect);
        sf::Text numText(std::to_string(arr[m]), font, 20);
        numText.setPosition(100.f + (m * 60), 350.f);
        window.draw(numText);
    }

    window.display();
    sf::sleep(sf::seconds(0.5f));
}

// Función recursiva de Merge Sort
void mergeSortRecursive(std::vector<int>& arr, int left, int right, sf::RenderWindow &window, sf::Font &font) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Dividir el arreglo en dos mitades
        mergeSortRecursive(arr, left, mid, window, font);
        mergeSortRecursive(arr, mid + 1, right, window, font);

        // Combinar las dos mitades ordenadas
        merge(arr, left, mid, right, window, font);
    }
}

void mergeSort(sf::RenderWindow &window, sf::Font &font) {
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

    // Llamar a la función recursiva de Merge Sort
    mergeSortRecursive(arr, 0, size - 1, window, font);

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
