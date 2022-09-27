#include "PokemonS.h"
#include <iostream>
#include <array>

using namespace std;

// 포켓몬 도감을 생성하는 함수
array<PokemonInfo, max_dict_num> CreatePokemonDict()
{
	array<PokemonInfo, max_dict_num> dict;
	for (int i = 0; i < max_dict_num; ++i) {
		dict[i].p_name = "null";
		dict[i].p_number = i + 1;
		dict[i].p_type = "null";
	}

	return dict;

}

// 도감 객체에 포켓몬 정보를 추가
array<PokemonInfo, max_dict_num> AddPokemon(array<PokemonInfo, max_dict_num> dict, PokemonInfo pokemon)
{
	(dict[pokemon.p_number - 1]).p_number = pokemon.p_number;
	(dict[pokemon.p_number - 1]).p_name = pokemon.p_name;
	(dict[pokemon.p_number - 1]).p_type = pokemon.p_type;

	return dict;

}


// 도감 객체에서 이름 기반으로 포켓몬 숫자를 검색
int SearchPokemonNumber(array<PokemonInfo, max_dict_num> dict, string name)
{
	bool existance = false;
	int numb;

	for (int i = 0; i < max_dict_num; ++i) {
		if ((dict[i]).p_name == name) {
			existance = true;
			numb = i;
		}
	}

	if (existance == true) {
		PokemonInfo pokemon = { (dict[numb]).p_number, (dict[numb]).p_name, (dict[numb]).p_type };
		return numb;
	}

	else {
		return -1;

	}
}

// 도감 객체에서 이름 기반으로 포켓몬 숫자를 검색하여 출력
PokemonInfo SearchPokemon(array<PokemonInfo, max_dict_num> dict, int search_pokemon_number)
{
	int numb = search_pokemon_number;

	if (numb != -1) {
		PokemonInfo pokemon = { (dict[numb]).p_number, (dict[numb]).p_name, (dict[numb]).p_type };
		cout << "찾은 포켓몬 이름: " << pokemon.p_name << ", ";
		cout << "번호: " << pokemon.p_number << ", ";
		cout << "타입: " << pokemon.p_type << endl;
		return pokemon;
	}

	else {
		cout << "입력한 포켓몬은 도감에 등록되어 있지 않습니다." << endl;

	}
}


// 도감 객체에서 이름 기반으로 포켓몬 정보를 삭제
array<PokemonInfo, max_dict_num> RemovePokemon(array<PokemonInfo, max_dict_num> dict, int search_pokemon_number)
{
	int numb = search_pokemon_number;

	if (numb != -1) {
		cout << dict[numb].p_name << "을(를) 제거합니다." << endl;
		dict[numb].p_name = "null";
		dict[numb].p_type = "null";
		return dict;
	}

	else {
		cout << "입력한 포켓몬은 도감에 등록되어 있지 않습니다." << endl;
		return dict;

	}
}



// 도감을 출력하는 함수
void PrintDict(const array<PokemonInfo, max_dict_num> dict)
{
	cout << " 현재 등록된 포켓몬 정보 " << endl;

	for (int i = 0; i < max_dict_num; ++i) {
		if ((dict[i]).p_name != "null") {
			cout << "이름: " << (dict[i]).p_name << ", ";
			cout << "번호: " << (dict[i]).p_number << ", ";
			cout << "타입: " << (dict[i]).p_type << endl;
		}
	}

}

