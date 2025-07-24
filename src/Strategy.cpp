#include "Strategy.hpp"
#include <numeric>

void Strategy::calculateSMA(const std::vector<OHLC>& data, int window) {
    sma_.clear();
    for (size_t i = window - 1; i < data.size(); ++i) {
        double sum = 0.0;
        for (int j = 0; j < window; ++j) {
            sum += data[i - j].close;
        }
        sma_.push_back(sum / window);
    }
}
