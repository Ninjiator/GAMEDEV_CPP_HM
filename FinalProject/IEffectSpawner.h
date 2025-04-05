#pragma once
#include <SFML/Graphics.hpp>

enum class EffectType
{
    HitSpark,
    IceCreamExplosion

};

class IEffectSpawner
{
public:
    virtual ~IEffectSpawner() = default;

    virtual void spawnEffect(sf::Vector2f position, EffectType type) = 0;
};