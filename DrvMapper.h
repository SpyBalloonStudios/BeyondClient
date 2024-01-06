#pragma once
#include "Imports.h"
#include "Xorstr.h"

#include <vector>

namespace DrvMapper
{
	struct DownloadRD {
		bool Valid;
		std::vector<std::uint8_t> RawDriver;
		size_t Size;
	};

	static std::uintptr_t mappedDriverBase;
	static std::size_t mappedDriverSize;

	bool MapDriver();
	bool UnloadDriver(std::uintptr_t driverBase, std::uint32_t driverSize);
	bool UnloadBeyondDriver();
}