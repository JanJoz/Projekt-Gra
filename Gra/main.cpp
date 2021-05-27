#include"Precompiled.h"


int main() {
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");




    while (window.isOpen()) {



        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);



        // end the current frame
        window.display();

    }

    return 0;
}