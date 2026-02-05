#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <random>
#include <chrono>
#include <string>
#include <iomanip>
#include <cassert>
#include "map_perm_algorithms.h"

using namespace std;

/**
 * 接口转换适配器 (Interface Adapter)
 * 解决测试代码中 MR_rank 与算法库中 MyrvoldRuskey_rank 名称不一致的问题
 */
void MR_rank(const vector<int> &D, vector<int> &C) {
    MyrvoldRuskey_rank(D, C);
}

void MR_unrank(const vector<int> &C, vector<int> &D) {
    MyrvoldRuskey_unrank(C, D);
}

// --- 正确性校验函数 ---
bool verify_logic(int n) {
    vector<int> original(n), C(n), restored(n);
    iota(original.begin(), original.end(), 0);
    mt19937 g(42);
    
    // 校验三种典型分布
    vector<string> cases = {"Sorted", "Reverse", "Random"};
    for (const auto& name : cases) {
        if (name == "Reverse") reverse(original.begin(), original.end());
        if (name == "Random") shuffle(original.begin(), original.end(), g);

        // PP 校验
        PositionPure_rank(original, C);
        PositionPure_unrank(C, restored);
        for (int i = 0; i < n; ++i) {
            if (original[i] != restored[i]) return false;
        }

        // MR 校验
        MR_rank(original, C);
        MR_unrank(C, restored);
        for (int i = 0; i < n; ++i) {
            if (original[i] != restored[i]) return false;
        }
    }
    return true;
}

// --- 性能测试核心 ---
typedef void (*RankFunc)(const vector<int>&, vector<int>&);

double measure_speed(RankFunc func, int n, int its, const string& dist) {
    vector<int> D(n), C(n);
    iota(D.begin(), D.end(), 0);
    if (dist == "Reverse") reverse(D.begin(), D.end());
    if (dist == "Random") {
        mt19937 g(123);
        shuffle(D.begin(), D.end(), g);
    }

    // 热身阶段
    func(D, C);

    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < its; ++i) {
        func(D, C);
    }
    auto end = chrono::high_resolution_clock::now();
    
    chrono::duration<double, nano> diff = end - start;
    return diff.count() / its;
}

int main() {
    // 阶段 1: 正确性验证
    cout << "====================================================" << endl;
    cout << "PHASE 1: CORRECTNESS VALIDATION" << endl;
    cout << "====================================================" << endl;
    
    if (verify_logic(10000)) {
        cout << "[SUCCESS] Both PP and MR algorithms passed round-trip tests." << endl;
    } else {
        cerr << "[FAILED] Logic error detected in algorithms!" << endl;
        return 1;
    }

    // 阶段 2: 性能对比测试
    cout << "\n==================================================================" << endl;
    cout << "PHASE 2: INDUSTRIAL BENCHMARK (Core-Locked Recommended)" << endl;
    cout << "==================================================================" << endl;
    cout << left << setw(10) << "N" << setw(12) << "Dist" 
         << setw(15) << "MR (ns/it)" << setw(15) << "PP (ns/it)" << "Speedup" << endl;
    cout << "------------------------------------------------------------------" << endl;

    vector<int> sizes = {1000, 100000, 1000000};
    vector<string> dists = {"Random", "Sorted", "Reverse"};

    for (int n : sizes) {
        // 动态调整迭代次数以平衡测试精度和时间
        int its = (n <= 1000) ? 10000 : (n <= 100000 ? 500 : 50);
        
        for (const auto& d : dists) {
            double t_mr = measure_speed(MR_unrank, n, its, d);
            double t_pp = measure_speed(PositionPure_unrank, n, its, d);
            double speedup = t_mr / t_pp;

            cout << left << setw(10) << n 
                 << setw(12) << d 
                 << setw(15) << fixed << setprecision(1) << t_mr
                 << setw(15) << fixed << setprecision(1) << t_pp
                 << setprecision(2) << speedup << "x" << endl;
        }
        cout << "------------------------------------------------------------------" << endl;
    }

    return 0;
}