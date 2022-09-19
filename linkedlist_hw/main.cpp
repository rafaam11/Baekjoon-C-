#include <iostream>

// 노드 구조 선언
struct Node
{
    int data;               // Node가 가진 데이터값
    struct Node* link;      // Node에 링크된 Node를 가리키는 포인터

};

// 헤드 노드 구조 선언
struct HeadNode 
{
    Node* link;             // Head 다음 Node를 가리키는 포인터

};

// 리스트를 생성하는 함수
HeadNode* CreateList()
{
    HeadNode* H = new HeadNode;     // 헤드 노드를 생성
    H->link = NULL;                 // 헤드 노드의 링크를 NULL 상태로 초기화

    return H;

}

// 리스트의 가장 뒤에 노드를 삽입하는 함수
void addNode(HeadNode* H, int x)
{
    Node* NewNode = new Node;       // 새로 만들 노드
    Node* LastNode;                 // 원래 있던 노드의 마지막 노드
    
    NewNode->data = x;
    NewNode->link = NULL;

    // 리스트가 비어있을 경우
    if (H->link == NULL) {          
        H->link = NewNode;          // 헤드 노드에 새로 만든 노드를 링크시킴
        return;
    }

    // 리스트가 비어있지 않은 경우
    else {
        LastNode = H->link;             // 가장 앞의 노드를 마지막 노드라고 초기화.

        while (LastNode->link != NULL) LastNode = LastNode->link;   // 링크된 노드가 없는 노드를 마지막 노드로 업데이트

        LastNode->link = NewNode;       // 마지막 노드 뒤에 새로 만든 노드를 링크시킴

    }
    
}


// 리스트의 가장 앞의 노드 삭제하는 함수
void deleteNode(HeadNode* H) 
{
    // 리스트가 비어있을 경우
    if (H->link == NULL) return;

    // 리스트가 한 개의 노드만 가진 경우
    if (H->link->link == NULL) {
        delete H->link;
        H->link = NULL;
        return;
    }

    // 리스트에 노드가 여러 개 있는 경우
    else {
        Node* FirstNode = H->link;
        Node* SecondNode = H->link->link;
        H->link = SecondNode;
        delete FirstNode;
        
    }

}

// 링크드리스트 출력하는 함수
void PrintList(const HeadNode* L)
{
    Node* p;
    std::cout << "링크드리스트 목록 = (";
    p = L->link;

    while (p != NULL) {
        std::cout << p->data;
        p = p->link;
        
        if (p != NULL) std::cout << " -> " ;

    }

    std::cout << " )" << std::endl;

}

// 동적할당 변수 삭제하는 함수
void DeleteMallocParam(HeadNode* L)
{   
    // 헤드 노드에 연결된 모든 노드를 제거
    while (L->link != NULL) deleteNode(L);        
    
    // 헤드 노드를 제거
    delete L;
    
}


int main() 
{   
    std::cout << "빈 링크드리스트를 생성" << std::endl;
    HeadNode* L = CreateList();

    std::cout << "링크드리스트에 추가할 노드의 데이터를 3개 입력:" << std::endl;
    int data1, data2, data3;
    std::cin >> data1 >> data2 >> data3;
    addNode(L, data1);
    PrintList(L);
    addNode(L, data2);
    PrintList(L);
    addNode(L, data3);
    PrintList(L);

    std::cout << "링크드리스트의 가장 앞에 있는 데이터를 삭제" << std::endl;
    deleteNode(L);
    PrintList(L);

    std::cout << "링크드리스트의 가장 앞에 있는 데이터를 삭제" << std::endl;
    deleteNode(L);
    PrintList(L);

    std::cout << "다시 링크드리스트에 추가할 노드의 데이터를 3개 입력:" << std::endl;
    int data4, data5, data6;
    std::cin >> data4 >> data5 >> data6;
    addNode(L, data4);
    PrintList(L);
    addNode(L, data5);
    PrintList(L);
    addNode(L, data6);
    PrintList(L);

    std::cout << "링크드리스트의 가장 앞에 있는 데이터를 삭제" << std::endl;
    deleteNode(L);
    PrintList(L);

    std::cout << "힙 메모리의 동적할당 변수 제거" << std::endl;
    DeleteMallocParam(L);

    return 0;

}