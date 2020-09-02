#pragma once
#include <map>

class gameNode;

class sceneManager
{
public:
	static sceneManager* getInstance()
	{
		static sceneManager instance;
		return &instance;
	}
private:
	sceneManager();
	~sceneManager();

public:
	typedef map<string, gameNode*>			 mapSceneList;
	typedef map<string, gameNode*>::iterator mapSceneIter;

private:
	static gameNode* _currentScene;
	mapSceneList _mSceneList;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	gameNode* addScene(string sceneName, gameNode* scene);

	HRESULT changeScene(string sceneName);

};

