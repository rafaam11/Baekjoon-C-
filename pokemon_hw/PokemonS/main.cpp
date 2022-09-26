#include "PokemonS.h"
#include <iostream>
#include <string>
#include <array>
#include <vector>

using namespace std;

// 포켓몬 정보 구조체 선언
struct PokemonInfo
{
	int p_number;					// 포켓몬 번호 (int형)
	string p_name;					// 포켓몬 이름 (string형)
	string p_type;					// 포켓몬 타입 (string형)

};

// 포켓몬 도감을 생성하는 함수
auto CreatePokemonDict()	
{
	array<PokemonInfo, 905> dict;
	for (int i = 0 ; i < 905 ; ++i) {
		dict[i]->p_name = "null";
		dict[i]->p_number = i+1;
		dict[i]->p_type = "null";
	}

	return dict;

}


// 도감 객체에 포켓몬 정보를 추가
void AddPokemon(PokemonInfo* dict[], PokemonInfo* pokemon)			
{
	(dict[pokemon->p_number - 1])->p_number = pokemon->p_number;
	(dict[pokemon->p_number - 1])->p_name = pokemon->p_name;
	(dict[pokemon->p_number - 1])->p_type = pokemon->p_type;

}





// 도감을 출력하는 함수
void PrintDict(PokemonInfo* dict[])
{
	cout << " 포켓몬 도감 정보 " << endl;

	for (int i = 0 ; i < 905 ; ++i) {
		cout << "이름: " << (dict[i])->p_name << ", ";
		cout << "번호: " << (dict[i])->p_number << ", ";
		cout << "타입: " << (dict[i])->p_type << endl;
	}

}


int main() {

	PokemonInfo* dict[905];

	for (int i = 0 ; i < 905 ; ++i) {
		dict[i]->p_name = "null";
		dict[i]->p_number = i+1;
		dict[i]->p_type = "null";
	}

	PokemonInfo pokemon1 = {1, "이상해씨", "풀, 독"};
	PokemonInfo pokemon6 = {6, "리자몽", "불꽃, 비행"};
	PokemonInfo pokemon8 = {8, "어니부기", "물"};
	PokemonInfo pokemon25 = {25, "피카츄", "전기"};

	AddPokemon(dict, &pokemon1);
	AddPokemon(dict, &pokemon6);
	AddPokemon(dict, &pokemon8);
	AddPokemon(dict, &pokemon25);



	PrintDict(dict);




}


