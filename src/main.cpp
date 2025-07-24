#include "DataFetcher.hpp"
#include "Backtester.hpp"
#include <nlohmann/json.hpp>
#include <fstream>

using json = nlohmann::json;

std::vector<OHLC> parseJSON(const std::string& file_path) {
    std::ifstream f(file_path);
    json data = json::parse(f);
    std::vector<OHLC> ohlc_data;

    for (auto& [date, values] : data["Time Series (Daily)"].items()) {
        OHLC entry;
        entry.date = date;
        entry.open = std::stod(values["1. open"].get<std::string>());
        entry.high = std::stod(values["2. high"].get<std::string>());
        entry.low = std::stod(values["3. low"].get<std::string>());
        entry.close = std::stod(values["4. close"].get<std::string>());
        entry.volume = std::stol(values["5. volume"].get<std::string>());
        ohlc_data.push_back(entry);
    }
    return ohlc_data;
}

int main() {
    const std::string api_key = "7UCU42EM5QOHKE7P"; // Замените на ваш ключ!
    const std::string symbol = "AAPL";
    const std::string data_path = "data/AAPL.json";

    // Загрузка данных
    DataFetcher fetcher(api_key);
    if (!fetcher.fetchDailyData(symbol, data_path)) {
        return 1;
    }

    // Парсинг JSON
    auto ohlc_data = parseJSON(data_path);

    // Бэктестинг
    Backtester backtester;
    backtester.run(ohlc_data, 10, 50); // SMA(10) vs SMA(50)

    return 0;
}
