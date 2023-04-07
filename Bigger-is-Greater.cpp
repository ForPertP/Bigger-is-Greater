#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'biggerIsGreater' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING w as parameter.
 */

string biggerIsGreater(string w)
{
    string result{};
    size_t n = w.length();

    for (int i = n-2; i >= 0; --i)
    {
        for (int j = n-1; j > i; --j)
        {
            if (w[i] < w[j])
            {
                std::swap(w[i], w[j]);
                std::sort(w.begin()+i+1, w.end());
                return w;
            }
        }
    }

    return "no answer";
}


string biggerIsGreater1(string w)
{
    if (next_permutation(w.begin(), w.end()))
    {
        return w;
    }
    else
    {
        return "no answer"; 
    }
} 

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string T_temp;
    getline(cin, T_temp);

    int T = stoi(ltrim(rtrim(T_temp)));

    for (int T_itr = 0; T_itr < T; T_itr++) {
        string w;
        getline(cin, w);

        string result = biggerIsGreater(w);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
