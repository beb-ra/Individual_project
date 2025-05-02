//  Copyright 2025 Guseva Olga

#pragma once

enum State { empty, busy, deleted };

template <class T>
class TVector {
    T* data;
    size_t _capacity;
    size_t _size;
    size_t _deleted;
    State* states;
};
