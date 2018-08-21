//
// Created by aosamesan on 2018-08-20.
//

#ifndef UNTITLED_INVOKECOUNTER_H
#define UNTITLED_INVOKECOUNTER_H
#include<functional>

template<typename R, typename ...T>
class InvokeCounter {
public:
    using FuncPtr = R(*)(T...);

    InvokeCounter(FuncPtr fptr) : count(0) {
        func = fptr;
    }

    template<typename L>
    InvokeCounter(L lambda) : count(0) {
        func = lambda;
    }

    R operator()(T... args) {
        count++;
        return func(args...);
    }

    void resetCount() {
        count = 0;
    }

    int getCount() {
        return count;
    }

private:
    std::function<R(T...)> func;
    int count;
};
#endif //UNTITLED_INVOKECOUNTER_H
