
class GameConfig
{
public:
	//Boss
	static constexpr unsigned BossHP_Phase1 = 150;
	static constexpr unsigned BossHP_Phase2 = 100;
	static constexpr unsigned BossHP_Phase3 = 50;
	static constexpr float BossProjectileSPEED = 720.f;
	static constexpr float BossBombsSPEED = 500.f;
	//Player
	static constexpr float acceleration = 2000.f;
	static constexpr float jumpImpulse = -70000.f;
	static constexpr float PlayerProjectileSPEED = 1000.f;
};