#pragma once
#include "stdafx.h"
bool Syntax_Check(Lexem_Arr main_vec);


enum lexem_syntax_status
{
	_BEGIN, _KEYWORD_WHILE,_ID1,_KEYWORD_DO,_ID2,_COLON,_EQUALLY,_ID3,_SQUOP,_SIGN,_NUMBER,_SQUCL,_SEMICOLON
};