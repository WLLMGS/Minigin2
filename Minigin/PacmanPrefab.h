#pragma once
#include "GameObject.h"
#include "GameActor.h"

class PacmanPrefab : public GameActor
{
public:
	PacmanPrefab();
	~PacmanPrefab() = default;
	virtual void Update(float elapsedSec) override;
private:
	const float m_Speed = 100.0f;
};

