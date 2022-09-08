#include <iostream>

// "Stack"이라는 구조체의 선언문
struct Stack               
{
    unsigned int max_size;	    // 최대 사용 가능한 크기
    int stack_pointer;	    // 데이터가 채워진 마지막 위치
    unsigned int* data;	    // 데이터

};


// 최대 크기가 max_size인 Stack을 생성
Stack* CreateStack(unsigned int max_size)
{
    Stack* stack = new Stack;
    stack->max_size = max_size;
    stack->stack_pointer = -1;
    stack->data = new unsigned int[max_size];

    return stack;
};

// 동적할당된 Stack을 삭제
void DeleteStack(Stack* st)
{
    delete[] st->data;
    delete st;

};

// Stack src에 있는 모든 정보(최대 크기, 현재 크기, 정보)를 Stack dst로 복사
void Copy(Stack* src, Stack* dst)
{
    dst->max_size = src->max_size;
    dst->stack_pointer = src->stack_pointer;
    for (int i = 0 ; i < dst->max_size ; ++i) {
        dst->data[i] = src->data[i];
    }

};

// Stack과 동일한 정보를 가지고 있는 Stack을 추가적으로 생성
Stack* Clone(Stack* st)
{
    Stack* clone = new Stack;
    clone->max_size = st->max_size;
    clone->stack_pointer = st->stack_pointer;
    clone->data = new unsigned int[clone->max_size];
    for (int i = 0 ; i < clone->max_size ; ++i) {
        clone->data[i] = st->data[i];
    }

    return clone;

};

// 데이터 x를 Stack의 가장 위에 추가
void Push(Stack* st, unsigned int x)
{
    if (st->stack_pointer == st->max_size-1) {
        std::cout << "Stack이 가득 참. \n";
    }

    else {
        st->data[++st->stack_pointer] = x;
    }
    
};

// Stack에서 가장 위에 있는 데이터를 삭제하고 반환, 만약 데이터가 없는 경우 -1 반환
int Pop(Stack* st)
{
    if (st->stack_pointer == -1) {
        return -1;
    }

    else {
        return st->data[st->stack_pointer--];
    }
};

// Stack에서 가장 위에 있는 데이터를 반환(삭제하지는 않음), 만약 데이터가 없는 경우 -1 반환
int Top(Stack* st)
{
    if (st->stack_pointer == -1) {
        return -1;
    }

    else {
        return st->data[st->stack_pointer];
    }
};

// Stack의 최대 사용 가능한 크기 반환
int MaxSize(Stack* st) 
{
    return st->max_size - st->stack_pointer - 1;
};

// Stack의 현재 사용 중인 크기 반환
unsigned int Size(Stack* st)
{
    return st->stack_pointer;
};

// Stack이 현재 비어있는지 여부를 반환
bool isEmpty(Stack* st)
{
    if (st->stack_pointer == -1) {
        return true;
    }

    else {
        return false;
    }

};

// Stack을 프린트
void PrintStack(Stack* st)
{   
    std::cout << "Max size : " << st->max_size << std::endl;
    std::cout << "Top : " << st->stack_pointer+1 << std::endl;
    std::cout << "Data : " ;

    if (st->stack_pointer == -1) {
        std::cout << "-1 \n";
    }

    else {
        for (int i ; i < st->max_size ; ++i) {
            if (i <= st->stack_pointer) {
                std::cout << st->data[i] << " ";
            }

            else {
                std::cout << 0 << " ";
            }
        }
        std::cout << std::endl;
    }
    
};


int main() 
{   
    // St1의 최대크기 사용자 입력
    int max_size;
    std::cout << "St1의 최대크기 입력.\n";
    std::cin >> max_size;

    // CreateStack 테스트
    Stack* st1 = CreateStack(max_size);
    std::cout << "\n @@@ st1 정보 출력 (CreateStack 테스트) \n";
    PrintStack(st1);

    // Push 테스트
    Push(st1, 1);
    Push(st1, 3);
    Push(st1, 5);
    Push(st1, 7);
    Push(st1, 9);
    std::cout << "\n @@@ st1 정보 출력 (Push 테스트) \n";
    PrintStack(st1);

    // Pop 테스트
    std::cout << "\n @@@ st1 정보 출력 (Pop 테스트) \n";
    std::cout << "가장 위에 있던 데이터: " << Pop(st1) << std::endl;
    PrintStack(st1);

    // Top 테스트
    std::cout << "\n @@@ st1 정보 출력 (Top 테스트) \n";
    std::cout << "가장 위에 있는 데이터: " << Top(st1) << std::endl;
    PrintStack(st1);

    // Maxsize 테스트
    std::cout << "\n @@@ st1 정보 출력 (Maxsize 테스트) \n";
    std::cout << "최대 사용 가능한 크기 : " << MaxSize(st1) << std::endl;

    // Size 테스트
    std::cout << "\n @@@ st1 정보 출력 (Size 테스트) \n";
    std::cout << "현재 사용 가능한 크기 : " << Size(st1) << std::endl;

    // isEmpty 테스트
    std::cout << "\n @@@ st1 정보 출력 (isEmpty 테스트) \n";
    std::cout << "비어있는지 여부 (1이면 비어있음) : " << isEmpty(st1) << std::endl;

    // Copy 테스트
    Stack* st_copy = CreateStack(max_size + 10);
    std::cout << "\n @@@ st_copy 정보 출력 (copy 전) \n";
    PrintStack(st_copy);
    Copy(st1, st_copy);
    std::cout << "\n @@@ st_copy 정보 출력 (copy 후) \n";
    PrintStack(st_copy);

    // Clone 테스트
    Stack* st_clone = Clone(st1);
    std::cout << "\n @@@ st_clone 정보 출력 (Clone 테스트) \n";
    PrintStack(st_copy);


    // 동적할당된 변수를 제거하고 마무리
    DeleteStack(st1);
    DeleteStack(st_copy);
    DeleteStack(st_clone);



    return 0;
}