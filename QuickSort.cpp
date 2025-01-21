#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void quickSort(vector <int>& A, int S, int E, int K); //퀵 정렬 알고리즘
int partition(vector <int>& A, int S, int E); //파티션 함수
void swap(vector <int>& A, int S, int E); //스왑 함수

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;
    vector <int> A(N,0);

    for(int i = 0; i<N; i++) {
        cin >> A[i];
    }
    quickSort(A,0,N-1,K-1);
    cout << A[K-1];
}

void quickSort(vector <int>& A, int S, int E, int K) {
    int pivot = partition(A,S,E);
    if(pivot==K) {
        return;
    }else if(pivot > K) {
        quickSort(A,S,pivot-1,K); //(재귀함수 활용) pivot이 K보다 크면 왼쪽에 있는 데이터들을 다시 정렬 
    }else {
        quickSort(A,pivot+1,E,K); // pivot이 K보다 작으면 오른쪽에 있는 데이터들을 다시 정렬
    }


}

int partition(vector <int>& A, int S, int E) {
    if(S+1 == E) {
        if(A[S] > A[E]) swap(A,S,E);
        return E;
    }
    int N = (S+E)/2;
    swap(A,S,N);
    int pivot = A[S];
    int i = S+1;
    int j = E;
    while(i<=j) {
        while(pivot<A[j]&&j>0) j--; //작은 데이터 값이 나올때까지 "--j"(뒤에서부터 앞으로)
        while(pivot>A[i]&&i<A.size()-1) i++; //큰 데이터 값이 나올때까지 ++i (앞에서부터 뒤로)
        if(i<=j) swap(A, i++, j--);
        }
        A[S] = A[j]; //pivot을 가운데로
        A[j] = pivot; //pivot을 가운데에 대입
        return j;

    }


void swap(vector <int>& A, int S, int E){ //swap 함수는 무조건 암기하기
    int temp = A[S];
    A[S]=A[E];
    A[E] = temp;
}
