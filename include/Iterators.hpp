#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include <functional>
#include <optional>

namespace stackixx {
	template <typename T>
	class random_access_iterator {
	public:
		using iterator_category = std::random_access_iterator_tag;
		using difference_type = std::ptrdiff_t;
		using value_type = T;
		using pointer = value_type*;
		using reference = value_type&;

		random_access_iterator():
			_ptr(nullptr) {}

		random_access_iterator(pointer ptr):
			_ptr(ptr) {}

		reference operator*() const { return *_ptr; }
		pointer   operator->() const { return _ptr; }

		random_access_iterator& operator++() {
			++_ptr;
			return *this;
		}

		random_access_iterator operator++(int) {
			auto tmp(*this);
			++_ptr;
			return tmp;
		}

		random_access_iterator& operator--() {
			--_ptr;
			return *this;
		}

		random_access_iterator operator--(int) {
			auto tmp(*this);
			--_ptr;
			return tmp;
		}

		difference_type operator-(const random_access_iterator& rhs) const { return _ptr - rhs._ptr; }

		bool operator==(const random_access_iterator& rhs) const { return _ptr == rhs._ptr; }
		bool operator<(const random_access_iterator& rhs) const { return _ptr < rhs._ptr; }
		bool operator<=(const random_access_iterator& rhs) const { return _ptr <= rhs._ptr; }
		bool operator>(const random_access_iterator& rhs) const { return _ptr > rhs._ptr; }
		bool operator>=(const random_access_iterator& rhs) const { return _ptr >= rhs._ptr; }

		friend random_access_iterator operator+(difference_type diff, const random_access_iterator& ite) {
			return ite + diff;
		};
		random_access_iterator operator+(difference_type diff) const { return _ptr + diff; }

		random_access_iterator& operator+=(difference_type diff) {
			_ptr += diff;
			return *this;
		}

		random_access_iterator operator-(difference_type diff) const { return _ptr - diff; }

		random_access_iterator& operator-=(difference_type diff) {
			_ptr -= diff;
			return *this;
		}

		reference operator[](difference_type i) const { return *(_ptr + i); }

	private:
		pointer _ptr;
	};

	template <typename T>
	class reverse_bidirectional_iterator {
	public:
		using iterator_category = std::bidirectional_iterator_tag;
		using difference_type = std::ptrdiff_t;
		using value_type = T;
		using pointer = T*;
		using reference = T&;

		reverse_bidirectional_iterator():
			_ptr(nullptr) {}

		reverse_bidirectional_iterator(pointer ptr):
			_ptr(ptr) {}

		reference operator*() const { return *_ptr; }
		pointer   operator->() const { return _ptr; }

		reverse_bidirectional_iterator& operator++() {
			--_ptr;
			return *this;
		}

		reverse_bidirectional_iterator operator++(int) {
			auto tmp(*this);
			--_ptr;
			return tmp;
		}

		reverse_bidirectional_iterator& operator--() {
			++_ptr;
			return *this;
		}

		reverse_bidirectional_iterator operator--(int) {
			auto tmp(*this);
			++_ptr;
			return tmp;
		}

		bool operator==(const reverse_bidirectional_iterator& rhs) const { return _ptr == rhs._ptr; }

	private:
		pointer _ptr;
	};

	template <typename T, typename U>
	class map_iterator {
	public:
		using iterator_category = std::forward_iterator_tag;
		using difference_type = std::ptrdiff_t;
		using value_type = U;

		map_iterator() = delete;

		map_iterator(std::function<U(T)> func):
			_ptr(nullptr), _func(func) {}

		map_iterator(T* ptr, std::function<U(T)> func):
			_ptr(ptr), _func(func) {}

		U operator*() const {
			if (!_out.has_value())
				_out = _func(*_ptr);

			return _out.value();
		}

		T* operator->() const { return _ptr; }

		map_iterator& operator++() {
			_out.reset();
			++_ptr;
			return *this;
		}

		map_iterator operator++(int) {
			auto tmp(*this);
			_out.reset();
			++_ptr;
			return tmp;
		}

		bool operator==(const map_iterator& rhs) const { return _ptr == rhs._ptr; }
		bool operator==(const random_access_iterator<T>& rhs) const { return _ptr == rhs.operator->(); }

	private:
		T*                       _ptr;
		std::function<U(T)>      _func;
		mutable std::optional<U> _out;
	};

	template <typename T>
	bool operator==(const reverse_bidirectional_iterator<T>& lhs, const random_access_iterator<T>& rhs) {
		return lhs.operator->() == rhs.operator->();
	}

	template <typename T>
	bool operator==(const random_access_iterator<T>& lhs, const reverse_bidirectional_iterator<T>& rhs) {
		return lhs.operator->() == rhs.operator->();
	}
}

#endif // ITERATOR_HPP
