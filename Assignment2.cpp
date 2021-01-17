#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <iostream>
#include <vector>

int main()
{
    //Window size
    int windowSizeX = 800;
    int windowSizeY = 600;

    //gravity
    float gravity;

    //World Simulation & Clock
    float timeStep = 1.0f/60f;
    float timeElapsedSinceLastFrame = 0;
    int32 velocityIterations = 10;
    int32 positionIterations = 8;
    sf::Clock fixedUpdateClock;
    
    //Box2D Variables
    b2World world(gravity);

    //create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Game Title here");

    while(window.isOpen())
    {
        sf::Event event;

        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        //Clock things (restart can get time.delta time and as seconds return value in seconds)
        timeElapsedSinceLastFrame += fixedUpdateClock.restart().asSeconds();

        //Update physics after reach the time step
        if(timeElapsedSinceLastFrame >= timeStep)
        {
            //this functions performs collision detection, integration and constraint solution
            world.step(timeStep, velocityIterations, positionIterations);
            
            //Update others physics here


            //reset the time
            timeElapsedSinceLastFrame -= timeStep;
        }

        //clear the screen
        window.clear(sf::Color(100, 149, 237));

        //draw here

        //Update the window
        window.display();
    }

    return 0;
}