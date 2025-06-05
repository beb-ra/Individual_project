//  Copyright 2025 Guseva Olga

#include "C:/Users/Lelya/cc++/Individual_project/Library/FIO/fio.h"
#include <iostream>

void copy_string(char** new_str, const char* copied_str) {
	if (*new_str != nullptr) {
		delete[] * new_str;
		*new_str = nullptr;
	}
	if (copied_str == nullptr)
		return;

	int str_len = len(copied_str);

	*new_str = new char[str_len + 1];

	// ����������� ������
	int i = 0;
	for (; copied_str[i] != '\0'; i++) {
		(*new_str)[i] = copied_str[i];
	}
	(*new_str)[i] = '\0';
}

int len(const char* str) {
	int i = 0;
	for (; str[i] != '\0'; i++) {}
	return i;
}

bool FIO::is_correct_name(const char* name) {
	if (name == nullptr)
		return true;

	int str_len = len(name);

	for (int i = 1; i < str_len; i++) {
		if (!(name[0] >= 'A' && name[0] <= 'Z' || name[0] >= '�' && name[0] <= '�' || name[0] == '�' ||
			name[i] >= 'a' && name[i] <= 'z' || name[i] >= '�' && name[i] <= '�' || name[0] == '�'))
			return false;
	}
	return true;
}

/*
void FIO::input_fio(char* fn, char* sn, char* ln) {
	char* first_name = new char[FIELD_SIZE],
		* second_name = new char[FIELD_SIZE],
		* last_name = new char[FIELD_SIZE];

	// ���� �������
	while (true) {
		std::cout << "������� ������� (��� ��������): ";
		std::cin >> last_name;

		if (is_correct_name(last_name)) {
			(*this).set_last_name(last_name);
			break;
		}
	}

	// ���� �����
	while (true) {
		std::cout << "������� ��� (��� ��������): ";
		std::cin >> first_name;

		if (is_correct_name(first_name)) {
			(*this).set_first_name(first_name);
			break;
		}
	}

	// ���� ��������
	while (true) {
		std::cout << "������� �������� (��� ��������): ";
		std::cin >> second_name;

		if (is_correct_name(second_name)) {
			(*this).set_second_name(second_name);
			break;
		}
	}

	delete[] first_name;
	delete[] second_name;
	delete[] last_name;
	first_name = nullptr;
	second_name = nullptr;
	last_name = nullptr;
} */
void FIO::convert_to_normal_form(char* str) {
	int str_len = len(str);

	if (str[0] >= 'a' && str[0] <= 'z' || str[0] >= '�' && str[0] <= '�')
		str[0] -= 32;
	else if (str[0] == '�')
		str[0] = '�';

	for (int i = 1; i < str_len; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z' || str[i] >= '�' && str[i] <= '�')
			str[i] += 32;

		else if (str[i] == '�')
			str[i] = '�';
	}
}

FIO::FIO() : _first_name(nullptr), _second_name(nullptr), _last_name(nullptr) {
	copy_string(&_first_name, "Default_name");
	copy_string(&_second_name, "Default_name");
	copy_string(&_last_name, "Default_name");
}

FIO::FIO(char* fn, char* sn, char* ln) : _first_name(nullptr), _second_name(nullptr), _last_name(nullptr) {
	if (is_correct_name(fn)) {
		copy_string(&_first_name, fn);
	}
	else {
		copy_string(&_first_name, "Default_name");
		throw std::logic_error("������������ ���\n");
	}

	if (is_correct_name(sn)) {
		copy_string(&_second_name, sn);
	}
	else {
		copy_string(&_second_name, "Default_name");
		throw std::logic_error("������������ ��������\n");
	}

	if (is_correct_name(ln)) {
		copy_string(&_last_name, ln);
	}
	else {
		copy_string(&_last_name, "Default_name");
		throw std::logic_error("������������ �������\n");
	}
}

FIO::FIO(const char* fn, const char* sn, const char* ln) : _first_name(nullptr), _second_name(nullptr), _last_name(nullptr) {
	if (is_correct_name(fn)) {
		copy_string(&_first_name, fn);
	}
	else {
		copy_string(&_first_name, "Default_name");
		throw std::logic_error("������������ ���\n");
	}

	if (is_correct_name(sn)) {
		copy_string(&_second_name, sn);
	}
	else {
		copy_string(&_second_name, "Default_name");
		throw std::logic_error("������������ ��������\n");
	}

	if (is_correct_name(ln)) {
		copy_string(&_last_name, ln);
	}
	else {
		copy_string(&_last_name, "Default_name");
		throw std::logic_error("������������ �������\n");
	}
}

FIO::FIO(const FIO& original) : _first_name(nullptr), _second_name(nullptr), _last_name(nullptr) {
	if (&original == NULL) {
		throw std::logic_error("������ �� ������ ");
	}
	copy_string(&_first_name, original._first_name);
	copy_string(&_second_name, original._second_name);
	copy_string(&_last_name, original._last_name);
}

FIO::~FIO() {
	if (_first_name != nullptr) {
		delete[] _first_name;
		_first_name = nullptr;
	}
	if (_second_name != nullptr) {
		delete[] _second_name;
		_second_name = nullptr;
	}
	if (_last_name != nullptr) {
		delete[] _last_name;
		_last_name = nullptr;
	}
}

void FIO::set_first_name(char* fn) {
	if (is_correct_name(fn)) {
		convert_to_normal_form(fn);
		copy_string(&_first_name, fn);
	}
	else {
		throw std::logic_error("������������ ���\n");
	}
}
void FIO::set_second_name(char* sn) {
	if (is_correct_name(sn)) {
		convert_to_normal_form(sn);
		copy_string(&_second_name, sn);
	}
	else {
		throw std::logic_error("������������ ��������\n");
	}
}
void FIO::set_last_name(char* ln) {
	if (is_correct_name(ln)) {
		convert_to_normal_form(ln);
		copy_string(&_last_name, ln);
	}
	else {
		throw std::logic_error("������������ �������\n");
	}
}

const char* FIO::get_first_name() {
	return _first_name;
}
const char* FIO::get_second_name() {
	return _second_name;
}
const char* FIO::get_last_name() {
	return _last_name;
}
