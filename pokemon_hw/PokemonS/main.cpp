#include "PokemonS.h"
#include <iostream>
#include <string>
#include <map>
#include <list>

using namespace std;

// 포켓몬 정보 구조체 선언
struct PokemonInfo
{
	int p_number;					// 포켓몬 번호 (int형)
	string p_name;					// 포켓몬 이름 (string형)

};

// 포켓몬 도감 구조체 선언
struct PokemonDict
{
	PokemonInfo* next_pokemon;

};

// 포켓몬 도감을 생성하는 함수
PokemonDict* CreatePokemonDict()	
{
	PokemonDict* dict = new PokemonDict;
	dict->next_pokemon = nullptr;

	return dict;

}


// 도감 객체에 포켓몬 정보를 추가
void AddPokemon(PokemonDict* dict, int number, string name, string type)			
{
	PokemonInfo* new_pokemon = new PokemonInfo;
	PokemonInfo* last_pokemon;

	new_pokemon->p_name = name;
	new_pokemon->p_number = number;
	new_pokemon->p_type = type;
	new_pokemon->next_pokemon = nullptr;

	// 도감이 비어있을 경우
	if (dict->next_pokemon == nullptr) {
		dict->next_pokemon == new_pokemon;	// 더미에 새 포켓몬을 연결시킴.
		return;
	}

	// 도감이 비어있지 않은 경우
	else {

		last_pokemon = dict->next_pokemon;		// 더미를 마지막 포켓몬으로 초기화.

		while (last_pokemon->next_pokemon != nullptr) last_pokemon = last_pokemon->next_pokemon;
		// 한 칸씩 이동하면서 연결된 포켓몬이 없는 포켓몬까지 이동.

		last_pokemon->next_pokemon = new_pokemon;		// 마지막 포켓몬 뒤에 새 포켓몬을 연결시킴.

	}

	
}

PokemonInfo SearchPokemon(list<PokemonInfo> dict, string name)		// 도감 객체에서 이름 기반으로 포켓몬 정보를 검색
{

}

void RemovePokemon(list<PokemonInfo> dict, string name)				// 도감 객체에서 이름 기반으로 포켓몬 정보를 삭제
{

}

// 도감을 출력하는 함수
void PrintDict(const PokemonDict* dict)
{
	PokemonInfo* p;
	cout << " 포켓몬 도감 정보 " << endl;
	p = dict->next_pokemon;

	while (p != nullptr) {
		cout << "이름: " << p->p_name << ", ";
		cout << "번호: " << p->p_number << ", ";
		cout << "타입: " << p->p_type << endl;
		p = p->next_pokemon;

	}

}

vector<string> WritePokemonType(string type_name)			// 타입 이름을 "," 로 구분하여 벡터로 저장
{
	string delimiter = ",";
	vector<string> type{};

	size_t pos = 0;
	while ((pos = type_name.find(delimiter)) != string::npos) {
		type.push_back(type_name.substr(0, pos));
		type_name.erase(0, pos + delimiter.length());
	}

	return type;

}


int main() {

	PokemonDict* pokemon_dict = CreatePokemonDict();

	AddPokemon(pokemon_dict, 1, "이상해씨", "풀, 독");
	AddPokemon(pokemon_dict, 6, "리자몽", "불꽃, 비행");
	AddPokemon(pokemon_dict, 8, "어니부기", "물");
	AddPokemon(pokemon_dict, 25, "피카츄", "전기");

	PrintDict(pokemon_dict);




}


