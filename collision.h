#pragma once

namespace IOTA_UTIL
{
	typedef struct tagMYPOINT
	{
		float x;
		float y;

		tagMYPOINT() : x(0.0f), y(0.0f) {}

		void set(float _x, float _y)
		{
			x = _x;
			y = _y;
		}

		void move(float dx, float dy)
		{
			x += dx;
			y += dy;
		}

		POINT toPoint(void)
		{
			return { (long)x, (long)y };
		}

	}MYPOINT, *LPMYPOINT;

	inline MYPOINT PointMake(float x, float y)
	{
		MYPOINT pt;
		pt.set(x, y);

		return pt;
	}


	typedef struct tagMYCIRCLE
	{
		float x;
		float y;
		float r;

		tagMYCIRCLE() : x(0.0f), y(0.0f), r(0.0f) {}
		tagMYCIRCLE(float _x, float _y, float _r) : x(_x), y(_y), r(_r) {}

		void move(float dx, float dy)
		{
			x += dx;
			y += dy;
		}

		void set(float centerX, float centerY, float radius)
		{
			x = centerX;
			y = centerY;
			r = radius;
		}

		void setCenterPos(float posX, float posY)
		{
			x = posX;
			y = posY;
		}

		void render(HDC hdc)
		{
			int x1 = FLOAT_TO_INT(x);
			int y1 = FLOAT_TO_INT(y);
			int r1 = FLOAT_TO_INT(r);

			Ellipse(hdc, x1 - r1, y1 - r1, x1 + r1, y1 + r1);
		}

	}MYCIRCLE, *LPMYCIRCLE;

	typedef struct tagMYRECT
	{
		float left;
		float top;
		float right;
		float bottom;

		tagMYRECT() : left(0.0f), top(0.0f), right(0.0f), bottom(0.0f) {}
		tagMYRECT(float _left, float _top, float _right, float _bottom)
			: left(_left), top(_top), right(_right), bottom(_bottom) {}

		void move(float dx, float dy)
		{
			left += dx;
			top += dy;
			right += dx;
			bottom += dy;
		}

		void set(float _left, float _top, float _right, float _bottom)
		{
			left = _left;
			top = _top;
			right = _right;
			bottom = _bottom;
		}

		void set(RECT rc)
		{
			left = rc.left;
			top = rc.top;
			right = rc.right;
			bottom = rc.bottom;
		}

		RECT toRect(void)
		{
			return RectMake(left, top, right - left, bottom - top);;
		}

		void setCenter(float _cx, float _cy, float _width, float _height)
		{
			left = _cx - _width / 2;
			top = _cy - _height / 2;
			right = _cx + _width / 2;
			bottom = _cy + _height / 2;
		}

		void setLeftTopPos(float _left, float _top)
		{
			float width = getWidth();
			float height = getHeight();

			left = _left;
			top = _top;
			right = left + width;
			bottom = top + height;
		}

		void setCenterPos(float centerX, float centerY)
		{
			float halfW = getWidth() * 0.5f;
			float halfH = getHeight() * 0.5f;

			left = centerX - halfW;
			top = centerY - halfH;
			right = centerX + halfW;
			bottom = centerY + halfH;
		}

		void render(HDC hdc)
		{
			Rectangle(hdc,
				FLOAT_TO_INT(left),
				FLOAT_TO_INT(top),
				FLOAT_TO_INT(right),
				FLOAT_TO_INT(bottom));
		}

		void render(HDC hdc, int cameraX, int cameraY)
		{
			Rectangle(hdc,
				FLOAT_TO_INT(left - cameraX),
				FLOAT_TO_INT(top - cameraY),
				FLOAT_TO_INT(right - cameraX),
				FLOAT_TO_INT(bottom - cameraY));
		}

		float getWidth(void) { return right - left; }
		float getHeight(void) { return bottom - top; }
	}MYRECT, *LPMYRECT;

	//POINT�� �簢���ȿ� �ִ�?
	bool checkPointInRect(const RECT& rc, const POINT& pt);
	bool checkPointInRect(const RECT& rc, int x, int y);
	bool checkPointInRect(const MYRECT& rc, float x, float y);
	bool checkPointInRect(const MYRECT& rc, const MYPOINT& pt);

	//POINT�� ���ȿ� �ִ�?
	bool checkPointInCircle(float cX, float cY, float cR, const MYPOINT& pt);
	bool checkPointInCircle(float cX, float cY, float cR, float x, float y);
	bool checkPointInCircle(const MYCIRCLE& rc, float x, float y);
	bool checkPointInCircle(const MYCIRCLE& rc, const MYPOINT& pt);

	//�簢���� �簢���̶� �ε�����?
	bool isCollision(const MYRECT& rc1, const MYRECT& rc2);
	bool isCollision(const RECT& rc1, const RECT& rc2);

	//���� ���� �ε�����?
	bool isCollision(const MYCIRCLE& cir1, const MYCIRCLE& cir2);

	//�簢���� ���� �ε�����?
	bool isCollision(const MYCIRCLE& cir1, const RECT& rc);
	bool isCollision(const MYCIRCLE& cir, const MYRECT& rc);

	//�ε����� �����Ҳ���?
	bool isCollisionReaction(const RECT& rcHold, RECT& rcMove);
	int isCollisionOffset(const RECT& rcHold, RECT& rcMove);
	bool isCollisionReaction(const MYRECT& mrcHold, MYRECT& mrcMove);
	bool isCollisionReaction(const MYCIRCLE& cirHold, MYCIRCLE& cirMove);

	//����Ʈ�� ������ �������� ��Ʈ�� ������ ���� �ű�
	bool PointInRectReaction(const MYRECT& rc, MYPOINT& pt);

}