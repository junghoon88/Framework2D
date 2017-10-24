#pragma once
#include <vector>

class animation
{
public:
	typedef vector<POINT> vFrameList;
	typedef vector<int> vPlayList;

private:
	int			_frameNum;			//�� ����������

	vFrameList	_frameList;			//�ִϸ��̼� ������ ����Ʈ
	vPlayList	_playList;			//�ִϸ��̼� �÷��� �ε��� ���� ����Ʈ

	int			_frameWidth;		//������ ����ũ��
	int			_frameHeight;		//������ ����ũ��

	BOOL		_loop;				//�ִϸ��̼� ���� ����

	float		_frameUpdateSec;	//������ ���� �ӵ�
	float		_elapsedSec;

	DWORD		_nowPlayIndex;		//���� ��� ���� �÷��� �ε���
	BOOL		_play;


public:
	animation();
	~animation();

	HRESULT init(int totalW, int totalH, int frameW, int frameH);
	void release(void);

	void setDefPlayFrame(BOOL reverse = FALSE, BOOL loop = FALSE);
	void setPlayFrame(int* playArr, int arrLen, BOOL loop = FALSE);
	void setPlayFrame(int start, int end, BOOL reverse = FALSE, BOOL loop = FALSE);

	void setFPS(int framePerSec);

	void frameUpdate(float elapsedTime);

	void start(void);
	void stop(void);
	void pause(void);
	void resume(void);

	inline BOOL isPlay(void) { return _play; }
	inline POINT getFramePos(void) { return _frameList[_playList[_nowPlayIndex]]; }
	inline int getFrameWidth(void) { return _frameWidth; }
	inline int getFrameHeight(void) { return _frameHeight; }


};

