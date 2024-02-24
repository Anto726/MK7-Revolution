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

		static void emplace_traverse(nlohmann::json &, nlohmann::json const &, std::vector<std::tuple<nlohmann::json *, std::string, nlohmann::json>> &);
		static void erase_traverse(nlohmann::json &, nlohmann::json const &, std::vector<std::pair<nlohmann::json *, std::string>> &);

		nlohmann::json const m_default_options =
		R"({
			"item":
			{
				"item_rain":
				{
					"items": [0, 1, 2, 3, 4],
					"multi": false,
					"delay": 15,
					"height": 128.0,
					"width": 256.0
				}
			},
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
