#include"Precompiled.h"

class bohater : public sf::RectangleShape {
public:
    bohater(sf::Vector2f size, sf::Vector2f position)
        : sf::RectangleShape(size) { this->setPosition(position); }

    void poruszanie()
    {
            sf::FloatRect rectangle_bounds = this->getGlobalBounds();
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
    void grawitacja(sf::FloatRect podloga, sf::FloatRect podloga2)
    {
        if ((this->getGlobalBounds().intersects(podloga) || (this->getGlobalBounds().intersects(podloga2))))
        {

        }
        else
        {
            this->move(0, 0.2);
        }
        

    }
    void skakansko(sf::FloatRect podloga)
    {
        sf::FloatRect rectangle_bounds = this->getGlobalBounds();
        for (int i = 0; i < 500;i++) {


            if (rectangle_bounds.intersects(podloga))
            {
                this->move(0, 0.4);
            }
            else
            {
                this->move(0, -0.4);
            }
        }



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

class przeciwnik : public sf::RectangleShape {
public:
    przeciwnik(sf::Vector2f size, sf::Vector2f position)
        : sf::RectangleShape(size) { this->setPosition(position); }


    
    void setBounds(sf::IntRect bohater)
    {
        winddown = bohater.top + bohater.height;
        windup = bohater.top;
        windleft = bohater.left;
        windright = bohater.left + bohater.width;
    }
    void grawitacja(sf::FloatRect podloga, sf::FloatRect podloga2)
    {
        if ((this->getGlobalBounds().intersects(podloga) || (this->getGlobalBounds().intersects(podloga2))))
        {

        }
        else
        {
            this->move(0, 0.2);
        }

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
        void teksturowanie(sf::Texture podloga)
        {
            this->setTexture(&podloga);
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
    sf::Vector2f size_floor2(400, 60);
    sf::Vector2f position_floor2(500, 500);
    sf::Texture podloga;
    podloga.loadFromFile("floor.png");



    std::vector<floorr> podlogi;
    podlogi.emplace_back(floorr(size_floor, position_floor));
    podlogi.emplace_back(floorr(size_floor2, position_floor2));


    for (auto& pod : podlogi) {
        pod.teksturowanie(podloga);
    }
    
    sf::FloatRect rectangle_bounds2 = podlogi[0].getGlobalBounds();
    sf::FloatRect rectangle_bounds3 = podlogi[1].getGlobalBounds();


    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed)
                window.close();
            if (event.key.code== sf::Keyboard::Space) {

                bohater.skakansko(rectangle_bounds3);

            }


          
        }


        window.clear(sf::Color::Black);

        sf::Time elapsed = clock.restart();


        sf::FloatRect rectangle_bounds = bohater.getGlobalBounds();
        window.draw(bohater);
        bohater.poruszanie();


        for (const auto& pod : podlogi) {
            window.draw(pod);
        }

        
        bohater.grawitacja(rectangle_bounds2, rectangle_bounds3);



        window.display();
    }


        

        




    return 0;
}