#include "Player.h"
#include <SFML/Graphics.hpp>
#include "Monster.h"
//using namespace sf;

int main()
{   //Задали размер окна
    
    Player hero("astronaut.png", 0.2f, 3, 1000, 400);

    Monster aliens[100];
    for (int i = 0; i < 2; i++)
    {
        Monster alien("C:/working folder/SFML_PROJECT/ALIEN_big.png", 2.5, 1000, 400);
        aliens[i] = (alien);
   }
    
    
    Clock clock; //создаем переменную для привязки персонажа ко времени.
    float time;

    RenderWindow window(sf::VideoMode(1000, 400), "SFML works!");

    while (window.isOpen())
    {
        Event event;
        time = (float)clock.getElapsedTime().asMicroseconds(); 
        
        time /= 800;
        hero.SetTime(time);
        aliens[0].SetTime(time);
        aliens[1].SetTime(time);
        
        clock.restart();
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        hero.SavePosition();
        hero.Keyboard();
        hero.Move();
       for (int i = 0; i < 2; i++)
       {
            aliens[i].SavePosition();
            aliens[i].DistanceToHero(hero.GetPositionX());
            aliens[i].Move();
            aliens[i].Attack();
       }

        window.clear();

        hero.Draw(window);
        aliens[0].Draw(window);
        aliens[1].Draw(window);
        window.display();
    }
    
}