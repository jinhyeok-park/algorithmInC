#include <iostream>
#include <map>

using namespace std;

map<string , string> m;
map<string, string> ::iterator iter;
int N, M;

int main(void)
{
    cin >> N >> M;
    for(int i = 0 ; i < N ; i++)
    {
        string site;
        string pwd;
        cin >> site >> pwd;
        m.insert({site, pwd});
    }
    for (int i = 0 ; i < M ; i++)
    {
        string site;
        cin >> site;
        iter = m.find(site);
        cout << iter->second << "\n";
    }
}