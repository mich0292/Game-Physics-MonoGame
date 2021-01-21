#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

class Planet
{
    private:
    sf::CircleShape planet;
    b2Body* body;
    b2BodyDef bodyDef;
    b2CircleShape shape;
    b2FixtureDef fixture;
	float gravitationalForce;

    public:
    void settingUpPlanet(b2World& world, float radius, sf::Vector2f position, sf::Color fillColor, sf::Color outlineColor, float thickness);
	void exertGravity(b2Body*);
    void update();
    void setTexture(sf::Texture* texture);
    b2Body* getBody();
    sf::Shape& getShape();
};