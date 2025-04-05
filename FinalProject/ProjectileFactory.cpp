//#include <map>
//#include "Projectile.h"
//#include "ProjectileFactory.h"
//#include "GameConfig.h"
//
//std::map<ProjectileType, ProjectileConfig> g_projectileConfigs;
//
//void initProjectileConfigs(sf::Texture& fire, sf::Texture& boss, sf::Texture& bomb)
//{
//    g_projectileConfigs.clear();
//
//    g_projectileConfigs[ProjectileType::CupHeadSimpleShot] = ProjectileConfig{ 1.f, &fire, {80, 82}, 8, 0.6f };
//    g_projectileConfigs[ProjectileType::BossSimpleShot] = ProjectileConfig{ 1.f, &boss, {80, 80}, 9, 1.f };
//    g_projectileConfigs[ProjectileType::IceCreamBomb] = ProjectileConfig{ 0.5f, &bomb, {89, 136}, 10, 0.5f };
//}
//
//
//Projectile* createProjectile(sf::RenderWindow* window,
//    ProjectileType type,
//    const sf::Vector2f& position,
//    float speedX,
//    float speedY)
//{
//    const auto& config = g_projectileConfigs.at(type);
//
//    return new Projectile(
//        window,
//        config,    
//        position,
//        speedX,
//        speedY
//    );
//}
