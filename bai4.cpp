#include <iostream>
#include <vector>
using namespace std;
int n;
vector<vector<int>> a;  // Ma tran goc
// ham bien doi ma tran theo Arnold's Cat Map
void Arnold(const vector<vector<int>>& source, vector<vector<int>>& dest) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x_new = (2 * i + j) % n;
            int y_new = (i + j) % n;
            dest[x_new][y_new] = source[i][j];
        }
    }
}
// Ham so sanh xem 2 ma tran co giong nhau khong
bool compare(const vector<vector<int>>& mat1, const vector<vector<int>>& mat2) {

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mat1[i][j] != mat2[i][j]) return false;
        }
    }
    return true;
}
// ham tim chu trinh cua ma tran
int findCycle() {
    // Khoi tao ma tran tam đe luu các lan bien đoi
    vector<vector<int>> temp = a, transformed(n, vector<int>(n));

    int cycle = 0;
    while (true) {
        cycle++;
        Arnold(temp, transformed);  // Bien đoi Arnold
        if (compare(a, transformed)) break;  // Neu quay ve trang thai ban dau stop
        // Cap nhat temp de lap tiep
        temp = transformed;
    }
    return cycle;
}

int main() {
    cin >> n;

    a.resize(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    int chu_ky = findCycle();
    cout << chu_ky << "\n";

    return 0;
}
