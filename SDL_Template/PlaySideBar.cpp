#include "PlaySideBar.h"


PlaySideBar::PlaySideBar() {
	mTimer = Timer::Instance();
	mAudio = AudioManager::Instance();

	mBackground = new GLTexture("Black.png");
	mBackground->Parent(this);
	mBackground->Scale(Vector2(3.0f, 10.0f));
	mBackground->Position(45.0f, 380.0f);

	mTitle = new GLTexture("PSB Title", "emulogic.ttf", 32, { 255, 255, 255 });
	mTitle->Parent(this);
	mTitle->Position(-25.0f , 0.0f);

}

PlaySideBar::~PlaySideBar() {
	mTimer = nullptr;
	mAudio = nullptr;

	delete mBackground;
	mBackground = nullptr;

	delete mTitle;
	mTitle = nullptr;
}

void PlaySideBar::Update() {

}

void PlaySideBar::Render() {
	mBackground->Render();
	mTitle->Render();
}