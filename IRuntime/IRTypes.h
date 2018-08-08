#pragma once

#include <vector>
#include <utility>
#include <unordered_map>
#include <memory>

namespace IRuntime {
	
enum BaseType : char {
	BT_INT,
	BT_BOOL,
	BT_ADDRESS,
	BT_VOID,
	
	BT_COUNT
};

extern const std::unordered_map<BaseType, short> TypeSizes;

struct ResultValue {
public:
	BaseType Type;
	char Value[1];
	
	static std::unique_ptr<ResultValue> Create(BaseType type);
	
private:
	  explicit ResultValue(BaseType type);
	  static void* operator new(std::size_t count, short typeSize);
};



}