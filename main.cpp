#include "injection.h"

const char* ProcName = "Target.exe";
const char* DllName = "Payload.dll";

int main(int argc, char* argv[]) {
	if (argc == 5) {
		for (int i = 0; i < argc; i++) {
			if (!strcmp(argv[i], "-proc")) {
				ProcName = argv[i + 1];
				continue;
			}
			if (!strcmp(argv[i], "-dll")) {
				DllName = argv[i + 1];
				continue;
			}
		}
	}

	std::filesystem::path DllPath = std::filesystem::absolute(DllName);

	if (!std::filesystem::exists(DllPath)) {
		printf("[-] Can't locate %s\n", DllName);
		system("pause");
		return 0;
	}

	HANDLE hProc = OpenProc(ProcName);
	if (!hProc)
		return 0;

	printf("[+] %s Handle: %p\n", ProcName, hProc);

	if (!ManualMap(hProc, DllPath)) {
		printf("[-] Injection error\n");
		CloseHandle(hProc);
		system("pause");
		return 0;
	}

	CloseHandle(hProc);

	printf("[+] Injected!\n");
	system("pause");

	return 0;
}
