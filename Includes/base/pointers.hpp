#pragma once

namespace base
{
	class pointers
	{
	public:
		explicit pointers();
		~pointers();
	};

	inline pointers *g_pointers{};
}