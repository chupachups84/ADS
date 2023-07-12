#include <iostream>
#include <vector>

using namespace std;

// ������� ��� ������ �������
void print(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

// ������� ��� ��������� ������� ����������� ��������, ������� ������ ��������
int get_largest_mobile(vector<int> v, vector<int> dir) {
    int largest_mobile = -1;
    for (int i = 0; i < v.size(); i++) {
        if ((dir[i] == -1 && i > 0 && v[i] > v[i - 1] && v[i] > v[i - 1]) ||
            (dir[i] == 1 && i < v.size() - 1 && v[i] > v[i + 1] && v[i] > v[i - 1])) {
            if (largest_mobile == -1 || v[i] > v[largest_mobile]) {
                largest_mobile = i;
            }
        }
    }
    return largest_mobile;
}

// ������� ��� ��������� ����������� �������� ��������
void swap_directions(vector<int>& dir, int mobile_index) {
    for (int i = 0; i < dir.size(); i++) {
        if (v[i] > v[mobile_index]) {
            dir[i] *= -1;
        }
    }
}

// ������� ��� ��������� ��������� ������������
bool get_next_permutation(vector<int>& v, vector<int>& dir) {
    int mobile_index = get_largest_mobile(v, dir);
    if (mobile_index == -1) {
        return false;
    }
    int new_index = mobile_index + dir[mobile_index];
    swap(v[mobile_index], v[new_index]);
    swap_directions(dir, mobile_index);
    return true;
}

// ������� ��� ��������� ���� ������������ �� n ���������
void johnson_trotter(int n) {
    // ������������� ������� � ����������� ��������
    vector<int> v(n);
    vector<int> dir(n, -1);
    for (int i = 0; i < n; i++) {
        v[i] = i + 1;
    }

    print(v);

    while (get_next_permutation(v, dir)) {
        print(v);
    }
}

int main() {
    johnson_trotter(3); // ��������� ���� ������������ �� 3 ���������
    return 0;
}