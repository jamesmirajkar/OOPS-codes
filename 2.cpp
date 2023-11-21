#include <iostream>
#include <fstream>
using namespace std;

class Logger {
public:
  class LogWriter {
  private:
    ofstream outfile;
  public:
    LogWriter(string filename) {
      outfile.open(filename);
    }

    void write(string message) {
      outfile << message << endl;
    }

    void close() {
      outfile.close();
    }
  };

  // Outer class member function that creates and returns a LogWriter object.
  LogWriter getLogWriter(string filename) {
    return LogWriter(filename);
  }
};

int main() {
  Logger logger;

  // Get a log writer object.
  Logger::LogWriter logWriter = logger.getLogWriter("logfile.txt");

  // Write a message to the log file.
  logWriter.write("This is a log message.");

  // Close the log file.
  logWriter.close();

  return 0;
}
