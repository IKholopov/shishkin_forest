#include <IRTypes.h>
#include <unordered_map>

namespace IRuntime {

class RegisterData {
public:
  RegisterData(BaseType type) { data = new std::byte[TypeSizes.at(type)]; }
  RegisterData(const RegisterData&) = delete;
  ~RegisterData() { delete data; }

private:
  BaseType type;
  std::byte* data;
};

class RegisterManager {
private:
  std::unordered_map<int, 
};

}

