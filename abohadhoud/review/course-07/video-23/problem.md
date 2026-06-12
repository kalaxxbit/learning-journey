Write a program to read a
string then print the first
letter of each word in that
string ?
// Problem #23
string ReadString()
{
string S1 = " ";
cout << "Pleas Enter your string ? \n";
getline(cin, S1);
return S1;
}
void PrintFirstLetterOfEachWord(string S1)
{
bool isFirstLetter = true;
\n";
cout << "\n First letters of this string :
for (int i = 0; i < S1.length(); i++)
{
if (S1[i] != ' ' && isFirstLetter)
{
cout << S1[i] << endl;
}
? Pleas Enter your string
Mohammed Saqer
Abu-Hadhoud
@Programming Advices
First letters of this string
M
S
A
@
A