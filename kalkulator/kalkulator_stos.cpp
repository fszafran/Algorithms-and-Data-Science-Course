// Zadanie: Kalkulator
//Autor: Filip Szafran
//Nr. indeksu: 325705

#include <iostream>
#include <stack>
#include<string>
using namespace std;
int main()
{	//inicjalizacja stosow
	stack<int> numbers_stack;
	string wejscie;
	stack<char> operators_stack;
	getline(cin, wejscie);
	for (size_t i = 0; i < wejscie.size(); i++)
	{
		if (wejscie[i] == ' ' || wejscie[i] == '(')// pomijanie spacji i nawiasow otwierajacych
			continue;
		else if (wejscie[i] == '-' || wejscie[i] == '+' || wejscie[i] == '*' || wejscie[i] == '/')
			operators_stack.push(wejscie[i]); // odkladanie operatorow na stos
		else if (wejscie [i] >= '0' && wejscie[i] <= '9')
			numbers_stack.push(wejscie[i] - '0'); // odkladanie cyfr na stos
		else if (wejscie[i] == ')')// wykonywanie czynnosci dopiero przy napotkaniu nawiasu zamykajacego
		{
			int sec_num = numbers_stack.top();//przypisuje wartosc drugiej liczby i zdejmuje ja ze stosu
			numbers_stack.pop();
			int first_num = numbers_stack.top();
			numbers_stack.pop();
			char Operator = operators_stack.top();// przyjmuje operator i zdejmuje go ze stosu
			operators_stack.pop();
			if (Operator == '-')
				numbers_stack.push(first_num - sec_num);//numbers_stack.top() = wynik  działania
			else if (Operator == '+')
				numbers_stack.push(first_num + sec_num);
			else if (Operator == '*')
				numbers_stack.push(first_num * sec_num);
			else if (Operator == '/') {
				if (sec_num == 0) {
					cout << "NaN" << endl;
					return 0;
				}
				else
					numbers_stack.push(first_num / sec_num);
			}

		}
	}cout << numbers_stack.top();// wyswietlanie wyniku
	return 0;
}
