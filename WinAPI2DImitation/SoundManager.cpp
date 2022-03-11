#include "framework.h"
#include "SoundManager.h"
#include "Sound.h"


SoundManager::SoundManager()
{
	m_pSystem = nullptr;
}

SoundManager::~SoundManager()
{

}

void SoundManager::init()
{
	FMOD_RESULT result; // 에러 메세지 확인용 변수
	result = FMOD::System_Create(&m_pSystem);
	assert(!result);
	result = m_pSystem->init(32, FMOD_INIT_NORMAL, nullptr); //초기화
	assert(!result);
}

void SoundManager::update()
{
	//important!! update per frame
	m_pSystem->update();
}

void SoundManager::addSound(wstring _keyName, wstring filePath, bool bgm)
{
	Sound* pSound = ResourceManager::getInst()->loadSound(_keyName, filePath);


	map<wstring, Sound*>::iterator iter = m_mapSound.find(_keyName);
	pSound->setLoop(bgm);
	if(m_mapSound.end() == iter)
		m_mapSound.insert(make_pair(_keyName, pSound));

}

FMOD::System* SoundManager::getSystem()
{
	return m_pSystem;
}

void SoundManager::play(wstring _keyName)
{
	map<wstring, Sound*>::iterator iter = m_mapSound.find(_keyName);
	
	if (m_mapSound.end() == iter)
		assert(nullptr);

	iter->second->play();
}


void SoundManager::stop(wstring _keyName)
{

	map<wstring, Sound*>::iterator iter = m_mapSound.find(_keyName);
	if (m_mapSound.end() == iter)
		assert(nullptr);
	iter->second->stop();
}

void SoundManager::pause(wstring _keyName)
{
	map<wstring, Sound*>::iterator iter = m_mapSound.find(_keyName);
	if (m_mapSound.end() == iter)
		assert(nullptr);
	iter->second->pause();
}

void SoundManager::resume(wstring _keyName)
{
	map<wstring, Sound*>::iterator iter = m_mapSound.find(_keyName);
	if (m_mapSound.end() == iter)
		assert(nullptr);
	iter->second->resume();
}

bool SoundManager::isPlaySound(wstring _keyName)
{
	map<wstring, Sound*>::iterator iter = m_mapSound.find(_keyName);
	
	if (m_mapSound.end() == iter)
		assert(nullptr);

	return iter->second->isPlay();

}

bool SoundManager::isPauseSound(wstring _keyName)
{
	map<wstring, Sound*>::iterator iter = m_mapSound.find(_keyName);

	if (m_mapSound.end() == iter)
		assert(nullptr);

	return iter->second->isPause();
}
