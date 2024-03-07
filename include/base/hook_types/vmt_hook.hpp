#pragma once

#include <memory>
#include <string_view>

namespace base::hook_types
{
    class vmt_hook
	{
	public:
		explicit vmt_hook(std::string_view name, void *obj, size_t num_funcs);
		~vmt_hook();

		vmt_hook(vmt_hook &&) = delete;
		vmt_hook(vmt_hook const &) = delete;
		vmt_hook &operator=(vmt_hook &&) = delete;
		vmt_hook &operator=(vmt_hook const &) = delete;

		void hook(size_t index, void *func);
		void unhook(size_t index);

		void enable();
		void disable();

		template <typename t>
		t get_original(size_t index);

	private:
		std::string_view m_name;
		void ***m_object;
		std::size_t m_num_funcs;
		void **m_original_table;
		std::unique_ptr<void *[]> m_new_table;
	};

	template <typename t>
	inline t vmt_hook::get_original(size_t index)
	{
		return reinterpret_cast<t>(m_original_table[index]);
	}
}