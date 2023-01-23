#pragma once

#include <cstddef>
#include <cstdint>
#include <type_traits>

namespace base::memory
{
	class handle
	{
	public:
		handle(void *ptr = nullptr);
		explicit handle(std::uintptr_t ptr);

		template <typename T>
		std::enable_if_t<std::is_pointer_v<T>, T> as();

		template <typename T>
		std::enable_if_t<std::is_lvalue_reference_v<T>, T> as();

		template <typename T>
		std::enable_if_t<std::is_same_v<T, std::uintptr_t>, T> as();

		template <typename T>
		handle add(T offset);

		template <typename T>
		handle sub(T offset);

		handle jmp();

		explicit operator bool();

		friend bool operator==(handle a, handle b);
		friend bool operator!=(handle a, handle b);

	private:
		void *m_ptr;
	};

	inline handle::handle(void *ptr)
	:
		m_ptr(ptr)
	{}

	inline handle::handle(std::uintptr_t ptr)
	:
		m_ptr(reinterpret_cast<void *>(ptr))
	{}

	template <typename T>
	inline std::enable_if_t<std::is_pointer_v<T>, T> handle::as()
	{
		return static_cast<T>(m_ptr);
	}

	template <typename T>
	inline std::enable_if_t<std::is_lvalue_reference_v<T>, T> handle::as()
	{
		return *static_cast<std::add_pointer_t<std::remove_reference_t<T>>>(m_ptr);
	}

	template <typename T>
	inline std::enable_if_t<std::is_same_v<T, std::uintptr_t>, T> handle::as()
	{
		return reinterpret_cast<std::uintptr_t>(m_ptr);
	}

	template <typename T>
	inline handle handle::add(T offset)
	{
		return handle(as<std::uintptr_t>() + offset);
	}

	template <typename T>
	inline handle handle::sub(T offset)
	{
		return handle(as<std::uintptr_t>() - offset);
	}

	inline handle handle::jmp()
	{
		return add((((as<std::int32_t &>() & 0xFFFFFF) << 2) << 6) >> 6).add(8);
	}

	inline handle::operator bool()
	{
		return m_ptr != nullptr;
	}

	inline bool operator==(handle a, handle b)
	{
		return a.m_ptr == b.m_ptr;
	}

	inline bool operator!=(handle a, handle b)
	{
		return a.m_ptr != b.m_ptr;
	}
}