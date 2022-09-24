#include "PokemonS.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>

using namespace std;

struct PokemonInfo
{
	string p_name;							// 포켓몬 이름 (string형)
	int p_number;							// 포켓몬 번호 (int형)
	string p_type;							// 포켓몬 타입 (string형)

};

auto CreatePokemonDict()										// 도감 객체를 생성
{
	list<PokemonInfo>* dict = new list<PokemonInfo>;

	return dict;

}

void AddPokemon(list<PokemonInfo> dict, const PokemonInfo pokemon)			// 도감 객체에 포켓몬 정보를 추가
{
	dict.push_back(pokemon);
}

PokemonInfo SearchPokemon(list<PokemonInfo> dict, string name)		// 도감 객체에서 이름 기반으로 포켓몬 정보를 검색
{

}

void RemovePokemon(list<PokemonInfo> dict, string name)				// 도감 객체에서 이름 기반으로 포켓몬 정보를 삭제
{

}

void PrintDict(list<PokemonInfo> dict)
{
	list<PokemonInfo>::iterator it;

	for (it = dict.begin(); it != dict.end(); it++) {
		cout << "이름: " << (*it).p_name << ", ";
		cout << "번호: " << (*it).p_number << ", ";
		cout << "타입: ";

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
	list<PokemonInfo>* dict = CreatePokemonDict();
	PokemonInfo pokemon1 = { '이상해씨', 1, '풀, 독' };





}


