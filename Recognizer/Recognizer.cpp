#include "Input-Output.h"
#include "Transliteration_Block.h"
#include "Lexical_Block.h"
#include "Syntax_Block.h"

int main()
{
	string input_str = Input(); //���������� ������ �� �����
	Lexem_Arr main_vec;  //������ ������
	if (Transliteration(Input(), main_vec)) { //�������������� �������� ������
		if (Lexical_Check(main_vec)) {        //�������� ������ � ����������� ����� � ������������� �������� ���� 
			Output(Syntax_Check(main_vec));  //�������� ������ � �������������� ����� � ����� ����������
		}
		else Output(false);  //���� ��� �������������� ���� ������
	}
	else Output(false);   //����������� ������
	system("pause");
    return 0;
}

