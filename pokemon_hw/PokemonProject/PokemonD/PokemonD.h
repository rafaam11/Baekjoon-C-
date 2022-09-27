#pragma once

#ifdef DYNAMIC_EXPORTS
#	define DYNAMIC_DECLSPEC __declspec(dllexport)
#else
#	define DYNAMIC_DECLSPEC __declspec(dllimport)
#endif



#include <string>

using namespace std;
const int max_dict_num = 905;		// 포켓몬 도감의 끝번

// 포켓몬 정보 구조체 선언
DYNAMIC_DECLSPEC struct PokemonInfo
{
	int p_number;					// 포켓몬 번호 (int형)
	string p_name;					// 포켓몬 이름 (string형)
	string p_type;					// 포켓몬 타입 (string형)

};

DYNAMIC_DECLSPEC array<PokemonInfo, max_dict_num> CreatePokemonDict();
DYNAMIC_DECLSPEC array<PokemonInfo, max_dict_num> AddPokemon(array<PokemonInfo, max_dict_num> dict, PokemonInfo pokemon);
DYNAMIC_DECLSPEC int SearchPokemonNumber(array<PokemonInfo, max_dict_num> dict, string name);
DYNAMIC_DECLSPEC PokemonInfo SearchPokemon(array<PokemonInfo, max_dict_num> dict, int search_pokemon_number);
DYNAMIC_DECLSPEC array<PokemonInfo, max_dict_num> RemovePokemon(array<PokemonInfo, max_dict_num> dict, int search_pokemon_number);
DYNAMIC_DECLSPEC void PrintDict(const array<PokemonInfo, max_dict_num> dict);
