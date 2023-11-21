/*Consider a scenario in which you have to manage configuration parameters in a C++ application. 
You might need to store and retrieve both global and local configurations, and you want to avoid 
naming conflicts.*/


#include <iostream>
#include <string>
using namespace std;

class ConfigurationManager
{
    static int globalConfiguration;  // Global configuration
public:
    int localConfiguration;         // Local configuration

    ConfigurationManager(int localConfig)
    {
        localConfiguration = localConfig;
    }

    static int getGlobalConfiguration()
    {
        return globalConfiguration;
    }

    int getLocalConfiguration()
    {
        return localConfiguration;
    }
};

int ConfigurationManager::globalConfiguration = 42;  // Default global configuration

int main()
{
    ConfigurationManager globalManager(10);   // Local configuration for a specific instance
    ConfigurationManager localManager(20);

    cout << "Global Configuration: " << ConfigurationManager::getGlobalConfiguration() << endl;
    cout << "Local Configuration for globalManager: " << globalManager.getLocalConfiguration() << endl;
    cout << "Local Configuration for localManager: " << localManager.getLocalConfiguration() << endl;

    return 0;
}
