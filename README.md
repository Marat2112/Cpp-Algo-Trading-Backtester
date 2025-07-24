# Cpp-Algo-Trading-Backtester
# 📊 C++ AlgoTrading Backtester

Профессиональный бэктестер для алгоритмической торговли на C++ с подключением к реальным рыночным данным через API Alpha Vantage.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)
[![C++17](https://img.shields.io/badge/C++-17-blue.svg)](https://en.cppreference.com/w/cpp/17)
[![Build Status](https://img.shields.io/github/actions/workflow/status/yourname/Cpp-Algo-Trading-Backtester/build.yml)](https://github.com/yourname/Cpp-Algo-Trading-Backtester/actions)

## 🚀 Возможности

- 📡 Загрузка исторических данных через **Alpha Vantage API**
- 📈 Реализация стратегии **SMA Crossover** (скользящие средние)
- 💻 Оптимизированный код на **C++17**
- 📊 Визуализация результатов через Python (опционально)
- 📦 Простая сборка через CMake/Make

## ⚙️ Установка

### Требования
- Компилятор C++17 (GCC 9+, Clang 10+, MSVC 2019+)
- Библиотеки: `libcurl`, `nlohmann-json`
- Python 3.8+ (для визуализации)

# 🛠 Сборка и запуск

bash

Клонировать репозиторий
git clone https://github.com/yourname/Cpp-Algo-Trading-Backtester.git
cd Cpp-Algo-Trading-Backtester

# Сборка через Make

make && ./backtester

# Или через CMake

mkdir build && cd build
cmake .. && make
./backtester

# 🔑 Настройка API

Получите бесплатный API-ключ на Alpha Vantage

Вставьте ключ в src/main.cpp:

cpp
const std::string api_key = "YOUR_API_KEY";

# 📜 Лицензия

MIT License. Подробнее в файле LICENSE.

# 📂 Структура проекта

```mermaid
graph TD
    A[Cpp-Algo-Trading-Backtester] --> B[data/]
    A --> C[include/]
    A --> D[src/]
    A --> E[CMakeLists.txt]
    A --> F[Makefile]
    A --> G[README.md]
    
    B --> B1["🗄️ AAPL.json"]
    
    C --> C1["🌐 DataFetcher.hpp"]
    C --> C2["📊 Backtester.hpp"]
    C --> C3["📈 Strategy.hpp"]
    
    D --> D1["🚀 main.cpp"]
    D --> D2["⚡ DataFetcher.cpp"]
    D --> D3["💰 Backtester.cpp"]
    D --> D4["✨ Strategy.cpp"]
    
    style A fill:#f9f9f9,stroke:#333,stroke-width:2px
    style B fill:#e3f2fd,stroke:#64b5f6
    style C fill:#e8f5e9,stroke:#81c784
    style D fill:#fff3e0,stroke:#ffb74d
```
