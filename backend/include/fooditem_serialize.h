#ifndef FOODITEM_SERIALIZE_H
#define FOODITEM_SERIALIZE_H

#include "iserializable.h"

class FoodItem_Serialize : public ISerializable
{
public:
	void serialize(std::ostream&, void*) override;
	void unserialize(std::istream&, void*) override;
	~FoodItem_Serialize();
};

#endif