#include "Rectangulo.h"

Rectangulo::Rectangulo(b2World& world) {
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(400.0f, 100.0f);
    m_body = world.CreateBody(&bodyDef);

    b2PolygonShape boxShape;
    boxShape.SetAsBox(50.0f, 50.0f);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &boxShape;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;

    m_body->CreateFixture(&fixtureDef);

    m_shape.setSize(sf::Vector2f(100.0f, 100.0f));
    m_shape.setFillColor(sf::Color::Red);
}

Rectangulo::~Rectangulo() {
}

void Rectangulo::update() {
    b2Vec2 position = m_body->GetPosition();
    // Ajusta la posición para que el rectángulo de SFML se dibuje desde su esquina superior izquierda
    m_shape.setPosition(position.x - m_shape.getSize().x / 2, position.y - m_shape.getSize().y / 2);
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
