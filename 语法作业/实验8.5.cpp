/*#include <iostream>
#include <fstream>

using namespace std;

int main() {
	fstream file("afile.dat", ios::in | ios::out);
	
	if (file.is_open()) {
		// 向文件写入用户输入的信息
		string user_input;
		cout << "请输入要写入文件的信息：";
		getline(cin, user_input);
		file << user_input;
		
		// 将文件指针移到文件开头
		file.seekg(0);
		
		// 从文件读取信息并输出到屏幕上
		string file_content;
		getline(file, file_content);
		cout << "从文件中读取的信息：" << file_content << endl;
		
		file.close();
	} else {
		cerr << "无法打开文件" << endl;
	}
	
	return 0;
}

#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	fstream fout("afile.dat",ios::out);
	string s;
	while (getline(cin,s))
	{
		if (s[s.length()]==EOF)
			break;
		fout<<s<<"\n";
	}
	fout.close();
	fstream fin("afile.dat",ios::in);
	while(getline(fin,s))
	{
		cout<<s<<"\n";
	}
	fin.close();
	return 0;
}
 */
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	fstream fout("afile.dat", ios::out);
	
	if (!fout) {
		cerr << "无法打开输出文件" << endl;
		return 1;
	}
	
	string s;
	while (getline(cin, s))
	{
		fout << s << '\n';
	}
	
	fout.close();
	
	fstream fin("afile.dat", ios::in);
	
	if (!fin) {
		cerr << "无法打开输入文件" << endl;
		return 1;
	}
	
	while (getline(fin, s))
	{
		cout << s << '\n';
	}
	
	fin.close();
	
	return 0;
}

