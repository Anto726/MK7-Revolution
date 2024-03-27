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
					"speed": { "status": true, "value": 32.0 },
					"delay": 15,
					"height": 128.0,
					"width": 256.0
				},
				"item_wheel":
				{
					"items": [0, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 13, 14]
				}
			},
			"kart":
			{
				"intangibility":
				{
					"invert": true
				},
				"kart_statuses":
				{
					"blink": true,
					"ink": true,
					"press": false,
					"star": false,
					"thunder": false
				},
				"instant_miniturbo":
				{
					"type": 1
				}
			},
			"network":
			{
				"protections":
				{
					"network": true
				}
			}
		})"_json;
	};

	inline settings g_settings;
}
