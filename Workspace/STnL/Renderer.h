/********************************************************************
	created:	2012/09/14
	created:	14:9:2012   17:29
	filename: 	e:\GitHub\STnL\Workspace\STnL\Renderer.h
	file path:	e:\GitHub\STnL\Workspace\STnL
	file base:	Renderer
	file ext:	h
	author:		Rainisng
	
	purpose:	ʵ�ʸ���ִ����Ⱦ�����Ķ���
*********************************************************************/
#ifndef Renderer_h__
#define Renderer_h__

#include <vector>

class BackBuffer;
class RenderUnit;

typedef std::vector<RenderUnit*> RenderUnitList;

class Renderer
{
public:
	Renderer(void);

	void SetRenderTarget(BackBuffer* renderTarget);
	void AddRenderUnit(RenderUnit* renderUnit);
	void Render(void);

	void DrawLine(int x0, int y0, int x1, int y1, Color color);

private:
	BackBuffer* m_renderTarget;
	RenderUnitList m_renderUnitList;
};

#endif // Renderer_h__