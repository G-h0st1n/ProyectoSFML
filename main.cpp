#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

int main()
{
    // Crear ventana
    RenderWindow window(VideoMode(800, 600), "Prueba de Fuente y Menu Interactivo");

    // Cargar la fuente
    Font font;
    if (!font.loadFromFile("C:\\Users\\frpat\\Fonts\\Tr2n.ttf"))
    {
        cerr << "Error: No se pudo cargar la fuente Tr2n.ttf" << endl;
        return EXIT_FAILURE;
    }

    // Crear opciones del menú
    const int MENU_ITEMS = 3;
    Text menu[MENU_ITEMS];
    string menuStrings[MENU_ITEMS] = {"Opcion 1", "Opcion 2", "Opcion 3"};

    for (int i = 0; i < MENU_ITEMS; i++)
    {
        menu[i].setFont(font);
        menu[i].setString(menuStrings[i]);
        menu[i].setCharacterSize(36); // Tamaño del texto
        menu[i].setFillColor(Color::Green); // Color base
        menu[i].setPosition(300, 200 + i * 50); // Posición en la pantalla
    }

    // Bucle principal
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
        }

        // Detectar si el mouse está sobre una opción
        Vector2i mousePos = Mouse::getPosition(window);
        for (int i = 0; i < MENU_ITEMS; i++)
        {
            FloatRect bounds = menu[i].getGlobalBounds();
            if (bounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
            {
                menu[i].setFillColor(Color::Red); // Cambia a rojo si está sobre
            }
            else
            {
                menu[i].setFillColor(Color::Green); // Vuelve a verde si no está sobre
            }
        }

        // Renderizar
        window.clear(Color::Black); // Fondo negro
        for (int i = 0; i < MENU_ITEMS; i++)
        {
            window.draw(menu[i]);
        }
        window.display();
    }

    return EXIT_SUCCESS;
}
