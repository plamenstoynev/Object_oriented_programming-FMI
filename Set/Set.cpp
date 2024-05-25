#include "Set.h"

Set *Set::virtualCopy() const{
    return const_cast<Set *>(this);
}
Set::~Set(){}