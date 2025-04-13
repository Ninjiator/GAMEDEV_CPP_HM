
class GameConfig
{
public:
	//Boss start HP 200
	static constexpr unsigned BossHPThreshold_1 = 90;
	static constexpr unsigned BossHPThreshold_2 = 50;
	static constexpr unsigned BossHPThreshold_3 = 30;
	static constexpr float BossProjectileSPEED = 720.f;
	static constexpr float BossBombsSPEED = 500.f;
	//Player
	static constexpr float acceleration = 2000.f;
	static constexpr float jumpImpulse = -70000.f;
	static constexpr float PlayerProjectileSPEED = 1000.f;
};