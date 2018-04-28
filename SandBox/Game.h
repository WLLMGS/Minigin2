#pragma once
#include "MiniginGame.h"

class Game : public MiniginGame
{
public:
	Game();
	~Game();
	virtual void LoadGameData() override;
	virtual void Update(float elapsedSec) override;

};

