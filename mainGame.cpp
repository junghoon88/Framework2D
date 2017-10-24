#include "stdafx.h"
#include "mainGame.h"

mainGame::mainGame()
{

}


mainGame::~mainGame()
{

}

//�ʱ�ȭ
HRESULT mainGame::init(void)
{
	gameNode::init(true);

	initScene();



	return S_OK;
}

void mainGame::initScene(void)
{
	SCENEMANAGER->addScene(L"�⺻��", new sceneInit);
}



//�޸� ����
void mainGame::release(void)
{
	gameNode::release();

	SCENEMANAGER->release();
}

//�������(Ÿ�̸�)
void mainGame::update(void)	
{
	gameNode::update();

	SCENEMANAGER->update();
}

//�׷��ִ� �Լ�
void mainGame::render(void)	
{
	//��� ��ȭ�� �� �� �ʿ�
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==============================================================
	
	SCENEMANAGER->render();


	RENDERMANAGER->render();

	TIMEMANAGER->render(getMemDC());
	
	//========================================================================
	//����ۿ� �ִ°� HDC�� �׷��ִ� ����
	this->getBackBuffer()->render(getHDC(), 0, 0);

}

