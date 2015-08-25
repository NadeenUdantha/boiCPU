#include <WinSock2.h>
#include <sys/stat.h>
#include <process.h>
#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <direct.h>
#include <stdarg.h>
#include <dirent.h>
#include <malloc.h>
#include <Tchar.h>
#include <istream>
#include <fstream>
#include <ostream>
#include <sstream>
#include <errno.h>
#include <ctype.h>
#include <stdio.h>
#include <time.h>
#include <string>
#include <ctime>
#include <dos.h>
#include <io.h>
#include <map>

using namespace std;

void write(string s){cout << s << endl;}

int main(int argc, char * args[])

{
ifstream file("file.txt");
if(!file.is_open()){cout << "Unable to open file";return 1;}
string line;
while(getline(file,line))
{
if(line.empty())continue;
if(line.size() == 0)continue;
if(strcmp(line.c_str(),"jmpn") == 0)
{write("0001");}
if(strcmp(line.c_str(),"sleep 1s") == 0)
{write("0100");}
if(strcmp(line.substr(0,3).c_str(),"led") == 0)
{if(strcmp(line.substr(4,5).c_str(),"1") == 0)
{write("0010");}else{write("0011");};
}
}
file.close();
return 0;
}