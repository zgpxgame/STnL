/********************************************************************
	created:	2012/09/24
	created:	24:9:2012   10:18
	filename: 	e:\GitHub\STnL\Workspace\STnL\PixelShader.h
	file path:	e:\GitHub\STnL\Workspace\STnL
	file base:	PixelShader
	file ext:	h
	author:		Rainsing
	
	purpose:	
*********************************************************************/
#ifndef PixelShader_h__
#define PixelShader_h__

#include "Vector.h"

class VertexShaderOutput;
class Texture;

class PixelShader
{
public:
	virtual Vector4 Main(VertexShaderOutput& vertexAttribute) = 0;
};

class PsFixedFunction : public PixelShader
{
public:
	virtual Vector4 Main(VertexShaderOutput& vertexAttribute);

public:
	Texture* baseTexture;
};

class PsNormalMap : public PixelShader
{
public:
	virtual Vector4 Main(VertexShaderOutput& vertexAttribute);

public:
	Texture* baseTexture;
	Texture* normalTexture;

	Vector3 diffuseColor;
	Vector3 ambientColor;
};

class PsToonLighting : public PixelShader
{
public:
	virtual Vector4 Main(VertexShaderOutput& vertexAttribute);

public:
	Texture* baseTexture;

	Vector3 diffuseColor;
	Vector3 ambientColor;
};

#endif // PixelShader_h__
