#include <SFML/Config.hpp>
#include "Game.h"
#include <Box2D/Box2D.h>

// SFML
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Event.hpp>


Game::Game() : m_window{ sf::RenderWindow(sf::VideoMode(800, 600), "SFML + Box2D") }, m_world(b2Vec2(0.0f, 9.8f)), m_rectangulo(m_world) {

    // Crear el piso (un cuerpo estático)
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(400.0f, 550.0f); // Posición del centro del piso
    m_groundBody = m_world.CreateBody(&groundBodyDef);
    b2PolygonShape groundBox;
    groundBox.SetAsBox(400.0f / 2, 10.0f / 2); // Tamaño del piso dividido por 2
    m_groundBody->CreateFixture(&groundBox, 0.0f); // Crea la forma del piso

}

Game::~Game() {
}

void Game::run() {
    while (m_window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (m_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            m_window.close();
    }
}

void Game::update() {
    m_world.Step(1 / 60.0f, 6, 2);
    m_rectangulo.update();

    // Verificar colisiones con el piso
    b2ContactEdge* edge = m_rectangulo.getContactList();
    while (edge) {
        if (edge->other == m_groundBody && edge->contact->IsTouching()) {
            // Detener el movimiento del rectángulo
            m_rectangulo.getBody()->SetLinearVelocity(b2Vec2(0.0f, 0.0f));
            break; // Salir del bucle si se detecta la colisión
        }
        edge = edge->next;
    }
}

void Game::render() {
    m_window.clear(sf::Color::White); // Limpiar la ventana con un color de fondo blanco
    // Renderizar otros elementos aquí si es necesario
    m_window.draw(m_rectangulo.getShape());
    m_window.display();
}
