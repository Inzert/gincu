#include "gincu/gimage.h"
#include "gincu/grenderengine.h"
#include "gincu/gerrorhandler.h"
#include "gincu/gtransform.h"
#include "gincu/grenderinfo.h"
#include "gincu/sfml/gimagedata.h"

namespace gincu {

GImage::GImage()
	: data()
{
}

GImage::GImage(const std::shared_ptr<GImageData> & data)
{
	this->setResource(data);
}

GImage::GImage(const std::shared_ptr<GImageData> & data, const GRect & rect)
	: data(data), rect(rect)
{
}

GImage::~GImage()
{
}

void GImage::load(const std::string & fileName)
{
	this->data.reset(new GImageData());
	this->data->load(fileName);
}

void GImage::draw(const GTransform & transform, const GRenderInfo * renderInfo)
{
	GRenderEngine::getInstance()->draw(*this, transform, renderInfo);
}

GSize GImage::getSize() const
{
	return { this->rect.width, this->rect.height };
}

void GImage::setResource(const std::shared_ptr<GImageData> & data)
{
	this->data = data;
	if(this->data) {
		auto size = this->data->texture.getSize();
		this->rect = GRect{ 0, 0, (GCoord)size.x, (GCoord)size.y };
	}
}


} //namespace gincu
