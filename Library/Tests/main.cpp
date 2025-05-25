//  Copyright 2025 Guseva Olga

#include <iostream>
#include <windows.h>
#include "C:/Users/Lelya/cc++/Individual_project/Library/Tvector/tvector.h"

void set_color(int text_color, int bg_color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (bg_color << 4) | text_color);
}

namespace TestSystem {
    int count_success = 0, count_failed = 0;

    void start_test(bool(*test)(), const char* name_of_test) {
        set_color(2, 0);
        std::cout << "[ RUN      ]\t";
        set_color(7, 0);
        std::cout << name_of_test << std::endl;

        bool status = test();

        if (status == true) {
            set_color(2, 0);
            std::cout << "[       OK ]\n" << std::endl;
            count_success++;
        }
        else {
            set_color(4, 0);
            std::cout << "[  FAILED  ]" << std::endl;
            count_failed++;
        }
        set_color(7, 0);
    }

    template <class T>
    bool check(const T& expected, const T& actual) {
        if (expected == actual) {
            return true;
        }
        else {
            std::cerr << "Expected result is " << expected << ", but actual is " << actual << "." << std::endl;
            return false;
        }
    }

    void print_init_info() {
        set_color(2, 0);
        std::cout << "[==========] " << std::endl;
        set_color(7, 0);
    }

    void print_final_info() {
        set_color(2, 0);
        std::cout << "[==========] ";
        set_color(7, 0);
        std::cout << count_success + count_failed << " test" << (count_success + count_failed > 1 ? "s" : "") << " ran." << std::endl;
        set_color(2, 0);
        std::cout << "[  PASSED  ] ";
        set_color(7, 0);
        std::cout << count_success << " test" << (count_success > 1 ? "s" : "") << std::endl;
        if (count_failed > 0) {
            set_color(4, 0);
            std::cout << "[  FAILED  ] ";
            set_color(7, 0);
            std::cout << count_failed << " test" << (count_failed > 1 ? "s." : ".") << std::endl;
        }
    }
};

// может создать объект через конструктор по умолчанию
bool test1_try_create_default_object() {
    bool expected_result = true;
    bool actual_result = true;

    try {
        TVector<int> object;
    }
    catch (const std::exception& ex) {
        std::cerr << ex.what();
        actual_result = false;
    }

    return TestSystem::check(expected_result, actual_result);
}

// создает корректно объект через конструктор по умолчанию
bool test2_try_create_with_default_object() {
    TVector<int> object;

    return TestSystem::check(static_cast <size_t>(0), object.size()) &&
        TestSystem::check(static_cast <size_t>(STEP_OF_CAPACITY), object.capacity()) &&
        TestSystem::check(static_cast <size_t>(0), object.deleted()) &&
        TestSystem::check(State::empty, object.states()[0]);
}

// создает корректно объект через первый конструктор инициализации
bool test3_check_create_object_with_initialization() {
    int size = 2;
    int* mass = new int[size];
    mass[0] = 1; mass[1] = 2;

    TVector<int> object(size, mass);

    return TestSystem::check(1, object.data()[0]) &&
        TestSystem::check(2, object.data()[1]) &&
        TestSystem::check(static_cast <size_t>(size), object.size()) &&
        TestSystem::check(static_cast <size_t>(15), object.capacity()) &&
        TestSystem::check(static_cast <size_t>(0), object.deleted()) &&
        TestSystem::check(State::busy, object.states()[0]) &&
        TestSystem::check(State::busy, object.states()[1]) &&
        TestSystem::check(State::empty, object.states()[2]);
}

// создает корректно объект через первый конструктор
bool test4_try_create_object() {
    bool expected_result = true;
    bool actual_result = true;

    try {
        TVector<int> object(3);
    }
    catch (const std::exception& ex) {
        std::cerr << ex.what();
        actual_result = false;
    }

    return TestSystem::check(expected_result, actual_result);
}

// создает корректно объект через второй конструктор инициализации
bool test4_2_check_create_object() {
    TVector<int> object(3, { 1, 2, 3 });
    
    return TestSystem::check(1, object.data()[0]) &&
        TestSystem::check(2, object.data()[1]) &&
        TestSystem::check(3, object.data()[2]) &&
        TestSystem::check(State::busy, object.states()[0]) &&
        TestSystem::check(State::busy, object.states()[1]) &&
        TestSystem::check(State::busy, object.states()[2]) &&
        TestSystem::check(State::empty, object.states()[3]) &&
        TestSystem::check(static_cast <size_t>(0), object.deleted()) &&
        TestSystem::check(static_cast <size_t>(3), object.size()) &&
        TestSystem::check(static_cast <size_t>(15), object.capacity());
}

// создает корректно объект через второй конструктор инициализации
bool test4_2_2_check_create_object() {
    TVector<int> object(3, { 1, 2 });

    return TestSystem::check(1, object.data()[0]) &&
        TestSystem::check(2, object.data()[1]) &&
        TestSystem::check(0, object.data()[2]) &&
        TestSystem::check(State::busy, object.states()[0]) &&
        TestSystem::check(State::busy, object.states()[1]) &&
        TestSystem::check(State::busy, object.states()[2]) &&
        TestSystem::check(State::empty, object.states()[3]) &&
        TestSystem::check(static_cast <size_t>(0), object.deleted()) &&
        TestSystem::check(static_cast <size_t>(3), object.size()) &&
        TestSystem::check(static_cast <size_t>(15), object.capacity());
}

// создает корректно объект через второй конструктор инициализации
bool test4_2_3_check_create_object() {
    TVector<int> object(3, { 1, 2, 3, 4 });

    return TestSystem::check(1, object.data()[0]) &&
        TestSystem::check(2, object.data()[1]) &&
        TestSystem::check(3, object.data()[2]) &&
        TestSystem::check(State::busy, object.states()[0]) &&
        TestSystem::check(State::busy, object.states()[1]) &&
        TestSystem::check(State::busy, object.states()[2]) &&
        TestSystem::check(State::empty, object.states()[3]) &&
        TestSystem::check(static_cast <size_t>(0), object.deleted()) &&
        TestSystem::check(static_cast <size_t>(3), object.size()) &&
        TestSystem::check(static_cast <size_t>(15), object.capacity());
}

// создает корректно объект через конструктор копирования
bool test4_3_check_create_object_with_copy() {
    TVector<int> object1(3, { 1, 2, 3 });

    TVector<int> object(object1);

    return TestSystem::check(1, object.data()[0]) &&
        TestSystem::check(2, object.data()[1]) &&
        TestSystem::check(3, object.data()[2]) &&
        TestSystem::check(State::busy, object.states()[0]) &&
        TestSystem::check(State::busy, object.states()[1]) &&
        TestSystem::check(State::busy, object.states()[2]) &&
        TestSystem::check(State::empty, object.states()[3]) &&
        TestSystem::check(static_cast <size_t>(0), object.deleted()) &&
        TestSystem::check(static_cast <size_t>(3), object.size()) &&
        TestSystem::check(static_cast <size_t>(15), object.capacity());
}

// перегрузка присваивания
bool test5_check_assign_operator() {
    TVector<int> object1(2, { 1, 2 });
    TVector<int> object2(1, { 3 });

    object2 = object1;

    return TestSystem::check(true, object1 == object2) &&
        TestSystem::check(1, object2.data()[0]) &&
        TestSystem::check(2, object2.data()[1]) &&
        TestSystem::check(static_cast <size_t>(2), object2.size()) &&
        TestSystem::check(static_cast <size_t>(15), object2.capacity()) &&
        TestSystem::check(static_cast <size_t>(0), object2.deleted()) &&
        TestSystem::check(State::busy, object2.states()[0]) &&
        TestSystem::check(State::busy, object2.states()[1]);
}

// перегрузка []
bool test6_check_indexing_operator() {
    TVector<int> object(6);
    object[0] = 1;
    object[1] = 2;
    object[2] = 3;
    object[4] = 5;
    object[5] = 6;

    TVector<int> object2(6, { 1, 2, 3, 0, 5, 6 });
  
    return TestSystem::check(1, object.data()[0]) &&
        TestSystem::check(2, object.data()[1]) &&
        TestSystem::check(3, object.data()[2]) &&
        TestSystem::check(5, object.data()[4]) &&
        TestSystem::check(6, object.data()[5]) &&
        TestSystem::check(true, object == object2);
}

bool test6_2_check_indexing_operator() {
    TVector<int> object(8);
    object[0] = 1;
    object[2] = 2;
    object[3] = 3;
    object[5] = 4;
    object[7] = 5;

    TVector<int> object2(8, { 1, 0, 2, 3, 0, 4, 0, 5, 0 });

    return TestSystem::check(1, object.data()[0]) &&
        TestSystem::check(2, object.data()[2]) &&
        TestSystem::check(3, object.data()[3]) &&
        TestSystem::check(4, object.data()[5]) &&
        TestSystem::check(5, object.data()[7]) &&
        TestSystem::check(true, object == object2);
}

bool test6_3_check_const_indexing_operator() {
    TVector<int> object(5);
    for (size_t i = 0; i < 5; i++) {
        object[i] = i + 1;
    }
    const TVector<int> const_object(object);

    return TestSystem::check(1, const_object[0]) &&
        TestSystem::check(2, const_object[1]) &&
        TestSystem::check(3, const_object[2]) &&
        TestSystem::check(4, const_object[3]) &&
        TestSystem::check(5, const_object[4]);
}

bool test_7_check_reserve() {
    TVector<int> object(10, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });
    object.reserve(5);
    object.reserve(15);
    TVector<int> object2(10, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });

    return TestSystem::check(true, object == object2);
}

bool test_7_2_check_reserve() {
    TVector<int> object(10, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });
    object.reserve(30);
    TVector<int> object2(10, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });

    return TestSystem::check(true, object == object2) &&
        TestSystem::check(static_cast <size_t>(30), object.capacity());
}

bool test_7_3_check_resize() {
    TVector<int> object(10, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });
    object.resize(5);
    TVector<int> object2(5, { 1, 2, 3, 4, 5 });

    return TestSystem::check(true, object == object2);
}

bool test_7_4_check_resize() {
    TVector<int> object(10, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });
    object.resize(15);
    TVector<int> object2(15, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0, 0, 0, 0, 0 });

    return TestSystem::check(true, object == object2);
}

bool test_7_5_check_resize() {
    TVector<int> object(10, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });
    object.resize(0);
    TVector<int> object2;
    object2.clear();

    return TestSystem::check(true, object == object2);
}

bool test_7_6_check_resize() {
    TVector<int> object(10, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });
    object.resize(16);
    TVector<int> object2(16, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0, 0, 0, 0, 0, 0 });

    return TestSystem::check(static_cast<size_t>(16), object.size()) &&
        TestSystem::check(static_cast<size_t>(30), object.capacity()) &&
        TestSystem::check(true, object == object2);
}

bool test8_check_pop_front() {
    TVector<int> object(15);
    object[0] = 1;
    object[2] = 2;
    object[3] = 3;
    object[5] = 4;

    object.pop_front();
    object.pop_front();

    return TestSystem::check(State::deleted, object.states()[0]) &&
        TestSystem::check(State::deleted, object.states()[1]) &&
        TestSystem::check(3, object.data()[3]) &&
        TestSystem::check(4, object.data()[5]) &&
        TestSystem::check(3, object[1]) &&
        TestSystem::check(4, object[3]) &&
        TestSystem::check(static_cast <size_t>(15), object.size());
}

bool test8_2_check_pop_front_with_resize() {
    TVector<int> object(10);
    object[0] = 1;
    object[2] = 2;
    object[3] = 3;
    object[5] = 4;

    object.pop_front();
    object.pop_front();

    TVector<int> object2(8, { 2, 3, 0, 4, 0, 0, 0, 0, 0 });

    return TestSystem::check(true, object == object2) && 
        TestSystem::check(static_cast <size_t>(8), object.size());
}

bool test9_check_pop_back() {
    TVector<int> object(15);
    object[0] = 1;
    object[2] = 2;
    object[3] = 3;
    object[5] = 5;

    object.pop_back();
    object.pop_back();

    return TestSystem::check(State::empty, object.states()[14]) &&
        TestSystem::check(State::empty, object.states()[13]) &&
        TestSystem::check(3, object.data()[3]) &&
        TestSystem::check(5, object.data()[5]) &&
        TestSystem::check(3, object[3]) &&
        TestSystem::check(5, object[5]) &&
        TestSystem::check(static_cast <size_t>(15), object.size());
}

bool test9_2_check_pop_back_with_resize() {
    TVector<int> object(10);
    object[0] = 1;
    object[2] = 2;
    object[3] = 3;
    object[5] = 4;

    object.pop_back();
    object.pop_back();

    return TestSystem::check(1, object.data()[0]) &&
        TestSystem::check(2, object.data()[2]) &&
        TestSystem::check(1, object[0]) &&
        TestSystem::check(2, object[2]) &&
        TestSystem::check(static_cast <size_t>(8), object.size());
}

bool test10_check_erase() {
    TVector<int> object(15);
    object[0] = 1;
    object[2] = 2;
    object[3] = 3;
    object[5] = 4;

    object.erase(2);
    object.erase(2);

    return TestSystem::check(State::deleted, object.states()[2]) &&
        TestSystem::check(State::deleted, object.states()[3]) &&
        TestSystem::check(1, object.data()[0]) &&
        TestSystem::check(4, object.data()[5]) &&
        TestSystem::check(1, object[0]) &&
        TestSystem::check(4, object[3]) &&
        TestSystem::check(static_cast <size_t>(15), object.size());
}

bool test10_2_check_erase_with_resize() {
    TVector<int> object(15);
    object[0] = 1;
    object[2] = 2;
    object[3] = 3;
    object[5] = 4;

    object.erase(2);
    object.erase(2);
    object.erase(2);
    object.erase(3);

    return TestSystem::check(1, object.data()[0]) &&
        TestSystem::check(4, object.data()[2]) &&
        TestSystem::check(1, object[0]) &&
        TestSystem::check(4, object[2]) &&
        TestSystem::check(static_cast <size_t>(12), object.size());
}

bool test10_3_check_erase_last_elem() {
    TVector<int> object(10);

    object.erase(9);

    return TestSystem::check(static_cast <size_t>(10), object.size()) &&
        TestSystem::check(State::empty, object.states()[9]);
}

bool test11_check_resize_with_lowest_size() {
    TVector<int> object(10);

    for (size_t i = 0; i < 10; i++) {
        object[i] = i + 1;
    }

    object.resize(5);

    TVector<int> object2(5, { 1, 2, 3, 4, 5 });

    return TestSystem::check(static_cast <size_t>(5), object.size()) &&
        TestSystem::check(static_cast <size_t>(15), object.capacity()) &&
        TestSystem::check(State::empty, object.states()[5]) &&
        TestSystem::check(true, object == object2);
}

bool test11_2_check_resize_with_largest_size() {
    TVector<int> object(10);

    object.resize(20);

    return TestSystem::check(static_cast <size_t>(20), object.size()) &&
        TestSystem::check(static_cast <size_t>(30), object.capacity()) &&
        TestSystem::check(State::busy, object.states()[10]) &&
        TestSystem::check(State::busy, object.states()[19]) &&
        TestSystem::check(0, object.data()[10]) &&
        TestSystem::check(0, object.data()[19]);
}

bool test12_check_push_back() {
    TVector<int> object(10);

    object.push_back(5);
    object.push_back(6);

    return TestSystem::check(static_cast <size_t>(12), object.size()) &&
        TestSystem::check(5, object[10]) &&
        TestSystem::check(6, object[11]);
}

bool test12_2_check_push_back() {
    TVector<int> object(5, {1, 0, 2, 3, 4});

    object.push_back(5);

    TVector<int> object2(6, { 1, 0, 2, 3, 4, 5 });

    return TestSystem::check(static_cast <size_t>(6), object.size()) &&
        TestSystem::check(true, object == object2);
}

bool test12_3_check_push_back() {
    TVector<int> object(10);
    object[1] = 1;
    object[2] = 2;
    object[4] = 4;
    object[5] = 5;

    object.push_back(6);
    object.push_back(7);

    TVector<int> object2(12, { 0, 1, 2, 0, 4, 5, 0, 0, 0, 0, 6, 7 });

    return TestSystem::check(static_cast <size_t>(12), object.size()) &&
        TestSystem::check(true, object == object2);
}

bool test13_check_push_front() {
    TVector<int> object(10);
    object[0] = 1;
    object[1] = 2;
    object[3] = 4;
    object[4] = 5;

    object.push_front(11);
    object.push_front(10);

    TVector<int> object2(12, { 10, 11, 1, 2, 0, 4, 5, 0, 0, 0, 0, 0, 0 });

    return TestSystem::check(static_cast <size_t>(12), object.size()) &&
        TestSystem::check(true, object == object2);
}

bool test13_2_check_push_front_with_increasing_capacity() {
    TVector<int> object(14, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 });

    object.push_front(55);

    TVector<int> object2(15,
        { 55, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 });

    return TestSystem::check(static_cast<size_t>(30), object.capacity()) &&
        TestSystem::check(true, object == object2);
}

bool test13_3_check_push_front_in_empty_vector() {
    TVector<int> object;
    object.push_front(11);

    TVector<int> object2(1, { 11 });

    return TestSystem::check(true, object == object2);
}

bool test14_check_insert() {
    TVector<int> object(10);
    object[1] = 1;
    object[2] = 2;
    object[4] = 4;
    object[5] = 5;

    object.insert(3, 3);
    object.insert(3, 13);

    TVector<int> object2(12, { 0, 1, 2, 13, 3, 0, 4, 5, 0, 0, 0, 0 });

    return TestSystem::check(static_cast <size_t>(12), object.size()) &&
        TestSystem::check(true, object == object2);
}

bool test14_2_check_insert_with_reserve() {
    TVector<int> object(10);
    object[1] = 1;
    object[3] = 2;
    object[4] = 4;
    object[6] = 5;

    object.insert(3, 10);
    object.insert(3, 11);
    object.insert(1, 12);
    object.insert(7, 13);
    object.insert(0, 14);

    TVector<int> object2(15, { 14, 0, 12, 1, 0, 11, 10, 2, 13, 4, 0, 5, 0, 0, 0 });

    return TestSystem::check(static_cast <size_t>(15), object.size()) &&
        TestSystem::check(static_cast <size_t>(30), object.capacity()) &&
        TestSystem::check(true, object == object2);
}

bool test14_3_check_insert() {
    TVector<int> object(10, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });
    object.insert(3, { 11, 12, 13 });

    TVector<int> object2(13, { 1, 2, 3, 11, 12, 13, 4, 5, 6, 7, 8, 9, 10 });

    return TestSystem::check(static_cast <size_t>(15), object.capacity()) &&
        TestSystem::check(true, object == object2);
}

bool test14_4_check_insert() {
    TVector<int> object(10, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });

    object.insert(0, { 11, 12, 13 });
    object.insert(7, { 21, 22, 23 });
    object.insert(16, { 31, 32, 33 });

    TVector<int> object2(19, { 11, 12, 13, 1, 2, 3, 4, 21, 22, 23, 5, 6, 7, 8, 9, 10, 31, 32, 33 });

    return TestSystem::check(static_cast <size_t>(30), object.capacity()) &&
        TestSystem::check(true, object == object2);
}

bool test14_5_try_throw_insert() {
    bool expected_result = false;
    bool actual_result = true;

    TVector<int> object(10, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });
    try {
        object.insert(11, 11);
    }
    catch (const std::exception& ex) {
        //std::cerr << ex.what();
        actual_result = false;
    }

    return TestSystem::check(expected_result, actual_result);
}

bool test14_6_check_insert() {
    TVector<int> object(10, { 6, 2, 3, 4, 5, 6, 7, 8, 5, 6 });
    object.insert(2, 4, 99);

    TVector<int> object2(14, { 6, 2, 99, 99, 99, 99, 3, 4, 5, 6, 7, 8, 5, 6 });
    return TestSystem::check(static_cast<size_t>(15), object.capacity()) &&
        TestSystem::check(static_cast<size_t>(14), object.size()) &&
        TestSystem::check(true, object == object2);
}

bool test15_check_compare_operator() {
    TVector<int> object(10, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });
    TVector<int> object2(12, { 1, 2, 3, 4, 21, 5, 6, 7, 8, 9, 10, 31 });
    object2.pop_back();
    object2.erase(4);

    return TestSystem::check(true, object == object2);
}

bool test15_2_check_compare_operator() {
    TVector<int> object(10, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });
    TVector<int> object2(12, { 1, 2, 3, 4, 21, 5, 6, 7, 8, 9, 10, 31 });

    return TestSystem::check(false, object == object2);
}

bool test15_3_check_compare_operator() {
    TVector<int> object(10, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });
    TVector<int> object2(12, { 1, 2, 3, 4, 21, 5, 6, 7, 8, 9, 10, 31 });

    return TestSystem::check(true, object != object2);
}

bool test15_4_check_compare_operator() {
    TVector<int> object(10, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });
    TVector<int> object2(12, { 1, 2, 3, 4, 21, 5, 6, 7, 8, 9, 10, 31 });
    object2.pop_back();
    object2.erase(4);

    return TestSystem::check(false, object != object2);
}

bool test16_check_at() {
    TVector<int> object(10, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });

    object.erase(2);
    object.erase(5);
    object.erase(6);

    return TestSystem::check(1, object.at(0)) &&
        TestSystem::check(2, object.at(1)) &&
        TestSystem::check(4, object.at(2)) &&
        TestSystem::check(5, object.at(3)) &&
        TestSystem::check(6, object.at(4)) &&
        TestSystem::check(8, object.at(5)) &&
        TestSystem::check(10, object.at(6)) &&
        TestSystem::check(static_cast <size_t>(8), object.size());
}

bool test16_2_check_at_with_deleted() {
    TVector<int> object(10, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });

    object.pop_front();
    object.erase(1);
    object.erase(4);
    object.erase(6);
    object.pop_back();

    return TestSystem::check(2, object.at(0)) &&
        TestSystem::check(4, object.at(1)) &&
        TestSystem::check(5, object.at(2)) &&
        TestSystem::check(6, object.at(3)) &&
        TestSystem::check(8, object.at(4));
}

bool test_17_check_the_assignment_operator() {
    TVector<int> object(10, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });
    TVector<int> object2;
    object2 = object;

    return TestSystem::check(true, object == object2);
}

bool test18_check_find() {
    TVector<int> object(10, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });

    object.pop_front();
    object.erase(1);
    object.erase(4);
    object.erase(6);
    object.pop_back();

    return TestSystem::check(0, find_first_elem(object, 2)) &&
        TestSystem::check(1, find_first_elem(object, 4)) &&
        TestSystem::check(2, find_first_elem(object, 5)) &&
        TestSystem::check(3, find_first_elem(object, 6)) &&
        TestSystem::check(4, find_first_elem(object, 8));
}

bool test18_2_check_find() {
    TVector<int> object(15, { 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 });

    object.pop_front();
    object.erase(1);
    object.erase(4);
    object.erase(6);
    object.pop_back();

    /*
    std::cout << find_last_elem(object, 1) << " " << find_last_elem(object, 2) << " " <<
        find_last_elem(object, 3) << " " << find_last_elem(object, 4) << " " <<
        find_last_elem(object, 5) << std::endl;

    std::cout << object[6] << " " << object[7] << " " << object[8] << " " << object[9] << " " << object[2] << std::endl;
    */
    return TestSystem::check(6, find_last_elem(object, 1)) &&
        TestSystem::check(7, find_last_elem(object, 2)) &&
        TestSystem::check(8, find_last_elem(object, 3)) &&
        TestSystem::check(9, find_last_elem(object, 4)) &&
        TestSystem::check(2, find_last_elem(object, 5));
}

bool test18_3_check_find() {
    bool expected_result = true;
    bool actual_result = true;

    TVector<int> object(15, { 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 });

    object.pop_front();
    object.erase(1);
    object.erase(4);
    object.erase(6);
    object.pop_back();

    size_t size_1 = find_elem(object, 2)[0];
    int expected_1[3] = { 2, 3, 6 };
    int expected_2[3] = { 2, 0, 7 };

    for (size_t i = 0; i < size_1 + 1; i++) {
        if (expected_2[i] != find_elem(object, 2)[i] || expected_1[i] != find_elem(object, 1)[i])
            actual_result = false;
    }

    size_t size_4 = find_elem(object, 4)[0];
    int expected_4[4] = { 3, 1, 5, 9 };

    for (size_t i = 0; i < size_4 + 1; i++) {
        if (expected_4[i] != find_elem(object, 4)[i])
            actual_result = false;
    }

    return TestSystem::check(expected_result, actual_result);
}

bool test18_4_check_find() {
    TVector<int> object(10, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });

    int pos1 = find_first_elem(object, 55);
    int pos2 = find_last_elem(object, 55);
    
    return TestSystem::check(-1, pos1) &&
        TestSystem::check(-1, pos2);
}

bool test18_5_check_find() {
    TVector<int> object(10, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });

    size_t size = find_elem(object, 55)[0];

    return TestSystem::check(static_cast <size_t>(0), size);
}

bool test_19_check_find_by_pointer() {
    TVector<int> object(9, { 1, 2, 5, 4, 5, 3, 6, 7, 9 });
    int* ptr = find_first_elem_by_pointer(object, 5);

    return TestSystem::check(&object[2], ptr) &&
        TestSystem::check(5, *ptr);
}

bool test_19_2_check_find_by_pointer() {
    TVector<int> object(10, { 1, 2, 5, 4, 5, 3, 6, 7, 5, 9 });
    TVector<int*> ptr = find_elem_by_pointer(object, 55);

    return TestSystem::check(static_cast <size_t>(0), ptr.size());
}

bool test_19_3_check_find_by_pointer() {
    TVector<int> object(10, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });
    object.erase(3);
    object.pop_front();
    object.pop_back();
    object.erase(3);

    int* ptr = find_first_elem_by_pointer(object, 7);
    return TestSystem::check(&object[3], ptr) &&
        TestSystem::check(7, *ptr);
}

bool test_20_check_shrink_to_fit() {
    TVector<int> object(10, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });
    object.shrink_to_fit();
    TVector<int> object2(10, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });

    return TestSystem::check(static_cast<size_t>(10), object.size()) &&
        TestSystem::check(static_cast<size_t>(10), object.capacity()) &&
        TestSystem::check(true, object == object2);
}

int main() {
    TestSystem::start_test(test1_try_create_default_object, "TVector.test1_try_create_default_object");
    TestSystem::start_test(test2_try_create_with_default_object, "TVector.test2_try_create_with_default_object");
    TestSystem::start_test(test3_check_create_object_with_initialization, "TVector.test3_check_create_object_with_initialization");
    TestSystem::start_test(test4_try_create_object, "TVector.test4_try_create_object");
    TestSystem::start_test(test4_2_check_create_object, "TVector.test4_2_check_create_object");
    TestSystem::start_test(test4_2_2_check_create_object, "TVector.test4_2_2_check_create_object");
    TestSystem::start_test(test4_2_3_check_create_object, "TVector.test4_2_3_check_create_object");
    TestSystem::start_test(test4_3_check_create_object_with_copy, "TVector.test4_3_check_create_object_with_copy");
    TestSystem::start_test(test5_check_assign_operator, "TVector.test5_check_assign_operator");
    TestSystem::start_test(test6_check_indexing_operator, "TVector.test6_check_indexing_operator");
    TestSystem::start_test(test6_2_check_indexing_operator, "TVector.test6_2_check_indexing_operator");
    TestSystem::start_test(test6_3_check_const_indexing_operator, "TVector.test6_3_check_const_indexing_operator");
    TestSystem::start_test(test_7_check_reserve, "TVector.test_7_check_reserve");
    TestSystem::start_test(test_7_2_check_reserve, "TVector.test_7_2_check_reserve");
    TestSystem::start_test(test_7_3_check_resize, "TVector.test_7_3_check_resize");
    TestSystem::start_test(test_7_4_check_resize, "TVector.test_7_4_check_resize");
    TestSystem::start_test(test_7_5_check_resize, "TVector.test_7_5_check_resize");
    TestSystem::start_test(test_7_6_check_resize, "TVector.test_7_6_check_resize");
    TestSystem::start_test(test8_check_pop_front, "TVector.test8_check_pop_front");
    TestSystem::start_test(test8_2_check_pop_front_with_resize, "TVector.test8_2_check_pop_front_with_resize");
    TestSystem::start_test(test9_check_pop_back, "TVector.test9_check_pop_back");
    TestSystem::start_test(test9_2_check_pop_back_with_resize, "TVector.test9_2_check_pop_back_with_resize");
    TestSystem::start_test(test10_check_erase, "TVector.test10_check_erase");
    TestSystem::start_test(test10_2_check_erase_with_resize, "TVector.test10_2_check_erase_with_resize");
    TestSystem::start_test(test10_3_check_erase_last_elem, "TVector.test10_3_check_erase_last_elem");
    TestSystem::start_test(test11_check_resize_with_lowest_size, "TVector.test11_check_resize_with_lowest_size");
    TestSystem::start_test(test11_2_check_resize_with_largest_size, "TVector.test11_2_check_resize_with_largest_size");
    TestSystem::start_test(test12_check_push_back, "TVector.test12_check_push_back");
    TestSystem::start_test(test12_2_check_push_back, "TVector.test12_2_check_push_back");
    TestSystem::start_test(test12_3_check_push_back, "TVector.test12_3_check_push_back");
    TestSystem::start_test(test13_check_push_front, "TVector.test13_check_push_front");
    TestSystem::start_test(test13_2_check_push_front_with_increasing_capacity, "TVector.test13_2_check_push_front_with_increasing_capacity");
    TestSystem::start_test(test13_3_check_push_front_in_empty_vector, "TVector.test13_3_check_push_front_in_empty_vector");

    TestSystem::start_test(test14_check_insert, "TVector.test14_check_insert");
    TestSystem::start_test(test14_2_check_insert_with_reserve, "TVector.test14_2_check_insert_with_reserve");
    TestSystem::start_test(test14_3_check_insert, "TVector.test14_3_check_insert");
    TestSystem::start_test(test14_4_check_insert, "TVector.test14_4_check_insert");
    TestSystem::start_test(test14_5_try_throw_insert, "TVector.test14_5_try_throw_insert");
    TestSystem::start_test(test14_6_check_insert, "TVector.test14_6_check_insert");
    TestSystem::start_test(test15_check_compare_operator, "TVector.test15_check_compare_operator");
    TestSystem::start_test(test15_2_check_compare_operator, "TVector.test15_2_check_compare_operator");
    TestSystem::start_test(test15_3_check_compare_operator, "TVector.test15_3_check_compare_operator");
    TestSystem::start_test(test15_4_check_compare_operator, "TVector.test15_4_check_compare_operator");
    TestSystem::start_test(test16_check_at, "TVector.test16_check_at");
    TestSystem::start_test(test16_2_check_at_with_deleted, "TVector.test16_2_check_at_with_deleted");
    TestSystem::start_test(test_17_check_the_assignment_operator, "TVector.test_17_check_the_assignment_operator");
    TestSystem::start_test(test18_check_find, "TVector.test18_check_find");
    TestSystem::start_test(test18_2_check_find, "TVector.test18_2_check_find");
    TestSystem::start_test(test18_3_check_find, "TVector.test18_3_check_find");
    TestSystem::start_test(test18_4_check_find, "TVector.test18_4_check_find");
    TestSystem::start_test(test18_5_check_find, "TVector.test18_5_check_find");
    TestSystem::start_test(test_19_check_find_by_pointer, "TVector.test_19_check_find_by_pointer");
    TestSystem::start_test(test_19_2_check_find_by_pointer, "TVector.test_19_2_check_find_by_pointer");
    TestSystem::start_test(test_19_3_check_find_by_pointer, "TVector.test_19_3_check_find_by_pointer");
    TestSystem::start_test(test_20_check_shrink_to_fit, "TVector.test_20_check_shrink_to_fit");

    TestSystem::print_final_info();
    system("pause");
	return 0;
}