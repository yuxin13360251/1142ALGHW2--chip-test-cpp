#include <iostream>
#include <vector>
using namespace std;

// report[i][j] = 晶片 i 對晶片 j 的判斷
// true  表示 i 說 j 是好晶片
// false 表示 i 說 j 是壞晶片

class ChipTester {
private:
    vector<vector<bool>> report;

public:
    ChipTester(const vector<vector<bool>>& r) : report(r) {}

    // 回傳一顆好晶片的索引；若無法找到則回傳 -1
    int findGoodChip(vector<int> chips) {
        // TODO:
        // 反覆執行下列步驟：
        //
        // 1. 若 chips 中只剩一顆晶片，直接回傳它的索引
        //
        // 2. 令第一顆晶片為候選晶片 A
        //
        // 3. 設 V = 0
        //
        // 4. 將 A 與其餘晶片逐一互測：
        //    若 A 說 B 是好的，且 B 說 A 是好的，則 V++
        //
        // 5. 若 V >= n/2，回傳 A
        //
        // 6. 否則刪除 A，對剩下的晶片重複測試

        while (true) {
            int n = chips.size();

            if (n == 1) {
                return chips[0];
            }

            int A = chips[0];
            int V = 0;

            for (int i = 1; i < n; i++) {
                int B = chips[i];

                if (report[A][B] && report[B][A]) {
                    V++;
                }
            }

            // ✅ 修正這裡
            if (V >= (n - 1) / 2) {
                return A;
            } else {
                chips.erase(chips.begin());
            }

            if (chips.empty()) {
                return -1;
            }
        }

        return -1;
    }
};

int main() {
    // 範例：6 顆晶片，編號 0~5
    // 假設好晶片多於壞晶片
    // 好晶片會誠實回答，壞晶片可任意回答

    vector<vector<bool>> report = {
        // 0    1    2    3    4    5
        {true, true, true, false, true, false},
        {true, true, true, false, true, false},
        {true, true, true, false, true, false},
        {true, false, true, true, false, true},
        {true, true, true, false, true, false},
        {false, true, false, true, true, true}
    };

    ChipTester tester(report);

    vector<int> chips = {0, 1, 2, 3, 4, 5};

    int goodChip = tester.findGoodChip(chips);

    if (goodChip != -1) {
        cout << "Found a good chip: chip " << goodChip << endl;
    } else {
        cout << "No good chip found." << endl;
    }

    return 0;
}
