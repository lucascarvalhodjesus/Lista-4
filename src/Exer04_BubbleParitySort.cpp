#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cassert>

using namespace std;

#define IOFAST() ios_base::sync_with_stdio(0); cin.tie(0);

void printVector(const vector<int>& v) {
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i] << (i + 1 == v.size() ? "" : " ");
    }
    cout << "\n";
}

bool should_swap(int a, int b) {
    bool a_is_even = (a % 2 == 0);
    bool b_is_even = (b % 2 == 0);

    if (!a_is_even && b_is_even) return true;
    if (a_is_even && !b_is_even) return false;

    if (a_is_even && b_is_even) {
        return a > b;
    } else {
        return a < b;
    }
}

void bubble_sort_parity(vector<int>& arr) {
    int n = static_cast<int>(arr.size());
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (should_swap(arr[j], arr[j + 1])) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

int hoare_partition_parity(vector<int>& arr, int low, int high) {
    int i = low - 1;
    int j = high + 1;

    while (true) {
        do {
            ++i;
        } while (i <= high && arr[i] % 2 == 0);

        do {
            --j;
        } while (j >= low && arr[j] % 2 != 0);

        if (i >= j) return j;

        swap(arr[i], arr[j]);
    }
}

void hoare_parity_sort(vector<int>& arr) {
    int n = static_cast<int>(arr.size());
    if (n <= 1) return;

    int split = hoare_partition_parity(arr, 0, n - 1);

    if (split >= 0) {
        sort(arr.begin(), arr.begin() + split + 1);
    }
    if (split + 1 < n) {
        sort(arr.begin() + split + 1, arr.end(), greater<int>());
    }
}

void onlineJudge() {
    int n;
    if (!(cin >> n)) return;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    hoare_parity_sort(arr);

    printVector(arr);
}

void runLocalTests() {
    cout << "=== Question 4 (Hoare Partition Parity Sort) ===\n\n";

    {
        vector<int> arr1 = {4, 3, 2, 7, 8, 1};
        vector<int> arr2 = arr1;

        bubble_sort_parity(arr1);
        hoare_parity_sort(arr2);

        cout << "Teste 1 (Bubble): ";
        printVector(arr1);
        cout << "Teste 1 (Hoare) : ";
        printVector(arr2);

        vector<int> expected = {2, 4, 8, 7, 3, 1};
        assert(arr1 == expected);
        assert(arr2 == expected);
        cout << "[PASSOU Teste 1]\n\n";
    }

    {
        vector<int> arr1 = {10, 9, 8, 7, 6};
        vector<int> arr2 = arr1;

        bubble_sort_parity(arr1);
        hoare_parity_sort(arr2);

        cout << "Teste 2 (Bubble): ";
        printVector(arr1);
        cout << "Teste 2 (Hoare) : ";
        printVector(arr2);

        vector<int> expected = {6, 8, 10, 9, 7};
        assert(arr1 == expected);
        assert(arr2 == expected);
        cout << "[PASSOU Teste 2]\n\n";
    }

    {
        vector<int> arr = {2, 4, 6};
        hoare_parity_sort(arr);
        assert((arr == vector<int>{2, 4, 6}));
        cout << "[PASSOU Teste Apenas Pares]\n\n";
    }

    {
        vector<int> arr = {1, 3, 5};
        hoare_parity_sort(arr);
        assert((arr == vector<int>{5, 3, 1}));
        cout << "[PASSOU Teste Apenas Impares]\n\n";
    }

    cout << "Todos os testes locais passaram com sucesso!\n";
}

int main() {
    IOFAST();
    runLocalTests();
    // onlineJudge();

    return 0;
}