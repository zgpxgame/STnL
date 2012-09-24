/********************************************************************
	created:	2012/09/21
	created:	21:9:2012   16:28
	filename: 	e:\GitHub\STnL\Workspace\STnL\Texture.cpp
	file path:	e:\GitHub\STnL\Workspace\STnL
	file base:	Texture
	file ext:	cpp
	author:		Rainsing
	
	purpose:	
*********************************************************************/
#include "stdafx.h"
#include "Texture.h"

#include "Utilities.h"

Texture::Texture( void )
{
	m_width = m_height = 0;
	m_colorData = NULL;
}

void Texture::Initialize( int width, int height )
{
	m_width = width;
	m_height = height;
	m_colorData = new unsigned char[m_width * m_height * 4];
}

Texture::~Texture()
{
	SAFE_VECTOR_DELETE(m_colorData);
}

Vector4 Texture::Sample( float u, float v )
{
	// wrapѰַ��ʽ
	if (u > 1.0f || u < 0.0f)
	{
		u = u - Float2Int(u);
	}

	if (v > 1.0f || v < 0.0f)
	{
		v = v - Float2Int(v);
	}

	int texelIndex = (Float2Int(v * (m_height - 1)) * m_width + Float2Int(u * (m_width - 1))) << 2;

	Vector4 color;
	color.x = m_colorData[texelIndex + 0] / 255.0f;
	color.y = m_colorData[texelIndex + 1] / 255.0f;
	color.z = m_colorData[texelIndex + 2] / 255.0f;
	color.w = m_colorData[texelIndex + 3] / 255.0f;

	return color;
}