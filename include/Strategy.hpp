#pragma once
#include <vector>
#include <string>

struct OHLC {
    std::string date;
    double open, high, low, close;
    long volume;
};

class Strategy {
public:
    void calculateSMA(const std::vector<OHLC>& data, int window);
    std::vector<double> getSMA() const { return sma_; }

private:
    std::vector<double> sma_;
};
