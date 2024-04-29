#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

class Rectangulo {
public:
    Rectangulo(b2World& world);
    ~Rectangulo();
    void update();
    sf::RectangleShape& getShape(); // M�todo para obtener el objeto sf::RectangleShape
    b2ContactEdge* getContactList(); // M�todo para obtener la lista de contactos
    b2Body* getBody(); // M�todo para obtener el cuerpo de Box2D

private:
    b2Body* m_body;
    sf::RectangleShape m_shape;
};