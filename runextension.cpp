
#include <stdio.h>
#include <Windows.h>
int main(int argc, char* argv[])
{
	if (argc > 1)
	{
		char cmdline[500];
		sprintf_s(cmdline, "%s", argv[1]);
		if (argc > 2)
		{
			for (int i = 2; i < argc; i++)
			{
				char tmp[40];
				sprintf_s(tmp, " %s", argv[i]);
				strcat_s(cmdline, tmp);
			}
		}
		PROCESS_INFORMATION pi;
		STARTUPINFOA si = { sizeof(STARTUPINFO) };
		CreateProcessA(0, cmdline, 0, 0, false, 0, 0, 0, &si, &pi);
		CloseHandle(pi.hThread);
		CloseHandle(pi.hProcess);
		exit(0);
	}
	return -1;
}

