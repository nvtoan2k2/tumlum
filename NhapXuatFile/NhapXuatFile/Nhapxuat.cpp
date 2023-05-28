#include <iostream>
#include <fstream>
using namespace std;

int main(){
	ifstream fin("inputt.txt");
	int a , b ;
	fin >> a >> b;
	int result1 = a + b;
	int c , d ;
	fin >> c >> d;
	int result2 = c + d;
	fin.close();
	ofstream fout("output.txt");

	fout << "1 + 2 = " << result1 << endl;

	fout << "3 + 4 = " << result2 << endl;

	fout.close();

	return 0;
}
