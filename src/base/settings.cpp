#include <base/settings.hpp>

#include <base/files.hpp>
#include <base/logger.hpp>

#include <CTRPluginFramework.hpp>

namespace base
{
	using namespace CTRPluginFramework;

	bool settings::load()
	{
		if (load_impl())
		{
			std::vector<std::tuple<nlohmann::json *, std::string, nlohmann::json>> additions;
			emplace_traverse(m_options, m_default_options, additions);
			for (auto &[options, key, value] : additions)
				options->emplace(key, value);

			std::vector<std::pair<nlohmann::json *, std::string>> removals;
			erase_traverse(m_options, m_default_options, removals);
			for (auto &[options, key] : removals)
				options->erase(key);

			if (!additions.empty() || !removals.empty())
				return store();

			return true;
		}

		return reset();
	}

	bool settings::store()
	{
		if (g_files->m_settings.Clear() == File::OPResult::SUCCESS)
		{
			auto dump = m_options.dump(4);
			return g_files->m_settings.Write(dump.c_str(), strlen(dump.c_str())) == File::OPResult::SUCCESS;
		}

		return false;
	}

	bool settings::reset()
	{
		if (g_files->m_settings.Clear() == File::OPResult::SUCCESS)
		{
			auto dump = m_default_options.dump(4);
			
			if (g_files->m_settings.Write(dump.c_str(), strlen(dump.c_str())) == File::OPResult::SUCCESS)
			{
				m_options = m_default_options;
				g_logger.debug("Settings reset.");
				return true;
			}
		}

        return false;
	}

	bool settings::load_impl()
	{
		bool result{};

		auto size = g_files->m_settings.GetSize();

		if (size > 0)
		{
			if (auto buffer = new char[size]; buffer != nullptr)
			{
				if (g_files->m_settings.Read(buffer, size) == File::OPResult::SUCCESS)
				{
					std::string dump(buffer, size);
					m_options = nlohmann::json::parse(dump);
					result = true;
				}

				delete[] buffer;
			}
		}

        return result;
	}

	void settings::emplace_traverse(nlohmann::json &options, nlohmann::json const &default_options, std::vector<std::tuple<nlohmann::json *, std::string, nlohmann::json>> &additions)
	{
		for (auto const &[key, value] : default_options.items())
		{
			if (value.is_object())
			{
				if (options.contains(key))
					emplace_traverse(options.at(key), default_options.at(key), additions);
				else
					additions.push_back({ &options, key, value});
			}
			else
			{
				if (!options.contains(key))
					additions.push_back({ &options, key, value });
			}
		}
	}

	void settings::erase_traverse(nlohmann::json &options, nlohmann::json const &default_options, std::vector<std::pair<nlohmann::json *, std::string>> &removals)
	{
		for (auto const &[key, value] : options.items())
		{
			if (value.is_object())
			{
				if (default_options.contains(key))
					erase_traverse(options.at(key), default_options.at(key), removals);
				else
					removals.push_back({ &options, key });
			}
			else
			{
				if (!default_options.contains(key))
					removals.push_back({ &options, key });
			}
		}
	}
}