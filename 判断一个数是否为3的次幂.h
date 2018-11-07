static const auto __ = []() {
	//解除c++/c的io同步
    std::ios::sync_with_stdio(false);
	//解除cout与cin绑定
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool isPowerOfThree(int n) {
        long base = 1;
        while(base < n) {    base *= 3;    }
        return base == n;
    }
};