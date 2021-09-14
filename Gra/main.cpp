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
        for (int i = 0; i < 500; i++) {


            if (rectangle_bounds.intersects(podloga))
            {
                this->move(0, 0.2);
            }
            else
            {
                this->move(0, -0.2);
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

class pocisk : public sf::CircleShape {
public:
    pocisk(float radius, sf::Vector2f position)
        : sf::CircleShape(radius) { this->setPosition(position); }

    void poruszanie()
    {
        this->move(0.5, 0);
        this->setFillColor(sf::Color(255,0,0));
    
    }
    void kolizja(sf::FloatRect p1, sf::FloatRect p2, sf::FloatRect p3)
    {
        if (this->getGlobalBounds().intersects(p1))
        {
            
        }
        if (this->getGlobalBounds().intersects(p2))
        {
            
        }
        if (this->getGlobalBounds().intersects(p3))
        {
           
        }

    }


private:

};


int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 1000), "My window");
    sf::Clock clock;
    sf::Vector2f size(98.0, 124.0);
    sf::Vector2f position(20.0, 800.0);
    bohater bohater(size, position);
    sf::Vector2f sizep(98.0, 124.0);
    sf::Vector2f positionp1(1100, 800);
    sf::Vector2f positionp2(700, 800);
    sf::Vector2f positionp3(600, 350);


    przeciwnik przeciwnik1(sizep, positionp1);
    przeciwnik przeciwnik2(sizep, positionp2);
    przeciwnik przeciwnik3(sizep, positionp3);


    sf::Texture teksturabohatera;
    teksturabohatera.loadFromFile("CT.jpg");
    teksturabohatera.setSmooth(true);
    bohater.setTexture(&teksturabohatera);

    sf::Vector2f positionpoc(1100, 1100);
    
    pocisk P1(5, positionpoc);
    std::vector<pocisk> pociski;
    sf::Vector2f bohatercentrum;
    pociski.push_back(pocisk(P1));
     


    sf::Texture teksturaprzeciwnika;
    teksturaprzeciwnika.loadFromFile("TT.jpg");
    teksturaprzeciwnika.setSmooth(true);
    przeciwnik1.setTexture(&teksturaprzeciwnika);
    przeciwnik2.setTexture(&teksturaprzeciwnika);
    przeciwnik3.setTexture(&teksturaprzeciwnika);



    sf::Vector2f size_floor(1200, 60);
    sf::Vector2f position_floor(0, 940);
    sf::Vector2f size_floor2(400, 60);
    sf::Vector2f position_floor2(500, 500);
    sf::Texture podloga;
    podloga.loadFromFile("floor.png");


    std::vector<floorr> podlogi;
    podlogi.emplace_back(floorr(size_floor, position_floor));
    podlogi.emplace_back(floorr(size_floor2, position_floor2));

    bool p1z = true;
    bool p2z = true;
    bool p3z = true;


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

            if (event.key.code == sf::Keyboard::Z) {

                P1.setPosition(bohatercentrum);

                pociski.push_back(pocisk(P1));
                
            }


          
        }


        window.clear(sf::Color::Black);

        sf::Time elapsed = clock.restart();


        sf::FloatRect rectangle_bounds = bohater.getGlobalBounds();
        sf::FloatRect przeciwnik1bounds = przeciwnik1.getGlobalBounds();
        sf::FloatRect przeciwnik2bounds = przeciwnik2.getGlobalBounds();
        sf::FloatRect przeciwnik3bounds = przeciwnik3.getGlobalBounds();
        
        bohatercentrum = sf::Vector2f(bohater.getPosition().x+65, bohater.getPosition().y+70);


   

        window.draw(bohater);
        window.draw(przeciwnik1);
        window.draw(przeciwnik2);
        window.draw(przeciwnik3);

        for (size_t i = 0; i < pociski.size(); i++)
        {
            window.draw(pociski[i]);
        }


        bohater.poruszanie();

        for (size_t i = 0; i < pociski.size(); i++)
        {
            pociski[i].poruszanie();
            pociski[i].kolizja(przeciwnik1bounds, przeciwnik2bounds, przeciwnik3bounds);
        }
        for (size_t i = 0; i < pociski.size(); i++)
        {
            sf::FloatRect pociskb = pociski[i].getGlobalBounds();
            if (pociskb.intersects(przeciwnik1bounds))
            {
                
                p1z = false;
                
            }
            if (pociskb.intersects(przeciwnik2bounds))
            {

                p2z = false;

            }
            if (pociskb.intersects(przeciwnik3bounds))
            {

                p3z = false;
            }
        }
        

        for (const auto& pod : podlogi) {
            window.draw(pod);
        }



        bohater.grawitacja(rectangle_bounds2, rectangle_bounds3);
        przeciwnik1.grawitacja(rectangle_bounds2, rectangle_bounds3);
        przeciwnik2.grawitacja(rectangle_bounds2, rectangle_bounds3);
        przeciwnik3.grawitacja(rectangle_bounds2, rectangle_bounds3);



        window.display();
        if ((p1z == false) && (p2z == false) && (p3z == false))
        {
            window.close();
        }
    }

   
        

        




    return 0;
}