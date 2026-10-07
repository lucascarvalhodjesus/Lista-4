#include <iostream>
#include <vector>
#include <string>
#include <utility>

// a)
void merge(std::vector<std::string>& arr, std::vector<std::string>& temp, int left, int mid, int right) {
    int i = left;      // Varredura da partição esquerda
    int j = mid + 1;   // Varredura da partição direita
    int k = left;      // Índice de escrita no buffer temporário

    while (i <= mid && j <= right) {
        // CONDIÇÃO CRÍTICA DE ESTABILIDADE: '>='
        // Em empates de comprimento, o elemento da esquerda (i) tem prioridade,
        // preservando sua precedência original na sequência.
        if (arr[i].size() >= arr[j].size()) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; ++i) {
        arr[i] = temp[i];
    }
}

void mergeSort(std::vector<std::string>& arr, std::vector<std::string>& temp, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, temp, left, mid);
        mergeSort(arr, temp, mid + 1, right);
        merge(arr, temp, left, mid, right);
    }
}

void stableMergeSort(std::vector<std::string>& arr) {
    if (arr.empty()) return;
    std::vector<std::string> temp(arr.size());
    mergeSort(arr, temp, 0, static_cast<int>(arr.size()) - 1);
}

// b)
int partitionLomutoDesc(std::vector<std::string>& arr, int low, int high) {
    size_t pivotLen = arr[high].size(); // Pivô fixado à direita
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        // Elementos com tamanho estritamente maior que o pivô vão para o prefixo
        if (arr[j].size() > pivotLen) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    // Troca de longa distância: insere o pivô na posição divisora definitiva
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(std::vector<std::string>& arr, int low, int high) {
    if (low < high) {
        int p = partitionLomutoDesc(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

void unstableQuickSort(std::vector<std::string>& arr) {
    if (arr.empty()) return;
    quickSort(arr, 0, static_cast<int>(arr.size()) - 1);
}