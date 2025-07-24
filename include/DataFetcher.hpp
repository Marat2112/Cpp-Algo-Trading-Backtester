#pragma once
#include <string>
#include <curl/curl.h>

class DataFetcher {
public:
    DataFetcher(const std::string& api_key);
    bool fetchDailyData(const std::string& symbol, const std::string& output_path);
    static size_t writeCallback(void* contents, size_t size, size_t nmemb, void* userp);

private:
    std::string api_key_;
};
