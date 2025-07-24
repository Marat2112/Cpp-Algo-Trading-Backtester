#pragma once
#include <vector>
#include "Strategy.hpp"

class Backtester {
public:
    void run(const std::vector<OHLC>& data, int short_window, int long_window);
    double getProfit() const { return profit_; }

private:
    double profit_ = 0.0;
};
