#include <iostream>
using namespace std;

// "Stack"이라는 구조체의 선언문
struct Stack               
{
    unsigned int max_size;	    // 최대 사용 가능한 크기
    int stack_pointer;	    // 데이터가 채워진 마지막 위치
    unsigned int* data;	    // 데이터

};


// 최대 크기가 max_size인 Stack을 생성
Stack* CreateStack(unsigned int max_size);

// Stack을 삭제
void DeleteStack(Stack* st);

// Stack src에 있는 모든 정보(최대 크기, 현재 크기, 정보)를 Stack dst로 복사
void Copy(Stack* src, Stack* dst);

// Stack과 동일한 정보를 가지고 있는 Stack을 추가적으로 생성
Stack* Clone(Stack* st);

// 데이터 x를 Stack의 가장 위에 추가
void Push(Stack* st, unsigned int x);

// Stack에서 가장 위에 있는 데이터를 삭제하고 반환, 만약 데이터가 없는 경우 -1 반환
int Pop(Stack* st);

// Stack에서 가장 위에 있는 데이터를 반환(삭제하지는 않음), 만약 데이터가 없는 경우 -1 반환
int Top(Stack* st);

// Stack의 최대 사용 가능한 크기 반환
int MaxSize(Stack* st);

// Stack의 현재 사용 중인 크기 반환
unsigned int Size(Stack* st);

// Stack이 현재 비어있는지 여부를 반환
bool isEmpty(Stack* st);



Matrix* CreateMatrix(int width, int height)         // Matrix를 생성하는 함수
{
    Matrix* mat = new Matrix;
    mat->w = width;
    mat->h = height;
    mat->data = new int[width*height];

    return mat;

}

void fill(Matrix* mat, int value)           // Matrix의 데이터를 채우는 함수
{
    for (int width=0; width < mat->w; ++width) 
        for (int height=0; height < mat->h; ++height) 
            mat->data[width * mat->h + height] = value;
}

void fillArange(Matrix* mat, int value)           // Matrix의 데이터를 초기 value에서 1씩 더하여 채우는 함수
{

    for (int k=0; k < mat->h*mat->w; ++k) {
        if (k == 0)
            mat->data[k] = value;
        else 
            mat->data[k] = mat->data[k-1] + 1;

    }

}

void PrintMatrix(Matrix* mat)               // Matrix의 모든 데이터 값을 출력하는 함수
{
    for (int width=0; width < mat->w; ++width) {
        for (int height=0; height < mat->h; ++height) {
            cout << mat->data[width * mat->h + height] << " ";
        }
        cout << " " << endl;
    }   
}

Matrix* Multiply(Matrix* mat1, Matrix* mat2)        // Matrix 곱셈 연산을 하는 함수
{
    Matrix* mat3 = CreateMatrix(mat1->w, mat2->h);

    if (mat1->h != mat2->w) {
        cout << "*곱셈을 하려했지만 두 Matrix의 크기가 적절하지 않습니다. \n";
    }

    else {
        for (int width=0; width < mat3->w; ++width) {
            for (int height=0; height < mat3->h; ++height) {
                int element_sum = 0;
                for (int k=0; k < mat1->h; ++k) {           // k: 덧셈연산 반복수 (0~)
                    element_sum += mat1->data[width * mat1->h + k] * mat2->data[k * mat2->h + height];
                }
                mat3->data[width * mat3->h + height] = element_sum;
            }
        }
    }

    return mat3;

}

Matrix* Add(Matrix* mat1, Matrix* mat2)             // Matrix 덧셈 연산을 하는 함수
{
    Matrix* mat3 = CreateMatrix(mat1->w, mat1->h);

    if (mat1->w != mat2->w || mat1->h != mat2->h) {
        cout << "*덧셈을 하려했지만 두 Matrix의 크기가 일치하지 않습니다. \n";
    }

    else {
        for (int width=0; width < mat3->w; ++width) {
            for (int height=0; height < mat3->h; ++height) {
                mat3->data[width * mat3->h + height] = mat1->data[width * mat1->h + height] + mat2->data[width * mat2->h + height];
            }
        }

    }

    return mat3;

}

void DeleteMatrix(Matrix* mat)                  // 동적할당된 변수를 제거하는 함수
{
    delete[] mat->data;
    delete mat;
}

int main() 
{   
    // Matrix 크기 선언
    int w1, h1, w2, h2;
    cout << "*mat1 크기 입력.\n";
    cin >> w1 >> h1 ;
    cout << "*mat2 크기 입력.\n";
    cin >> w2 >> h2 ;

    // mat1 생성 및 숫자 채우기
    cout << "\n mat1 = \n" ;
    Matrix* mat1 = CreateMatrix(w1, h1);
    int val1 = 4; // mat2 데이터를 채울 값
    fillArange(mat1, val1);
    PrintMatrix(mat1);

    // mat2 생성 및 숫자 채우기
    cout << "\n mat2 = \n" ;
    Matrix* mat2 = CreateMatrix(w2, h2);
    int val2 = 10; // mat2 데이터를 채울 값
    fillArange(mat2, val2);
    PrintMatrix(mat2);

    // 곱셈 연산
    cout << "\n mat1 x mat2 = \n" ;
    Matrix* mat_mul = Multiply(mat1, mat2);
    if (mat1->h == mat2->w) PrintMatrix(mat_mul);

    // 덧셈 연산
    cout << "\n mat1 + mat2 = \n" ;
    Matrix* mat_add = Add(mat1, mat2);
    if (mat1->w == mat2->w && mat1->h == mat2->h) PrintMatrix(mat_add);

    // 동적할당된 변수를 제거하고 마무리
    DeleteMatrix(mat1);
    DeleteMatrix(mat2);
    DeleteMatrix(mat_add);
    DeleteMatrix(mat_mul);


    return 0;

}