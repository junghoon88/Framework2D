#pragma once
#include "gameNode.h"
#include "sceneInit.h"
#include "sceneSelect.h"
#include "sceneGame.h"

class mainGame : public gameNode
{
private:

private:
	void initScene(void);

public:
	virtual HRESULT init(void);		//�ʱ�ȭ
	virtual void release(void);		//�޸� ����
	virtual void update(void);		//�������(Ÿ�̸�)
	virtual void render(void);	//�׷��ִ� �Լ�
	
	mainGame();
	~mainGame();
};

