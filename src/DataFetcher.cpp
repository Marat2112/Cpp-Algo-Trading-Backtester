#include "DataFetcher.hpp"
#include <fstream>
#include <iostream>

DataFetcher::DataFetcher(const std::string& api_key) : api_key_(api_key) {}

bool DataFetcher::fetchDailyData(const std::string& symbol, const std::string& output_path) {
    CURL* curl = curl_easy_init();
    if (!curl) return false;

    std::string url = "https://www.alphavantage.co/query?function=TIME_SERIES_DAILY&symbol=" 
                    + symbol + "&apikey=" + api_key_ + "&outputsize=full&datatype=json";

    std::ofstream out_file(output_path);
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &out_file);

    CURLcode res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    if (res != CURLE_OK) {
        std::cerr << "Ошибка загрузки данных: " << curl_easy_strerror(res) << std::endl;
        return false;
    }
    return true;
}

size_t DataFetcher::writeCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    std::ofstream* stream = static_cast<std::ofstream*>(userp);
    stream->write(static_cast<char*>(contents), size * nmemb);
    return size * nmemb;
}
