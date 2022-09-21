#include <iostream>

// 노드 구조 선언
struct Node
{
    int data;               // Node가 가진 데이터값
    Node* link;      // Node에 링크된 Node를 가리키는 포인터

};

// 링크드리스트 구조 선언
struct LinkedList 
{
    Node* link;             // head 다음 Node를 가리키는 포인터

};

// 리스트를 생성하는 함수 (더미 노드)
LinkedList* CreateList()
{
    LinkedList* h = new LinkedList;     // 헤드 노드를 생성
    h->link = nullptr;                 // 헤드 노드의 링크를 nullptr 상태로 초기화

    return h;

}

// 리스트의 가장 뒤에 노드를 삽입하는 함수
void PushNode(LinkedList* h, int x)
{
    Node* new_node = new Node;       // 새로 만들 노드
    Node* last_node;                 // 원래 있던 노드의 마지막 노드
    
    new_node->data = x;
    new_node->link = nullptr;

    // 리스트가 비어있을 경우
    if (h->link == nullptr) {          
        h->link = new_node;          // 헤드 노드에 새로 만든 노드를 링크시킴
        return;
    }

    // 리스트가 비어있지 않은 경우
    else {
        last_node = h->link;             // 가장 앞의 노드를 마지막 노드라고 초기화.

        while (last_node->link != nullptr) last_node = last_node->link;   // 링크된 노드가 없는 노드를 마지막 노드로 업데이트

        last_node->link = new_node;       // 마지막 노드 뒤에 새로 만든 노드를 링크시킴

    }
    
}


// 리스트의 가장 앞의 노드 삭제하는 함수
void PopNode(LinkedList* h) 
{
    // 리스트가 비어있을 경우
    if (h->link == nullptr) return;

    // 리스트가 한 개의 노드만 가진 경우
    if (h->link->link == nullptr) {
        delete h->link;
        h->link = nullptr;
        return;
    }

    // 리스트에 노드가 여러 개 있는 경우
    else {
        Node* FirstNode = h->link;
        Node* SecondNode = h->link->link;
        h->link = SecondNode;
        delete FirstNode;
        
    }

}

// 리스트에 특정 데이터가 있는지 확인하는 함수
bool FindNode(const LinkedList* h, int search_data)
{
    bool answer = 0;                    // 반환할 답

    Node* searchNode = h->link;     // 서치 노드를 첫 번째 노드로 초기화

    // 서치 노드를 한 칸 씩 뒤로 넘기며 탐색
    while (true) {        

        // 만약 찾는 데이터가 있다면 답을 1로 바꾸고 탈출
        if (searchNode->data == search_data) {
            answer = 1;
            break;
        }

        // 서치 노드가 마지막에 도달했으면 탈출
        if (searchNode->link == nullptr) {
            break;
        }
        
        // 서치 노드를 한 칸 뒤로 넘김
        searchNode = searchNode->link;

    }

    return answer;

}

// 리스트를 삭제하는 함수
void DeleteList(LinkedList* L)
{   
    // 헤드 노드에 연결된 모든 노드를 제거 (스택 및 힙 메모리)
    while (L->link != nullptr) PopNode(L);        
    
    // 헤드 노드를 제거 (힙 메모리)
    delete L;
    
}

// 리스트를 출력하는 함수
void PrintList(const LinkedList* L)
{
    Node* p;
    std::cout << " ** 링크드리스트 목록 = (";
    p = L->link;

    while (p != nullptr) {
        std::cout << p->data;
        p = p->link;
        
        if (p != nullptr) std::cout << " -> " ;

    }

    std::cout << " )" << std::endl;

}


int main() 
{   
    std::cout << "\n * 빈 리스트를 생성" << std::endl;
    LinkedList* L = CreateList();

    std::cout << "\n * 리스트에 추가할 노드의 데이터를 3개 입력: ";
    int data1, data2, data3;
    std::cin >> data1 >> data2 >> data3;
    PushNode(L, data1);
    PrintList(L);
    PushNode(L, data2);
    PrintList(L);
    PushNode(L, data3);
    PrintList(L);

    std::cout << "\n * 리스트의 가장 앞에 있는 데이터를 삭제" << std::endl;
    PopNode(L);
    PrintList(L);

    std::cout << "\n * 리스트의 가장 앞에 있는 데이터를 삭제" << std::endl;
    PopNode(L);
    PrintList(L);

    std::cout << "\n * 다시 리스트에 추가할 노드의 데이터를 3개 입력: ";
    int data4, data5, data6;
    std::cin >> data4 >> data5 >> data6;
    PushNode(L, data4);
    PrintList(L);
    PushNode(L, data5);
    PrintList(L);
    PushNode(L, data6);
    PrintList(L);

    std::cout << "\n * 리스트의 가장 앞에 있는 데이터를 삭제" << std::endl;
    PopNode(L);
    PrintList(L);

    std::cout << "\n * 리스트에 특정 데이터가 있는지 탐색: ";
    int search_data;
    std::cin >> search_data;
    bool search_result = FindNode(L, search_data);
    if (search_result == 1) std::cout << "** " << search_data << " 은(는) 리스트에 존재함 \n" ;
    else std::cout << "** " << search_data << " 은(는) 리스트에 존재하지 않음 \n" ;

    std::cout << "\n * 리스트 삭제" << std::endl;
    DeleteList(L);

    return 0;

}