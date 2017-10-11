#include "GUIDrawable.h"




GUIDrawable::GUIDrawable(sf::Drawable * drawable)
{
	this->drawable = drawable;
}

GUIDrawable::~GUIDrawable()
{
	for (GUIDrawable* c : children) {
		delete c;
	}
}

void GUIDrawable::Delete()
{
	this->toDelete = true;
	for (GUIDrawable* child : children) {
		child->Delete();
	}
}
