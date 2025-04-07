#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "GameObj.h"
#include "Animation.h"

enum class BossOrientation
{
	Left,
	Right,
};

enum class BossPhase 
{			 //HP:
	Phase_1, //150-100
	Phase_2, //150-100
	Phase_3, //100-0
};

class Boss : public GameObject
{
public:
	Boss(sf::RenderWindow* window);

	void update(float dt) override;
	void draw() override;
	void onCollision(GameObject* colidable) override;
	void updateStage();

	sf::Vector2f getPosition() override{ return m_position = m_sprite.getPosition(); }
	const float getSpriteWidth() override  { return m_sprite.getGlobalBounds().size.x; }
	const float getSpriteHeight() override { return m_sprite.getGlobalBounds().size.y; }
	Type getType() override { return Type::Boss; }
	bool isEntityAlive() override;
	int getHealthPoints() override { return m_hp; }

	sf::FloatRect getBoundingBox() { return m_sprite.getGlobalBounds(); }
	const BossOrientation& getBossOrientation() { return m_orientation; }
	
	BossPhase getBossPhase() { return m_bossPhase; }
private:
	void chooseAnimation(float dt);
	void giveDamage();
	void handleBossOrientation();
	void move(float dt); 

private:
	sf::Clock m_damageCooldown;
	float m_invincibilityDuration = 0.1f;
	BossPhase m_bossPhase = BossPhase::Phase_1;

	sf::Texture m_texture;
	sf::Sprite m_sprite;
	Animation m_defaultAnimation;

	sf::Texture m_finalStageTexture;
	Animation m_finalStageAnimation;
	sf::Texture m_deathTexture;
	Animation m_deathAnimation;

	int m_hp = 20;

	sf::Vector2f m_position;
	
	bool m_reverse = false;

	BossOrientation m_newOrientationRequest;
	BossOrientation m_orientation;

	std::vector<sf::Vector2f >m_waypoints;
	int m_currentWaypoint = 0;
};