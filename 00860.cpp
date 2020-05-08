/**
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string line;
    unordered_map<string, int> m;
    while (true) {
        getline(cin, line);
        if (line == "****END_OF_INPUT****") {
            break;
        }
        m.clear();
        int l = 0;
        stringstream wtf;
        while (true) {
            for (char& i : line) {
                if (!isalpha(i)) {
                    i = ' ';
                } else {
                    i = tolower(i);
                }
            }
            wtf << line << " ";
            getline(cin, line);
            if (line == "****END_OF_TEXT****") {
                break;
            }
        }
        string s;
        while (wtf >> s) {
            m[s]++;
            l++;
        }
        double e_t = 0, e_max = log10(l);
        for (const auto& i : m) {
            e_t += i.second * (log10(l) - log10(i.second));
        }
        e_t /= l;
        cout << l << " " << fixed << setprecision(1) << e_t << " " << setprecision(0) << round(e_t * 100 / e_max) << "\n";
    }
    return 0;
}
**/

#include<iostream>
#include<iomanip>
#include<sstream>
#include<string>
#include<cmath>
#include<cctype>
#include<map>
using namespace std;
int main()
{
	
	string temp;
	string notneed = ",.:;!?\"()\t\n";
	while (1)
	{
		map<string, int> words;
		int landa = 0;
		double ET = 0;
		double Erel = 0;;
		stringstream ins;
		while (1)
		{
			getline(cin, temp);
			if (temp == "****END_OF_TEXT****") break;
			else if (temp == "****END_OF_INPUT****") return 0;
			for (int i = 0; i < signed(temp.size()); i++)
			{
				for (int j = 0; j < signed(notneed.size()); j++)
				{
					if (temp[i] == notneed[j])
					{
						temp[i] = ' ';
					}
				}
				if (isupper(temp[i]))
				{
					temp[i] = tolower(temp[i]);
				}
			}
			ins << temp << " ";
		}
		while (1)
		{
			ins >> temp;
			if (ins.eof()) break;
			words[temp]++;
			landa++;
		}
		for (map<string, int>::iterator i = words.begin(); i != words.end(); i++)
		{
			ET += (i->second)*(log10(landa) - log10(i->second));
		}
		ET /= landa;
		Erel = ET * 100 / log10(landa) ;
		cout << fixed<<setprecision(0)<<landa << " " << setprecision(1) << ET << " " << setprecision(0) << round(Erel) << endl;
	}
}