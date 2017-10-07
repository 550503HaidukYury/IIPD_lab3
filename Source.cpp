
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <PowrProf.h>
#include <string>
#include <sstream>

bool applyVideoTimeout(DWORD);
int showVideoTimeout();

int main(int argc,char* argv[])
{
	std::cout << argc << std::endl;
	if (argc == 3)// если 3 аргумента - сохраняем текущее время отключения дисплея
	{
		int x = showVideoTimeout();
		//std::cout << showVideoTimeout() << std::endl;
		std::ofstream file("file", std::ios::binary);
		file.write((char *)&x, sizeof(x));
		file.close();
	}

	if (argc == 2)// если 2 аргумента - устанавливаем новое время
	{
		std::string ss(argv[1]);
		int x = atoi(ss.c_str());
		
		if(applyVideoTimeout(x))
		std::cout << "changed to:" << x << std::endl;
	}
	else
	{
		std::cout << "Not arguments" << std::endl;
		int x;
		std::ifstream file("file", std::ios::binary);
		if (!file){
		int x = showVideoTimeout();
		std::ofstream file("file", std::ios::binary);
		file.write((char *)&x, sizeof(x));
		file.close();
		}
		file.read((char *)&x, sizeof(x));
		file.close();

		std::cout << "saved data: "<< x << std::endl;
	}
	//system("pause");
	return 0;

}

bool applyVideoTimeout(DWORD newtimeOut)
{
	SYSTEM_POWER_POLICY powerPolicy;
	DWORD ret;
	DWORD size = sizeof(SYSTEM_POWER_POLICY);

	ret = CallNtPowerInformation(SystemPowerPolicyAc, nullptr, 0, &powerPolicy, size);

	if ((ret != ERROR_SUCCESS) || (size != sizeof(SYSTEM_POWER_POLICY)))
	{
		return false;
	}

	powerPolicy.VideoTimeout = newtimeOut;
	ret = CallNtPowerInformation(SystemPowerPolicyAc, &powerPolicy, size, nullptr, 0);

	if ((ret != ERROR_SUCCESS))
	{
		return false;
	}

	return true;
}
int showVideoTimeout()
{
	SYSTEM_POWER_POLICY powerPolicy;
	DWORD ret;
	DWORD size = sizeof(SYSTEM_POWER_POLICY);

	ret = CallNtPowerInformation(SystemPowerPolicyAc, nullptr, 0, &powerPolicy, size);

	if ((ret != ERROR_SUCCESS) || (size != sizeof(SYSTEM_POWER_POLICY)))
	{
		return 0;
	}

	std::cout << powerPolicy.VideoTimeout << std::endl;
	return powerPolicy.VideoTimeout;
}