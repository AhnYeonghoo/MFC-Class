#include <iostream>

template<typename T, unsigned int N>
class Array
{
	T data[N];
	
public:
	Array(T(&arr)[N])
	{
		for (int i = 0; i < N; i++)
		{
			data[i] = arr[i];
		}
	}

	T* GetArray() { return data; }

	unsigned int size() { return N; }
	
	void PrintAll()
	{
		for (int i = 0; i < N; i++)
		{
			std::cout << data[i] << ", ";
		}
		std::cout << std::endl;
	}
};

template<int N>
struct Int
{
	static const int num = N;
};

template<typename T, typename U>
struct add
{
	typedef Int<T::num + U::num> result;
};

template<int N>
struct Factorial
{
	static const int result = N * Factorial<N - 1>::result;
};

template<>
struct Factorial<1>
{
	static const int result = 1;
};

template<int X, int Y>
struct GCD
{
	static const int value = GCD<Y, X% Y>::value;
};

template<int X>
struct GCD<X, 0>
{
	static const int value = x;
};

template<int N, int D = 1>
struct Ratio
{
	typedef Ratio<N, D> type;
	static const int num = N;
	static const int den = D;
};

template<class R1, class R2>
struct _Ratio_add
{
	typedef Ratio<R1::num* R2::den + R2::num * R1::den * R2::den> type;
};

int main()
{
	int arr[3]{ 1,2, 3 };
	Array<int, 3> arrW(arr);

	arrW.PrintAll();

	typedef Int<1> one;
	typedef Int<2> two;
	
	typedef add<one, two>::result three;
	std::cout << "Addtion result: " << three::num << std::endl;

	std::cout << "6! = 1*2*3*4*5*6 = " << Factorial<6>::result << std::endl;
	return 0;
}