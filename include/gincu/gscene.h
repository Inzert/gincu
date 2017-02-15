#ifndef GSCENE_H
#define GSCENE_H

#include "gincu/ggeometry.h"

#include "cpgf/tween/gtweenlist.h"

#include <memory>
#include <vector>

namespace gincu {

class GComponentManager;
class GEntity;
struct GEvent;

class GScene
{
private:
	typedef std::unique_ptr<GEntity> EntityPointer;

public:
	GScene();
	virtual ~GScene();

	void onEnter();
	void onExit();

	void renderScene();

	void handleTouchEvent(const GEvent & touchEvent);

	GEntity * addEntity(GEntity * entity);
	void removeEntity(GEntity * entity);
	void removeAllEntities();

	void setTouchCapture(GEntity * touchCapture);
	GEntity * getTouchCapture() const;

	cpgf::GTweenList * getTweenList() { return &this->tweenList; }

private:
	void initializePrimaryCamera();

private:
	virtual void doOnEnter();
	virtual void doOnExit();

private:
	std::unique_ptr<GComponentManager> componentManager;
	std::vector<EntityPointer> entityList;
	GEntity * primaryCamera;
	GEntity * touchCapture;
	cpgf::GTweenList tweenList;
};


template <typename T>
T * sceneCreator()
{
	return new T();
}

cpgf::GTweenList * getTweenListFromScene();


} //namespace gincu

#endif

