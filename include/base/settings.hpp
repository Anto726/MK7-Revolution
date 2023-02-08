#pragma once
#include <nlohmann/json.hpp>

namespace base
{
	class settings
	{
	public:
		explicit settings() = default;
		~settings() = default;

		bool load();
		bool store();
		bool reset();
		
		nlohmann::json m_options;

	private:
		bool load_impl();

		nlohmann::json const m_default_options =
		R"({
			"kart":
			{
				"intangibility":
				{
					"invert": false
				},
				"instant_miniturbo":
				{
					"type": 0
				}
			}
		})"_json;
	};

	inline settings g_settings;
}
