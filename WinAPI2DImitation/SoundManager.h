#pragma once

#include "FMod/inc/fmod.hpp"
#pragma comment(lib, "FMod/lib/x64/fmod_vc.lib")

class Sound;

class SoundManager
{
	SINGLETON(SoundManager);

private:

	map<wstring, Sound*>  m_mapSound; // 사운드들을 관리 하기 위한 자료구조

	FMOD::System* m_pSystem;		  // 사운드 시스템

	
	
public:
	void init();
	void update();
	void addSound(wstring _keyName, wstring filePath, bool bgm);

	FMOD::System* getSystem();

	void play(wstring _keyName);
	void stop(wstring _keyName);
	void pause(wstring _keyName);
	void resume(wstring _keyName);

	bool isPlaySound(wstring _keyName);
	bool isPauseSound(wstring _keyName);

};

