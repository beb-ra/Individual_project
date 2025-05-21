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

    return TestSystem::check((const int *)nullptr, object.data()) &&
        TestSystem::check((size_t)0, object.size()) &&
        TestSystem::check((size_t)STEP_OF_CAPACITY, object.capacity()) &&
        TestSystem::check((size_t)0, object.deleted()) &&
        TestSystem::check((const State*)nullptr, object.states());
}

// создает корректно объект через первый конструктор инициализации
bool test3_check_create_object_with_initialization() {
    int size = 2;
    int* mass = new int[size];
    mass[0] = 1; mass[1] = 2;

    TVector<int> object(size, mass);

    return TestSystem::check(1, object.data()[0]) &&
        TestSystem::check(2, object.data()[1]) &&
        TestSystem::check((size_t)size, object.size()) &&
        TestSystem::check((size_t)15, object.capacity()) &&
        TestSystem::check((size_t)0, object.deleted()) &&
        TestSystem::check(State::busy, object.states()[0]) &&
        TestSystem::check(State::busy, object.states()[1]);
}

// создает корректно объект через конструктор /
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

// перегрузка присваивания
bool test5_check_assign_operator() {
    int size1 = 2;
    int* mass1 = new int[size1];
    mass1[0] = 1; mass1[1] = 2;

    TVector<int> object1(size1, mass1);

    int size2 = 1;
    int* mass2 = new int[size2];
    mass2[0] = 3;

    TVector<int> object2(size2, mass2);

    object2 = object1;

    return TestSystem::check(1, object2.data()[0]) &&
        TestSystem::check(2, object2.data()[1]) &&
        TestSystem::check((size_t)size1, object2.size()) &&
        TestSystem::check((size_t)15, object2.capacity()) &&
        TestSystem::check((size_t)0, object2.deleted()) &&
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
  
    return TestSystem::check(1, object.data()[0]) &&
        TestSystem::check(2, object.data()[1]) &&
        TestSystem::check(3, object.data()[2]) &&
        TestSystem::check(5, object.data()[4]) &&
        TestSystem::check(6, object.data()[5]);
}

bool test7_check_indexing_operator_2() {
    TVector<int> object(8);
    object[0] = 1;
    object[2] = 2;
    object[3] = 3;
    object[5] = 4;
    object[7] = 5;

    return TestSystem::check(1, object.data()[0]) &&
        TestSystem::check(2, object.data()[2]) &&
        TestSystem::check(3, object.data()[3]) &&
        TestSystem::check(4, object.data()[5]) &&
        TestSystem::check(5, object.data()[7]);
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
        TestSystem::check((size_t)15, object.size());
}

bool test8_2_check_pop_front_with_reserve() {
    TVector<int> object(10);
    object[0] = 1;
    object[2] = 2;
    object[3] = 3;
    object[5] = 4;

    object.pop_front();
    object.pop_front();

    return TestSystem::check(3, object.data()[1]) &&
        TestSystem::check(4, object.data()[3]) &&
        TestSystem::check(3, object[1]) &&
        TestSystem::check(4, object[3]) &&
        TestSystem::check((size_t)8, object.size());
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
        TestSystem::check((size_t)15, object.size());
}

bool test9_2_check_pop_back_with_reserve() {
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
        TestSystem::check((size_t)8, object.size());
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
        TestSystem::check((size_t)15, object.size());
}

bool test10_2_check_erase_with_reserve() {
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
        TestSystem::check((size_t)12, object.size());
}

bool test10_3_check_erase_last_elem() {
    TVector<int> object(10);

    object.erase(9);

    return TestSystem::check((size_t)10, object.size()) &&
        TestSystem::check(State::empty, object.states()[9]);
}

bool test11_check_resize_with_lowest_size() {
    TVector<int> object(10);

    for (size_t i = 0; i < 10; i++) {
        object[i] = i + 1;
    }

    object.resize(5);

    return TestSystem::check((size_t)5, object.size()) &&
        TestSystem::check((size_t)15, object.capacity()) &&
        TestSystem::check(State::empty, object.states()[5]);
}

bool test11_2_check_resize_with_largest_size() {
    TVector<int> object(10);

    object.resize(20);

    return TestSystem::check((size_t)20, object.size()) &&
        TestSystem::check((size_t)30, object.capacity()) &&
        TestSystem::check(State::empty, object.states()[10]) &&
        TestSystem::check(State::empty, object.states()[19]);
}

bool test12_check_push_back() {
    TVector<int> object(10);

    object.push_back(5);
    object.push_back(6);

    return TestSystem::check((size_t)12, object.size()) &&
        TestSystem::check(5, object[10]) &&
        TestSystem::check(6, object[11]);
}

bool test12_2_check_push_back() {
    TVector<int> object(5);
    object[0] = 1;
    object[2] = 2;
    object[3] = 3;
    object[4] = 4;

    object.push_back(5);

    return TestSystem::check((size_t)6, object.size()) &&
        TestSystem::check(1, object[0]) &&
        TestSystem::check(2, object[2]) &&
        TestSystem::check(3, object[3]) &&
        TestSystem::check(4, object[4]) &&
        TestSystem::check(5, object[5]);
}

bool test12_3_check_push_back() {
    TVector<int> object(10);
    object[1] = 1;
    object[2] = 2;
    object[4] = 4;
    object[5] = 5;

    object.push_back(6);
    object.push_back(7);

    return TestSystem::check((size_t)12, object.size()) &&
        TestSystem::check(1, object[1]) &&
        TestSystem::check(2, object[2]) &&
        TestSystem::check(4, object[4]) &&
        TestSystem::check(5, object[5]) &&
        TestSystem::check(6, object[10]) &&
        TestSystem::check(7, object[11]);
}

bool test13_check_push_front() {
    TVector<int> object(10);
    object[0] = 1;
    object[1] = 2;
    object[3] = 4;
    object[4] = 5;

    object.push_front(11);
    object.push_front(10);

    return TestSystem::check((size_t)12, object.size()) &&
        TestSystem::check(10, object[0]) &&
        TestSystem::check(11, object[1]) &&
        TestSystem::check(1, object[2]) &&
        TestSystem::check(2, object[3]) &&
        TestSystem::check(4, object[5]) &&
        TestSystem::check(5, object[6]);
}

bool test14_check_insert() {
    TVector<int> object(10);
    object[1] = 1;
    object[2] = 2;
    object[4] = 4;
    object[5] = 5;

    object.insert(3, 3);
    object.insert(3, 13);

    return TestSystem::check((size_t)12, object.size()) &&
        TestSystem::check(1, object[1]) &&
        TestSystem::check(2, object[2]) &&
        TestSystem::check(13, object[3]) &&
        TestSystem::check(3, object[4]) &&
        TestSystem::check(4, object[6]) &&
        TestSystem::check(5, object[7]);
}

bool test14_2_check_insert() {
    TVector<int> object(10);
    object[1] = 1;
    object[3] = 2;
    object[4] = 4;
    object[6] = 5;

    object.insert(3, 10);
    object.insert(3, 11);
    object.insert(1, 12);
    object.insert(7, 13);

    return TestSystem::check((size_t)14, object.size()) &&
        TestSystem::check(12, object[1]) &&
        TestSystem::check(1, object[2]) &&
        TestSystem::check(0, object[3]) &&
        TestSystem::check(11, object[4]) &&
        TestSystem::check(10, object[5]) &&
        TestSystem::check(2, object[6]) &&
        TestSystem::check(13, object[7]) &&
        TestSystem::check(4, object[8]) &&
        TestSystem::check(0, object[9]) &&
        TestSystem::check(5, object[10]);
}

bool test14_3_check_insert() {
    TVector<int> vec(10, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });
    vec.insert(3, { 11, 12, 13 });
    TVector<int> res(13,
        { 1, 2, 3, 11, 12, 13, 4, 5, 6, 7, 8, 9, 10 });
    bool expected_result = true;
    bool actual_result = (vec == res);
    return TestSystem::check(static_cast<size_t>(15), vec.capacity()) &&
        TestSystem::check(expected_result, actual_result);
}

bool test14_4_check_insert() {
    TVector<int> vec(10, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });
    vec.insert(0, { 11, 12, 13 });
    vec.insert(7, { 21, 22, 23 });
    vec.insert(16, { 31, 32, 33 });
    TVector<int> res(19,
        { 11, 12, 13, 1, 2, 3, 4, 21, 22, 23, 5, 6, 7, 8, 9, 10, 31, 32, 33 });
    bool expected_result = true;
    bool actual_result = (vec == res);
    return TestSystem::check(static_cast<size_t>(30), vec.capacity()) &&
        TestSystem::check(expected_result, actual_result);
}

bool test14_5_try_throw_insert() {
    bool expected_result = false;
    bool actual_result = true;

    TVector<int> vec(10, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });
    try {
        vec.insert(11, 11);
    }
    catch (const std::exception& ex) {
        //std::cerr << ex.what();
        actual_result = false;
    }

    return TestSystem::check(expected_result, actual_result);
}

bool test15_check_compare_operator() {
    bool expected_result = true;
    TVector<int> vec(10, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });
    TVector<int> res(12,
        { 1, 2, 3, 4, 21, 5, 6, 7, 8, 9, 10, 31 });
    res.pop_back();
    res.erase(4);
    bool actual_result = (vec == res);
    return TestSystem::check(expected_result, actual_result);
}

bool test15_2_check_compare_operator() {
    bool expected_result = true;
    TVector<int> vec(10, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });
    TVector<int> res(12,
        { 1, 2, 3, 4, 21, 5, 6, 7, 8, 9, 10, 31 });
    bool actual_result = (vec != res);
    return TestSystem::check(expected_result, actual_result);
}

int main() {
    TestSystem::start_test(test1_try_create_default_object, "TVector.test1_try_create_default_object");
    TestSystem::start_test(test2_try_create_with_default_object, "TVector.test2_try_create_with_default_object");
    TestSystem::start_test(test3_check_create_object_with_initialization, "TVector.test3_check_create_object_with_initialization");
    TestSystem::start_test(test4_try_create_object, "TVector.test4_try_create_object");
    TestSystem::start_test(test5_check_assign_operator, "TVector.test5_check_assign_operator");
    TestSystem::start_test(test6_check_indexing_operator, "TVector.test6_check_indexing_operator");
    TestSystem::start_test(test7_check_indexing_operator_2, "TVector.test7_check_indexing_operator_2");
    TestSystem::start_test(test8_check_pop_front, "TVector.test8_check_pop_front");
    TestSystem::start_test(test8_2_check_pop_front_with_reserve, "TVector.test8_2_check_pop_front_with_reserve");
    TestSystem::start_test(test9_check_pop_back, "TVector.test9_check_pop_back");
    TestSystem::start_test(test9_2_check_pop_back_with_reserve, "TVector.test9_2_check_pop_back_with_reserve");
    TestSystem::start_test(test10_check_erase, "TVector.test10_check_erase");
    TestSystem::start_test(test10_2_check_erase_with_reserve, "TVector.test10_2_check_erase_with_reserve");
    TestSystem::start_test(test10_3_check_erase_last_elem, "TVector.test10_3_check_erase_last_elem");
    TestSystem::start_test(test11_check_resize_with_lowest_size, "TVector.test11_check_resize_with_lowest_size");
    TestSystem::start_test(test11_2_check_resize_with_largest_size, "TVector.test11_2_check_resize_with_largest_size");
    TestSystem::start_test(test12_check_push_back, "TVector.test12_check_push_back");
    TestSystem::start_test(test12_2_check_push_back, "TVector.test12_2_check_push_back");
    TestSystem::start_test(test12_3_check_push_back, "TVector.test12_3_check_push_back");
    TestSystem::start_test(test13_check_push_front, "TVector.test13_check_push_front");
    TestSystem::start_test(test14_check_insert, "TVector.test14_check_insert");
    TestSystem::start_test(test14_2_check_insert, "TVector.test14_2_check_insert");
    TestSystem::start_test(test14_3_check_insert, "TVector.test14_3_check_insert");
    TestSystem::start_test(test14_4_check_insert, "TVector.test14_4_check_insert");
    TestSystem::start_test(test14_5_try_throw_insert, "TVector.test14_5_try_throw_insert");
    TestSystem::start_test(test15_check_compare_operator, "TVector.test15_check_compare_operator");
    TestSystem::start_test(test15_2_check_compare_operator, "TVector.test15_2_check_compare_operator");


    TestSystem::print_final_info();
    system("pause");
	return 0;
}