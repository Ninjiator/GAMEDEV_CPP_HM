#pragma once
#include <SFML/Graphics.hpp>

enum class EffectType
{
    //Gameplay effect's
    HitSpark,
    IceCreamExplosion,
    //Side effect's
    READY,
    DEAD,
    VICTORY
};

class IEffectSpawner
{
public:
    virtual ~IEffectSpawner() = default;

    virtual void spawnEffect(sf::Vector2f position, EffectType type) = 0;
};