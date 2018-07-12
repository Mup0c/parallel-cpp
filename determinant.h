#include <iostream>
#include <cmath>
#include <iomanip>
#include <thread>
#include <vector>

using namespace std;

void show(const vector<vector<double>> &A, int n)
{
    for(int i = 0; i < n; i++) {
        cout << "\t";
        for(int j = 0; j < n; j++) {
            cout << (A[i][j]) << "\t";
        }
        cout << endl;
    }
}

void LU(const vector<vector<double>> &A, vector<vector<double>> &L, vector<vector<double>> &U, int n)
{
    U = A;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            L[j][i] = U[j][i] / U[i][i];
        }
    }
    show(L, n);
    for(int k = 1; k < n; k++) {
        for(int i = k - 1; i < n; i++) {
            for(int j = i; j < n; j++) {
                L[j][i] = U[j][i] / U[i][i];
            }
        }
        for(int i = k; i < n; i++) {
            for(int j = k - 1; j < n; j++) {
                U[i][j] = U[i][j] - L[i][k-1] * U[k-1][j];
            }
        }
    }
}

//mutex mu;

void LU_1(vector<vector<double>> &L, vector<vector<double>> &U, int n, int from, int to)
{
    for (int i = from; i < to; i++) {
        for (int j = i; j < n; j++) {
            //lock_guard<mutex> guard(mu);
            L[j][i] = U[j][i] / U[i][i];
        }
    }
}

void LU_2(vector<vector<double>> &L, vector<vector<double>> &U, int n, int from, int to)
{
    for(int i = from; i < to; i++) {
        for(int j = i; j < n; j++) {
            L[j][i] = U[j][i] / U[i][i];
        }
    }
}

void LU_3(vector<vector<double>> &L, vector<vector<double>> &U, int n, int from, int to, int k)
{
    for(int i = from; i < to; i++) {
        for(int j = k - 1; j < n; j++) {
            U[i][j] = U[i][j] - L[i][k-1] * U[k-1][j];
        }
    }
}


void multiplication(const vector<vector<double>> &A, const vector<vector<double>> &B, vector<vector<double>> &R, int n)
{
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                R[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}


void thr_join(vector<thread> &threads)
{
    for (int i = 0; i < threads.size(); ++i){
        threads[i].join();
    }
    threads.resize(0);
}


int LU_eval()
{
    const int n=4;
    vector<vector<double>> A (n), L (n), U(n), R(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            //rand();
            A[i].push_back(rand()%20 - 10);
            L[i].push_back(0);
            U[i].push_back(0);
            R[i].push_back(0);
        }
    }
    cout << std::setprecision(2) << std::fixed;
    LU(A, L, U, n);
    cout << "Initial matrix" << endl;
    show(A,n);
    cout << "U matrix" << endl;
    show(U,n);
    cout << "L matrix" << endl;
    show(L,n);
    multiplication(L,U,R,n);
    cout << "L*U matrix" << endl;
    show(R,n);
    int det = 1;
    for (int i = 0; i < n; i++) {
        det *= U[i][i];
    }
    cout << det << " <- det";
    return 0;
}

int LU_eval_threading(int threads_num) {
    const int n=1000;
    vector<vector<double>> A (n), L (n), U(n), R(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            A[i].push_back(rand()%20 - 10);
            L[i].push_back(0);
            U[i].push_back(0);
            R[i].push_back(0);
        }
    }
    cout << std::setprecision(2) << std::fixed;
    vector<thread> threads;
    U = A;
    int interval = int(ceil(double(n) / double(threads_num)));
    for (int i = 0; i < threads_num; ++i) {
        threads.emplace_back(LU_1, ref(L), ref(U), n, i * interval, min(n, (i + 1) * interval));
    }
    thr_join(threads);
    for(int k = 1; k < n; k++) {

        interval = int(ceil(double(n - k + 1) / double(threads_num)));
        for (int i = 0; i < threads_num; ++i) {
            threads.emplace_back(LU_2, ref(L), ref(U), n, k - 1 + i * interval, min(n, k - 1 + (i + 1) * interval));
        }
        thr_join(threads);

        interval = int(ceil(double(n - k) / double(threads_num)));
        for (int i = 0; i < threads_num; ++i) {
            threads.emplace_back(LU_3, ref(L), ref(U), n, k + i * interval, min(n, k + (i + 1) * interval), k);
        }
        thr_join(threads);

    }
    cout << "Initial matrix" << endl;
    show(A,n);
    cout << "U matrix" << endl;
    show(U,n);
    cout << "L matrix" << endl;
    show(L,n);
    multiplication(L,U,R,n);
    cout << "L*U matrix" << endl;
    show(R,n);
    long long det = 1;
    for (int i = 0; i < n; i++) {
        det *= U[i][i];
    }
    cout << det << " <- det";
    return 0;

    //thread t1
}