#include <type_traits>
#include <cstddef>

using namespace std;

template <class... Types>
class A {
public:
	A() = default;

	template <size_t Idx, typename = enable_if_t<(Idx < sizeof...(Types))>> // Works with parens
		A(int, int) {}

		template <size_t Idx, typename = enable_if_t<Idx < sizeof...(Types)>> // Errors without parens
			A(int) {}
};

int main() {
	A<char, float, int, double, unsigned short>{};
}
