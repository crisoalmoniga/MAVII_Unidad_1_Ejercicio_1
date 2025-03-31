#include "Rectangulo.h"

Rectangulo::Rectangulo(b2World& world) {
    // Definir el cuerpo dinámico de Box2D
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(400.0f, 100.0f);  // Posición inicial
    m_body = world.CreateBody(&bodyDef);

    // Definir la forma (un cuadrado de 100x100 píxeles, 50x50 Box2D unidades)
    b2PolygonShape boxShape;
    boxShape.SetAsBox(50.0f, 50.0f);  // Mitad del tamaño total

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &boxShape;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;

    m_body->CreateFixture(&fixtureDef);

    // Configurar la forma visual de SFML
    m_shape.setSize(sf::Vector2f(100.0f, 100.0f));  // Tamaño visual
    m_shape.setFillColor(sf::Color::Red);
    m_shape.setOrigin(sf::Vector2f(m_shape.getSize().x / 2, m_shape.getSize().y / 2));

}

Rectangulo::~Rectangulo() {
    // Si querés liberar recursos, podés hacerlo acá.
}

void Rectangulo::update() {
    b2Vec2 position = m_body->GetPosition();
    m_shape.setPosition(sf::Vector2f(position.x, position.y));  // Posición del centro
}

sf::RectangleShape& Rectangulo::getShape() {
    return m_shape;
}

b2ContactEdge* Rectangulo::getContactList() {
    return m_body->GetContactList();
}

b2Body* Rectangulo::getBody() {
    return m_body;
}