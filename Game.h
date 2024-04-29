#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "Rectangulo.h"

class Game {
public:
    Game();
    ~Game();
    void run();

private:
    void processEvents();
    void update();
    void render();

    sf::RenderWindow m_window;
    b2World m_world;
    Rectangulo m_rectangulo;
    b2Body* m_groundBody;
};