#include "Input-Output.h"

string Input()
{
	ifstream Input_File("Input.txt");
	char buff[80];
	Input_File.getline(buff, 80);
	string input_str = buff;
	Input_File.close();
	return input_str;
}

void Output(bool result)
{
	ofstream Output_File("Output.txt");
	if (result) {
		Output_File << "ACCEPT" << endl;
	}
	else {
		Output_File << "REJECT" << endl;
	}
	Output_File.close();
}
