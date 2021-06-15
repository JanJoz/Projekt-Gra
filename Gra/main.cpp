#include"Precompiled.h"

class bohater : public sf::RectangleShape {
public:
    bohater(sf::Vector2f size, sf::Vector2f position)
        : sf::RectangleShape(size) { this->setPosition(position); }

    void poruszanie()
    {
            sf::FloatRect rectangle_bounds = this->getGlobalBounds();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && windup < rectangle_bounds.top) {
                this->move(0, -0.1);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && winddown > rectangle_bounds.top + rectangle_bounds.height) {
                this->move(0, 0.1);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && windleft < rectangle_bounds.left) {
                this->move(-0.1, 0);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ) {
                this->move(0.1, 0);
            }
        


    }
    void setBounds(sf::IntRect bohater)
    {
        winddown = bohater.top + bohater.height;
        windup = bohater.top;
        windleft = bohater.left;
        windright = bohater.left + bohater.width;
    }
    void grawitacja(sf::IntRect bohater)
    {

    }
    void bounce()
    {
        sf::FloatRect rectangle_bounds = this->getGlobalBounds();
        if (rectangle_bounds.left <= windleft)
        {
            a_x = 1;
        }
        if (rectangle_bounds.top + rectangle_bounds.height >= winddown)
        {
            a_y = -1;
        }
        if (rectangle_bounds.left + rectangle_bounds.width >= windright)
        {
            a_x = -1;
        }
        if (rectangle_bounds.top <= windup)
        {
            a_y = 1;
        }
    }

private:
    int speed_x = 0;
    int speed_y = 0;
    int speed_z = 0;
    int winddown = 0;
    int windup = 0;
    int windleft = 0;
    int windright = 0;
    int a_x = 0;
    int a_y = 0;
    bool is_selected = false;



};

class floorr : public sf::RectangleShape {
public:
    floorr(sf::Vector2f size, sf::Vector2f position)
        : sf::RectangleShape(size) { this->setPosition(position); }
 
    void setBounds(sf::IntRect floor)
    {
        winddown = floor.top + floor.height;
        windup = floor.top;
        windleft = floor.left;
        windright = floor.left + floor.width;
    }
    

private:
    int winddown = 0;
    int windup = 0;
    int windleft = 0;
    int windright = 0;

};


int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 1000), "My window");
    sf::Clock clock;
    sf::Vector2f size(98.0, 124.0);
    sf::Vector2f position(20.0, 800.0);
    bohater bohater(size, position);

    sf::Texture teksturabohatera;
    teksturabohatera.loadFromFile("CT.jpg");
    teksturabohatera.setSmooth(true);
    bohater.setTexture(&teksturabohatera);
    

    sf::Vector2f size_floor(1200, 60);
    sf::Vector2f position_floor(0, 940);
    floorr floorr(size_floor, position_floor);

    sf::Texture podloga;
    podloga.loadFromFile("floor.png");
    floorr.setTexture(&podloga);


    

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed)
                window.close();



          
        }


        window.clear(sf::Color::Black);

        sf::Time elapsed = clock.restart();


        sf::FloatRect rectangle_bounds = bohater.getGlobalBounds();
        window.draw(bohater);
        window.draw(floorr);
        bohater.poruszanie();

        window.display();

    }

    return 0;
}