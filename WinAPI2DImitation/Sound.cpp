#include "framework.h"
#include "Sound.h"

Sound::Sound()
{
	m_pChannel = nullptr;
	m_pSound = nullptr;
	m_bLoop = true;
}

Sound::~Sound()
{
	stop();
	if (nullptr != m_pChannel)
		delete m_pChannel;

	if (nullptr != m_pSound)
	{
		m_pSound->release();
		delete m_pSound;
	}
}

void Sound::play()
{
	SoundManager::getInst()->getSystem()->playSound(m_pSound, 0, false, &m_pChannel);
	assert(m_pChannel);
}

void Sound::stop()
{


	if (nullptr != m_pChannel)
		m_pChannel->stop();

}

void Sound::pause()
{
	if (nullptr != m_pChannel)
		m_pChannel->setPaused(true);
}

void Sound::resume()
{
	if (nullptr != m_pChannel)
		m_pChannel->stop();
}

void Sound::load(const wstring& _strFilePath)
{
	char str[255];

	wcstombs_s(nullptr, str, _strFilePath.c_str(), 255);

	SoundManager::getInst()->getSystem()->createSound(str, FMOD_DEFAULT, nullptr, &m_pSound);


}

bool Sound::isPlay()
{
	bool playing = false;
	if (nullptr != m_pChannel)
		m_pChannel->isPlaying(&playing);

	return playing;
}

bool Sound::isPause()
{
	bool paused = false;
	if (nullptr != m_pChannel)
		m_pChannel->isPlaying(&paused);

	return paused;
}

void Sound::setLoop(bool loop)
{
	if (loop)
	{
		m_pSound->setMode(FMOD_DEFAULT);
	}
	else
	{
		m_pSound->setMode(FMOD_LOOP_OFF);
	}
}