#include "Syntax_Block.h"

#define cur_lexem main_vec[cur_lexem_num].type //Рассматриваемый тип элемента исходного вектора
#define next cur_lexem_num++   //Переход к следующему элементу

bool Syntax_Check(Lexem_Arr main_vec)
{
	int status = _BEGIN;          //Текущий статус обрабатывающего автомата
	int cur_lexem_num = 0;       //Номер текущей лексемы из main_vec
	bool Is_Operating = true;   //Работает ли автомат

	while (Is_Operating) {
		switch (status) {  //Автомат реализован через switch-case,принцип работы описан в разделе 3.2.3 отчета
		case _BEGIN: {
			if (cur_lexem == "KEYWORD_while") {
				status = _KEYWORD_WHILE;
			}
			else {
				cout << "Syntax error at status BEGIN" << endl;
				return false;
			}
		}break;

		case _KEYWORD_WHILE: {
			if (cur_lexem == "KEYWORD_while") {
				status = _ID1;
				next;
			}
			else {
				cout << "Syntax error at status KEYWORD_WHILE" << endl;
				return false;
			}
		}break;

		case _ID1: {
			if (cur_lexem == "ID") {
				status = _KEYWORD_DO;
				next;
			}
			else {
				cout << "Syntax error at status ID1" << endl;
				return false;
			}
		}break;

		case _KEYWORD_DO: {
			if (cur_lexem == "KEYWORD_do") {
				status = _ID2;
				next;
			}
			else {
				cout << "Syntax error at status KEYWORD_DO" << endl;
				return false;
			}
		}break;

		case _ID2: {
			if (cur_lexem == "ID") {
				status = _COLON;
				next;
			}
			else {
				cout << "Syntax error at status ID2" << endl;
				return false;
			}
		}break;

		case _COLON: {
			if (cur_lexem == "COLON") {
				status = _EQUALLY;
				next;
			}
			else {
				cout << "Syntax error at status COLON" << endl;
				return false;
			}
		}break;

		case _EQUALLY: {
			if (cur_lexem == "EQUALLY") {
				status = _ID3;
				next;
			}
			else {
				cout << "Syntax error at status EQUALLY" << endl;
				return false;
			}
		}break;

		case _ID3: {
			if (cur_lexem == "ID") {
				status = _SQUOP;
				next;
			}
			else {
				cout << "Syntax error at status ID3" << endl;
				return false;
			}
		}break;

		case _SQUOP: {
			if (cur_lexem == "SQUAREOP") {
				status = _SIGN;
				next;
			}
			else if (cur_lexem == "SEMICOLON") {
				status = _SEMICOLON;
			}
			else {
				cout << "Syntax error at status SQUOP" << endl;
				return false;
			}
		}break;

		case _SIGN: {
			if (cur_lexem == "SIGN") {
				status = _NUMBER;
				next;
			}
			else if (cur_lexem == "NUMBER") {
				status = _NUMBER;
			}
			else {
				cout << "Syntax error at status SIGN" << endl;
				return false;
			}
		}break;

		case _NUMBER: {
			if (cur_lexem == "NUMBER") {
				status = _SQUCL;
				next;
			}
			else {
				cout << "Syntax error at status NUMBER" << endl;
				return false;
			}
		}break;

		case _SQUCL: {
			if (cur_lexem == "SQUARECL") {
				status = _SEMICOLON;
				next;
			}
			else {
				cout << "Syntax error at status SQUCL" << endl;
				return false;
			}
		}break;

		case _SEMICOLON: {
			if (cur_lexem == "SEMICOLON") {
				Is_Operating = false;
			}
			else {
				cout << "Syntax error at status SEMICOLON" << endl;
				return false;
			}
		}break;
		}
	}
	return true;
}
