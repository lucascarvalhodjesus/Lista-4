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

int partitionLomuto(vector<int>& arr, int low, int high, ll& swap_count) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            if (i != j) {
                swap(arr[i], arr[j]);
                ++swap_count;
            }
        }
    }

    if (i + 1 != high) {
        swap(arr[i + 1], arr[high]);
        ++swap_count;
    }

    return i + 1;
}

int quickselect(vector<int>& arr, int low, int high, int target_idx, ll& swap_count) {
    if (low == high) {
        return arr[low];
    }

    int p = partitionLomuto(arr, low, high, swap_count);

    if (p == target_idx) {
        return arr[p];
    } else if (p < target_idx) {
        return quickselect(arr, p + 1, high, target_idx, swap_count);
    } else {
        return quickselect(arr, low, p - 1, target_idx, swap_count);
    }
}

void onlineJudge() {
    int n, k;
    if (!(cin >> n >> k)) return;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    ll swap_count = 0;
    int target_idx = n - k;
    int kth_largest = quickselect(arr, 0, n - 1, target_idx, swap_count);

    cout << kth_largest << "\n";
    printVector(arr);
    cout << swap_count << "\n";
}

void runLocalTests() {
    cout << "=== Question 3 (Quickselect Lomuto Kth Largest) ===\n\n";

    {
        vector<int> arr = {3, 2, 1, 5, 6, 4};
        int n = 6, k = 2;
        ll swaps = 0;
        int res = quickselect(arr, 0, n - 1, n - k, swaps);

        cout << "Resultado: " << res << " | Esperado: 5\n";
        cout << "Vetor final: ";
        printVector(arr);
        cout << "Trocas: " << swaps << " | Esperado: 2\n";

        assert(res == 5);
        assert(swaps == 2);
        assert((arr == vector<int>{3, 2, 1, 4, 5, 6}));
        cout << "[PASSOU Teste 1]\n\n";
    }

    {
        vector<int> arr = {3, 2, 3, 1, 2, 4, 5, 5, 6};
        int n = 9, k = 4;
        ll swaps = 0;
        int res = quickselect(arr, 0, n - 1, n - k, swaps);

        cout << "Resultado: " << res << " | Esperado: 4\n";
        cout << "Vetor final: ";
        printVector(arr);
        cout << "Trocas: " << swaps << " | Esperado: 2\n";

        assert(res == 4);
        assert(swaps == 2);
        assert((arr == vector<int>{3, 2, 3, 1, 2, 4, 5, 5, 6}));
        cout << "[PASSOU Teste 2]\n\n";
    }

    cout << "Todos os testes locais passaram com sucesso!\n";
}

int main() {
    IOFAST();
    runLocalTests();
    // onlineJudge();

    return 0;
}