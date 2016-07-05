// stdafx.h: включаемый файл дл€ стандартных системных включаемых файлов
// или включаемых файлов дл€ конкретного проекта, которые часто используютс€, но
// не часто измен€ютс€
//

#pragma once


#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct lexem {
	string title, type;
};

typedef vector<lexem> Lexem_Arr;



// TODO: ”становите здесь ссылки на дополнительные заголовки, требующиес€ дл€ программы
