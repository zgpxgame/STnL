/********************************************************************
	created:	2012/09/14
	created:	14:9:2012   10:17
	filename: 	e:\GitHub\STnL\Workspace\STnL\BackBuffer.h
	file path:	e:\GitHub\STnL\Workspace\STnL
	file base:	BackBuffer
	file ext:	h
	author:		Rainsing
	
	purpose:	软件渲染器的所有绘制操作都写入这个BackBuffer，在每一帧
				的最后调用其Present()函数将buffer的内容blit到显示设备上。
				这是这个软件渲染器中唯一一个和硬件打交道的对象。
*********************************************************************/
#ifndef BackBuffer_h__
#define BackBuffer_h__

#include "Types.h"

class BackBuffer
{
public:

	BackBuffer(HWND hWnd, int width, int height);
	~BackBuffer();

	void Clear(Color color);
	void Clear(void);	// 快速clear至全黑
	void Present(void);
	inline void SetPixel(int x, int y, Color color);
	inline int GetWidth(void);
	inline int GetHeight(void);

private:

	HWND m_hWnd;
	int m_width;
	int m_height;
	Color* m_colorData;

	HDC m_windowDC;
	HDC m_memoryDC;
	HBITMAP m_hBitmap;
};

void BackBuffer::SetPixel( int x, int y, Color color )
{
	// TODO: This won't be needed any more after clipping is implemented.
	if (x < 0 || x >= m_width || y < 0 || y >= m_height)
	{
		return;
	}

	*(m_colorData + y * m_width + x) = color;
}

int BackBuffer::GetWidth( void )
{
	return m_width;
}

int BackBuffer::GetHeight( void )
{
	return m_height;
}

#endif // BackBuffer_h__
