#pragma once
#include "stdafx.h"

bool Transliteration(string input_string, Lexem_Arr& main_vec);
void Str_Tolower(string &str);
void Fragmentation_Str(string inputString, Lexem_Arr& main_vec);
bool Assign_Class(Lexem_Arr& main_vec);


const int table_size = 44;

//Список всех допустимых заданием символов и их типов
const string Transliteration_Table[table_size][2] = {
	{ "a", "letter" },{ "b", "letter" },{ "c", "letter" },{ "d", "letter" },
	{ "e", "letter" },{ "f", "letter" },{ "g", "letter" },{ "h", "letter" },
	{ "i", "letter" },{ "j", "letter" },{ "k", "letter" },{ "l", "letter" },
	{ "m", "letter" },{ "n", "letter" },{ "o", "letter" },{ "p", "letter" },
	{ "q", "letter" },{ "r", "letter" },{ "s", "letter" },{ "t", "letter" },
	{ "u", "letter" },{ "v", "letter" },{ "w", "letter" },{ "x", "letter" },
	{ "y", "letter" },{ "z", "letter" },{ "0", "digit" },{ "1", "digit" },
	{ "2", "digit" },{ "3", "digit" },{ "4", "digit" },{ "5", "digit" },
	{ "6", "digit" },{ "7", "digit" },{ "8", "digit" },{ "9", "digit" },
	{ "+", "sign" },{ "-", "sign" },{ ";", "semicolon" },{ " ", "space" },
	{ "[", "squareop" },{ "]", "squarecl" },{ "=", "equally" },{ ":", "colon" }
};