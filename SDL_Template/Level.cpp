#include "Level.h"

void Level::HandleStartLabels() {
	if (mStage > 1) {
		StartStage();
	}
	else {
			StartStage();
			mPlayer->Active(true);
			mPlayer->Visible(true);
	}
}

void Level::HandleCollisions() {
	if (!mPlayerHit) {
		if (mPlayer->WasHit()) {
			mPlayerHit = true;
			mRespawnTimer = 0.0f;
			mPlayer->Active(false);
		}
	}
}

void Level::HandlePlayerDeath() {
	if (!mPlayer->IsAnimating()) {
		if (mPlayer->Lives() > 0) {
			if (mRespawnTimer == 0.0f) {
				mPlayer->Visible(false);
			}

			mRespawnTimer += mTimer->DeltaTime();
			if (mRespawnTimer >= mRespawnDelay) {
				mPlayer->Active(true);
				mPlayer->Visible(true);
				mPlayerHit = false;
			}
		}
		else {
			if (mGameOverTimer == 0.0f) {
				mPlayer->Visible(false);
			}
			mGameOverTimer += mTimer->DeltaTime();
			if (mGameOverTimer >= mGameOverDelay) {
				mCurrentState = GameOver;
			}
		}
	}
}

void Level::StartStage() {
	mStageStarted = true;
}

Level::Level(int stage, PlaySideBar * sideBar, Player * player) {
	mTimer = Timer::Instance();
	mSideBar = sideBar;

	mStage = stage;
	mStageStarted = false;

	mPlayer = player;
	mPlayerHit = false;
	mRespawnDelay = 3.0f;
	mRespawnTimer = 0.0f;
	mRespawnLabelOnScreen = 2.0f;

	mGameOverLabel = new GLTexture("GAME OVER", "emulogic.ttf", 32, { 150, 0, 0 });
	mGameOverLabel->Parent(this);
	mGameOverLabel->Position(Graphics::SCREEN_WIDTH * 0.4f, Graphics::SCREEN_HEIGHT * 0.5f);

	mGameOverDelay = 6.0f;
	mGameOverTimer = 0.0f;
	mGameOverLabelOnScreen = 1.0f;

	mCurrentState = Running;
}

Level::~Level() {
	mTimer = nullptr;
	mSideBar = nullptr;

	mPlayer = nullptr;

	delete mGameOverLabel;
	mGameOverLabel = nullptr;
}

Level::LevelStates Level::State() {
	return mCurrentState;
}

void Level::Update() {
	if (!mStageStarted) {
		HandleStartLabels();
	}
	else {

		HandleCollisions();

		if (mPlayerHit) {
			HandlePlayerDeath();
		}
	}
}

void Level::Render() {
	if (mPlayerHit) {
		if (mGameOverTimer >= mGameOverLabelOnScreen) {
			mGameOverLabel->Render();
		}
	}
}
