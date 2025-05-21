//  Copyright 2025 Guseva Olga

#pragma once

#include <iostream>
#include <cmath>
#define STEP_OF_CAPACITY 15

enum State { empty, busy, deleted };

template <class T> class TVector;
template <class T> void hoara_sort(TVector<T>& data);
template <class T> void hoara_sort_rec(TVector<T>&, size_t, size_t);
template <class T> int find_first_elem_by_index(const TVector<T>&, T);
template <class T> int find_last_elem_by_index(const TVector<T>& data, T value);
template <class T> int* find_elem_by_index(const TVector<T>& data, T value);
template <class T> T* find_first_elem_by_pointer(const TVector<T>&, T);
template <class T> T* find_last_elem_by_pointer(const TVector<T>&, T);
template <class T> TVector<T*> find_elem_by_pointer(const TVector<T>&, T);
template <class T> void shuffle(TVector<T>& data);

template <class T>
class TVector {
    T* _data;
    size_t _capacity;
    size_t _size;
    size_t _deleted;
    State* _states;

public:
    TVector(size_t size = 0);
    TVector(size_t size, const T* data);
    TVector(const TVector<T>&);
    TVector(size_t size, std::initializer_list<T> data);
    ~TVector();

    bool operator == (const TVector<T>& other) const noexcept;
    bool operator != (const TVector<T>& other) const noexcept;
    TVector& operator = (const TVector&);
    T& operator [] (size_t index);

    inline bool is_empty() const noexcept;

    // сеттеры
    //inline void data(size_t, const T*) noexcept;
    //inline front() noexcept;
    //inline back() noexcept;
    //inline begin() noexcept;
    //inline end() noexcept;

    // геттеры
    inline const T* data() const noexcept;
    inline const size_t size() const noexcept;
    inline const size_t capacity() const noexcept;
    inline const size_t deleted() const noexcept;
    inline const State* states() const noexcept;

    inline const T& front() const noexcept;
    inline const T& back() const noexcept;
    inline const T* begin() const noexcept;
    inline const T* end() const noexcept;

    void resize(size_t new_size);

    void push_front(const T& value);
    void push_back(const T& value);
    void insert(const size_t index, const T& value);
    void insert(const size_t index, std::initializer_list<T> data);

    void pop_back();
    void pop_front();
    void erase(size_t index);

    void print();
    void print_all_info();

    friend void hoara_sort_rec<T>(TVector<T>& data, size_t left, size_t right);
    friend void hoara_sort<T>(TVector<T>& data);
    friend int find_first_elem_by_index<T>(const TVector<T>& data, T value);
    friend int find_last_elem_by_index<T>(const TVector<T>& data, T value);
    friend int* find_elem_by_index<T>(const TVector<T>& data, T value);
    friend T* find_first_elem_by_pointer<T>(const TVector<T>&, T);
    friend T* find_last_elem_by_pointer<T>(const TVector<T>& data, T value);
    friend TVector<T*> find_elem_by_pointer<T>(const TVector<T>& data, T value);
    friend void shuffle<T>(TVector<T>& data);
    /* ... */
private: 
    /* ... */
    inline bool is_full() const noexcept;
    void make_space_for_insert(size_t index, size_t count);
    int count_real_index(size_t index);
};

template <class T>
TVector<T>::TVector(size_t size) {
    _size = size;
    _capacity = (size / STEP_OF_CAPACITY + 1) * STEP_OF_CAPACITY;
    _deleted = 0;

    if (size == 0) {
        _data = nullptr;
        _states = nullptr;
    }
    else {
        _data = new T[_capacity];
        _states = new State[_capacity];

        for (size_t i = 0; i < size; i++) {
            _data[i] = T();
            _states[i] = State::busy;
        }
        for (size_t i = size; i < _capacity; i++) {
            _states[i] = State::empty;
        }
    }
}

template <class T>
TVector<T>::TVector(size_t size, const T* data) {
    _size = size;
    _capacity = (size / STEP_OF_CAPACITY + 1) * STEP_OF_CAPACITY;
    _deleted = 0;

    _data = new T[_capacity];
    _states = new State[_capacity];

    for (size_t i = 0; i < size; i++) {
        _data[i] = data[i];
        _states[i] = State::busy;
    }
    for (size_t i = size; i < _capacity; i++) {
        _states[i] = State::empty;
    }
}

template <class T>
TVector<T>::TVector(const TVector<T>& other) {
    if (&other == NULL)
        throw std::logic_error("The object not found\n");

    _size = other._size;
    _capacity = other._capacity;
    _deleted = other._deleted;

    _data = new T[_capacity];
    _states = new State[_capacity];

    for (size_t i = 0; i < _capacity; i++) {
        _data[i] = other._data[i];
        _states[i] = other._states[i];
    }
}

template <class T>
TVector<T>::TVector(size_t size, std::initializer_list<T> data) {
    _size = size;
    _capacity = (size / STEP_OF_CAPACITY + 1) * STEP_OF_CAPACITY;
    _deleted = 0;

    _data = new T[_capacity];
    _states = new State[_capacity];

    auto it = data.begin();
    size_t i = 0;
    for (; it != data.end(); i++, it++) {
        _data[i] = *it;
        _states[i] = State::busy;
    }
    for (; i < _size; i++) {
        _data[i] = T();
    }
    for (; i < _capacity; i++) {
        _states[i] = State::empty;
    }
}

template <class T>
TVector<T>::~TVector() {
    delete[] _data;
    _data = nullptr;

    delete[] _states;
    _states = nullptr;
}

template <class T>
TVector<T>& TVector<T>::operator = (const TVector& other) {
    if (&other == NULL) {
        throw std::logic_error("The object is empty ");
    }
    if (this == &other) {
        return *this;
    }
    
    _size = other._size;
    _capacity = other._capacity;
    _deleted = other._deleted;

    delete[] _data;
    delete[] _states;

    _data = new T[_capacity];
    _states = new State[_capacity];

    for (size_t i = 0; i < _capacity; i++) {
        _data[i] = other._data[i];
        _states[i] = other._states[i];
    }

    return *this;
}

template <class T>
bool TVector<T>::operator == (const TVector<T>& other) const noexcept {
    // мб вообще убрать
    if (_size - _deleted != other._size - other._deleted) {
        return false;
    }
    size_t i = 0, j = 0;

    while (i < _capacity && j < other._capacity) {
        while (i < _capacity && _states[i] != State::busy)
            i++;
        while (j < other._capacity && other._states[j] != State::busy)
            j++;
        if (_data[i++] != other._data[j++]) {
            return false;
        }
    }
    return true;
}

template <class T>
bool TVector<T>::operator != (const TVector<T>& other) const noexcept {
    return !((*this) == other);
}

template <class T>
T& TVector<T>::operator[](size_t index) {
    size_t real_index = 0;
    size_t not_deleted_count = 0;

    for (; real_index < _capacity; real_index++) {
        if (_states[real_index] != State::deleted) not_deleted_count++;
        if (not_deleted_count == index + 1) break;
    }

    _states[real_index] = State::busy;
    return _data[real_index];
}

template <class T>
inline bool TVector<T>::is_empty() const noexcept {
    //return _size == 0;
    for (size_t i = 0; i < _capacity; i++) {
        if (_states[i] == State::busy)
            return false;
    }
    return true;
}

template <class T>
inline const T* TVector<T>::data() const noexcept {
    return _data;
}

template <class T>
inline const size_t TVector<T>::size() const noexcept {
    return _size;
}

template <class T>
inline const size_t TVector<T>::capacity() const noexcept {
    return _capacity;
}

template <class T>
inline const size_t TVector<T>::deleted() const noexcept {
    return _deleted;
}

template <class T>
inline const State* TVector<T>::states() const noexcept {
    return _states;
}

template <class T>
inline const T& TVector<T>::front() const noexcept {
    return _data[0];
}

template <class T>
inline const T& TVector<T>::back() const noexcept {
    return _data[_size - 1];
}

template <class T>
inline const T* TVector<T>::begin() const noexcept {
    return _data;
}

template <class T>
inline const T* TVector<T>::end() const noexcept {
    return _data + _size;
}

template <class T>
inline bool TVector<T>::is_full() const noexcept {
    for (size_t i = 0; i < _capacity; i++) {
        if (_states[i] == State::empty || _states[i] == State::deleted)
            return false;
    }
    return true;
}

template <class T>
void TVector<T>::resize(size_t new_size) {
    if (new_size == _size) return;

    T* new_data; State* new_states;
    size_t new_capacity = (new_size / STEP_OF_CAPACITY + 1) * STEP_OF_CAPACITY;
    size_t lowest_capacity = new_capacity > _capacity ? _capacity : new_capacity;

    if (new_size == 0) {
        new_data = nullptr;
        new_states = nullptr;
    }
    else {
        new_data = new T[new_capacity];
        new_states = new State[new_capacity];

        size_t not_delete_count = 0;
        if (_data != nullptr) {
            for (size_t i = 0; i < lowest_capacity; i++) {
                if (_states[i] != State::deleted) {
                    if (not_delete_count < new_size) {
                        new_data[not_delete_count] = _data[i];
                        new_states[not_delete_count] = _states[i];
                        not_delete_count++;
                    }
                    else {
                        _data[i].~T();
                        _states[i] = State::deleted;
                    }
                }
            }
        }
        for (int i = not_delete_count; i < new_capacity; i++) {
            new_states[i] = State::empty;
        }
    }

    if (_data != nullptr) {
        for (size_t i = 0; i < _capacity; ++i) {
            if (_states[i] != State::deleted)
                _data[i].~T();
        }
        delete[] _data;
        delete[] _states;
    }
    _data = new_data;
    _states = new_states;
    _capacity = new_capacity;
    _size = new_size;
    _deleted = 0;
}

template <class T>
void TVector<T>::make_space_for_insert(size_t index, size_t count) {
    int j = count - _deleted;
    for (size_t i = _size + j - 1; i > index; i--) {
        while (_states[i - j] == State::deleted) j++;

        if (j != 0) {
            _data[i] = _data[i - j];
            _states[i] = _states[i - j];
        }
    }
}

template <class T>
int TVector<T>::count_real_index(size_t index) {
    size_t busy_count = 0;
    size_t real_index = 0;
    for (; real_index < _size; real_index++) {
        if (busy_count == index) break;
        if (_states[real_index] == State::busy) busy_count++;
    }
    if (busy_count == 0) return -1;
    return real_index;
}

template <class T>
void TVector<T>::push_front(const T& value) {
    insert(0, value);
}

template <class T>
void TVector<T>::push_back(const T& value) {
    insert(_size, value);
}

template <class T>
void TVector<T>::insert(const size_t index, const T& value) {
    if (index > _size)
        throw std::invalid_argument("Index is larger than vector size\n");

    if (_size < _capacity) {
        make_space_for_insert(index, 1);
        _size++;
    }
    else {
        resize(_size + 1);
        make_space_for_insert(index, 1);
    }

    _data[index] = value;
    _states[index] = State::busy;

    if (is_full()) {
        // какая-то функция которая увеличивает capacity и выделяет доп память для того же размера
    }
}

template <class T>
void TVector<T>::insert(const size_t index, std::initializer_list<T> data_list) {
    if (index > _size)
        throw std::invalid_argument("Index is larger than vector size\n");

    if (_size + data_list.size() <= _capacity) {
        make_space_for_insert(index, data_list.size());
        _size += data_list.size();
    }
    else {
        resize(_size + data_list.size());
        make_space_for_insert(index, data_list.size());
    }

    auto it = data_list.begin();
    for (size_t i = 0; i < data_list.size(); i++) {
        _data[index + i] = *(it + i);
        _states[index + i] = State::busy;
    }

    if (is_full()) {
        // какая-то функция которая увеличивает capacity и выделяет доп память для того же размера
    }
}

template <class T>
void TVector<T>::pop_back() {
    int first_busy_index = -1;
    for (size_t i = _capacity; i >= 0; i--) {
        if (_states[i] == State::busy) {
            first_busy_index = i;
            break;
        }
    }

    if (first_busy_index != -1) {
        _states[first_busy_index] = State::empty;
        _deleted++;
    }

    if (_deleted >= _size * 0.2)
        resize(_size - _deleted);
}

template <class T>
void TVector<T>::pop_front() {
    int first_busy_index = -1;
    for (size_t i = 0; i < _capacity; i++) {
        if (_states[i] == State::busy) {
            first_busy_index = i;
            break;
        }
    }

    if (first_busy_index != -1) {
        _states[first_busy_index] = State::deleted;
        _deleted++;
    }

    if (_deleted >= _size * 0.2)
        resize(_size - _deleted);
}

template <class T>
void TVector<T>::erase(size_t index) {
    bool is_last_elem = true;

    if (is_empty()) return;

    for (size_t i = index + 1; i < _size; i++) {
        if (_states[i] == State::busy) {
            is_last_elem = false;
            break;
        }
    }
    if (is_last_elem) {
        pop_back();
    }
    else {
        size_t real_index = count_real_index(index);

        while (_states[real_index] == State::deleted) real_index++;
        _states[real_index] = State::deleted;
        _deleted++;
    }
    if (_deleted >= _size * 0.2)
        resize(_size - _deleted);
}

template <class T>
void TVector<T>::print() {
    std::cout << "Your vector: ";

    for (int i = 0; i < _size; i++) {
        if (_states[i] == State::busy) {
            std::cout << _data[i] << " ";
        }
    }
    std::cout << std::endl;
}

template <class T>
void TVector<T>::print_all_info() {
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "CAPACITY: " << _capacity << std::endl;
    std::cout << "SIZE: " << _size << std::endl;
    std::cout << "DELETED: " << _deleted << std::endl;
    std::cout << "DATA: ";
    for (int i = 0; i < _size; i++) {
        std::cout << _data[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "STATES: ";
    for (int i = 0; i < _size; i++) {
        std::cout << _states[i] << " ";
    }
    std::cout << std::endl;
    print();
    std::cout << "---------------------------------------------------" << std::endl;
}

template <class T>
void hoara_sort(TVector<T>& data) {
    if (data._size < 2) return;
    hoara_sort_rec(data, 0, data._size - 1);
}

template <class T>
void hoara_sort_rec(TVector<T>& data, size_t left, size_t right) {
    if (left < right) {
        size_t base = (left + right) / 2;
        size_t l = left, r = right;
        const T base_value = data[base];
        while (l <= r) {
            while (data._data[l] < base_value) {
                l++;
            }
            while (data._data[r] > base_value) {
                r--;
            }
            if (l <= r) {
                T tmp = data._data[l];
                data._data[l] = data._data[r];
                data._data[r] = tmp;

                T tmp = data._states[l];
                data._states[l] = data._states[r];
                data._states[r] = tmp;
                l++;
                if (r > 0) r--;
            }
            else {
                break;
            }
        }
        hoara_sort_rec(data, left, r);
        hoara_sort_rec(data, l, right);
    }
}

template<class T>
int find_first_elem_by_index(const TVector<T>& data, T value) {
    size_t not_real_index = 0;
    for (; not_real_index < data._size; not_real_index++) {
        if (data[not_real_index] == value) break;
    }
    return data.count_real_index(not_real_index);
}

template <class T>
int find_last_elem_by_index(const TVector<T>& data, T value) {
    size_t not_real_index = 0;
    for (size_t i = 0; i < data._size; i++) {
        if (data[i] == value) not_real_index = i;
    }
    return data.count_real_index(not_real_index);
}
template <class T>
int* find_elem_by_index(const TVector<T>& data, T value) {
    size_t occurrences_count = 0;
    for (size_t i = 0; i < data._size; i++) {
        if (data[i] == value) occurrences_count++;
    }

    int* result = new int[occurrences_count + 1];
    result[0] = occurrences_count;

    if (occurrences_count > 0) {
        size_t index = 1, not_busy_count = 0;

        for (size_t i = 0; i < data._size; i++) {
            if (data._states[i] != State::busy)
                not_busy_count++;
            if (data._data[i] == value && data._states[i] == State::busy)
                result[index++] = i - not_busy_count;
        }
        
    }
    return result;
}
template <class T>
T* find_first_elem_by_pointer(const TVector<T>& data, T value) {
    size_t count_deleted = 0;
    for (size_t i = 0; i < data._size + data._deleted; i++) {
        if (data._data[i] == value && data._states[i] == busy) {
            return &data._data[i];
        }
    }
    return nullptr;
}
template <class T>
T* find_last_elem_by_pointer(const TVector<T>& data, T value) {
    size_t count_deleted = 0;
    for (int i = data._size + data._deleted - 1; i >= 0; i--) {
        if (data._data[i] == value && data._states[i] == busy)
            return &data._data[i];
    }
    return nullptr;
}
template <class T>
TVector<T*> find_elem_by_pointer(const TVector<T>& data, T value) {
    size_t count_repetitions = 0;
    for (size_t i = 0; i < data._size + data._deleted; i++) {
        if (data._data[i] == value && data._states[i] == busy) {
            count_repetitions++;
        }
    }
    size_t count_deleted = 0;
    TVector<T*> result;
    if (count_repetitions > 0) {
        size_t  index = 0;
        for (size_t i = 0; i < data._size + data._deleted; i++) {
            if (data._data[i] == value && data._states[i] == busy) {
                result.insert(index, &data._data[i]);
                index++;
            }
        }
    }
    return result;
}
template <class T>
void shuffle(TVector<T>& data) {
    int i, rand_i;
    for (i = 0; i < data._size + data._deleted; i++) {
        rand_i = data.rand_generation(0, data._size + data._deleted - 1);
        data.my_swap(data._data[i], data._data[rand_i]);
        data.my_swap(data._states[i], data._states[rand_i]);
    }
}