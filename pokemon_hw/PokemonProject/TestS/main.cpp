#include "PokemonS.h"
#include <iostream>
#include <array>

using namespace std;

int main() {

	cout << "정적 라이브러리 실행 성공 \n" << endl;

	// 포켓몬 도감 및 포켓몬 등록 함수 체크
	cout << " ** 포켓몬 도감 및 포켓몬 등록 함수 체크" << endl;
	array<PokemonInfo, max_dict_num> dict = CreatePokemonDict();

	PokemonInfo pokemon1 = { 1, "이상해씨", "풀, 독" };
	PokemonInfo pokemon6 = { 6, "리자몽", "불꽃, 비행" };
	PokemonInfo pokemon8 = { 8, "어니부기", "물" };
	PokemonInfo pokemon25 = { 25, "피카츄", "전기" };

	dict = AddPokemon(dict, pokemon1);
	dict = AddPokemon(dict, pokemon6);
	dict = AddPokemon(dict, pokemon8);
	dict = AddPokemon(dict, pokemon25);
	PrintDict(dict);

	// 포켓몬 검색 함수 체크
	cout << "\n ** 포켓몬 검색 함수 체크" << endl;
	int search_pokemon1_numb = SearchPokemonNumber(dict, "리자몽");
	int search_pokemon2_numb = SearchPokemonNumber(dict, "파이리");

	PokemonInfo search_pokemon1_info = SearchPokemon(dict, search_pokemon1_numb);
	PokemonInfo search_pokemon2_info = SearchPokemon(dict, search_pokemon2_numb);

	// 포켓몬 삭제 함수 체크
	cout << "\n ** 포켓몬 삭제 함수 체크" << endl;
	dict = RemovePokemon(dict, search_pokemon1_numb);
	dict = RemovePokemon(dict, search_pokemon2_numb);

	cout << endl;
	PrintDict(dict);

	// 추가 등록
	PokemonInfo pokemon905 = { 905, "러브로스", "페어리, 비행" };
	dict = AddPokemon(dict, pokemon905);
	cout << endl;
	PrintDict(dict);

	dict = RemovePokemon(dict, SearchPokemonNumber(dict, "러브로스"));
	cout << endl;
	PrintDict(dict);


	system("pause");

	return 0;
}