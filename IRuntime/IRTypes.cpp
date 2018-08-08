#include "IRTypes.h"
#include <assert.h>


namespace IRuntime {
	
const std::unordered_map<BaseType, short> TypeSizes = {
	{ BT_INT, 4 },
	{ BT_BOOL, 1 },
	{ BT_ADDRESS, 4 },
	{ BT_VOID, 1 },
	{ BT_COUNT, 0 }
};

std::unique_ptr<ResultValue> ResultValue::Create(BaseType type) {
	assert(BT_COUNT > type);
	return std::unique_ptr<ResultValue>(new(TypeSizes.at(type)) ResultValue(type));
}

ResultValue::ResultValue(BaseType type): Type(type) {
	const short size = TypeSizes.at(type);
	for(short i = 0; i < size; ++i) {
		Value[i] = 0;
	}
}
	
void* ResultValue::operator new(std::size_t count, short typeSize) {
	return ::operator new(count + typeSize - 1);
}
	
}
