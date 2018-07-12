#include "catch.h"
#include "determinant.h"


TEST_CASE( "LU testing max(L*U - A)") {
    SECTION("size 4") {
        const int n = 4;

        vector<vector<double>> A(n), L(n), U(n), L_U(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                A[i].push_back(rand() % 20 - 10);
                L[i].push_back(0);
                U[i].push_back(0);
                L_U[i].push_back(0);
            }
        }

        CHECK(LU_test(1, n, A, L, U, L_U) < 0.001);

        CHECK(LU_test(2, n, A, L, U, L_U) < 0.001);

        CHECK(LU_test(5, n, A, L, U, L_U) < 0.001);

        CHECK(LU_test(8, n, A, L, U, L_U) < 0.001);

        CHECK(LU_test(16, n, A, L, U, L_U) < 0.001);

        CHECK(LU_test(31, n, A, L, U, L_U) < 0.001);

        CHECK(LU_test(71, n, A, L, U, L_U) < 0.001);
    }

    SECTION("size 400") {
        const int n = 400;

        vector<vector<double>> A(n), L(n), U(n), L_U(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                A[i].push_back(rand() % 20 - 10);
                L[i].push_back(0);
                U[i].push_back(0);
                L_U[i].push_back(0);
            }
        }

        CHECK(LU_test(1, n, A, L, U, L_U) < 0.001);

        CHECK(LU_test(2, n, A, L, U, L_U) < 0.001);

        CHECK(LU_test(5, n, A, L, U, L_U) < 0.001);

        CHECK(LU_test(8, n, A, L, U, L_U) < 0.001);

        CHECK(LU_test(16, n, A, L, U, L_U) < 0.001);

        CHECK(LU_test(31, n, A, L, U, L_U) < 0.001);

        CHECK(LU_test(71, n, A, L, U, L_U) < 0.001);
    }

}