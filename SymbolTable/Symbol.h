#pragma once

#include <string>

namespace SymbolTable { 

  class Symbol {
  public:
    const std::string& String() const;
    Symbol() {};
    Symbol( const Symbol& ) = delete;
    void operator=( const Symbol& ) = delete;

    bool operator ==( const Symbol& a );
		bool operator !=( const Symbol& a );

    virtual ~Symbol();
  protected:
    std::string name;
  };
}
