#include<iostream>
#include<vector>



template <class T>
class Bigint {
	friend std::ostream& operator <<(std::ostream & os, Bigint r) {
		auto ptr = r.vec.rbegin();
		while (ptr != r.vec.rend()) {
			os << *ptr++;
		}
		return os;
	}
public:

	Bigint() = default;

	Bigint(int x) {
		vec.push_back(x);
	}

	Bigint operator +(const Bigint & r) const {
		int carry = 0;
		int maxn = r.vec.size() > vec.size() ? r.vec.size() : vec.size();
		Bigint res;
		for (auto i = 0; i < maxn; i++) {
			int n1 = i >= vec.size() ? 0 : vec[i];
			int n2 = i >= r.vec.size() ? 0 : r.vec[i];
			res.vec.push_back((n1 + n2 + carry) % 10);
			carry = (n1 + n2 + carry) / 10;
		}
		if (carry>0) res.vec.push_back(carry);
		return res;
	}

	Bigint operator *(const Bigint & r) const {
		int carry = 0;
		int num1 = vec.size();
		int num2 = r.vec.size();
		Bigint res;
		res.vec.resize(num1 + num2);
		for (auto i = 0; i < num1; i++) {
			for (auto j = 0; j< num2; j++) {
				int temp = vec[i] * r.vec[j];
				int t = res.vec[i + j];
				res.vec[i + j] = (t + temp + carry) % 10;
				res.vec[i + j + 1] = (t + temp + carry) / 10;
			}
		}
		while (res.vec.size() > 0 && res.vec.back() == 0 ) {
			res.vec.pop_back();
		}
		return res;
	}

private:
	std::vector<T> vec;

};




template<class T>
class sq_matrix {
	friend int main();
public:
	sq_matrix() :arr0(1), arr1(1), arr2(1), arr3(0) {}
	sq_matrix operator * (const sq_matrix& a) const {
		sq_matrix temp;
		temp.arr0 = arr0 * a.arr0 + arr1 * a.arr2;
		temp.arr1 = arr0 * a.arr1 + arr1 * a.arr3;
		temp.arr2 = arr2 * a.arr0 + arr3 * a.arr2;
		temp.arr3 = arr2 * a.arr1 + arr3 * a.arr3;
		return temp;
	}

	T arr0, arr1, arr2, arr3;
};


template<class Tp>
Tp fast_power(const Tp& m, int n) {
	if (n == 1) return m;
	if (n % 2) return m * fast_power(m*m, (n - 1) / 2);
	else return fast_power(m*m, n / 2);
}


int main() {
	sq_matrix<Bigint<int>> M;
	std::cout << fast_power(M,20).arr1;
	return 0;
}
