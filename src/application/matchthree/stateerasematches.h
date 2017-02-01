#ifndef STATEERASEMATCHES_H
#define STATEERASEMATCHES_H

#include "framework/state.h"

#include <memory>
#include <set>
#include <vector>

namespace gincu {

class SceneMatchThree;

class StateEraseMatches : public State
{
private:
	typedef State super;

public:
	explicit StateEraseMatches(SceneMatchThree * scene, const int stateId, const int nextStateId);
	~StateEraseMatches();

private:
	bool doFindAllMatches();
	void finishedMatch();
	void animateToDisappear();
	void fullfilNewChesses();

private:
	virtual void doOnEnter() override;
	virtual void doOnExit() override;

private:
	SceneMatchThree * scene;
	std::vector<std::set<int> > matchedColumnRows; // first dimension -- column based, second dimension -- row based
};


} //namespace gincu

#endif
