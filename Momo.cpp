#include "Momo.hpp"

Momo::Momo()
{
    // Texture
    if (!texture.loadFromFile("assets/momo.png"))
        std::cout << "Errore caricamento texture!" << std::endl;
    
    texture.setSmooth(true);

    // Sprite
    sprite.setTexture(texture);

    // Origine delle trasformazioni al centro dello sprite
    sf::FloatRect spriteRect = sprite.getLocalBounds();
    sprite.setOrigin(spriteRect.width / 2, spriteRect.height / 2);

    // Dimensioni sprite
    sprite.scale(1.4f, 1.4f);
}

// Getter
sf::Sprite& Momo::getSprite()
{
    return sprite;
}

sf::Texture Momo::getTexture()
{
    return texture;
}

float Momo::getSpeed()
{
    return speed;
}

// Setter
void Momo::setSprite(sf::Sprite s)
{
    sprite = s;
}

void Momo::setTexture(sf::Texture t)
{
    texture = t;
}

void Momo::spawn(sf::Vector2u windowSize)
{
    sf::Vector2f spawnPoint = static_cast<sf::Vector2f>(windowSize) / 2.f;
    sprite.setPosition(spawnPoint);
}

void Momo::move(float xMove, float yMove)
{
    sprite.move(xMove, yMove);
}

void Momo::rotate(char direction)
{
    if (direction == 'd')
        sprite.rotate(rotateAngle);
    else if (direction == 'a')
        sprite.rotate(-rotateAngle);
}

sf::FloatRect Momo::getHitbox()
{
    return sprite.getGlobalBounds();
}

sf::RectangleShape Momo::drawHitbox()
{
    sf::FloatRect hitbox = sprite.getLocalBounds();
    sf::RectangleShape rectangle(sf::Vector2f(hitbox.width, hitbox.height));
    rectangle.setOrigin(sprite.getOrigin());
    rectangle.setPosition(sprite.getPosition());
    rectangle.setRotation(sprite.getRotation());
    rectangle.setScale(sprite.getScale());
    rectangle.setFillColor(sf::Color::Transparent); // Rettangolo senza riempimento
    rectangle.setOutlineColor(sf::Color::Green); // Colore del bordo
    rectangle.setOutlineThickness(2.0f);

    return rectangle;
}

void Momo::gravity()
{
    sprite.move(0, 0.055);
}
