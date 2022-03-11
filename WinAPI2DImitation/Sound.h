#pragma once

#include "FMod/inc/fmod.hpp"
#pragma comment(lib, "FMod/lib/x64/fmod_vc.lib")
#include "Resource.h"




class Sound : public Resource
{

private:
	
	FMOD::Sound* m_pSound;		// À½¾Ç
	FMOD::Channel* m_pChannel;	// À½¾Ç Ã¤³Î

	bool m_bLoop;


public:

	Sound();
	~Sound();

	void play();
	void stop();
	void pause();
	void resume();

	void load(const wstring& _strFilePath);


	bool isPlay();
	bool isPause();
	void setLoop(bool loop);
};

