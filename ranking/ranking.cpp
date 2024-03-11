//Zadanie: Ranking
// Autor: Filip Szafran
//Nr.indeksu: 325705
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct zawodnik
{
	int index;
	int score;
	int ranking;

};
int main()
{//wprowadzanie ilosci zawodnikow, wypelnianie vectora indeksami i wynikami
	zawodnik g;
	int n;
	cin >> n;
	vector<zawodnik> wyniki(n);
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		g.index = i;
		g.score = k;
		wyniki[i] = g;
	}
	//sortowanie wzgledem wyniku
	sort(wyniki.begin(), wyniki.end(), [](zawodnik first, zawodnik sec) {return first.score > sec.score; });
	wyniki.front().ranking = 1;

	for (int i = 1; i < n; i++)
	{
		// Jezeli zawodnik ma inny wynik od gracza nad soba
		if (wyniki[i - 1].score != wyniki[i].score)
		{
			wyniki[i].ranking = i + 1;
		}
		// Gdy ma taki sam jak gracz wyzej w rankingu to ma to samo miejsce
		else
		
		wyniki[i].ranking = wyniki[i - 1].ranking;
		
		}
	//sortowanie wzgledem indeksow
		sort(wyniki.begin(), wyniki.end(), [](zawodnik first, zawodnik sec) {return first.index < sec.index; });
		for (int i=0;i<n;i++)
		{
			cout << wyniki[i].ranking << ' ';
		}
	}
