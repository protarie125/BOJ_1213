#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	string l;
	cin >> l;

	auto m = map<char, int>{};

	const auto& n = static_cast<int>(l.length());
	for (int i = 0; i < n; ++i) {
		++m[l[i]];
	}

	auto oddChar = char{};
	auto oddCount = int{ 0 };
	for (const auto& [x, v] : m) {
		if (1 == v % 2) {
			++oddCount;
			oddChar = x;
		}
	}

	if (1 < oddCount) {
		cout << "I'm Sorry Hansoo";
		return 0;
	}

	if (1 == oddCount) {
		auto idx = int{ 0 };
		for (const auto& [x, v] : m) {
			if (x == oddChar) {
				const auto& w = (v - 1) / 2;
				for (int i = 0; i < w; ++i) {
					l[idx] = x;
					l[n - 1 - idx] = x;

					++idx;
				}

				l[(n - 1) / 2] = x;
			}
			else {
				const auto& w = v / 2;
				for (int i = 0; i < w; ++i) {
					l[idx] = x;
					l[n - 1 - idx] = x;

					++idx;
				}
			}
		}

		cout << l;
		return 0;
	}

	auto idx = int{ 0 };
	for (const auto& [x, v] : m) {
		const auto& w = v / 2;
		for (int i = 0; i < w; ++i) {
			l[idx] = x;
			l[n - 1 - idx] = x;

			++idx;
		}
	}

	cout << l;

	return 0;
}