#include "Input-Output.h"
#include "Transliteration_Block.h"
#include "Lexical_Block.h"
#include "Syntax_Block.h"

int main()
{
	string input_str = Input(); //Считывание строки из файла
	Lexem_Arr main_vec;  //Вектор лексем
	if (Transliteration(Input(), main_vec)) { //Транслитерация исходной строки
		if (Lexical_Check(main_vec)) {        //Проверка строки в лексическом блоке и идентификация ключевых слов 
			Output(Syntax_Check(main_vec));  //Проверка строки в синтаксическом блоке и вывод результата
		}
		else Output(false);  //Если при транслитерации была ошибка
	}
	else Output(false);   //Лексическая ошибка
	system("pause");
    return 0;
}

