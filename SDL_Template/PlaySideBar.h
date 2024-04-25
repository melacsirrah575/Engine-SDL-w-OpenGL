#ifndef __PLAYSIDEBAR_H
#define __PLAYSIDEBAR_H
#include "Timer.h"
#include "Scoreboard.h"
#include "AudioManager.h"

class PlaySideBar : public GameEntity {
private:
	Timer * mTimer;
	AudioManager * mAudio;

	Texture * mBackground;

	Texture * mTitle;

private:

public:
	PlaySideBar();
	~PlaySideBar();

	void Update() override;
	void Render() override;
};
#endif