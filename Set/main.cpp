#include  <iostream>

class Set {
public:
    virtual bool member(unsigned int x) const = 0;
    virtual Set* virtualCopy() = 0;
    virtual ~Set();
};

class Singleton : public Set{
private:
    unsigned int num;
public:
    Singleton() = default;
    Singleton(unsigned int num);
    Set* virtualCopy() override;

    bool member(unsigned int num) const override;
};

Singleton::Singleton(unsigned int num){
    this->num = num;
}

Set* Singleton::virtualCopy() {
    Singleton* obj = new Singleton();
    return obj;
}

bool Singleton::member(unsigned int num) const {
    return num == this->num;
}

class EmptySet : public Set{
public:
    bool member(unsigned num) const override;
    Set* virtualCopy() override;
};

bool EmptySet::member(unsigned int num) const {
    return false;
}

Set* EmptySet::virtualCopy() {
    EmptySet* obj = new EmptySet();
    return obj;
}

class EvenSet : public Set{
public:
    bool member(unsigned int num) const override;
    Set* virtualCopy() override;
};

bool EvenSet::member(unsigned int num) const {
    return num % 2 ==0;
}

Set* EvenSet::virtualCopy() {
    EvenSet* obj = new EvenSet();
    return obj;
}

class SetUnion : public Set{
private:
    Set* firstSet = nullptr;
    Set* secondSet = nullptr;
public:
    SetUnion() = default;
    SetUnion(const Set& firstSet, const Set& secondSet);
    Set* virtualCopy() override;

    bool member(unsigned int num) const override;
};

SetUnion::SetUnion(const Set& firstSet, const Set& secondSet){
    this->firstSet = firstSet.virtualCopy();
    this->secondSet = secondSet.virtualCopy();
}

bool SetUnion::member(unsigned int num) const {
    return this->firstSet->member(num) || this->secondSet->member(num);
}

Set* SetUnion::virtualCopy() {
    SetUnion* obj = new SetUnion();
    return obj;
}


int main(){
    Singleton s(5);
    EmptySet e;
    EvenSet ev;
    SetUnion u(s, e);
    SetUnion u2(s, ev);
    SetUnion u3(u, u2);

    std::cout << u3.member(5) << std::endl;
    return 0;
}