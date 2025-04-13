#pragma once
#include <SFML/Graphics.hpp>

enum class EffectType
{
    //Gameplay effect's
    PlayerHitSparkEffect,
    BossIceCreamEffect,
    BossIceCubsEffect,
    //Side effect's
    READY,
    VICTORY
};

class IEffectSpawner
{
public:
    virtual ~IEffectSpawner() = default;

    virtual void spawnEffect(sf::Vector2f position, EffectType type) = 0;
};