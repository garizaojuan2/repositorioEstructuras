#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
	vector<string> morse = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
	"...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", ".-.-.-",
	 "--..--", "..--..", ".----.", "-.-.--","-..-.", "-.--.", "-.--.-", ".-...", "---...", "-.-.-.", "-...-", ".-.-.", "-....-", "..--.-", ".-..-.", ".--.-."};

	vector<string> trad =  {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", 
	"0", "1", "2", "3", "4", "5","6", "7", "8", "9", ".", ",", "?", "'", "!", "/", "(", ")", "&", ":", ";", "=", "+", "-", "_", "\"", "@"};

	int i, cases, j, tam, tamVec = morse.size(), k;
	string line, cad;
	cin >> cases;
	cin.ignore();
	bool flag, flag2;
	for (i = 1 ; i <= cases; i++)
	{
		getline(cin,line);

		j = 0;
		tam = line.size();
		flag = false;
		string ans = "";
		while (j < tam)
		{
			cad = "";

			while ((j < tam && line[j] != ' ') || flag)
			{
				cad += line[j];
				j += 1;
			}
			flag2 = true;
			k = 0;
			while(k < tamVec && flag2)
			{
				if (morse[k] == cad)
				{
					flag2 = false;
					ans += trad[k];
				}
				k += 1;
			}
			if (j + 1 < tam && line[j + 1] == ' ' )
			{
				ans += " ";
				j += 1;
			}
			j += 1;
		}
		if(i < tam)
		{
			cout << "Message #"<< i << endl;
			cout << ans << endl;
			cout << endl;
		}
		else
		{
			cout << "Message #"<< i << endl; 
			cout << ans << endl;
		}

	}
	


	return 0;
}