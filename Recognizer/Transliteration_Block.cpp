#include "Transliteration_Block.h"


bool Transliteration(string input_string, Lexem_Arr & main_vec)
{
	Str_Tolower(input_string);                          //Перевод всей строки в нижний регистр
	Fragmentation_Str(input_string, main_vec);         //Разбиение строки на символы и занесение их в вектор
	if (Assign_Class(main_vec)) return true;          //Присвоение каждому символу его класса
	else return false;
}

void Str_Tolower(string & str) {
	for (int i = 0; i < str.size(); i++) {
		str[i] = tolower(str[i]);
	}
}

void Fragmentation_Str(string inputString, Lexem_Arr & main_vec)
{
	for (int i = 0; i < inputString.size(); i++) {
		lexem cur;
		cur.title = inputString[i];
		main_vec.push_back(cur);
	}
}

bool Assign_Class(Lexem_Arr & main_vec)
{
	bool flag;
	for (int i = 0; i < main_vec.size(); i++) {
		flag = false;
		for (int j = 0; j < table_size; j++) {
			if (Transliteration_Table[j][0] == main_vec[i].title) {
				main_vec[i].type = Transliteration_Table[j][1];
				flag = true;
			}
		}
		if (flag == false) {
			cout << "Error symbol " << main_vec[i].title << endl;
			return false;
		}
	}
	return true;
}

