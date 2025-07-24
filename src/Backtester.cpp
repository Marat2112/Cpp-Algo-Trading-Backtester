#include "Backtester.hpp"
#include <iostream>

void Backtester::run(const std::vector<OHLC>& data, int short_window, int long_window) {
    Strategy strategy;
    strategy.calculateSMA(data, short_window);
    auto sma_short = strategy.getSMA();

    strategy.calculateSMA(data, long_window);
    auto sma_long = strategy.getSMA();

    bool in_position = false;
    double entry_price = 0.0;

    for (size_t i = long_window; i < data.size(); ++i) {
        if (sma_short[i - long_window] > sma_long[i - long_window] && !in_position) {
            entry_price = data[i].close;
            in_position = true;
        } else if (sma_short[i - long_window] < sma_long[i - long_window] && in_position) {
            profit_ += data[i].close - entry_price;
            in_position = false;
        }
    }

    std::cout << "Итоговая прибыль: $" << profit_ << std::endl;
}
