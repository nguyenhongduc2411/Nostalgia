// -----------------------------------------------------------------------------------
typedef long long ll;
class Bank {
private:
    vector<ll> a;
    bool isValidAcc(int account) {
        return account >= 1 && account <= a.size();
    }
public:
    Bank(vector<long long>& balance) {
        swap(a, balance);
    }
    
    bool transfer(int account1, int account2, long long money) {
        if (!isValidAcc(account1) || !isValidAcc(account2))
            return false;

        if (a[account1 - 1] < money)
            return false;

        a[account1 - 1] -= money;
        a[account2 - 1] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if (!isValidAcc(account))
            return false;

        a[account - 1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if (!isValidAcc(account))
            return false;
            
        if (a[account - 1] < money)
            return false;

        a[account - 1] -= money;
        return true;
    }
};

// -----------------------------------------------------------------------------------
class Solution {
public:
    int numberOfBeams(vector<string>& a) {
        int n = a.size();
        int prev = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int cnt = count(a[i].begin(), a[i].end(), '1');
            if (cnt > 0) {
                ans += prev * cnt;
                prev = cnt;
            }
        }
        return ans;
    }
};

// -----------------------------------------------------------------------------------
class Solution {
public:
    int countValidSelections(vector<int>& a) {
        int sum = accumulate(a.begin(), a.end(), 0);
        int left = 0;
        int ans = 0;
        for (int u : a) {
            if (u == 0) {
                int right = sum - left;
                if (left == right)
                    ans += 2;
                else if (abs(left - right) == 1)
                    ans++;
            }
            left += u;
        }
        return ans;
    }
};

// -----------------------------------------------------------------------------------
class Solution {
public:
    int smallestNumber(int n) {
        int cur = 1; // 2^0
        while (cur - 1 < n) {
            cur = cur << 1;
        }
        return cur - 1;
    }
};