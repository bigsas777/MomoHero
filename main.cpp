#include <SFML/Graphics.hpp>
#include "Momo.hpp"
#include "Ground.hpp"

int main()
{
    // Costanti
    const float gravity = 0.07;

    // Finestra del programma
    sf::RenderWindow window(sf::VideoMode(1000, 910), "MomoHero");

    // Istanza sprite
    Ground ground(window.getSize());
    Momo momo;

    // Bordi rigidi
    sf::FloatRect borders(0.f, 0.f, static_cast<float>(window.getSize().x), static_cast<float>(window.getSize().y));

    // Genero lo sprite al centro dello schermo
    momo.spawn(window.getSize());

    while (window.isOpen())
    {
        // Aggiunta forza di gravità, applicata solo a momo
        momo.move(0, gravity);

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) // SFML ha l'asse Y invertito
        {
            float radiansAngle = momo.getSprite().getRotation() * M_PI / 180.f; // Converto l'angolo di rotazione in rad
            float xMov = momo.getSpeed() * std::sin(radiansAngle); // Calcolo la componente X del vettore direzione-movimento
            float yMov = -momo.getSpeed() * std::cos(radiansAngle); // Calcolo la componente Y del vett direzione-movimento
            momo.move(xMov, yMov);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            momo.rotate('a');
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            momo.rotate('d');
        }

        // Momo non trapassa il terreno
        if (ground.getHitbox().intersects(momo.getHitbox()))
        {
            momo.move(0, -(gravity + momo.getSpeed()));
        }

        // Bordi rigidi
        if (momo.getHitbox().left < borders.left)
        {
            momo.getSprite().setPosition(borders.left, momo.getSprite().getPosition().y);
        }

        /*if (player.getPosition().x < windowBounds.left)
            player.setPosition(windowBounds.left, player.getPosition().y);
        if (player.getPosition().x + player.getSize().x > windowBounds.left + windowBounds.width)
            player.setPosition(windowBounds.left + windowBounds.width - player.getSize().x, player.getPosition().y);
        if (player.getPosition().y < windowBounds.top)
            player.setPosition(player.getPosition().x, windowBounds.top);
        if (player.getPosition().y + player.getSize().y > windowBounds.top + windowBounds.height)
            player.setPosition(player.getPosition().x, windowBounds.top + windowBounds.height - player.getSize().y);*/

        // sf::RectangleShape momoHitbox = momo.drawHitbox();
        // sf::RectangleShape groundHitbox = ground.drawHitbox();

        window.clear(sf::Color(83, 111, 166, 1)); // Sfondo
        window.draw(ground.getSprite());
        window.draw(momo.getSprite());
        // window.draw(momoHitbox);
        // window.draw(groundHitbox);
        window.display();
    }

    return 0;
}
