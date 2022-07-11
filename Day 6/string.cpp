#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "Muskan is a , good girl";
    cout<<s<<endl;
    cout<<char(tolower(s[0]))<<endl; // a way to convert to lowercase

    // Another way
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    cout<<s<<endl;
    // s.replace( 0,",", " ");


}