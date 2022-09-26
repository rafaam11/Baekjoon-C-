#pragma once
#include <string>

using namespace std;
const int max_dict_num = 905;		// 포켓몬 도감의 끝번

// 포켓몬 정보 구조체 선언
struct PokemonInfo
{
	int p_number;					// 포켓몬 번호 (int형)
	string p_name;					// 포켓몬 이름 (string형)
	string p_type;					// 포켓몬 타입 (string형)

};

array<PokemonInfo, max_dict_num> CreatePokemonDict();
array<PokemonInfo, max_dict_num> AddPokemon(array<PokemonInfo, max_dict_num> dict, PokemonInfo pokemon);
int SearchPokemonNumber(array<PokemonInfo, max_dict_num> dict, string name);
PokemonInfo SearchPokemon(array<PokemonInfo, max_dict_num> dict, int search_pokemon_number);
array<PokemonInfo, max_dict_num> RemovePokemon(array<PokemonInfo, max_dict_num> dict, int search_pokemon_number);
void PrintDict(const array<PokemonInfo, max_dict_num> dict);
