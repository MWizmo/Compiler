#include "Lexical_Block.h"

#define cur_symbol main_vec[cur_symbol_num].type //Тип рассматриваемого элемента исходного вектора
#define next cur_symbol_num++   //Переход к следующему символу
#define create new_lexem.title = main_vec[cur_symbol_num].title;  //Создание новой лексемы в векторе new_lexem_arr
#define process new_lexem_arr[cur_lexem_num].title.insert(new_lexem_arr[cur_lexem_num].title.size(), main_vec[cur_symbol_num].title);  //Добавление текущего символа из main_vec к текущей лексеме из new_lexem_arr
#define save  cur_lexem_num++  //Закончить обработку текущей лексемы
#define check_id  Keywords_Recognize(new_lexem_arr[cur_lexem_num - 1]); //Проверка,совпадает ли id с одним из ключевых слов языка Паскаль


bool Lexical_Check(Lexem_Arr & main_vec)
{
	Lexem_Arr new_lexem_arr;   //Вектор лексем
	int status = BEGIN;       //Текущее состояние обрабатывающего автомата
	lexem new_lexem;
	int cur_lexem_num = 0;        //Номер текущей лексемы из new_lexem_arr
	int cur_symbol_num = 0;      //Номер текущего символа из main_vec
	bool Is_Operating = true;   //Работает ли автомат
	while (Is_Operating) {
		switch (status) {              //Автомат реализован через switch-case,принцип работы описан в разделе
		case BEGIN: {                                    //3.2.2 отчета
			if (cur_symbol == "space")
				next;
			else if (cur_symbol == "letter") {
				create;
				new_lexem.type = "ID";
				new_lexem_arr.push_back(new_lexem);
				status = KEYWORD_WHILE;
				next;
			}
			else { 
				cout << "Lexical error at status BEGIN" << endl;
				return false; 
			}
		} break;

		case KEYWORD_WHILE: {
			if (cur_symbol == "letter") {
				process;
				status = KEYWORD_WHILE;
				next;
			}
			else if (cur_symbol == "space") {
				save;
				check_id;
				status = SPACE1;
				next;
			}
			else {
				cout << "Lexical error at status KEYWORD_WHILE" << endl;
				return false;
			}
		} break;

		case SPACE1: {
			if (cur_symbol == "space")
				next;
			else if (cur_symbol == "letter") {
				create;
				new_lexem.type = "ID";
				new_lexem_arr.push_back(new_lexem);
				status = ID1;
				next;
			}
			else {
				cout << "Lexical error at status SPACE1" << endl;
				return false;
			}
		}break;

		case ID1: {
			if (cur_symbol == "letter") {
				process;
				status = ID1;
				next;
			}
			else if (cur_symbol == "digit") {
				process;
				status = ID1;
				next;
			}
			else if (cur_symbol == "space") {
				save;
				check_id;
				if ((new_lexem_arr[cur_lexem_num - 1].type == "KEYWORD_true") || (new_lexem_arr[cur_lexem_num - 1].type == "KEYWORD_false")) new_lexem_arr[cur_lexem_num - 1].type = "ID"; //KEYWORD_while можно                                                                             заменить на
				status = SPACE2;                                                     //ID, так как это не влияет на 
				next;                                                               //правильность цепочки
			}
			else {
				cout << "Lexical error at status ID1" << endl;
				return false;
			}
		}break;

		case SPACE2: {
			if (cur_symbol == "space")
				next;
			else if (cur_symbol == "letter") {
				create;
				new_lexem.type = "ID";
				new_lexem_arr.push_back(new_lexem);
				status = KEYWORD_DO;
				next;
			}
			else {
				cout << "Lexical error at status SPACE2" << endl;
				return false;
			}
		}break;

		case KEYWORD_DO: {
			if (cur_symbol == "letter") {
				process;
				status = KEYWORD_DO;
				next;
			}
			else if (cur_symbol == "space") {
				save;
				check_id;
				status = SPACE3;
				next;
			}
			else {
				cout << "Lexical error at status KEYWORD_DO" << endl;
				return false;
			}
		}break;

		case SPACE3: {
			if (cur_symbol == "space")
				next;
			else if (cur_symbol == "letter") {
				create;
				new_lexem.type = "ID";
				new_lexem_arr.push_back(new_lexem);
				status = ID2;
				next;
			}
			else {
				cout << "Lexical error at status SPACE3" << endl;
				return false;
			}
		}break;

		case ID2: {
			if (cur_symbol == "letter") {
				process;
				status = ID2;
				next;
			}
			else if (cur_symbol == "digit") {
				process;
				status = ID2;
				next;
			}
			else if (cur_symbol == "space") {
				save;
				check_id;
				status = SPACE4;
				next;
			}
			else if (cur_symbol == "colon") {
				save;
				check_id;
				create;
				new_lexem.type = "COLON";
				new_lexem_arr.push_back(new_lexem);
				status = COLON;
				next;
			}
			else {
				cout << "Lexical error at status ID2" << endl;
				return false;
			}
		}break;

		case  SPACE4: {
			if (cur_symbol == "space")
				next;
			else if (cur_symbol == "colon") {
				create;
				new_lexem.type = "COLON";
				new_lexem_arr.push_back(new_lexem);
				status = COLON;
				next;
			}
			else {
				cout << "Lexical error at status SPACE4" << endl;
				return false;
			}
		}break;

		case COLON: {
			if (cur_symbol == "equally") {
				save;
				create;
				new_lexem.type = "EQUALLY";
				new_lexem_arr.push_back(new_lexem);
				status = EQUALLY;
				next;
			}
			else {
				cout << "Lexical error at status COLON" << endl;
				return false;
			}
		}break;

		case EQUALLY: {
			if (cur_symbol == "space")
				next;
			else if (cur_symbol == "letter") {
				save;
				create;
				new_lexem.type = "ID";
				new_lexem_arr.push_back(new_lexem);
				status = ID3;
				next;
			}
			else {
				cout << "Lexical error at status EQUALLY" << endl;
				return false;
			}
		}break;

		case ID3: {
			if (cur_symbol == "letter") {
				process;
				status = ID3;
				next;
			}
			else if (cur_symbol == "digit") {
				process;
				status = ID3;
				next;
			}
			else if (cur_symbol == "space") {
				save;
				check_id;
				status = SPACE5;
				next;
			}
			else if (cur_symbol == "squareop") {
				save;
				check_id;
				create;
				new_lexem.type = "SQUAREOP";
				new_lexem_arr.push_back(new_lexem);
				status = SQUOP;
				next;
			}
			else if (cur_symbol == "semicolon") {
				save;
				check_id;
				create;
				new_lexem.type = "SEMICOLON";
				new_lexem_arr.push_back(new_lexem);
				status = SEMICOLON;
				next;
			}
			else {
				cout << "Lexical error at status ID3" << endl;
				return false;
			}
		}break;

		case SPACE5: {
			if (cur_symbol == "space")
				next;
			else if (cur_symbol == "squareop") {
				create;
				new_lexem.type = "SQUAREOP";
				new_lexem_arr.push_back(new_lexem);
				status = SQUOP;
				next;
			}
			else {
				cout << "Lexical error at status SPACE5" << endl;
				return false;
			}
		}break;

		case SQUOP: {
			if (cur_symbol == "space")
				next;
			else if (cur_symbol == "sign") {
				save;
				create;
				new_lexem.type = "SIGN";
				new_lexem_arr.push_back(new_lexem);
				status = SIGN;
				next;
			}
			else if (cur_symbol == "digit") {
				save;
				create;
				new_lexem.type = "NUMBER";
				new_lexem_arr.push_back(new_lexem);
				status = NUMBER;
				next;
			}
			else {
				cout << "Lexical error at status SQUOP" << endl;
				return false;
			}
		}break;

		case SIGN: {
			if (cur_symbol == "space")
				next;
			else if (cur_symbol == "digit") {
				save;
				create;
				new_lexem.type = "NUMBER";
				new_lexem_arr.push_back(new_lexem);
				status = NUMBER;
				next;
			}
			else {
				cout << "Lexical error at status SIGN" << endl;
				return false;
			}
		}break;

		case NUMBER:{
			if (cur_symbol == "space") {
				status = SPACE6;
				next;
			}
			else if (cur_symbol == "digit") {
				process;
				status = NUMBER;
				next;
			}
			else if (cur_symbol == "squarecl") {
				save;
				create;
				new_lexem.type = "SQUARECL";
				new_lexem_arr.push_back(new_lexem);
				status = SQUCL;
				next;
			}
			else {
				cout << "Lexical error at status NUMBER" << endl;
				return false;
			}
		}break;

		case SPACE6: {
			if (cur_symbol == "space")
				next;
			else if (cur_symbol == "squarecl") {
				create;
				new_lexem.type = "SQUARECL";
				new_lexem_arr.push_back(new_lexem);
				status = SQUCL;
				next;
			}
			else {
				cout << "Lexical error at status SPACE6" << endl;
				return false;
			}
		}break;

		case SQUCL: {
			if (cur_symbol == "space")
				next;
			else if (cur_symbol == "semicolon") {
				save;
				create;
				new_lexem.type = "SEMICOLON";
				new_lexem_arr.push_back(new_lexem);
				status = SEMICOLON;
				next;
			}
			else {
				cout << "Lexical error at status SQUCL" << endl;
				return false;
			}
		}break;

		case SEMICOLON: {
			if ((cur_symbol_num == main_vec.size()-1)|| (cur_symbol_num == main_vec.size()))
				Is_Operating = false;
			else if (cur_symbol == "space") {
				status = SEMICOLON;
				next;
			}
			else {
				cout << "Lexical error at status SEMICOLON" << endl;
				return false;
			}
		}break;
		}
	}
	main_vec = new_lexem_arr;
	return true;
}


void Keywords_Recognize(lexem & cur_lexem)   //Блок идентификации ключевых слов,реализован через бинарный поиск
{                                           //по массиву, содержащему все ключевые слова языка Паскаль
	string str = cur_lexem.title;
	int first = 0, last = key_table_size - 1, mid = 0;
	while (first <= last) {
		mid = (first + last) / 2;
		if (str < Pascal_Keywords[mid])       
			last = mid - 1;      
		else if (str > Pascal_Keywords[mid])  
			first = mid + 1;	   
		else {
			cur_lexem.type = "KEYWORD_" + str;
			return;
		}
	}
}

