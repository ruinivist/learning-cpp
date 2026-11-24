// Defines a logger and an in-memory implementation.
// The brew cycle uses it to record each result.

#pragma once

#include <string>
#include <vector>

class Logger {
   public:
    virtual ~Logger() = default;
    virtual void log(const std::string& message) = 0;
};

class InMemoryLogger : public Logger {
   public:
    void log(const std::string& message) override {
        messages_.push_back(message);
    }
    const std::vector<std::string>& messages() const { return messages_; }

   private:
    std::vector<std::string> messages_;
};
