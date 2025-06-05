//  Copyright 2025 Guseva Olga

#pragma once

#ifndef FIO_FIO_H_
#define FIO_FIO_H_

#define FIELD_SIZE 20
#define LAST_NAME 1
#define FIRST_NAME 2
#define SECOND_NAME 3

class FIO {
	//private
	char* _first_name;
	char* _second_name;
	char* _last_name;
public:
	FIO();
	FIO(const char* fn, const char* sn, const char* ln);
	FIO(char* fn, char* sn, char* ln);
	FIO(const FIO&);
	~FIO();

	void set_first_name(char*);
	void set_second_name(char*);
	void set_last_name(char*);

	const char* get_first_name();
	const char* get_second_name();
	const char* get_last_name();

	bool is_correct_name(const char*);
	void convert_to_normal_form(char* str);
};
void copy_string(char** new_str, const char* copied_str);
int len(const char* str);

#endif  // FIO_FIO_H_
