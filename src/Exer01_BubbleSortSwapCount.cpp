#include <iostream>
#include <vector>
#include <utility>
#include <cassert>

using namespace std;

using ll = long long;

#define IOFAST() ios_base::sync_with_stdio(0); cin.tie(0);

void printVector(const vector<int>& v) {
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i] << (i + 1 == v.size() ? "" : " ");
    }
    cout << "\n";
}

ll bubble_sort_swap_count(vector<int>& arr) {
    ll swap_count = 0;
    int n = static_cast<int>(arr.size());

    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                ++swap_count;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }

    return swap_count;
}

void onlineJudge() {
    int n;
    if (!(cin >> n)) return;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    ll total_swaps = bubble_sort_swap_count(arr);

    printVector(arr);
    cout << total_swaps << "\n";
}

void runLocalTests() {
    cout << "=== Question 1 (Bubble Sort Swap Count) ===\n\n";

    {
        vector<int> arr = {2, 3, 8, 6, 1};
        cout << "Teste 1 (Original): ";
        printVector(arr);

        ll swaps = bubble_sort_swap_count(arr);

        cout << "Teste 1 (Ordenado): ";
        printVector(arr);
        cout << "Trocas: " << swaps << " | Esperado: 5\n";
        assert(swaps == 5);
        assert((arr == vector<int>{1, 2, 3, 6, 8}));
        cout << "[PASSOU]\n\n";
    }

    {
        vector<int> arr = {1, 2, 3, 4};
        cout << "Teste 2 (Original): ";
        printVector(arr);

        ll swaps = bubble_sort_swap_count(arr);

        cout << "Teste 2 (Ordenado): ";
        printVector(arr);
        cout << "Trocas: " << swaps << " | Esperado: 0\n";
        assert(swaps == 0);
        assert((arr == vector<int>{1, 2, 3, 4}));
        cout << "[PASSOU]\n\n";
    }

    {
        vector<int> arr = {4, 3, 2, 1};
        ll swaps = bubble_sort_swap_count(arr);
        assert(swaps == 6);
        assert((arr == vector<int>{1, 2, 3, 4}));
        cout << "Teste 3 (Pior caso): 6 trocas | [PASSOU]\n\n";
    }

    cout << "Todos os testes locais passaram com sucesso!\n";
}

int main() {
    IOFAST();
    runLocalTests();
    // onlineJudge();

    return 0;
}