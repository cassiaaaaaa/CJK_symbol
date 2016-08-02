#include <iostream>
#include <string>
#include <io.h>
#include <stdlib.h>
#include <vector>
#include <windows.h> 

using namespace std;

string dirpath = "G:\\test-change\\";
string destpath = "G:\\test-symbol\\";

int main()
{
	_finddata_t file;
	long lf;
	char suffixs[] = "*.pnt";          //要寻找的文件类型
	vector<string> fileNameList;   //文件夹下.pnt类型文件的名字向量
	char *p;
	p = (char *)malloc((dirpath.size() + 1) * sizeof(char));
	strcpy(p, dirpath.c_str());

	//获取文件名向量
	if ((lf = _findfirst(strcat(p, suffixs), &file)) == -1l)
	{
		cout << "文件没有找到!\n";
	}
	else
	{
		cout << "\n文件列表:\n";
		do {
			cout << file.name << endl;
			//str是用来保存文件名的字符串string
			string str(file.name);
			fileNameList.push_back(str);
			cout << endl;
		} while (_findnext(lf, &file) == 0);
	}
	_findclose(lf);


	//遍历文件名向量，并进行修改
	for (vector<string>::iterator iter = fileNameList.begin(); iter != fileNameList.end(); ++iter)
	{
		string oldName = dirpath + *iter;
		//str1为原文件名要保留的部分
		
		string str1;
		string str2;
		string str3;
		string strAdd = ".uc.pnt";
		string str_a;
		str1 = (*iter).substr(0, 2);
		str2 = (*iter).substr(2, 2);
		str3 = (*iter).substr(4, 2);
		str_a = str2 +str3;
	
		string newName = dirpath + str1 + str2 + str3 +strAdd;
		string newName2 = destpath + str1 + str2 + str3 +strAdd;

		cout << "newName:" << newName << endl;
		cout << "newName2" << newName2 << endl;

		cout << "newName size = " << newName.size() << endl;
		cout << "newName2 size = " << newName2.size() << endl;

		char *newNamePointer, *newName2Pointer;
		newNamePointer = (char *)malloc((newName.size() + 1) * sizeof(char));
		newName2Pointer = (char *)malloc((newName2.size() + 1) * sizeof(char));
		strcpy(newNamePointer, newName.c_str());
		strcpy(newName2Pointer, newName2.c_str());
		cout << newNamePointer << endl;
		cout << newName2Pointer << endl;

		rename(newNamePointer, newNamePointer);

		
		char *ch;
		ch = (char *)str_a.c_str();
		int i;
		sscanf(ch,"%X",&i);
         cout << i << endl; // 23        
		if ((i < 0x4E00) | (i> 0x9FFF))

       {
		   MoveFile (newNamePointer,newName2Pointer); 
		
	}
        free(newNamePointer);
		free(newName2Pointer);

	}





	system("PAUSE");
	return 0;
}