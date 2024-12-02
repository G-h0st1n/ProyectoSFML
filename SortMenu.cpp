#include "SortMenu.h"
#include "BubbleSort.h"  // Incluir los archivos correspondientes de los algoritmos
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"

void sortMenu(sf::RenderWindow &window, sf::Font &font) {
    // Crear los textos para el menú
    sf::Text bubbleSortText, selectionSortText, insertionSortText, mergeSortText, quickSortText, backText;
    bubbleSortText.setFont(font);
    bubbleSortText.setCharacterSize(20);
    bubbleSortText.setFillColor(sf::Color::Green);

    selectionSortText.setFont(font);
    selectionSortText.setCharacterSize(20);
    selectionSortText.setFillColor(sf::Color::Green);

    insertionSortText.setFont(font);
    insertionSortText.setCharacterSize(20);
    insertionSortText.setFillColor(sf::Color::Green);

    mergeSortText.setFont(font);
    mergeSortText.setCharacterSize(20);
    mergeSortText.setFillColor(sf::Color::Green);

    quickSortText.setFont(font);
    quickSortText.setCharacterSize(20);
    quickSortText.setFillColor(sf::Color::Green);

    backText.setFont(font);
    backText.setCharacterSize(20);
    backText.setFillColor(sf::Color::Green);

    // Definir las opciones del menú
    bubbleSortText.setString("1. Bubble Sort");
    bubbleSortText.setPosition(100.f, 100.f);

    selectionSortText.setString("2. Selection Sort");
    selectionSortText.setPosition(100.f, 150.f);

    insertionSortText.setString("3. Insertion Sort");
    insertionSortText.setPosition(100.f, 200.f);

    mergeSortText.setString("4. Merge Sort");
    mergeSortText.setPosition(100.f, 250.f);

    quickSortText.setString("5. Quick Sort");
    quickSortText.setPosition(100.f, 300.f);

    backText.setString("6. Regresar");
    backText.setPosition(100.f, 350.f);

    // Mostrar el menú y esperar la selección
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                // Verificar si se hizo clic en una de las opciones
                if (bubbleSortText.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                    // Llamar a BubbleSort
                    bubbleSort(window, font);
                }
                else if (selectionSortText.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                    // Llamar a SelectionSort
                    selectionSort(window, font);
                }
                else if (insertionSortText.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                    // Llamar a InsertionSort
                    insertionSort(window, font);
                }
                else if (mergeSortText.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                    // Llamar a MergeSort
                    mergeSort(window, font);
                }
                else if (quickSortText.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                    // Llamar a QuickSort
                    quickSort(window, font);
                }
                else if (backText.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                    // Regresar al menú principal
                    return;
                }
            }
        }

        // Verificar si el ratón está sobre alguna opción para cambiar el color
        if (bubbleSortText.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
            bubbleSortText.setFillColor(sf::Color::Red);
        } else {
            bubbleSortText.setFillColor(sf::Color::Green);
        }

        if (selectionSortText.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
            selectionSortText.setFillColor(sf::Color::Red);
        } else {
            selectionSortText.setFillColor(sf::Color::Green);
        }

        if (insertionSortText.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
            insertionSortText.setFillColor(sf::Color::Red);
        } else {
            insertionSortText.setFillColor(sf::Color::Green);
        }

        if (mergeSortText.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
            mergeSortText.setFillColor(sf::Color::Red);
        } else {
            mergeSortText.setFillColor(sf::Color::Green);
        }

        if (quickSortText.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
            quickSortText.setFillColor(sf::Color::Red);
        } else {
            quickSortText.setFillColor(sf::Color::Green);
        }

        if (backText.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
            backText.setFillColor(sf::Color::Red);
        } else {
            backText.setFillColor(sf::Color::Green);
        }

        // Dibujar las opciones del menú
        window.clear(sf::Color::Black);
        window.draw(bubbleSortText);
        window.draw(selectionSortText);
        window.draw(insertionSortText);
        window.draw(mergeSortText);
        window.draw(quickSortText);
        window.draw(backText);
        window.display();
    }
}
