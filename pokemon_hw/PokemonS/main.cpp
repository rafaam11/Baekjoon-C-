#include "PokemonS.h"
#include <iostream>
#include <string>
#include <array>
#include <vector>

using namespace std;

int main() {

	array<PokemonInfo, max_dict_num> dict = CreatePokemonDict();

	PokemonInfo pokemon1 = {1, "이상해씨", "풀, 독"};
	PokemonInfo pokemon6 = {6, "리자몽", "불꽃, 비행"};
	PokemonInfo pokemon8 = {8, "어니부기", "물"};
	PokemonInfo pokemon25 = {25, "피카츄", "전기"};

	dict = AddPokemon(dict, pokemon1);
	dict = AddPokemon(dict, pokemon6);
	dict = AddPokemon(dict, pokemon8);
	dict = AddPokemon(dict, pokemon25);

	PrintDict(dict);


}