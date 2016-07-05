#pragma once
#include "stdafx.h"
bool Lexical_Check(Lexem_Arr& main_vec);
void Keywords_Recognize(lexem& str);

//Состояния обрабатывающего автомата лексического блока
enum lexem_status
{
	BEGIN,KEYWORD_WHILE,SPACE1,ID1,SPACE2,KEYWORD_DO,SPACE3,ID2,SPACE4,COLON,EQUALLY,ID3, SPACE5,SQUOP,SIGN,NUMBER,SPACE6,SQUCL,SEMICOLON
};

const int key_table_size = 75;
//Отсортированный массив ключевых слов языка Паскаль
const string Pascal_Keywords[key_table_size] = {
	"absolute","and","array","as","asm","begin",
	"case","class","const","constructor",
	"destructor","dispinterface","dispose","div","do","downto",
	"else","end","except","exit","exports",
	"false","file","finalization","finally","for","function","goto",
	"if","implementation","in","inherited","initialization","inline","interface","is",
	"label","library","mod","new","nil","not",
	"object","of","on","operator","or","out",
	"packed","procedure","program","property",
	"raise","record","reintroduce","repeat","resourcestring",
	"self","set","shl","shr","string",
	"then","threadvar","to","true","try","type",
	"unit","until","uses","var","while","with","xor"
};