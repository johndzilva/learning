#include <iostream>

using namespace std;

class LogLevel {

public:
	// WANNING AND ERROR automatically takes 1 and 2.
	// If the initial value is set to 5 then consequent 6 and 7 will be assigned
	enum LEVEL {
		INFO = 0, WARNING, ERROR
	};
private:
	int m_logLevel = INFO;
public:
	void setLogLevel(int level) {
		m_logLevel = level;
	}

	void warn(const char* message) {
		if (m_logLevel >= WARNING)
			cout << "[WARN] :: " << message;
	}
	void error(const char* message) {
		if (m_logLevel >= ERROR)
			cout << "[ERROR] :: " << message;
	}
	void info(const char* message) {
		if (m_logLevel >= INFO)
			cout << "[INFO] :: " << message;
	}
};

int main() {
	LogLevel l1;
	// here enum LEVEL is directly accessible from the LogLevel class
	l1.setLogLevel(LogLevel::WARNING);
	l1.info("warning!");
	l1.warn("warning!");
	l1.error("warning!");
}
