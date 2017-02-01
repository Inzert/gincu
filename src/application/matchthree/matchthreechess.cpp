#include "matchthree/matchthreechess.h"
#include "engine/errorhandler.h"
#include "framework/util.h"

#include <map>

namespace gincu {

namespace {

const std::map<ChessColor, std::string> chessColorResourceMap {
	{ ChessColor::normal0, "matchthree/1.png" },
	{ ChessColor::normal1, "matchthree/2.png" },
	{ ChessColor::normal2, "matchthree/3.png" },
	{ ChessColor::normal3, "matchthree/4.png" },
	{ ChessColor::normal4, "matchthree/5.png" },
};

}

std::string getChessResourceName(const ChessColor chessColor)
{
	auto it = chessColorResourceMap.find(chessColor);
	if(it == chessColorResourceMap.end()) {
		handleFatal("Can't find chess color: " + toString((int)chessColor));
		return std::string();
	}
	return it->second;
}

ChessColor randomChessColor()
{
	return (ChessColor)((int)ChessColor::normal0 + getRand(0, (int)ChessColor::count));
}

bool areCellsNeighbors(const RowColumn & cellA, const RowColumn & cellB)
{
	if(cellA.row == cellB.row && std::abs(cellA.column - cellB.column) == 1) {
		return true;
	}
	else if(cellA.column == cellB.column && std::abs(cellA.row - cellB.row) == 1) {
		return true;
	}
	else {
		return false;
	}
}


} //namespace gincu
