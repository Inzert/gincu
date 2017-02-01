#ifndef RENDERENGINE_H
#define RENDERENGINE_H

#include "engine/geometry.h"
#include "engine/gamecolor.h"

#include <vector>
#include <map>
#include <memory>

namespace gincu {

class RenderEngineResource;
class Renderable;
class GameTransform;
class GameImage;
class GameText;
class RectRender;

class RenderEngine
{
public:
	// Not singleton. It must be created somewhere, the default is created by GameApplication
	static RenderEngine * getInstance();

public:
	RenderEngine();
	~RenderEngine();

	void inititialize();

	void render();

	void appendRenderable(Renderable * renderable);
	void removeRenderable(Renderable * renderable);
	
	bool isAlive() const;

	void draw(const GameImage & image, const GameTransform & transform);
	void draw(const GameText & text, const GameTransform & transform);
	void draw(const RectRender & rect, const GameTransform & transform);

	const std::shared_ptr<RenderEngineResource> & getResource() const { return this->resource; }

private:
	std::shared_ptr<RenderEngineResource> resource;
	std::vector<Renderable *> renderableList;
};


} //namespace gincu

#endif
