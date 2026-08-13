#include <bits/stdc++.h>
using namespace std;

// Sieve of Eratosthenes để tìm tất cả số nguyên tố <= 100000
vector<bool> sieve(int maxn) {
    vector<bool> is_prime(maxn + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= maxn; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= maxn; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

// Kadane's algorithm: tìm max subarray sum
long long maxSubarraySum(vector<long long>& arr) {
    if (arr.empty()) return LLONG_MIN;

    long long max_so_far = arr[0];
    long long max_ending_here = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        max_ending_here = max(arr[i], max_ending_here + arr[i]);
        max_so_far = max(max_so_far, max_ending_here);
    }

    return max_so_far;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<long long> a(n);
    vector<int> b(n);

    set<int> unique_b;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        unique_b.insert(b[i]);
    }

    // Tìm tất cả số nguyên tố <= 100000
    vector<bool> is_prime = sieve(100000);

    long long ans = LLONG_MIN;
    bool found = false;

    // Với mỗi số nguyên tố p có trong dữ liệu
    for (int p : unique_b) {
        if (p < 2 || !is_prime[p]) continue;

        // Lấy tất cả a[i] mà b[i] == p
        vector<long long> values;
        for (int i = 0; i < n; i++) {
            if (b[i] == p) {
                values.push_back(a[i]);
            }
        }

        // Nếu có ít nhất một vị trí với b[i] == p
        if (!values.empty()) {
            found = true;
            long long max_sum = maxSubarraySum(values);
            ans = max(ans, max_sum);
        }
    }

    if (!found) {
        cout << "KHONG\n";
    } else {
        cout << ans << "\n";
    }

    return 0;
}
