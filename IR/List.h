#pragma once

#include <memory>
#include <assert.h>
#include <IExp.h>
#include <IStm.h>

namespace IR {

template<typename T>
class List : public T{
public:
    std::unique_ptr<List<T>> Head;
    std::unique_ptr<const T> Tail;

    List(const T* tail = nullptr, List<T>* head = nullptr) :
        Head(head),
        Tail(tail)
    {
        if(head != nullptr && head->Tail == nullptr) {
            delete head;
            Head = nullptr;
        }
    }

    ACCEPT_IR_VISITOR
};

typedef List<IExp> ExpList;
typedef List<IStm> StmList;

}